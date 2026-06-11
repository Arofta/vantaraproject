function:LoadCharacter(playerid)
{
    for(new i = 0; i < MAX_CHARACTERS; i++)
    {
        PlayerChar[playerid][i][CharID] = 0;
        PlayerChar[playerid][i][CharName][0] = EOS;
        PlayerChar[playerid][i][CharMoney] = 0;
        PlayerChar[playerid][i][CharBankMoney] = 0;
        PlayerChar[playerid][i][CharLevel] = 0;
    }
    for(new i = 0; i < cache_num_rows(); i++)
    {
        cache_get_value_name_int(i, "char_id", PlayerChar[playerid][i][CharID]);
        cache_get_value_name(i, "char_name", PlayerChar[playerid][i][CharName]);
        cache_get_value_name_int(i, "char_money", PlayerChar[playerid][i][CharMoney]);
        cache_get_value_name_int(i, "char_bank_money", PlayerChar[playerid][i][CharBankMoney]);
        cache_get_value_name_int(i, "char_level", PlayerChar[playerid][i][CharLevel]);
    }

    ShowCharacterList(playerid);
    return 1;
}

function:LoadCharacterData(playerid)
{
    if(!cache_num_rows())
    {
        Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, "Vantara Roleplay - Character not found", "Something went wrong, try later!", "Quit", "");
        Kick(playerid);
        return 1;
    }
    else
    { // char_id	char_account_id	char_ucp	char_name	char_register_date	char_last_online	char_pos_x	char_pos_y	char_pos_z	char_pos_a	char_health	char_armour	char_level	char_money	char_bank_money	char_skin	char_dob	char_origin	char_gender	char_weight	char_height	char_hunger	char_thirst	char_stress
        cache_get_value_name(0, "char_register_date", pData[playerid][pRegisterDate]);
        cache_get_value_name(0, "char_last_online", pData[playerid][pLastOnlineDate]);

        cache_get_value_name_int(0, "char_last_exit", pData[playerid][pLastExit]);

        cache_get_value_name_float(0, "char_pos_x", pData[playerid][pPosX]);
        cache_get_value_name_float(0, "char_pos_y", pData[playerid][pPosY]);
        cache_get_value_name_float(0, "char_pos_z", pData[playerid][pPosZ]);
        cache_get_value_name_float(0, "char_pos_a", pData[playerid][pPosA]);

        cache_get_value_name_float(0, "char_health", pData[playerid][pHealth]);
        cache_get_value_name_float(0, "char_armour", pData[playerid][pArmour]);

        //cache_get_value_name_int(0, "char_level", pData[playerid][pLevel]); // sudah dapet char level sejak awal select character
        cache_get_value_name_int(0, "char_money", pData[playerid][pMoney]); // sudah dapet money sejak awal select character, tapi untuk jaga jaga jadi di ambil lagi
        cache_get_value_name_int(0, "char_bank_money", pData[playerid][pBankMoney]); // sama kaya money
        cache_get_value_name_int(0, "char_skin", pData[playerid][pSkin]);

        cache_get_value_name(0, "char_dob", pData[playerid][pDOB]);
        cache_get_value_name_int(0, "char_origin", pData[playerid][pID]);
        cache_get_value_name_int(0, "char_gender", pData[playerid][pID]);
        cache_get_value_name_int(0, "char_weight", pData[playerid][pID]);
        cache_get_value_name_int(0, "char_height", pData[playerid][pID]);
        cache_get_value_name_int(0, "char_domicile", pData[playerid][pDomicile]);

        cache_get_value_name_float(0, "char_hunger", pData[playerid][pHunger]);
        cache_get_value_name_float(0, "char_thirst", pData[playerid][pThirst]);
        cache_get_value_name_float(0, "char_stress", pData[playerid][pStress]);

        if(gettime() > pData[playerid][pLastExit])
        {
            ShowSpawnSelection(playerid);
        }
        else
        {
            pData[playerid][pSpawned] = true;
            
            SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA]);
            TogglePlayerSpectating(playerid, false);
            SpawnPlayer(playerid);
            SetCameraBehindPlayer(playerid);
        }

        for(new i = 0; i < MAX_CHARACTERS; i++)
        {
            if(isnull(PlayerChar[playerid][i][CharName][0]))
                continue;
            PlayerChar[playerid][i][CharID] = 0;

            PlayerChar[playerid][i][CharName][0] = EOS;

            PlayerChar[playerid][i][CharMoney] = 0;
            PlayerChar[playerid][i][CharBankMoney] = 0;
            PlayerChar[playerid][i][CharLevel] = 0;
        }

        //new query[256];
        return 1;
    }
}

function:OnCharacterCreated(playerid)
{
    tempCharName[playerid][0] = EOS;
    tempCharDOB[playerid][0] = EOS;
    tempCharHeight[playerid] = 0;
    tempCharWeight[playerid] = 0;
    tempCharGender[playerid] = -1;
    tempCharOrigin[playerid] = -1;
    tempCharDomicile[playerid] = -1;

    new query[512];
    mysql_format(g_SQL, query, sizeof(query), "SELECT `char_id`, `char_name`, `char_level`, `char_money`, `char_bank_money` FROM `player_characters` WHERE `char_account_id` = %d LIMIT %d", pData[playerid][pAccountID], MAX_CHARACTERS);
    mysql_pquery(g_SQL, query, "LoadCharacter", "d", playerid);
    return 1;
}
