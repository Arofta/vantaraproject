function:OnInsertCharacterName(playerid, const char_name[])
{
    if(cache_num_rows() > 0)
        return Dialog_Show(playerid, "CreateCharName", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Nama karakter sudah digunakan pemain lain. Silahkan masukkan nama karakter Anda.", "Input", "Kembali");

    strcopy(tempCharName[playerid], char_name);
    Dialog_Show(playerid, "CreateCharDOB", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Silahkan masukkan tanggal lahir karakter Anda (DD-MM-YYYY).", "Input", "Kembali");
    return 1;
}

function:__ResetBHOP(playerid, lastBHOP)
{
    if(lastBHOP == g_BHOP[playerid]) g_BHOP[playerid] = 0;
    return 1;
}

function:__KickDelay(playerid)
{
    return Kick(playerid);
}