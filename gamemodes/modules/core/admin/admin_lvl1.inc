YCMD:aduty(playerid, params[], help)
{
    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");
    
    g_Aduty[playerid] = !g_Aduty[playerid];

    foreach(new i : Player)
    {
        if(pData[i][pAdminLevel] > 0)
            SendClientMessage(i, COLOR_LIGHTRED, "AdmCmd: %s telah %s duty admin sebagai %s", pData[playerid][pName], g_Aduty[playerid] ? ("on") : ("off"), pData[playerid][pAdminName]);
    }

    if(g_Aduty[playerid])
    {
        SetPlayerName(playerid, pData[playerid][pAdminName]);
        SetPlayerColor(playerid, 0xFF0000FF);
    }
    else
    {
        SetPlayerName(playerid, pData[playerid][pName]);
        SetPlayerColor(playerid, 0xFFFFFFFF);
    }
    return 1;
}

YCMD:veh(playerid, params[], help)
{
    new
        model[32],
        color1,
        color2;

    if(pData[playerid][pAdminLevel] < 1) 
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");

    if(sscanf(params, "s[32]I(0)I(0)", model, color1, color2))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/veh [model id/name] [color 1] [color 2]");

    if((model[0] = GetVehicleModelByName(model)) == 0) 
        return SendClientMessage(playerid, -1, ""RED"ERROR:Invalid Model ID!");

    new
        Float:x,
        Float:y,
        Float:z,
        Float:a;

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);

    for(new i; i < MAX_ADMIN_VEHICLES; i++)
    {
        if(SInfo[AdminVeh][i] == INVALID_VEHICLE_ID)
        {
            SInfo[AdminVeh][i] = CreateVehicle(model[0], x, y, z, a, color1, color2, 60000, false);
            //SwitchVehicleEngine(SInfo[AdminVeh][i], true);
            //SwitchVehicleDoors(SInfo[AdminVeh][i], false);

            if(GetPlayerInterior(playerid) != 0)
                LinkVehicleToInterior(SInfo[AdminVeh][i], GetPlayerInterior(playerid));

            if(GetPlayerVirtualWorld(playerid) != 0)
                SetVehicleVirtualWorld(SInfo[AdminVeh][i], GetPlayerVirtualWorld(playerid));

            PutPlayerInVehicle(playerid, SInfo[AdminVeh][i], 0);
            SetCameraBehindPlayer(playerid);
            SetVehicleParamsEx(SInfo[AdminVeh][i], 1, 1, 0, 0, 0, 0, 0);
            SetVehicleNumberPlate(SInfo[AdminVeh][i], ""RED"ADMIN");
            break;
        }

        if(i == (MAX_ADMIN_VEHICLES - 1))
            SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Kendaraan Admin sudah mencapai batas maksimum (100), Gunakan '/adveh' untuk menghancurkan semua kendaraan admin");
        
    }
    return 1;
}

YCMD:adveh(playerid, params[], help)
{
    if(pData[playerid][pAdminLevel] < 1) 
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");

    for(new i; i < MAX_ADMIN_VEHICLES; i++)
    {
        DestroyVehicle(SInfo[AdminVeh][i]);
        SInfo[AdminVeh][i] = INVALID_VEHICLE_ID;
    }
    
    foreach(new i : Player)
    {
        if(pData[i][pAdminLevel] > 0)
            SendClientMessage(i, COLOR_LIGHTRED, "AdmCmd: %s telah menghancurkan semua kendaraan admin.", pData[playerid][pAdminName]);
    }
    return 1;
}

YCMD:sethealth(playerid, params[], help)
{
    new 
        targetid,
        Float:health;

    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");

    if(sscanf(params, "dF(100.0)", targetid, health))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/sethealth <playerid> <health>");

    if(!IsPlayerConnected(targetid) || !pData[targetid][pLoggedIn] || !pData[targetid][pSpawned])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut tidak terkoneksi ke server atau belum spawn");

    SetPlayerHealthEx(targetid, health);
    
    foreach(new i : Player)
    {
        if(pData[i][pAdminLevel] > 0)
            SendClientMessage(i, COLOR_LIGHTRED, "AdmCmd: %s telah menetapkan nilai health pemain %s(%d) menjadi %.1f", pData[playerid][pAdminName], pData[targetid][pName], targetid, health);
    }
    SendClientMessage(targetid, COLOR_LIGHTRED, "AdmCmd: %s telah menetapkan nilai health karakter anda menjadi %.1f", pData[playerid][pAdminName], health);
    return 1;
}
YCMD:sethp(playerid, params[], help) = sethealth;

YCMD:setarmour(playerid, params[], help)
{
    new 
        targetid,
        Float:armour;

    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");

    if(sscanf(params, "dF(100.0)", targetid, armour))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/setarmour <playerid> <armour>");

    if(!IsPlayerConnected(targetid) || !pData[targetid][pLoggedIn] || !pData[targetid][pSpawned])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut tidak terkoneksi ke server atau belum spawn");

    SetPlayerArmourEx(targetid, armour);
    
    foreach(new i : Player)
    {
        if(pData[i][pAdminLevel] > 0)
            SendClientMessage(i, COLOR_LIGHTRED, "AdmCmd: %s telah menetapkan nilai armour pemain %s(%d) menjadi %.1f", pData[playerid][pAdminName], pData[targetid][pName], targetid, armour);
    }
    SendClientMessage(targetid, COLOR_LIGHTRED, "AdmCmd: %s telah menetapkan nilai armour karakter anda menjadi %.1f", pData[playerid][pAdminName], armour);
    return 1;
}
YCMD:setam(playerid, params[], help) = setarmour;

YCMD:sethts(playerid, params[], help)
{
    new 
        targetid,
        Float:value;

    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");

    if(sscanf(params, "dF(100.0)", targetid, value))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/sethts <playerid> <value>");

    if(!IsPlayerConnected(targetid) || !pData[targetid][pLoggedIn] || !pData[targetid][pSpawned])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut tidak terkoneksi ke server atau belum spawn");
    
    pData[playerid][pHunger] = value;
    pData[playerid][pThirst] = value;
    
    foreach(new i : Player)
    {
        if(pData[i][pAdminLevel] > 0)
            SendClientMessage(i, COLOR_LIGHTRED, "AdmCmd: %s telah menetapkan nilai HTS pemain %s(%d) menjadi %.1f", pData[playerid][pAdminName], pData[targetid][pName], targetid, value);
    }
    SendClientMessage(targetid, COLOR_LIGHTRED, "AdmCmd: %s telah menetapkan nilai HTS karakter anda menjadi %.1f", pData[playerid][pAdminName], value);
    return 1;
}
YCMD:sethbe(playerid, params[], help) = sethts;

YCMD:setstress(playerid, params[], help)
{
    new 
        targetid,
        Float:value;

    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");

    if(sscanf(params, "dF(0.0)", targetid, value))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/setstress <playerid> <value>");

    if(!IsPlayerConnected(targetid) || !pData[targetid][pLoggedIn] || !pData[targetid][pSpawned])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut tidak terkoneksi ke server atau belum spawn");
    
    pData[playerid][pStress] = value;
    
    foreach(new i : Player)
    {
        if(pData[i][pAdminLevel] > 0)
            SendClientMessage(i, COLOR_LIGHTRED, "AdmCmd: %s telah menetapkan nilai Stress pemain %s(%d) menjadi %.1f", pData[playerid][pAdminName], pData[targetid][pName], targetid, value);
    }
    SendClientMessage(targetid, COLOR_LIGHTRED, "AdmCmd: %s telah menetapkan nilai Stress karakter anda menjadi %.1f", pData[playerid][pAdminName], value);
    return 1;
}

YCMD:arevive(playerid, params[], help)
{
    new targetid = INVALID_PLAYER_ID;

    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");

    if(sscanf(params, "d", targetid))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/arevive <playerid>");

    if(!IsPlayerConnected(targetid) || !pData[targetid][pLoggedIn] || !pData[targetid][pSpawned])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut tidak ada didalam server atau belum spawn.");
    
    if(!pData[targetid][pInjured])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut tidak sedang pingsan.");

    new query[128];

    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `char_injured` = 0, `char_injury_time` = 0 WHERE `char_id` = %d", pData[targetid][pID]);
    mysql_pquery(g_SQL, query);

    pData[targetid][pInjured] = false;
    pData[targetid][pInjuryTime] = 0;
    ClearAnimations(targetid);
    SetPlayerDrunkLevelEx(playerid, 0);
    if(TDInfo[targetid][InjuryTDShown])
    {
        Hide_InjuryTD(playerid);
        Show_HBETD(playerid);
    }

    foreach(new i : Player)
    {
        if(pData[i][pAdminLevel] > 0)
            SendClientMessage(i, COLOR_LIGHTRED, "AdmCmd: %s telah menghidupkan pemain %s(%d).", pData[playerid][pAdminName], pData[targetid][pName], targetid);
    }
    SendClientMessage(targetid, COLOR_LIGHTRED, "AdmCmd: %s telah menghidupkan karakter anda.", pData[playerid][pAdminName]);
    return 1;
}

YCMD:akill(playerid, params[], help)
{
    new targetid;

    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");
    
    if(sscanf(params, "d", targetid))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/akill <playerid>");

    if(!IsPlayerConnected(targetid) || !pData[targetid][pLoggedIn] || !pData[targetid][pSpawned])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut tidak ada didalam server atau belum spawn.");

    if(pData[targetid][pInjured])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut sudah dalam keadaan pingsan.");
    
    SetPlayerHealthEx(playerid, 0);
    return 1;
}

YCMD:gotoco(playerid, params[], help)
{
    new 
        Float:x,
        Float:y,
        Float:z,
        int;

    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");
    
    if(sscanf(params, "fffd", x, y, z, int))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/gotoco <x-axis> <y-axis> <z-axis> <interiorid>");

    SetPlayerInteriorEx(playerid, int);
    SetPlayerPos(playerid, x, y, z);

    SendClientMessage(playerid, COLOR_LIGHTBLUE, "INFO: "F_COLOR_WHITE"Anda telah diteleportasikan ke %.4f, %.4f, %.4f, (int: %d)", x, y, z, int);
    return 1;
}

YCMD:gotospawn(playerid, params[], help)
{
    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");

    SetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);

    SendClientMessage(playerid, COLOR_LIGHTBLUE, "INFO: "F_COLOR_WHITE"Anda telah diteleportasikan ke %.4f, %.4f, %.4f", pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
    return 1;
}

YCMD:setskin(playerid, params[], help)
{
    new 
        targetid,
        skin;

    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");

    if(sscanf(params, "dd", targetid, skin))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/setskin <playerid> <skinid>");

    if(!IsPlayerConnected(targetid) || !pData[targetid][pLoggedIn] || !pData[targetid][pSpawned])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut tidak ada didalam server atau belum spawn.");

    SetPlayerSkinEx(targetid, skin);

    foreach(new i : Player)
    {
        if(pData[i][pAdminLevel] > 0)
            SendClientMessage(i, COLOR_LIGHTRED, "AdmCmd: %s telah mengganti skin pemain %s(%d) menjadi %d.", pData[playerid][pAdminName], pData[targetid][pName], targetid, skin);
    }
    SendClientMessage(targetid, COLOR_LIGHTRED, "AdmCmd: %s telah mengganti skin karakter anda menjadi %d.", pData[playerid][pAdminName], skin);
    return 1;
}

YCMD:jetpack(playerid, params[], help)
{
    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");

    if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
        return ClearAnimations(playerid);
    
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USEJETPACK);
    return 1;
}

YCMD:setname(playerid, params[], help)
{
    new 
        targetid,
        newName[MAX_PLAYER_NAME];

    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");
    
    if(sscanf(params, "ds[24]", targetid, newName))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/setname <playerid> <new-name>");

    if(!IsPlayerConnected(targetid) || !pData[targetid][pLoggedIn] || !pData[targetid][pSpawned])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut tidak ada didalam server atau belum spawn.");

    if(!strcmp(pData[playerid][pName], newName))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda harus memasukkan nama yang berbeda dari nama saat ini.");
    
    if(strlen(newName) < 3 || strlen(newName) > MAX_PLAYER_NAME)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Nama karakter harus berisi antara 3 sampai 24 karakter.");
    
    if(!IsRoleplayName(newName))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Nama karakter harus menggunakan format Firstname_Lastname.");

    static query[144];
    mysql_format(g_SQL, query, sizeof(query), "SELECT 1 FROM `player_characters` WHERE `char_name` = '%e'", newName);
    mysql_pquery(g_SQL, query, "OnAdminChangeCharName", "dds", playerid, targetid, newName);
    return 1;
}

YCMD:setadminname(playerid, params[], help)
{
    new 
        targetid,
        newName[MAX_PLAYER_NAME];

    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");
    
    if(sscanf(params, "ds[24]", targetid, newName))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/setadminname <playerid> <new-name>");

    if(!IsPlayerConnected(targetid) || !pData[targetid][pLoggedIn] || !pData[targetid][pSpawned])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut tidak ada didalam server atau belum spawn.");

    if(pData[targetid][pAdminLevel] < 1)
        return  SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain tersebut bukan seorang admin.");

    if(!strcmp(pData[playerid][pName], newName))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda harus memasukkan nama yang berbeda dari nama saat ini.");
    
    if(strlen(newName) < 3 || strlen(newName) > MAX_PLAYER_NAME)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Nama admin harus berisi antara 3 sampai 24 karakter.");

    if(!IsValidName(newName))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Nama admin tidak valid.");

    static query[144];
    mysql_format(g_SQL, query, sizeof(query), "SELECT 1 FROM `player_characters` WHERE `char_admin_name` = '%e' AND `char_account_id` != %d", newName, pData[targetid][pAccountID]);
    mysql_pquery(g_SQL, query, "OnAdminChangeAdminName", "dds", playerid, targetid, newName);
    return 1;
}
YCMD:setaname(playerid, params[], help) = setadminname;

YCMD:agiveitem(playerid, params[], help)
{
    new 
        targetid,
        quantity,
        itemName[32];

    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Anda tidak memiliki izin untuk menggunakan perintah ini.");
    
    if(sscanf(params, "dds[32]", targetid, quantity, itemName))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/agiveitem <playerid> <item-quantity> <item-name>");

    if(!IsPlayerConnected(targetid) || !pData[targetid][pLoggedIn] || !pData[targetid][pSpawned])
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Pemain dengan id tersebut tidak ada didalam server atau belum spawn.");

    if(quantity < 1)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Jumlah item tidak dapat kurang dari 1.");

    new itemid = Inventory_GetItemID(itemName);

    if(itemid != -1)
    {
        Inventory_Add(playerid, itemid, quantity);
            
        foreach(new i : Player)
        {
            if(pData[i][pAdminLevel] > 0)
                SendClientMessage(i, COLOR_LIGHTRED, "AdmCmd: %s telah memberikan %d %s kepada pemain %s(%d).", pData[playerid][pAdminName], quantity, itemName, pData[targetid][pName], targetid);
        }
        SendClientMessage(targetid, COLOR_LIGHTRED, "AdmCmd: %s telah memberikan %d %s ke karakter anda.", pData[playerid][pAdminName], quantity, itemName);
        return 1;
    }
    else
    {
        SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Item dengan nama tersebut tidak ditemukan.");
    }
    return 0;
}
/*
YCMD:getdcid(playerid, params[], help)
{
    new ucp[24];
    if(pData[playerid][pAdminLevel] < 1)
        return 1;

    if(sscanf(params, "s", ucp)) return SendClientMessage(playerid, -1, "SYNTAX: /getdcid <ucp>");

    new query[256];
    mysql_format(g_SQL, query, "SELECT `discordid` FROM `whitelists` WHERE `ucp` = '%e' LIMIT 1", ucp);
    mysql_pquery(g_SQL, query, "GetDiscordID", "is", playerid, ucp);
    return 1;
}

forward GetDiscordID(playerid, ucp[]);
public GetDiscordID(playerid, ucp[])
{
    new discordid[31+1];
    if(!cache_num_rows()) return SendClientMessage(playerid, -1, "ERRORR: Ucp dengan nama tersebut tidak ditemukan.");

    cache_get_value_name(0, "discordid", discordid);
    SendClientMessage(playerid, -1, "UCP: %s | DCID: %s", ucp, discordid);
    return 1;
}

YCMD:checkdcid(playerid, params[], help)
{
    new discordid[31+1];
    if(pData[playerid][pAdminLevel] < 1)
        return 1;

    if(sscanf(params, "s", discordid)) return SendClientMessage(playerid, -1, "SYNTAX: /getdcid <discordid>");
    
    new query[256];
    mysql_query(g_SQL, query, sizeof(query), "SELECT `ucp` FROM `whitelists` WHERE `discordid` = '%e'", discordid);
    mysql_pquery(g_SQL, query, "CheckDiscordID", "is", playerid, discordid)
    return 1;
}

forward CheckDiscordID(playerid, dcid[]);
public CheckDiscordID(playerid, dcid[])
{
    new 
        ucp[24],
        rows = cache_num_rows();
    if(rows)
    {
        SendClientMessage(playerid, -1, "Menemukan %d ucp yang terkait.", rows);
        for(new i = 0; i < rows; i++)
        {
            cache_get_value_name(i, "ucp", ucp);
            SendClientMessage(playerid, -1, "%s" ucp);
        }
        return 1;
    }
    SendClientMessage(playerid, -1, "ERROR: Tidak ada ucp dengan discordid tersebut.");
    return 1;
}*/

YCMD:checkacwarns(playerid, params[], help)
{
    new targetid;
    
    if(pData[playerid][pAdminLevel] < 1)
        return 1;

    if(sscanf(params, "u", targetid)) return SendClientMessage(playerid, -1, "SYNTAX: /checkacwarns <playerid>");

    if(!IsPlayerConnected(targetid) || targetid == INVALID_PLAYER_ID) return SendClientMessage(playerid, -1, "> Pemain dengan id tersebut tidak dapat ditemukan didalam server.");

    new str[666];

    format(str, sizeof(str), "Cheat Category\tStatus\n");

    format(str, sizeof(str),
        "%s\
     S0beit\t%s\n\
     CLEO #1\t%s\n\
     CLEO #2\t%s\n\
     CLEO #3\t%s\n\
     CLEO / MoonLoader #1\t%s\n\
     CLEO / MoonLoader #2\t%s\n\
     CLEO #4\t%s\n\
     SilentPatch\t%s\n\
     SAMPFUNCS\t%s\n\
     SAMPFUNCS #2\t%s\n\
     S0beit #2\t%s\n\
     Modified Vorbis\t%s\n\
     Ultra WH\t%s\n\
     Silent Aim\t%s\n\
     Improved Deagle\t%s\n\
     Stealth Remastered\t%s\n\
     Sensfix\t%s\n\
     S0beit v2 / RakNet Anomaly\t%s",
        str,

        ACVar[targetid][ac_IsS0beitDetected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsCleo1Detected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsCleo2Detected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsCleo3Detected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsCleoMoonloader1Detected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsCleoMoonloader2Detected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsCleo4Detected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsSilentPatchDetected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsSampFuncsDetected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsSampFuncs2Detected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsS0beit2Detected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsModedVorbisDetected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsUltraWhDetected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsSilentAimDetected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsImprovedDeagleDetected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsStealthRemasteredDetected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsSensfixDetected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected"),
        ACVar[targetid][ac_IsS0beit2orRAkNetAnomalyDetected] ? ("{FF0000}Detected") : ("{00FF00}Not Detected")
    );

    Dialog_Show(playerid, "Message", DIALOG_STYLE_TABLIST_HEADERS, "Player AntiCheat Warning", str, "Close", "");
    return 1;
}
