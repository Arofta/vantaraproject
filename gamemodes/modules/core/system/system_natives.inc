ShowCharacterList(playerid)
{
    new count = 0, 
        cstrl[512];

    format(cstrl, sizeof(cstrl), "Name\tLevel\tMoney\tBank\t\n");
    for(new i = 0; i < MAX_CHARACTERS; i++)
    {
        if(!isnull(PlayerChar[playerid][i][CharName]))
        {
            format(cstrl, sizeof(cstrl), "%s%s\t%d\t$%d\t$%d\n", cstrl, PlayerChar[playerid][i][CharName], PlayerChar[playerid][i][CharLevel], PlayerChar[playerid][i][CharMoney], PlayerChar[playerid][i][CharBankMoney]);
            count++;
        }
    }
    if(count < MAX_CHARACTERS) 
        format(cstrl, sizeof(cstrl), "%s{00FF00}Create New Character", cstrl);
    
    Dialog_Show(playerid, "CharacterList", DIALOG_STYLE_TABLIST_HEADERS, "Vantara Roleplay - Character Selection", cstrl, "Select", "Cancel");
    return 1;
}

ShowSpawnSelection(playerid)
{
    switch(pData[playerid][pDomicile])
    {
        case 0:
        {
            Dialog_Show(playerid, "LSSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "Los Santos International Airport\nOcean Docks", "Select", "");
            return 1;
        }
        
        case 1:
        {
            Dialog_Show(playerid, "SFSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "San Fierro Airport\nEsplande North", "Select", "");
            return 1;
        }

        case 2:
        {
            Dialog_Show(playerid, "LVSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "Las Venturas Airport\nLinden Station", "Select", "");
            return 1;
        }

        default:
        {
            Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, "Vantara Roleplay - Character's Domicile not found", "Something went wrong, please try later.", "Quit", "");
            Kick(playerid);
            return 1;
        }
    }
    
    return 1;
}

stock IsValidPassword(const name[])
{
    new len = strlen(name);

    for(new ch = 0; ch != len; ch++)
    {
        switch(name[ch])
        {
            case 'A' .. 'Z', 'a' .. 'z', '0' .. '9', ']', '[', '(', ')', '_', '.', '@', '#': continue;
            default: return false;
        }
    }
    return true;
}

stock IsRoleplayName(const name[]) 
{
    if(!name[0] || strfind(name, "_") == -1)
        return 0;

    for(new i = 0, len = strlen(name); i != len; i ++) 
    {
        if((i == 0) && (name[i] < 'A' || name[i] > 'Z'))
            return 0;

        else if((i != 0 && i < len  && name[i] == '_') && (name[i + 1] < 'A' || name[i + 1] > 'Z'))
            return 0;

        else if((name[i] < 'A' || name[i] > 'Z') && (name[i] < 'a' || name[i] > 'z') && name[i] != '_' && name[i] != '.')
            return 0;
    }
    return 1;
}

stock IsValidName(const name[])
{
    new len = strlen(name);

    for(new ch = 0; ch != len; ch++)
    {
        switch(name[ch])
        {
            case 'A' .. 'Z', 'a' .. 'z', '0' .. '9', ']', '[', '(', ')', '_', '.': continue;
            default: return false;
        }
    }
    return true;
}

IsNumericEx(const string[]) 
{
    for (new i = 0, j = strlen(string); i < j; i++)
    {
        if (string[i] > '9' || string[i] < '0') return 0;
    }
    return 1;
}

stock GetPlayerGender(playerid, gender[], size = sizeof(gender))
{
    strcopy(gender, size, GenderNames[pData[playerid][pGender]]);
    return 1;
}

stock UpperCase(string[])
{
    for(new i = 0; string[i] != '\0'; i++)
    {
        if('a' <= string[i] <= 'z')
        {
            string[i] -= ('a' - 'A'); // atau 32
        }
    }
    return 1;
}

stock bool:IsLeapYear(year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

stock bool:IsValidDOB(const string[])
{
    if(strlen(string) != 10)
        return false;

    if(string[2] != '-' || string[5] != '-')
        return false;

    new day, month, year;

    if(sscanf(string, "p<->ddd", day, month, year))
        return false;

    new currentYear, currentMonth, currentDay;
    getdate(currentYear, currentMonth, currentDay);

    // Minimal umur 17 tahun
    currentYear -= 17;

    if(year < 1900 || year > currentYear)
        return false;

    if(month < 1 || month > 12)
        return false;

    static const MonthDays[] =
    {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    new maxDay = MonthDays[month - 1];

    if(month == 2 && IsLeapYear(year))
        maxDay = 29;

    if(day < 1 || day > maxDay)
        return false;

    return true;
}

stock SaveCharacterData(playerid)
{
    if(!PlayerData[playerid][pLoggedIn])
        return 0;

    static query[4096];

    mysql_format(g_SQL, query, sizeof(query),
        "UPDATE `player_characters` SET \
        `char_ucp` = '%e', \
        `char_name` = '%e', \
        `char_last_online` = '%e', \
        `char_last_exit` = %d, \
        `char_pos_x` = %.4f, \
        `char_pos_y` = %.4f, \
        `char_pos_z` = %.4f, \
        `char_pos_a` = %.4f, \
        `char_health` = %.1f, \
        `char_armour` = %.1f, \
        `char_level` = %d, \
        `char_money` = %d, \
        `char_bank_money` = %d, \
        `char_skin` = %d, \
        `char_dob` = '%e', \
        `char_origin` = %d, \
        `char_gender` = %d, \
        `char_weight` = %d, \
        `char_height` = %d, \
        `char_domicile` = %d, \
        `char_hunger` = %.2f, \
        `char_thirst` = %.2f, \
        `char_stress` = %.2f \
        WHERE `char_id` = %d",
        PlayerData[playerid][pName],
        PlayerData[playerid][pLastOnlineDate],
        PlayerData[playerid][pLastExit],
        PlayerData[playerid][pPosX],
        PlayerData[playerid][pPosY],
        PlayerData[playerid][pPosZ],
        PlayerData[playerid][pPosA],
        PlayerData[playerid][pHealth],
        PlayerData[playerid][pArmour],
        PlayerData[playerid][pLevel],
        PlayerData[playerid][pMoney],
        PlayerData[playerid][pBankMoney],
        PlayerData[playerid][pSkin],
        PlayerData[playerid][pDOB],
        PlayerData[playerid][pOrigin],
        PlayerData[playerid][pGender],
        PlayerData[playerid][pWeight],
        PlayerData[playerid][pHeight],
        PlayerData[playerid][pDomicile],
        PlayerData[playerid][pHunger],
        PlayerData[playerid][pThirst],
        PlayerData[playerid][pStress],
        PlayerData[playerid][pID]
    );

    mysql_tquery(g_SQL, query);

    return 1;
}
    return 1;
}
