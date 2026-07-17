#include <easyDialog>

Dialog:CharacterList(playerid, response, listitem, inputtext[])
{
    if(!response) return KickEx(playerid);

    if(listitem < 0 || listitem >= MAX_CHARACTERS)
    {
        SendClientMessage(playerid, -1, "Invalid character selection. Please try again.");
        ShowCharacterList(playerid);
        return 1;
    }

    if(isnull(PlayerChar[playerid][listitem][CharName]))
        return Dialog_Show(playerid, "CreateCharName", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Silahkan masukkan nama karakter Anda.", "Input", "Kembali");
    
    strcopy(pData[playerid][pName], PlayerChar[playerid][listitem][CharName]);
    pData[playerid][pID] = PlayerChar[playerid][listitem][CharID];
    pData[playerid][pLevel] = PlayerChar[playerid][listitem][CharLevel];

    new query[256];
    mysql_format(SQL, query, sizeof(query), "SELECT * FROM `player_characters` WHERE `char_id` = %d LIMIT 1", PlayerChar[playerid][listitem][CharID]);
    mysql_pquery(SQL, query, "LoadCharacterData", "d", playerid);
    return 1;
}

Dialog:CreateCharName(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        tempCharName[playerid][0] = EOS;
        ShowCharacterList(playerid);
        return 1;
    }

    if(strlen(inputtext) < 3 || strlen(inputtext) > MAX_PLAYER_NAME)
        return Dialog_Show(playerid, "CreateCharName", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Nama karakter harus memiliki setidaknya 3 sampai dengan 24 karakter.\nContoh: Ucok_Soelaiman, Herlambang_Kurniawan\nSilahkan masukkan nama karakter Anda:", "Input", "Kembali");
    
    if(!IsRoleplayName(inputtext))
        return Dialog_Show(playerid, "CreateCharName", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Nama karakter yang anda masukkan tidak valid. Silahkan gunakan format Firstname_Lastname.\nContoh: Ucok_Soelaiman, Herlambang_Kurniawan\nSilahkan masukkan nama karakter Anda:", "Input", "Kembali");

    new query[256];
    mysql_format(SQL, query, sizeof(query), "SELECT 1 FROM `player_characters` WHERE `char_name` = '%e'", inputtext);
    mysql_pquery(SQL, query, "OnInsertCharacterName", "ds", playerid, inputtext);
    return 1;
}

// nama, tgl lahir, tinggi badan, berat badan, jenis kelamin, asal negara
Dialog:CreateCharDOB(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        tempCharDOB[playerid][0] = EOS;
        Dialog_Show(playerid, "CreateCharName", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Silahkan masukkan nama karakter anda.", "Input", "Kembali");
        return 1;
    }

    if(IsNull(inputtext) || !IsValidDOB(inputtext))
        return Dialog_Show(playerid, "CreateCharDOB", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Format tanggal lahir yang anda masukkan tidak valid.\nSilahkan masukkan tanggal lahir karakter Anda dengan format DD-MM-YYYY.\nContoh: 03-08-2001", "Input", "Kembali");
    
    strcopy(tempCharDOB[playerid], inputtext);

    Dialog_Show(playerid, "CreateCharWeight", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Silahkan masukkan berat badan karakter Anda (kg)", "Input", "Kembali");
    return 1;
}

Dialog:CreateCharWeight(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        tempCharWeight[playerid] = 0;
        Dialog_Show(playerid, "CreateCharDOB", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Silahkan masukkan tanggan lahir karakter Anda (DD-MM-YYYY)", "Input", "Kembali");
        return 1;
    }

    if(!IsNumericEx(inputtext))
        return Dialog_Show(playerid, "CreateCharWeight", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Berat badan tidak valid. Berat badan hanya dapat diisi dengan angka dalam satuan kilogram.", "Input", "Kembali");
    
    new weight = strval(inputtext);

    if(weight < 40 || weight > 110)
        return Dialog_Show(playerid, "CreateCharWeight", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Berat badan tidak valid. Berat badan minimal adalah 40 hingga 110 kilogram.", "Input", "Kembali");
    
    tempCharWeight[playerid] = weight;

    Dialog_Show(playerid, "CreateCharHeight", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Create Character", "Silahkan masukkan tinggi badan karakter Anda (cm)", "Input", "Kembali");
    return 1;
}

Dialog:CreateCharHeight(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        tempCharHeight[playerid] = 0;
        Dialog_Show(playerid, "CreateCharWeight", DIALOG_STYLE_INPUT, "Vantara Roleplay - Create Character", "Please enter your character's weight (kg)", "Input", "Back");
        return 1;
    }

    if(!IsNumericEx(inputtext))
        return Dialog_Show(playerid, "CreateCharHeight", DIALOG_STYLE_INPUT, "Vantara Roleplay - Create Character", "Invalid height. Please enter a numeric value in centimeters.", "Input", "Back");

    new height = strval(inputtext);

    if(height < 150 || height > 198)
        return Dialog_Show(playerid, "CreateCharHeight", DIALOG_STYLE_INPUT, "Vantara Roleplay - Create Character", "Invalid height. Please enter a height between 150 and 198 centimeters.", "Input", "Back");

    tempCharHeight[playerid] = height;

    Dialog_Show(playerid, "CreateCharGender", DIALOG_STYLE_LIST, "Vantara Roleplay - Create Character", "Male\nFemale", "Select", "Back");
    return 1;
}

Dialog:CreateCharGender(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        tempCharGender[playerid] = -1;
        Dialog_Show(playerid, "CreateCharHeight", DIALOG_STYLE_INPUT, "Vantara Roleplay - Create Character", "Please enter your character's height (cm)", "Input", "Back");
        return 1;
    }

    tempCharGender[playerid] = listitem + 1;

    static str[3528 + 1];
    str[0] = EOS;
    for(new i = 0; i < sizeof(CountryNames); i++)
    {
        format(str, sizeof(str), "%s%s\n", str, CountryNames[i]);
    }

    Dialog_Show(playerid, "CreateCharOrigin", DIALOG_STYLE_LIST, "Vantara Roleplay - Create Character", str, "Select", "Back");
    return 1;
}

Dialog:CreateCharOrigin(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        tempCharOrigin[playerid] = -1;
        Dialog_Show(playerid, "CreateCharGender", DIALOG_STYLE_LIST, "Vantara Roleplay - Create Character", "Male\nFemale", "Select", "Back");
        return 1;
    }

    if(listitem < 0 || listitem >= sizeof(CountryNames))
    {
        static str[3528 + 1];
        for(new i = 0; i < sizeof(CountryNames); i++)
        {
            format(str, sizeof(str), "%s%s\n", str, CountryNames[i]);
        }
        Dialog_Show(playerid, "CreateCharOrigin", DIALOG_STYLE_LIST, "Vantara Roleplay - Create Character", str, "Select", "Back");
        return 1;
    }

    tempCharOrigin[playerid] = listitem;

    Dialog_Show(playerid, "CreateCharDomicile", DIALOG_STYLE_TABLIST_HEADERS, "Vantara Roleplay - Create Character", "Select your character domicile\nLos Santos\nSan Fierro\nLas Venturas", "Select", "Back");
    return 1;
}

Dialog:CreateCharDomicile(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        tempCharDomicile[playerid] = -1;
        static str[3528 + 1];
        str[0] = EOS;
        for(new i = 0; i < sizeof(CountryNames); i++)
        {
            format(str, sizeof(str), "%s%s\n", str, CountryNames[i]);
        }

        Dialog_Show(playerid, "CreateCharOrigin", DIALOG_STYLE_LIST, "Vantara Roleplay - Create Character", str, "Select", "Back");
        return 1;
    }

    if(listitem < 0  || listitem > 2)
    {
        SendClientMessage(playerid, -1, "Invalid domicile, try again!");
        Dialog_Show(playerid, "CreateCharDomicile", DIALOG_STYLE_TABLIST_HEADERS, "Vantara Roleplay - Create Character", "Select your character domicile\nLos Santos\nSan Fierro\nLas Venturas", "Select", "Back");
        return 1;
    }

    tempCharDomicile[playerid] = listitem;
    new randSkin = 250;

    switch(tempCharGender[playerid])
    {
        case 1:
        {
            randSkin = rand_MaleSkin[random(sizeof(rand_MaleSkin))];
        }

        case 2:
        {
            randSkin = rand_FemaleSkin[random(sizeof(rand_FemaleSkin))];
        }
    }

    static query[2048];
    mysql_format(SQL, query, sizeof(query),
        "INSERT INTO `player_characters` \
        (`char_id`, `char_account_id`, `char_ucp`, `char_name`, `char_register_date`, `char_last_online`, \
        `char_admin_name`, `char_skin`, `char_dob`, `char_origin`, `char_gender`, `char_weight`, `char_height`, `char_domicile`) \
        VALUES \
        (NULL, %d, '%e', '%e', CURRENT_TIMESTAMP, CURRENT_TIMESTAMP, \
        '%e', %d, '%e', %d, %d, %d, %d, %d)",
        pData[playerid][pAccountID],
        pData[playerid][pUCP],
        tempCharName[playerid],
        pData[playerid][pUCP],
        randSkin,
        tempCharDOB[playerid],
        tempCharOrigin[playerid],
        tempCharGender[playerid],
        tempCharWeight[playerid],
        tempCharHeight[playerid],
        tempCharDomicile[playerid]);
    mysql_tquery(SQL, query, "OnCharacterCreated", "d", playerid);
    return 1;
}

Dialog:LSSpawn(playerid, response, listitem, inputtext[])
{
    if(!response)
        return Dialog_Show(playerid, "LSSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "Los Santos International Airport\nOcean Docks", "Select", "");
    
    new const Float:LsCoordSpawn[][] = {
        {1681.9485, -2245.8613, -2.6819, 178.6635},
        {1680.6769, -2242.9900, 13.5461, 180.0738},
        {2768.7446, -2433.5161, 13.6850, 89.6876}
    };

    switch(listitem)
    {
        case 0: // Los Santos International Airport
        {
            pData[playerid][pSpawned] = true;
            new rand = random(2);

            SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], LsCoordSpawn[rand][0], LsCoordSpawn[rand][1], LsCoordSpawn[rand][2], LsCoordSpawn[rand][3]);
            TogglePlayerSpectating(playerid, false);
            SpawnPlayer(playerid);
            SetCameraBehindPlayer(playerid);

            CallLocalFunction("PeriodCharacterSpawned", "d", playerid);
        }

        case 1: // ocean docks
        {
            pData[playerid][pSpawned] = true;

            SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], LsCoordSpawn[2][0], LsCoordSpawn[2][1], LsCoordSpawn[2][2], LsCoordSpawn[2][3]);
            TogglePlayerSpectating(playerid, false);
            SpawnPlayer(playerid);
            SetCameraBehindPlayer(playerid);

            CallLocalFunction("PeriodCharacterSpawned", "d", playerid);
        }

        case 2: // last exit
        {
            if(pData[playerid][pLastExit] == 0 || pData[playerid][pLastExit] > gettime())
                return ShowSpawnSelection(playerid);

            pData[playerid][pSpawned] = true;
            
            SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA]);
            TogglePlayerSpectating(playerid, false);
            SpawnPlayer(playerid);
            SetCameraBehindPlayer(playerid);

            CallLocalFunction("PeriodCharacterSpawned", "d", playerid);
        }

        default:
        {
            return Dialog_Show(playerid, "LSSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "Los Santos International Airport\nOcean Docks", "Select", "");
        }
    }
    return 1;
}

Dialog:SFSpawn(playerid, response, listitem, inputtext[])
{
    if(!response)
        return Dialog_Show(playerid, "SFSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "San Fierro Airport\nEsplande North", "Select", "");
    
    new const Float:SfCoordSpawn[][] = {
        {-1420.0392, -293.3337, 14.1484, 141.0071},
        {-1729.0839, 1460.8698, 7.1875, 90.4771}
    };

    switch(listitem)
    {
        case 0: // San Fierro Airport
        {
            pData[playerid][pSpawned] = true;

            SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], SfCoordSpawn[0][0], SfCoordSpawn[0][1], SfCoordSpawn[0][2], SfCoordSpawn[0][3]);
            TogglePlayerSpectating(playerid, false);
            SpawnPlayer(playerid);
            SetCameraBehindPlayer(playerid);

            CallLocalFunction("PeriodCharacterSpawned", "d", playerid);
        }

        case 1: // Esplande North
        {
            pData[playerid][pSpawned] = true;

            SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], SfCoordSpawn[1][0], SfCoordSpawn[1][1], SfCoordSpawn[1][2], SfCoordSpawn[1][3]);
            TogglePlayerSpectating(playerid, false);
            SpawnPlayer(playerid);
            SetCameraBehindPlayer(playerid);

            CallLocalFunction("PeriodCharacterSpawned", "d", playerid);
        }

        case 2: // Last Exit
        {
            if(pData[playerid][pLastExit] == 0 || pData[playerid][pLastExit] > gettime())
                return ShowSpawnSelection(playerid);

            pData[playerid][pSpawned] = true;
            
            SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA]);
            TogglePlayerSpectating(playerid, false);
            SpawnPlayer(playerid);
            SetCameraBehindPlayer(playerid);

            CallLocalFunction("PeriodCharacterSpawned", "d", playerid);
        }

        default:
        {
            return Dialog_Show(playerid, "SFSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "San Fierro Airport\nEsplande North", "Select", "");
        }
    }
    return 1;
}

Dialog:LVSpawn(playerid, response, listitem, inputtext[])
{
    if(!response)
        return Dialog_Show(playerid, "LVSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "Las Venturas Airport\nLinden Station", "Select", "");

    new const Float:LvCoordSpawn[][] = {
        {1674.3302, 1447.8229, 10.7907, 268.8487},
        {2840.3289, 1292.4557, 11.3906, 90.2542}
    };

    switch(listitem)
    {
        case 0: // Las Venturas Airport
        {
            pData[playerid][pSpawned] = true;

            SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], LvCoordSpawn[0][0], LvCoordSpawn[0][1], LvCoordSpawn[0][2], LvCoordSpawn[0][3]);
            TogglePlayerSpectating(playerid, false);
            SpawnPlayer(playerid);
            SetCameraBehindPlayer(playerid);

            CallLocalFunction("PeriodCharacterSpawned", "d", playerid);
        }

        case 1: // Linden Station
        {
            pData[playerid][pSpawned] = true;

            SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], LvCoordSpawn[1][0], LvCoordSpawn[1][1], LvCoordSpawn[1][2], LvCoordSpawn[1][3]);
            TogglePlayerSpectating(playerid, false);
            SpawnPlayer(playerid);
            SetCameraBehindPlayer(playerid);

            CallLocalFunction("PeriodCharacterSpawned", "d", playerid);
        }

        case 2: // Last Exit
        {
            if(pData[playerid][pLastExit] == 0 || pData[playerid][pLastExit] > gettime())
                return ShowSpawnSelection(playerid);
            
            pData[playerid][pSpawned] = true;
            
            SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA]);
            TogglePlayerSpectating(playerid, false);
            SpawnPlayer(playerid);
            SetCameraBehindPlayer(playerid);

            CallLocalFunction("PeriodCharacterSpawned", "d", playerid);
        }

        default:
        {
            return Dialog_Show(playerid, "LVSpawn", DIALOG_STYLE_LIST, "Vantara Roleplay - Spawn Selection", "Las Venturas Airport\nLinden Station", "Select", "");
        }
    }
    return 1;
}

