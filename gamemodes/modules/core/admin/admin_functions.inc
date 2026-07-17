
hook OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
    if(pData[playerid][pAdminLevel] > 0 && Aduty[playerid])
    {
        if(!IsPlayerInAnyVehicle(playerid))
        {
            SetPlayerPos(playerid, Float:fX, Float:fY, Float:fZ);
        }
        else
        {
            new vehicleid = GetPlayerVehicleID(playerid);
            SetVehiclePos(vehicleid, Float:fX, Float:fY, Float:fZ);
        }
    }
    return 1;
}

function:OnAdminChangeCharName(playerid, targetid, const name[])
{
    if(cache_num_rows())
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Nama tersebut sudah digunakan pemain lain.");

    new query[144];
    mysql_format(SQL, query, sizeof(query), "UPDATE `player_characters` SET `char_name` = '%e' WHERE `char_id` = %d", name, pData[targetid][pID]);
    mysql_pquery(SQL, query);

    foreach(new i : Player)
    {
        if(pData[i][pAdminLevel] > 0)
            SendClientMessage(i, COLOR_LIGHTRED, "AdmCmd: %s telah mengganti nama pemain %s(%d) menjadi %s(%d).", pData[playerid][pAdminName], pData[targetid][pName], targetid, name, targetid);
    }
    SendClientMessage(targetid, COLOR_LIGHTRED, "AdmCmd: %s telah mengganti nama karakter anda menjadi %s.", pData[playerid][pAdminName], name);
    SetPlayerNameEx(targetid, name);
    return 1;
}

function:OnAdminChangeAdminName(playerid, targetid, const name[])
{
    if(cache_num_rows())
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Nama tersebut sudah digunakan admin lain.");

    new query[144];
    mysql_format(SQL, query, sizeof(query), "UPDATE `player_characters` SET `char_admin_name` = '%e' WHERE `char_id` = %d", name, pData[targetid][pID]);
    mysql_pquery(SQL, query);

    foreach(new i : Player)
    {
        if(pData[i][pAdminLevel] > 0)
            SendClientMessage(i, COLOR_LIGHTRED, "AdmCmd: %s telah mengganti nama admin %s menjadi %s.", pData[playerid][pAdminName], pData[targetid][pAdminName], name);
    }
    SendClientMessage(targetid, COLOR_LIGHTRED, "AdmCmd: %s telah mengganti nama admin anda menjadi %s.", pData[playerid][pAdminName], name);
    
    strcopy(pData[targetid][pAdminName], name);
    if(Aduty[targetid]) SetPlayerName(playerid, name);
    return 1;
}