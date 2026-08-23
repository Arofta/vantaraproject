ShowCharacterList(playerid)
{
    new 
        count = 0, 
        cstrl[512];

    format(cstrl, sizeof(cstrl), "Name\tLevel\tMoney\tBank\t\n");
    for(new i = 0; i < MAX_CHARACTERS; i++)
    {
        if(!isnull(PlayerChar[playerid][i][CharName]))
        {
            format(cstrl, sizeof(cstrl), "%s%s\t%d\t"F_COLOR_DARKGREEN"%s\t"F_COLOR_DARKGREEN"%s\n", cstrl, PlayerChar[playerid][i][CharName], PlayerChar[playerid][i][CharLevel], FormatRupiah(PlayerChar[playerid][i][CharMoney]), FormatRupiah(PlayerChar[playerid][i][CharBankMoney]));
            count++;
        }
    }
    if(count < MAX_CHARACTERS) 
        format(cstrl, sizeof(cstrl), "%s"F_COLOR_GREEN"+ Buat Karakter Baru", cstrl);
    
    Dialog_Show(playerid, "CharacterList", DIALOG_STYLE_TABLIST_HEADERS, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Character Selection", cstrl, "Pilih", "Batal");
    return 1;
}

bool:Flood_Check(&minTime, maxTime)
{
    if(gettime() < minTime + maxTime)
        return true;
    minTime = gettime();
    return false;
}

ShowSpawnSelection(playerid)
{
    switch(pData[playerid][pDomicile])
    {
        case 0:
        {
            if(pData[playerid][pLastExit] > 0) 
                return Dialog_Show(playerid, "LSSpawn", DIALOG_STYLE_LIST, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Spawn Selection", "Los Santos International Airport\nOcean Docks\nLast Exit", "Pilih", "");
            Dialog_Show(playerid, "LSSpawn", DIALOG_STYLE_LIST, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Spawn Selection", "Los Santos International Airport\nOcean Docks", "Pilih", "");
            return 1;
        }
        
        case 1:
        {
            if(pData[playerid][pLastExit] > 0) 
                return Dialog_Show(playerid, "SFSpawn", DIALOG_STYLE_LIST, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Spawn Selection", "San Fierro Airport\nEsplande North\nLast Exit", "Pilih", "");
            Dialog_Show(playerid, "SFSpawn", DIALOG_STYLE_LIST, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Spawn Selection", "San Fierro Airport\nEsplande North", "Pilih", "");
            return 1;
        }

        case 2:
        {
            if(pData[playerid][pLastExit] > 0) 
                return Dialog_Show(playerid, "LVSpawn", DIALOG_STYLE_LIST, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Spawn Selection", "Las Venturas Airport\nLinden Station\nLast Exit", "Pilih", "");
            Dialog_Show(playerid, "LVSpawn", DIALOG_STYLE_LIST, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Spawn Selection", "Las Venturas Airport\nLinden Station", "Pilih", "");
            return 1;
        }

        default:
        {
            Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Character's Domicile not found", "Terjadi kesalahan saat sedang memproses permintaan Anda.", "Keluar", "");
            KickEx(playerid);
            return 1;
        }
    }
    
    return 1;
}

stock ShowPlayerStats(playerid, targetid)
{
    new 
        str[64],
        str2[1024];

    format(str, sizeof(str), ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - %s's Stats", pData[targetid][pName]);
    format(str2, sizeof(str2), "Category\tDetails\n\
    "F_COLOR_YELLOW"Account Section:"F_COLOR_WHITE"\n\
    ID:\t%d\n\
    Name:\t%s\n\
    Last Online:\t%s\n\
    Register Date:\t%s\n\
     \t \n\
    "F_COLOR_YELLOW"Character Section:"F_COLOR_WHITE"\n\
    ID:\t%d (Session ID:%d)\n\
    Name:\t%s\n\
    Birthday:\t%s\n\
    Origin:\t%s\n\
    Gender:\t%s\n\
    Height:\t%d cm\n\
    Weight:\t%d kg\n\
    Job:\t%s\n\
    Faction:\t%s - %s\n\
    Family:\t%s - %s\n\
    Cash:\t%s\n\
    Bank Money:\t%s\n\
    Health:\t%.1f\n\
    Armour:\t%.1f\n\
    Hunger:\t%.2f\n\
    Thirst:\t%.2f\n\
    Stress:\t%.2f\n\
    Total Warning:\t"F_COLOR_LIGHTYELLOW"%d/20\n\
    Level:\t%d - %s\n\
    Playtime:\t%02dj %02dm %02dd\n\
    Admin Level:\t%s\n\
    Guardian:\t%s - %s\n\
    VIP:\t%s"F_COLOR_WHITE" - %s\n\
    Vehicle Slot:\t%d/%d\n\
    Skin ID:\t%d\n\
    World ID:\t%d\n\
    Interior ID:\t%d\n\
    House ID:\t%d\n\
    Biz ID:\t%d\n\
    Door ID:\t%d\n\
    Rusun ID:\t%d\n\
    Last Online:\t%s\n\
    Register Date:\t%s",
    pData[targetid][pAccountID], 
    pData[targetid][pUCP], 
    pData[targetid][pAccountLastOnlineDate], 
    pData[targetid][pAccountRegistDate],

    pData[targetid][pID], targetid, 
    pData[targetid][pName],
    pData[targetid][pDOB], 
    GetPlayerOriginName(targetid),
    GetPlayerGenderName(targetid),
    pData[targetid][pHeight], 
    pData[targetid][pWeight],
    GetPlayerJobName(targetid), 
    GetPlayerFactionName(targetid), GetPlayerFactionRankName(targetid), 
    "N/A", "N/A",
    FormatRupiah(pData[targetid][pMoney]), 
    FormatRupiah(pData[targetid][pBankMoney]), 
    pData[targetid][pHealth], 
    pData[targetid][pArmour],
    pData[targetid][pHunger],
    pData[targetid][pThirst], 
    pData[targetid][pStress],
    0, 
    pData[targetid][pLevel], GetLevelName(pData[targetid][pLevel], pData[playerid][pSMaster]), 
    pData[targetid][pPlaytime] / 3600, (pData[targetid][pPlaytime] % 3600) / 60, pData[targetid][pPlaytime] % 60,
    GetPlayerAdminRankName(targetid),
    (pData[targetid][pGuardian]) ? (""F_COLOR_DARKGREEN"Yes"F_COLOR_WHITE"") : (""F_COLOR_DARKRED"No"F_COLOR_WHITE""), 
    ReturnDayTimelapse(gettime(), pData[targetid][pGuardianExpiry], ""F_COLOR_DARKRED"Expired"),
    GetPlayerVIPLevelName(targetid),
    ReturnDayTimelapse(gettime(), pData[targetid][pVIPExpiry], ""F_COLOR_DARKRED"Expired"),
    0, 0,
    pData[targetid][pSkin],
    pData[targetid][pVirtualWorld],
    pData[targetid][pInterior],
    0,
    0,
    0,
    0,
    pData[targetid][pLastOnlineDate],
    pData[targetid][pRegisterDate]);
    Dialog_Show(playerid, "PlayerStats", DIALOG_STYLE_TABLIST_HEADERS, str, str2, "Tutup", "");
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

stock IsNumericEx(const string[]) 
{
    for (new i = 0, j = strlen(string); i < j; i++)
    {
        if (string[i] > '9' || string[i] < '0') return 0;
    }
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
    new aQuery[256];

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
    
    pData[playerid][pSkin] = GetPlayerSkin(playerid);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_skin` = %d, ", query, pData[playerid][pSkin]);

    mysql_format(g_SQL, query, sizeof(query), "%s`char_dob` = '%e', ", query, pData[playerid][pDOB]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_origin` = %d, ", query, pData[playerid][pOrigin]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_gender` = %d, ", query, pData[playerid][pGender]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_weight` = %d, ", query, pData[playerid][pWeight]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_height` = %d, ", query, pData[playerid][pHeight]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_domicile` = %d, ", query, pData[playerid][pDomicile]);
    
    pData[playerid][pVirtualWorld] = GetPlayerVirtualWorld(playerid);
    pData[playerid][pInterior] = GetPlayerInterior(playerid);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_virtual_world` = %d, ", query, pData[playerid][pVirtualWorld]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_interior` = %d, ", query, pData[playerid][pInterior]);

    mysql_format(g_SQL, query, sizeof(query), "%s`char_job` = %d, ", query, pData[playerid][pJob]);

    mysql_format(g_SQL, query, sizeof(query), "%s`char_faction` = %d, ", query, pData[playerid][pFaction]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_faction_rank` = %d, ", query, pData[playerid][pFactionRank]);
    
    mysql_format(g_SQL, query, sizeof(query), "%s`char_family` = %d, ", query, pData[playerid][pFamily]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_family_rank` = %d, ", query, pData[playerid][pFamilyRank]);

    mysql_format(g_SQL, query, sizeof(query), "%s`char_injured` = %d, ", query, pData[playerid][pInjured]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_injury_time` = %d, ", query, pData[playerid][pInjuryTime]);
    
    mysql_format(g_SQL, query, sizeof(query), "%s`char_hunger` = %.2f, ", query, pData[playerid][pHunger]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_thirst` = %.2f, ", query, pData[playerid][pThirst]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_stress` = %.2f, ", query, pData[playerid][pStress]);
    
    mysql_format(g_SQL, query, sizeof(query), "%s`char_playtime` = %d, ", query, pData[playerid][pPlaytime]);

    mysql_format(g_SQL, query, sizeof(query), "%s`char_vip` = %d, ", query, pData[playerid][pVIP]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_vip_expiry` = %d, ", query, pData[playerid][pVIPExpiry]);
    
    mysql_format(g_SQL, query, sizeof(query), "%s`char_guardian` = %d, ", query, pData[playerid][pGuardian]);
    mysql_format(g_SQL, query, sizeof(query), "%s`char_guardian_expiry` = %d, ", query, pData[playerid][pGuardianExpiry]);
    
    mysql_format(g_SQL, query, sizeof(query), "%s`char_server_master` = %d ", query, pData[playerid][pSMaster]);

    mysql_format(g_SQL, query, sizeof(query), "%sWHERE `char_id` = %d", query, pData[playerid][pID]);
    mysql_tquery(g_SQL, query);

    mysql_format(g_SQL, aQuery, sizeof(aQuery), "UPDATE `player_accounts` SET `account_last_online` = CURRENT_TIMESTAMP WHERE `account_id` = %d", pData[playerid][pAccountID]);
    mysql_tquery(g_SQL, aQuery);
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

    // OOC Jail Variables Reset
    OJailData[playerid][IsJailed] = false;
    OJailData[playerid][JailTime] = -1;
    OJailData[playerid][JailFined] = 0;

    OJailData[playerid][JailIssuer][0] = EOS;
    OJailData[playerid][JailReason][0] = EOS;

    // Session Variables
    pData[playerid][pID] = 0;
    pData[playerid][pAccountID] = 0;

    pData[playerid][pVersion][0] = EOS;

    pData[playerid][pSpawned] = false;
    pData[playerid][pLoggedIn] = false;

    pData[playerid][pAccountRegistDate][0] = EOS;
    pData[playerid][pAccountLastOnlineDate][0] = EOS;
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

    pData[playerid][pVirtualWorld] = 0;
    pData[playerid][pInterior] = 0;

    pData[playerid][pJob] = 0;

    pData[playerid][pFaction] = 0;
    pData[playerid][pFactionRank] = 0;

    pData[playerid][pFamily] = -1;
    pData[playerid][pFamilyRank] = 0;

    pData[playerid][pInjured] = false;
    pData[playerid][pInjuryTime] = 0;

    pData[playerid][pHunger] = 0.0;
    pData[playerid][pThirst] = 0.0;
    pData[playerid][pStress] = 0.0;

    pData[playerid][pHungerTime] = 0;
    pData[playerid][pThirstTime] = 0;
    pData[playerid][pStressTime] = 0;

    pData[playerid][pInjuryWarn] = 0;

    pData[playerid][pPlaytime] = 0;

    pData[playerid][pVIP] = 0;
    pData[playerid][pVIPExpiry] = -1;

    pData[playerid][pGuardian] = false;
    pData[playerid][pGuardianExpiry] = -1;

    pData[playerid][pSMaster] = false;

    pData[playerid][pLevel] = 0;
    pData[playerid][pDrunkLevel] = 0;

    pData[playerid][pInvTotalWeight] = 0; 

    pData[playerid][InRelaxingArea] = -1;

    g_BHOP[playerid] = 0;

    //Textdraw State Variable Reset
    TDInfo[playerid][HBETDShown] = false;
    TDInfo[playerid][InjuryTDShown] = false;
    TDInfo[playerid][DyingTDShown] = false;
    TDInfo[playerid][InvTDShown] = false;

    g_Aduty[playerid] = false;
    return 1;
}

GetVehicleModelByName(const name[])
{
	if(IsNumericEx(name) && (strval(name) >= 400 && strval(name) <= 611))
		return strval(name);

	for (new i = 0; i < sizeof(g_VehicleNames); i ++)
	{
		if(strfind(g_VehicleNames[i], name, true) != -1)
		{
			return i + 400;
		}
	}
	return 0;
}

/*
stock FormatRupiah(money, dest[], size = sizeof(dest))
{
    new bool:isNegative = (money < 0);

    if(isNegative)
        money = -money;

    new integer = money / 100;
    new decimal = money % 100;

    format(dest, size, "%d", integer);

    new len = strlen(dest);
    for(new i = len - 3; i > 0; i -= 3)
    {
        strins(dest, ".", i, size);
    }

    format(dest, size, "%sRp%s,%02d", isNegative ? "-" : "", dest, decimal);

    return dest;
}
*/

stock FormatRupiah(money)
{
    new bool:isNegative = (money < 0);
    new frmtmny[24];

    if(isNegative)
        money = -money;

    new integer = money / 100;
    new decimal = money % 100;

    format(frmtmny, sizeof(frmtmny), "%d", integer);

    new len = strlen(frmtmny);
    for(new i = len - 3; i > 0; i -= 3)
    {
        strins(frmtmny, ".", i, sizeof(frmtmny));
    }

    format(frmtmny, sizeof(frmtmny), "%sRp%s,%02d", isNegative ? "-" : "", frmtmny, decimal);

    return frmtmny;
}

stock IsRupiahFormat(const rpfrmt[])
{
    new start = 0;
    new len = strlen(rpfrmt);

    if(!len)
        return 0;

    // Prefix Rp opsional
    if(len >= 2 && rpfrmt[0] == 'R'  && rpfrmt[1] == 'p')
    {
        start = 2;

        // Izinkan tepat satu spasi setelah Rp
        if(rpfrmt[start] == ' ')
            start++;

        if(start >= len)
            return 0;
    }

    new commaPos = -1;

    // Cari koma dan validasi karakter
    for(new i = start; i < len; i++)
    {
        switch(rpfrmt[i])
        {
            case ',':
            {
                if(commaPos != -1)
                    return 0;

                commaPos = i;
            }

            case '.':
            {
            }

            default:
            {
                if(rpfrmt[i] < '0' || rpfrmt[i] > '9')
                    return 0;
            }
        }
    }

    new intEnd = (commaPos == -1) ? len : commaPos;

    // Tidak boleh kosong
    if(intEnd <= start)
        return 0;

    // Tidak boleh leading zero kecuali 0 atau 0,xx
    if(rpfrmt[start] == '0' && intEnd - start > 1)
        return 0;

    // Validasi bagian integer
    new bool:hasDot;

    for(new i = start; i < intEnd; i++)
    {
        if(rpfrmt[i] == '.')
        {
            hasDot = true;
            break;
        }
    }

    if(hasDot)
    {
        new digitCount;

        for(new i = intEnd - 1; i >= start; i--)
        {
            if(rpfrmt[i] >= '0' && rpfrmt[i] <= '9')
            {
                digitCount++;
                continue;
            }

            if(rpfrmt[i] != '.')
                return 0;

            if(digitCount != 3)
                return 0;

            digitCount = 0;
        }

        if(digitCount < 1 || digitCount > 3)
            return 0;
    }

    // Validasi desimal
    if(commaPos != -1)
    {
        new decimals = len - commaPos - 1;

        if(decimals < 1 || decimals > 2)
            return 0;
    }

    return 1;
}

stock ReturnRupiahToInteger(const rpfrmt[])
{
    new start = 0;
    new len = strlen(rpfrmt);

    if((rpfrmt[0] == 'R' || rpfrmt[0] == 'r') && (rpfrmt[1] == 'P' || rpfrmt[1] == 'p'))
    {
        start = 2;

        if(rpfrmt[start] == ' ')
            start++;
    }

    new integerPart[32];
    new decimalPart[3] = "00";

    new intIdx;
    new commaPos = strfind(rpfrmt, ",");

    if(commaPos == -1)
        commaPos = len;

    for(new i = start; i < commaPos; i++)
    {
        if(rpfrmt[i] == '.')
            continue;

        integerPart[intIdx++] = rpfrmt[i];
    }
    integerPart[intIdx] = EOS;

    if(commaPos < len)
    {
        new decLen = len - commaPos - 1;

        switch(decLen)
        {
            case 1:
            {
                decimalPart[0] = rpfrmt[commaPos + 1];
                decimalPart[1] = '0';
            }
            default:
            {
                decimalPart[0] = rpfrmt[commaPos + 1];
                decimalPart[1] = rpfrmt[commaPos + 2];
            }
        }
    }

    return strval(integerPart) * 100 + strval(decimalPart);
}

stock ReturnTimelapse(start, till, const def[] = "Baru Saja")
{
    new ret[64];
    new second = till - start;

    enum e_durationData
    {
        edS,
        edL[10],
    }

    if(second <= 0)
    {
        strcopy(ret, def);
        return ret;
    }

    static durations[][e_durationData] =
    {
        {86400, "hari"},
        {3600, "jam"},
        {60, "menit"},
        {1, "detik"}
    };

    for (new i = 0; i < sizeof(durations); i++)
    {
        if (second > durations[i][edS])
        {
            new cur = floatround(second / durations[i][edS], floatround_floor);
            format(ret, 64, "%s %d %s", ret, cur, durations[i][edL]);
            second = second % durations[i][edS];
        }
    }
    return ret;
}

stock ReturnDayTimelapse(start, till, const def[] = "0.00 Hari")
{
    new ret[64];
    new second = till - start;

    if(second <= 0)
    {
        strcopy(ret, def);
        return ret;
    }

    new Float:cur = float(second) / 86400.0;
    format(ret, 64, "%.2f Hari", cur);
    return ret;
}

stock GetLevelName(level, smaster = false)
{
    new names[32];
    switch(level)
    {
        case 1 .. 9:
        {
            strcopy(names, ""F_COLOR_AQUA"Starter"F_COLOR_WHITE"");
        }

        case 10 .. 19:
        {
            strcopy(names, ""F_COLOR_LIGHTCYAN"Novice"F_COLOR_WHITE"");
        }

        case 20 .. 29:
        {
            strcopy(names, ""F_COLOR_LIGHTGREEN"Apprentice"F_COLOR_WHITE"");
        }

        case 30 .. 39:
        {
            strcopy(names, ""F_COLOR_LIGHTLIME"Senior"F_COLOR_WHITE"");
        }

        case 40 .. 49:
        {
            strcopy(names, ""F_COLOR_LIGHTORANGE"Adept"F_COLOR_WHITE"");
        }

        case 50 .. 59:
        {
            strcopy(names, ""F_COLOR_DARKORANGE"Expert"F_COLOR_WHITE"");
        }

        case 60 .. 69:
        {
            strcopy(names, ""F_COLOR_DARKBROWN"Veteran"F_COLOR_WHITE"");
        }

        case 70 .. 79:
        {
            strcopy(names, ""F_COLOR_DARKYELLOW"Legend"F_COLOR_WHITE"");
        }

        case 80 .. 99:
        {
            strcopy(names, ""F_COLOR_GOLD"Celestial"F_COLOR_WHITE"");
        }

        case 100:
        {
            if(smaster)
            {
                strcopy(names, ""F_COLOR_DARKBLUE"Server Master"F_COLOR_WHITE"");
            }
            else
            {
                strcopy(names, ""F_COLOR_DARKRED"Eternal"F_COLOR_WHITE"");
            }
        }

        default:
        {
            strcopy(names, ""F_COLOR_LIGHTGREY"Nobody"F_COLOR_WHITE"");
        }
    }

    return names;
}

stock GetPlayerJobName(playerid)
{
    new str[24];
    strcopy(str, g_JobNames[pData[playerid][pJob]]);
    return str;
}

stock GetPlayerVIPLevelName(playerid)
{
    new str[32];
    strcopy(str, g_VIPRankNames[pData[playerid][pVIP]]);
    return str;
}

stock GetPlayerAdminRankName(playerid)
{
    new str[24];
    strcopy(str, g_AdminRankNames[pData[playerid][pAdminLevel]]);
    return str;
}

stock GetPlayerFactionName(playerid)
{
    new str[24];
    strcopy(str, g_FactionNames[pData[playerid][pFaction]]);
    return str;
}

stock GetPlayerFactionRankName(playerid)
{
    new str[24];
    switch(pData[playerid][pFaction])
    {
        case 1:
        {
            strcopy(str, g_PoliceRankNames[pData[playerid][pFactionRank]]);
        }

        default:
        {
            strcopy(str, "N/A");
        }
    }
    return str;
}

stock GetPlayerOriginName(playerid)
{
    new str[64];
    strcopy(str, g_CountryNames[pData[playerid][pOrigin]]);
    return str;
}

stock GetPlayerGenderName(playerid)
{
    new str[16];
    strcopy(str, g_GenderNames[pData[playerid][pGender]]);
    return str;
}

stock debugmsg(playerid, const msg[])
{
    if(playerid != INVALID_PLAYER_ID && IsPlayerConnected(playerid))
        if(pData[playerid][pAdminLevel] > 0)
            SendClientMessage(playerid, 0xFFFFFFFF, ""F_COLOR_DARKRED"[DEBUG]"F_COLOR_WHITE" %s", msg);
    printf("[DEBUG] %s", msg);
    return 1;
}

stock GetWeaponModel(WEAPON:weaponid)
{
    switch(_:weaponid)
    {
        case 1:                     return 331;
        case 2..8:                  return _:weaponid + 331;
        case 9:                     return 341;
        case 10..15:                return _:weaponid + 311;
        case 16..18:                return _:weaponid + 326;
        case 22..29, 33..45:        return _:weaponid + 324;
        case 30..31:                return _:weaponid + 325;
        case 32:                    return 372;
        case 46:                    return 371;
        default:                    return 0;
    }
}

stock IsFirearmWeapon(WEAPON:weaponid)
{
    switch(_:weaponid)
    {
        case 22..34: return true;
    }
    return false;
}

stock bool:IsPlayerFalling(playerid)
{
    new
        Float:vecX,
        Float:vecY,
        Float:vecZ,
        anim = GetPlayerAnimationIndex(playerid);

    GetPlayerVelocity(playerid, vecX, vecY, vecZ);

    // Parachute
    if(vecZ <= -0.03 && vecZ > -0.10)
    {
        switch(anim)
        {
            case 963..966, 971..972, 976..979: return true;
        }
    } // Non-Parachute
    else if(vecZ <= -0.10) 
    {
        switch(anim)
        {
            case 958..959, 961..966, 971..972, 976..979, 1128, 1130..1132, 1134: return true;
        }
    }

    return false;
}

stock bool:IsValidWeapon(WEAPON:weaponid)
{
    return ((_:weaponid >= 1 && _:weaponid <= 18) || (_:weaponid >= 22 && _:weaponid < 46));
}

stock SetPlayerHealthEx(playerid, Float:health)
{
    pData[playerid][pHealth] = health;
    return SetPlayerHealth(playerid, health);
}

stock SetPlayerArmourEx(playerid, Float:armour)
{
    pData[playerid][pArmour] = armour;
    return SetPlayerArmour(playerid, armour);
}

stock SetPlayerSkinEx(playerid, skinid)
{
    pData[playerid][pSkin] = skinid;
    return SetPlayerSkin(playerid, skinid);
}

stock SetPlayerDrunkLevelEx(playerid, drnklvl)
{
    pData[playerid][pDrunkLevel] = drnklvl;
    return SetPlayerDrunkLevel(playerid, drnklvl);
}

stock GivePlayerMoneyEx(playerid, money)
{
    pData[playerid][pMoney] += money;
    return GivePlayerMoney(playerid, money);
}

stock SetPlayerNameEx(playerid, const name[])
{
    strcopy(pData[playerid][pName], name);
    return SetPlayerName(playerid, name);
}

stock SetPlayerInteriorEx(playerid, interiorid)
{
    pData[playerid][pInterior] = interiorid;
    return SetPlayerInterior(playerid, interiorid);
}

stock SetPlayerVirtualWorldEx(playerid, virtualWorld)
{
    pData[playerid][pInterior] = virtualWorld;
    return SetPlayerVirtualWorld(playerid, virtualWorld);
}

stock KickEx(playerid, delay = 500)
{
    return SetTimerEx("__KickDelay", delay, false, "d", playerid);
}