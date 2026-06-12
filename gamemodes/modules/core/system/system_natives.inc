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
            if(pData[playerid][pLastExit] > 0) 
                return Dialog_Show(playerid, "LSSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "Los Santos International Airport\nOcean Docks\nLast Exit", "Select", "");
            Dialog_Show(playerid, "LSSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "Los Santos International Airport\nOcean Docks", "Select", "");
            return 1;
        }
        
        case 1:
        {
            if(pData[playerid][pLastExit] > 0) 
                return Dialog_Show(playerid, "LSSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "San Fierro Airport\nEsplande North\nLast Exit", "Select", "");
            Dialog_Show(playerid, "SFSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "San Fierro Airport\nEsplande North", "Select", "");
            return 1;
        }

        case 2:
        {
            if(pData[playerid][pLastExit] > 0) 
                return Dialog_Show(playerid, "LVSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "Las Venturas Airport\nLinden Station\nLast Exit", "Select", "");
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
    if(!pData[playerid][pLoggedIn] || pData[playerid][pID] < 1)
        return 0;

    static query[4096];

    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET ");

    mysql_format(g_SQL, query, sizeof(query), "%s`char_ucp` = '%e', ", query, pData[playerid][pUCP]);

    mysql_format(g_SQL, query, sizeof(query), "%s`char_name` = '%e', ", query, pData[playerid][pName]);

    mysql_format(g_SQL, query, sizeof(query), "%s`char_last_online` = CURRENT_TIMESTAMP, ", query);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_last_exit` = %d, ", query, gettime() + 3600);

    GetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
    GetPlayerFacingAngle(playerid, pData[playerid][pPosA]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_pos_x` = %.4f, ", query, pData[playerid][pPosX]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_pos_y` = %.4f, ", query, pData[playerid][pPosY]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_pos_z` = %.4f, ", query, pData[playerid][pPosZ]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_pos_a` = %.4f, ", query, pData[playerid][pPosA]);

    mysql_format(g_SQL, query, sizeof(query), "%s`char_health` = %.2f, ", query, pData[playerid][pHealth]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_armour` = %.2f, ", query, pData[playerid][pArmour]);

    mysql_format(g_SQL, query, sizeof(query), "%s`char_admin_name` = '%e', ", query, pData[playerid][pAdminName]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_admin_level` = %d, ", query, pData[playerid][pAdminLevel]);

    mysql_format(g_SQL, query, sizeof(query), "%s`char_level` = %d, ", query, pData[playerid][pLevel]);
    
    mysql_format(g_SQL, query, sizeof(query), "%s`char_money` = %d, ", query, pData[playerid][pMoney]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_bank_money` = %d, ", query, pData[playerid][pBankMoney]);
        
    mysql_format(g_SQL, query, sizeof(query), "%s`char_skin` = %d, ", query, pData[playerid][pSkin]);

    mysql_format(g_SQL, query, sizeof(query), "%s`char_dob` = '%e', ", query, pData[playerid][pDOB]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_origin` = %d, ", query, pData[playerid][pOrigin]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_gender` = %d, ", query, pData[playerid][pGender]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_weight` = %d, ", query, pData[playerid][pWeight]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_height` = %d, ", query, pData[playerid][pHeight]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_domicile` = %d, ", query, pData[playerid][pDomicile]);
    
    mysql_format(g_SQL, query, sizeof(query), "%s`char_hunger` = %.2f, ", query, pData[playerid][pHunger]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_thirst` = %.2f, ", query, pData[playerid][pThirst]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_stress` = %.2f ", query, pData[playerid][pStress]);

    mysql_format(g_SQL, query, sizeof(query), "%sWHERE `char_id` = %d", query, pData[playerid][pID]);
    mysql_tquery(g_SQL, query);
    return 1;
}

stock ResetVariables(playerid)
{
    // Temporary Variables
    tempVerify[playerid] = -1;
    tempRecovery[playerid] = -1;
    tempLoginAttempts[playerid] = 3;

    tempCharName[playerid][0] = EOS;
    tempCharDOB[playerid][0] = EOS;

    tempCharHeight[playerid] = 0;
    tempCharWeight[playerid] = 0;

    tempCharGender[playerid] = -1;
    tempCharOrigin[playerid] = -1;
    tempCharDomicile[playerid] = -1;

    for(new i = 0; i < MAX_CHARACTERS; i++)
    {
        PlayerChar[playerid][i][CharID] = 0;
        PlayerChar[playerid][i][CharName][0] = EOS;
        PlayerChar[playerid][i][CharMoney] = 0;
        PlayerChar[playerid][i][CharBankMoney] = 0;
        PlayerChar[playerid][i][CharLevel] = 0;
    }

    // Session Variables
    pData[playerid][pID] = 0;
    pData[playerid][pAccountID] = 0;

    pData[playerid][pSpawned] = false;
    pData[playerid][pLoggedIn] = false;

    pData[playerid][pRegisterDate][0] = EOS;
    pData[playerid][pLastOnlineDate][0] = EOS;
    pData[playerid][pLastExit] = 0;

    pData[playerid][pName][0] = EOS;
    pData[playerid][pUCP][0] = EOS;

    pData[playerid][pAdminLevel] = 0;
    pData[playerid][pAdminName][0] = EOS;

    pData[playerid][pMoney] = 0;
    pData[playerid][pBankMoney] = 0;

    pData[playerid][pHealth] = 0.0;
    pData[playerid][pArmour] = 0.0;

    pData[playerid][pSkin] = 0;
    
    pData[playerid][pDOB][0] = EOS;
    pData[playerid][pGender] = -1;
    pData[playerid][pHeight] = 0;
    pData[playerid][pWeight] = 0;
    pData[playerid][pOrigin] = -1;
    pData[playerid][pDomicile] = -1;

    pData[playerid][pPosX] = 0.0;
    pData[playerid][pPosY] = 0.0;
    pData[playerid][pPosZ] = 0.0;
    pData[playerid][pPosA] = 0.0;

    pData[playerid][pInterior] = 0;
    pData[playerid][pVirtualWorld] = 0;

    pData[playerid][pHunger] = 0.0;
    pData[playerid][pThirst] = 0.0;
    pData[playerid][pStress] = 0.0;

    pData[playerid][pHungerTime] = 120;
    pData[playerid][pThirstTime] = 90;
    pData[playerid][pStressTime] = 150;

    pData[playerid][pLevel] = 0;
    pData[playerid][pDrunkLevel] = 0;

    Aduty[playerid] = false;
    return 1;
}
