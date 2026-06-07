function:OnInsertCharacterName(playerid, const char_name[])
{
    if(cache_num_rows() > 0)
        return Dialog_Show(playerid, "CreateCharName", DIALOG_STYLE_INPUT, "Vantara Roleplay - Create Character", "Character Name already exists. Please choose a different name.", "Input", "Back");

    strcopy(tempCharName[playerid], char_name);
    Dialog_Show(playerid, "CreateCharDOB", DIALOG_STYLE_INPUT, "Vantara Roleplay - Create Character", "Please enter your character's date of birth (DD-MM-YYYY)", "Input", "Back");
    return 1;
}
