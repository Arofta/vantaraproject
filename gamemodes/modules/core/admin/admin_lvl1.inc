#include <YSI_Viusal\y_commands>

YCMD:aduty(playerid, params[], help)
{
    if(pData[playerid][pAdminLevel] < 1)
        return SendClientMessage(playerid, -1, "ERROR: Kamu tidak memiliki izin untuk menggunakan perintah ini.");
    
    Aduty[playerid] = !Aduty[playerid];

    if(Aduty[playerid])
    {
        foreach(new i : Player)
        {
            if(pData[i][pAdminLevel] > 0)
                return SendClientMessage(i, -1, "AdmCmd: %s telah on duty admin sebagai %s", pData[playerid][pName], pData[playerid][pAdminName]);
        }
        return 1;
    }
    else
    {
        return 1;
    }
    return 1;
}