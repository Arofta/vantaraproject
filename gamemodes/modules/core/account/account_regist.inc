#include <easyDialog>

AccountCheck(playerid)
{
    new query[256];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_accounts` WHERE `account_name` = '%e' LIMIT 1", pData[playerid][pUCP]);
    mysql_tquery(g_SQL, query, "OnAccountCheck", "d", playerid);
    return 1;
}

function:OnAccountCheck(playerid)
{
    if(!cache_num_rows())
    {
        Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, "Vantara Roleplay - Account not found", "Your account was not found. Please join our discord server to create an account.\ndiscord.gg/vantara", "Quit", "");
        return Kick(playerid);
    }
    
    cache_get_value_name_int(0, "account_id", pData[playerid][pAccountID]);
    cache_get_value_name_int(0, "account_verify", tempVerify[playerid]);
    cache_get_value_name_int(0, "account_recovery", tempRecovery[playerid]);

    if(tempVerify[playerid] != -1)
        return Dialog_Show(playerid, "Verification", DIALOG_STYLE_INPUT, "Vantara Roleplay - Account Verification", "Your account is not verified. Please enter your verification code.", "Input", "Cancel");
    
    if(tempRecovery[playerid] != -1)
        return Dialog_Show(playerid, "Recovery", DIALOG_STYLE_INPUT, "Vantara Roleplay - Account Recovery", "Your account is in recovery mode. Please enter your recovery code.", "Input", "Cancel");

    Dialog_Show(playerid, "Login", DIALOG_STYLE_PASSWORD, "Vantara Roleplay - Login", "Please enter your password to login.", "Input", "Cancel");
    return 1;
}

function:OnPassworHashed(playerid)
{
    new hash[BCRYPT_HASH_LENGTH],
        str[144];
    bcrypt_get_hash(hash);

    new query[256];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_accounts` SET `account_password` = '%e', `account_verify` = -1, `account_recovery` = -1 WHERE `account_id` = %d;", hash, pData[playerid][pAccountID]);
    mysql_tquery(g_SQL, query);

    format(str, sizeof(str), "Your password has been set, Please enter your password.\nAttempt: %dx", tempLoginAttempts[playerid]);
    Dialog_Show(playerid, "Login", DIALOG_STYLE_PASSWORD, "Vantara Roleplay - Login", str, "Input", "Cancel");
    return 1;
}

function:OnPlayerInputPassword(playerid, const password[])
{
    if(!cache_num_rows())
    {
        Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, "Vantara Roleplay - Account not found", "Something went wrong!\nPlease try again later.", "Quit", "");
        return Kick(playerid);
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
        new query[512];
        mysql_format(g_SQL, query, sizeof(query), "SELECT `char_id`, `char_name`, `char_level`, `char_money`, `char_bank_money` FROM `player_characters` WHERE `char_account_id` = %d LIMIT %d", pData[playerid][pAccountID], MAX_CHARACTERS);
        mysql_pquery(g_SQL, query, "LoadCharacter", "d", playerid);
        return 1;
    }
    else
    {
        tempLoginAttempts[playerid]--;
        if(tempLoginAttempts[playerid] <= 0)
        {
            Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, "Vantara Roleplay - Login", "Too many failed login attempts. You have been kicked.", "Quit", "");
            return Kick(playerid);
        }
        new str[144];
        format(str, sizeof(str), "Invalid Password, Please enter your password.\nAttempt: %dx", tempLoginAttempts[playerid]);
        Dialog_Show(playerid, "Login", DIALOG_STYLE_PASSWORD, "Vantara Roleplay - Login", str, "Input", "Cancel");
    }
    return 1;
}

Dialog:Login(playerid, response, listitem, inputtext[])
{
    if(!response) return Kick(playerid);

    new str[144];
    if(isnull(inputtext))
    {
        tempLoginAttempts[playerid]--;
        if(tempLoginAttempts[playerid] <= 0)
        {
            Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, "a Roleplay - Login", "Too many failed login attempts. You have been kicked.", "Quit", "");
            return Kick(playerid);
        }

        format(str, sizeof(str), "Password Cannot be empty, Please enter your password.\nAttempt: %dx", tempLoginAttempts[playerid]);
        return Dialog_Show(playerid, "Login", DIALOG_STYLE_PASSWORD, "Vantara Roleplay - Login", str, "Input", "Cancel");
    }

    new query[256];
    mysql_format(g_SQL, query, sizeof(query), "SELECT `account_password` FROM `player_accounts` WHERE `account_id` = %d", pData[playerid][pAccountID]);
    mysql_tquery(g_SQL, query, "OnPlayerInputPassword", "ds", playerid, inputtext);
    return 1;
}

Dialog:NewPassword(playerid, response, listitem, inputtext[])
{
    if(!response) return Kick(playerid);

    if(isnull(inputtext) || strlen(inputtext) < 8)
        return Dialog_Show(playerid, "NewPassword", DIALOG_STYLE_PASSWORD, "Vantara Roleplay - Create Password", "Password must be at least 8 characters long. Please enter a valid password.", "Input", "Cancel");

    if(strlen(inputtext) > 32)
        return Dialog_Show(playerid, "NewPassword", DIALOG_STYLE_PASSWORD, "Vantara Roleplay - Create Password", "Password must be no longer than 32 characters. Please enter a valid password.", "Input", "Cancel");

    if(!IsValidPassword(inputtext))
        return Dialog_Show(playerid, "NewPassword", DIALOG_STYLE_PASSWORD, "Vantara Roleplay - Create Password", "Invalid password format. Please enter a valid password.", "Input", "Cancel");

    bcrypt_hash(playerid, "OnPassworHashed", inputtext, BCRYPT_COST);
    return 1;
}

Dialog:Verification(playerid, response, listitem, inputtext[])
{
    if(!response) return Kick(playerid);

    if(!IsNumericEx(inputtext) || isnull(inputtext))
        return Dialog_Show(playerid, "Verification", DIALOG_STYLE_INPUT, "Vantara Roleplay - Account Verification", "Verification code must be numbers only. Please enter a valid verification code.", "Input", "Cancel");

    if(strval(inputtext) != tempVerify[playerid])
        return Dialog_Show(playerid, "Verification", DIALOG_STYLE_INPUT, "Vantara Roleplay - Account Verification", "Incorrect verification code. Please try again.", "Input", "Cancel");
    
    Dialog_Show(playerid, "NewPassword", DIALOG_STYLE_PASSWORD, "Vantara Roleplay - Create Password", "Your account has been verified. Please enter your password to login.", "Input", "Cancel");
    return 1;
}

Dialog:Recovery(playerid, response, listitem, inputtext[])
{
    if(!response) return Kick(playerid);

    if(!IsNumericEx(inputtext) || isnull(inputtext))
        return Dialog_Show(playerid, "Recovery", DIALOG_STYLE_INPUT, "Vantara Roleplay - Account Recovery", "Recovery code must be numbers only. Please enter a valid recovery code.", "Input", "Cancel");

    if(strval(inputtext) != tempRecovery[playerid])
        return Dialog_Show(playerid, "Recovery", DIALOG_STYLE_INPUT, "Vantara Roleplay - Account Recovery", "Incorrect recovery code. Please try again.", "Input", "Cancel");
    
    Dialog_Show(playerid, "NewPassword", DIALOG_STYLE_PASSWORD, "Vantara Roleplay - Create Password", "Please enter your desired password to register your account.", "Input", "Cancel");
    return 1;
}
