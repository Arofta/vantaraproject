#include <easyDialog>

AccountCheck(playerid)
{
    new query[256];
    mysql_format(SQL, query, sizeof(query), "SELECT * FROM `player_accounts` WHERE `account_name` = '%e' LIMIT 1", pData[playerid][pUCP]);
    mysql_pquery(SQL, query, "OnAccountCheck", "d", playerid);
    return 1;
}

function:OnAccountCheck(playerid)
{
    if(!cache_num_rows())
    {
        Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Account not found", sprintf("Akun dengan nama "F_COLOR_RED"%s"F_COLOR_WHITE" tidak ditemukan didalam database kami. Silahkan bergabung dengan server discord kami untuk membuat akun.\n"F_COLOR_YELLOW"discord.gg/vantara", pData[playerid][pUCP]), "Keluar", "");
        return KickEx(playerid);
    }
    
    cache_get_value_name_int(0, "account_id", pData[playerid][pAccountID]);
    cache_get_value_name_int(0, "account_verify", tempVerify[playerid]);
    cache_get_value_name_int(0, "account_recovery", tempRecovery[playerid]);
    cache_get_value_name(0, "account_register_date", pData[playerid][pAccountRegistDate]);
    cache_get_value_name(0, "account_last_online", pData[playerid][pAccountLastOnlineDate]);

    if(tempVerify[playerid] != -1)
        return Dialog_Show(playerid, "Verification", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Account Verification", "Akun Anda belum terverifikasi. Silahkan masukkan kode verifikasi akun Anda.", "Input", "Batal");
    
    if(tempRecovery[playerid] != -1)
        return Dialog_Show(playerid, "Recovery", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Account Recovery", "Akun Anda dalam status pemulihan. Silahkan masukkan kode pemulihan akun Anda.", "Input", "Batal");

    Dialog_Show(playerid, "Login", DIALOG_STYLE_PASSWORD, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Login", sprintf(""F_COLOR_WHITE"Silahkan masukkan kata sandi akun Anda.\nLast online: "F_COLOR_YELLOW"%s\n"F_COLOR_WHITE"Attempt(s): "F_COLOR_YELLOW"%dx", pData[playerid][pAccountLastOnlineDate], tempLoginAttempts[playerid]), "Input", "Batal");
    return 1;
}

function:OnPassworHashed(playerid)
{
    new hash[BCRYPT_HASH_LENGTH];
    bcrypt_get_hash(hash);

    new query[256];
    mysql_format(SQL, query, sizeof(query), "UPDATE `player_accounts` SET `account_password` = '%e', `account_verify` = -1, `account_recovery` = -1 WHERE `account_id` = %d", hash, pData[playerid][pAccountID]);
    mysql_tquery(SQL, query);

    new str[211];
    format(str, sizeof(str), ""F_COLOR_WHITE"Kata sandi baru berhasil ditetapkan. Silahkan masukkan kata sandi akun Anda.\nLast online: "F_COLOR_YELLOW"%s\n"F_COLOR_WHITE"Attempt(s): "F_COLOR_YELLOW"%dx", pData[playerid][pAccountLastOnlineDate], tempLoginAttempts[playerid]);
    Dialog_Show(playerid, "Login", DIALOG_STYLE_PASSWORD, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Login", str, "Input", "Batal");
    return 1;
}

function:OnPlayerInputPassword(playerid, const password[])
{
    if(!cache_num_rows())
    {
        Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Account not found", "Terjadi kesalahan saat sedang memproses permintaan Anda.", "Keluar", "");
        return KickEx(playerid);
    }

    new hashPass[BCRYPT_HASH_LENGTH];
    cache_get_value_name(0, "account_password", hashPass);
    bcrypt_verify(playerid, "OnCheckingPassword", password, hashPass);
    return 1;
}

function:OnCheckingPassword(playerid, bool:match)
{
    if(match)
    {
        pData[playerid][pLoggedIn] = true;
        new query[256];
        mysql_format(SQL, query, sizeof(query), "SELECT `char_id`, `char_name`, `char_level`, `char_money`, `char_bank_money` FROM `player_characters` WHERE `char_account_id` = %d LIMIT %d", pData[playerid][pAccountID], MAX_CHARACTERS);
        mysql_pquery(SQL, query, "LoadCharacter", "d", playerid);
        return 1;
    }
    else
    {
        if(--tempLoginAttempts[playerid] <= 0)
        {
            Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Login", "Terlalu banyak Percobaan login.", "Keluar", "");
            return KickEx(playerid);
        }
        new str[211];
        format(str, sizeof(str), ""F_COLOR_WHITE"Kata sandi yang Anda masukkan salah. Silahkan masukkan kata sandi akun Anda.\nLast online: "F_COLOR_YELLOW"%s\n"F_COLOR_WHITE"Attempt(s): "F_COLOR_YELLOW"%dx", pData[playerid][pAccountLastOnlineDate], tempLoginAttempts[playerid]);
        Dialog_Show(playerid, "Login", DIALOG_STYLE_PASSWORD, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Login", str, "Input", "Keluar");
    }
    return 1;
}

Dialog:Login(playerid, response, listitem, inputtext[])
{
    if(!response) return KickEx(playerid);

    if(isnull(inputtext))
    {
        if(--tempLoginAttempts[playerid] <= 0)
        {
            Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Login", ""F_COLOR_WHITE"Terlalu banyak percobaan login.", "Keluar", "");
            return KickEx(playerid);
        }
        new str[211];
        format(str, sizeof(str), ""F_COLOR_WHITE"Kata sandi tidak dapat diisi kosong. Silahkan masukkan kata sandi akun Anda.\nLast online: "F_COLOR_YELLOW"%s\n"F_COLOR_WHITE"Attempt(s): "F_COLOR_YELLOW"%dx", pData[playerid][pAccountLastOnlineDate], tempLoginAttempts[playerid]);
        return Dialog_Show(playerid, "Login", DIALOG_STYLE_PASSWORD, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Login", str, "Input", "Keluar");
    }

    new query[256];
    mysql_format(SQL, query, sizeof(query), "SELECT `account_password` FROM `player_accounts` WHERE `account_id` = %d", pData[playerid][pAccountID]);
    mysql_pquery(SQL, query, "OnPlayerInputPassword", "ds", playerid, inputtext);
    return 1;
}

Dialog:NewPassword(playerid, response, listitem, inputtext[])
{
    if(!response) return KickEx(playerid);

    if(isnull(inputtext) || strlen(inputtext) < 8)
        return Dialog_Show(playerid, "NewPassword", DIALOG_STYLE_PASSWORD, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Password", "Kata sandi setidaknya memiliki 8 karakter. Silahkan masukkan kata sandi yang valid.", "Input", "Batal");

    if(strlen(inputtext) > 32)
        return Dialog_Show(playerid, "NewPassword", DIALOG_STYLE_PASSWORD, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Password", "Kata sandi tidak dapat memiliki lebih dari 32 karakter. Silahkan masukkan kata sandi yang valid.", "Input", "Batal");

    if(!IsValidPassword(inputtext))
        return Dialog_Show(playerid, "NewPassword", DIALOG_STYLE_PASSWORD, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Password", "Format kata sandi tidak valid. Silahkan masukkan kata sandi yang valid.", "Input", "Batal");

    bcrypt_hash(playerid, "OnPassworHashed", inputtext, BCRYPT_COST);
    return 1;
}

Dialog:Verification(playerid, response, listitem, inputtext[])
{
    if(!response) return KickEx(playerid);

    if(!IsNumericEx(inputtext) || isnull(inputtext))
        return Dialog_Show(playerid, "Verification", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Account Verification", "Kode verifikasi hanya dapat diisi dengan angka. Silahkan masukkan kode verifikasi Anda.", "Input", "Batal");

    if(strval(inputtext) != tempVerify[playerid])
        return Dialog_Show(playerid, "Verification", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Account Verification", "Kode verifikasi yang Anda masukkan salah. Silahkan coba lagi.", "Input", "Batal");
    
    Dialog_Show(playerid, "NewPassword", DIALOG_STYLE_PASSWORD, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Password", "Akun Anda berhasil diverifikasi. Silahkan buat kata sandi baru untuk login.", "Input", "Batal");
    return 1;
}

Dialog:Recovery(playerid, response, listitem, inputtext[])
{
    if(!response) return KickEx(playerid);

    if(!IsNumericEx(inputtext) || isnull(inputtext))
        return Dialog_Show(playerid, "Recovery", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Account Recovery", "Kode pemulihan hanya dapat diisi dengan angka. Silahkan masukkan kode pemulihan Anda", "Input", "Batal");

    if(strval(inputtext) != tempRecovery[playerid])
        return Dialog_Show(playerid, "Recovery", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Account Recovery", "Kode pemulihan yang Anda masukkan salah. Silahkan coba lagi.", "Input", "Batal");
    
    Dialog_Show(playerid, "NewPassword", DIALOG_STYLE_PASSWORD, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Password", "Akun Anda berhasil dipulihkan. Silahkan buat kata sandi baru untuk login", "Input", "Batal");
    return 1;
}
