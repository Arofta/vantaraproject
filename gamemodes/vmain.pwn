#define MIXED_SPELLINGS

#define MAX_ADMIN_VEHICLES 100

// Core
#include <open.mp>
#include <easyDialog>
#include <strlib>
#define CGEN_MEMORY 40000
#define YSI_NO_HEAP_MALLOC
#include <YSI_Coding\y_malloc>
#include <YSI_Server\y_colours>
#include <YSI_Visual\y_commands>
#include <YSI_Coding\y_inline>
#include <YSI_Extra\y_inline_timers>
#include <YSI_Coding\y_timers>
#include <YSI_Data\y_iterate>
#include <YSI_Server\y_flooding>
#include <YSI_Coding\y_hooks>

// Plugins
#include <a_mysql> // mysql
#include <samp_bcrypt> // samp_bcrypt
#include <streamer> // streamer
#include <sscanf2> // sscanf
// #include <textdraw-streamer> // textdraw-streamer

// Utils
#include "modules/utils/utils.inc"

enum e_PlayerData
{
    pID,
    pAccountID,

    pVersion[24],

    bool:pSpawned,
    bool:pLoggedIn,

    pAccountRegistDate[50],
    pAccountLastOnlineDate[50],
    pRegisterDate[50],
    pLastOnlineDate[50],
    pLastExit,

    pName[MAX_PLAYER_NAME],
    pUCP[MAX_PLAYER_NAME],

    pAdminLevel,
    pAdminName[MAX_PLAYER_NAME],

    pMoney,
    pBankMoney,

    Float:pHealth,
    Float:pArmour,

    pSkin,
    pDOB[11],
    pGender,
    pHeight,
    pWeight,
    pOrigin,
    pDomicile,

    Float:pPosX,
    Float:pPosY,
    Float:pPosZ,
    Float:pPosA,

    pVirtualWorld,
    pInterior,

    pJob,

    pFaction,
    pFactionRank,

    pFamily,
    pFamilyRank,

    bool:pInjured,
    pInjuryTime,

    Float:pHunger,
    Float:pThirst,
    Float:pStress,

    pHungerTime,
    pThirstTime,
    pStressTime,

    pInjuryWarn,

    pPlaytime,

    pVIP,
    pVIPExpiry,

    bool:pGuardian,
    pGuardianExpiry,

    bool:pSMaster,

    pLevel,
    pDrunkLevel,

    InRelaxingArea,
};

new pData[MAX_PLAYERS][e_PlayerData];

enum e_ServerInfo 
{
    AdminVeh[MAX_ADMIN_VEHICLES],

    bool:ServerLocked,
    ServerPassword[64]
};

new SInfo[e_ServerInfo];

enum e_TextDrawInfo
{
    bool:HBETDShown,
    bool:InjuryTDShown, 
    bool:DyingTDShown,
    bool:InvTDShown,
};

new TDInfo[MAX_PLAYERS][e_TextDrawInfo];

new Aduty[MAX_PLAYERS];

new MySQL:SQL;
new g_MySQLRaceCheck[MAX_PLAYERS];

#include "modules/core/gmcore.inc"
#include "modules/utils/utils_debugs.inc"

function:ExitCommandProcessed(seconds_to_exit)
{
    if(mysql_errno(SQL) != 0)
    {
        if(--seconds_to_exit > 0)
        {
            SetTimerEx("ExitCommandProcessed", 1000, false, "d", seconds_to_exit);
            printf("> %d..", seconds_to_exit);
        }
        else
        {
            printf("Shutdown Gamemode...");
            SendRconCommand("exit"); // Exit the server if database connection fails, since it's required for the gamemode to function properly.
        }
    }
    return 1;
}

main()
{
    if(mysql_errno(SQL) == 0)
    {
        printf("================================================");
        printf("| >>> Vantara Legacy Main Gamemode Loaded. <<< |");
        printf("================================================");
    }
}

public OnGameModeInit()
{
    EnableStuntBonusForAll(false);
    DisableInteriorEnterExits();

    SQL = mysql_connect_file("mysql.ini"); // Connect to server Database using mysql.ini file for credentials. Alternative:
    if(mysql_errno(SQL) == 0)
    {
        printf("===========================================================");
        printf("| >>> Vantara Legacy Database Connected Successfully. <<< |");
        printf("===========================================================");
    }
    else
    {
        printf("======================================================");
        printf("| >>> Vantara Legacy Database Connection Failed. <<< |");
        printf("======================================================");
        printf("Gamemode Automatically Shutdown in..");
        return SetTimerEx("ExitCommandProcessed", 1000, false, "d", 15);
    }

    Create_HBETD();
    Create_InjuryTD();
    Create_InvTD();
    //Create_ContainerTD();

    SetGameModeText("VRP: v0.3.0 Alpha");

    for(new x = 0; x < MAX_ADMIN_VEHICLES; x++)
    {
        SInfo[AdminVeh][x] = INVALID_VEHICLE_ID;
    }

    AddPlayerClass(299, 0.0, 0.0, 0.0, 300.0, WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
    return 1;
}

public OnGameModeExit()
{
    mysql_close(SQL);
    return 1;
}

public OnPlayerConnect(playerid)
{
    g_MySQLRaceCheck[playerid] ++;

    ResetVariables(playerid);

    SetPlayerTeam(playerid, NO_TEAM);
    SendClientMessage(playerid, -1, "Welcome to Vantara Roleplay.");

    Create_HBEPTD(playerid);
    Create_InjuryPTD(playerid);
    Create_InvPTD(playerid);
    //Create_ContainerPTD(playerid);

    SetPlayerColor(playerid, 0x7F7F83FF);
    GetPlayerName(playerid, pData[playerid][pUCP], MAX_PLAYER_NAME);

    SetPlayerCinemaScene(playerid, CINEMA_LOGIN);

    AccountCheck(playerid);
    GetPlayerVersion(playerid, pData[playerid][pVersion]);

    if(strcmp(pData[playerid][pVersion], "0.3.7") && strcmp(pData[playerid][pVersion], "0.3.7-R3"))
    {
        SendClientMessage(playerid, Y_RED, "[WARNING] "YELLOW1"CLIENT SA-MP ANDA TIDAK COCOK DENGAN SERVER KAMI! "ORANGE1"(GUNAKAN 0.3.7 ATAU 0.3.7-R3).");
        SendClientMessage(playerid, Y_RED, "[WARNING] "YELLOW1"JIKA TERJADI MASALAH, GANTI CLIENT SA-MP ANDA DAN GUNAKAN "ORANGE1"0.3.7 "YELLOW1" ATAU "ORANGE1"0.3.7-R3.");
    }

    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    g_MySQLRaceCheck[playerid] ++;

    Destroy_HBEPTD(playerid);
    Destroy_InjuryPTD(playerid);
    Destroy_InvPTD(playerid);
    //Destroy_ContainerPTD(playerid);

    SaveCharacterData(playerid);
    ResetVariables(playerid);
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{  
    return 1;
}

public OnPlayerSpawn(playerid)
{
    return 1;
}

public OnPlayerDeath(playerid, killerid, WEAPON:reason)
{
    if (!pData[playerid][pLoggedIn] || !pData[playerid][pSpawned]) return KickEx(playerid);
    
    foreach (new x : Player)
    {
        if (pData[x][pAdminLevel] > 0)
        {
            SendDeathMessageToPlayer(x, killerid, playerid, reason);
        }
    }
    SetPlayerHealthEx(playerid, 100);
    SetPlayerHealth(playerid, 1000);
    return 1;
}
public e_COMMAND_ERRORS:OnPlayerCommandReceived(playerid, cmdtext[], e_COMMAND_ERRORS:success)
{
    if(success != COMMAND_OK)
    {
        SendClientMessage(playerid, -1, "ERROR: Perintah '%s' tidak diketahui, gunakan '/help' untuk melihat semua perintah yang tersedia.", cmdtext);
        Command_SetDeniedReturn(true);
        return COMMAND_OK;
    }

    if(!pData[playerid][pLoggedIn])
    {
        SendClientMessage(playerid, -1, "ERROR: Anda harus login atau spawn sebelum menggunakan perintah!");
        Command_SetDeniedReturn(true);
        return COMMAND_DENIED;
    }

    if(!pData[playerid][pSpawned])
    {
        SendClientMessage(playerid, -1, "ERROR: Anda harus login atau spawn sebelum menggunakan perintah!");
        Command_SetDeniedReturn(true);
        return COMMAND_DENIED;
    }
    return COMMAND_OK;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    return 1;
}

public OnPlayerText(playerid, text[])
{
    if(!pData[playerid][pLoggedIn] && !pData[playerid][pSpawned])
        return KickEx(playerid);

    new Float:POS[3];
    GetPlayerPos(playerid, POS[0], POS[1], POS[2]);
    foreach(new x : Player)
    {
        if(IsPlayerInRangeOfPoint(x, 14, POS[0], POS[1], POS[2]))
        {
            if(pData[playerid][pAdminLevel] >= 1 && Aduty[playerid])
            {
                SendClientMessage(x, -1, ""F_COLOR_RED"%s %s"F_COLOR_WHITE": "VANTARA"(("F_COLOR_WHITE" %s "VANTARA"))"F_COLOR_WHITE"", GetPlayerAdminRankName(playerid), pData[playerid][pAdminName], text);
            }
            else
            {
                SendClientMessage(x, -1, "%s %s(%d): "VANTARA"(("F_COLOR_WHITE" %s "VANTARA"))"F_COLOR_WHITE"", GetLevelName(pData[playerid][pLevel], pData[playerid][pSMaster]), pData[playerid][pUCP], playerid, text);
            }
        }
    }
    return 0;
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, WEAPON:weaponid, bodypart)
{
    if(pData[playerid][pArmour] > 0.0 && weaponid != WEAPON:53 && weaponid != WEAPON:54)
    {
        if(pData[playerid][pArmour] >= amount)
        {
            pData[playerid][pArmour] -= amount;
        }
        else
        {
            new Float:remaining = amount - pData[playerid][pArmour];

            pData[playerid][pArmour] = 0.0;
            pData[playerid][pHealth] -= remaining;
        }
    }
    else
    {
        pData[playerid][pHealth] -= amount;
    }

    //SendClientMessage(playerid, -1, "Damage taken on Bodyparts: %d | Damage: %.2f | Reason: %d | Issuer: %d", bodypart, amount, weaponid, issuerid);
    //printf("Damage taken on Bodyparts: %d | Damage: %.2f | Reason: %d | Issuer: %d", bodypart, amount, weaponid, issuerid);
    return 1;
}

public OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
    SendClientMessage(playerid, -1, "Player %d has shooting with Weapon: %d | Hit Type: %d | Hit ID: %d | X: %.4f | Y: %.4f | Z: %.4f", playerid, weaponid, hittype, hitid, fX, fY, fZ);
    printf("Player %d has shooting with Weapon: %d | Hit Type: %d | Hit ID: %d | X: %.4f | Y: %.4f | Z: %.4f", playerid, weaponid, hittype, hitid, fX, fY, fZ);
    return 1;
}

public OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
    if(newstate != PLAYER_STATE_NONE && newstate != PLAYER_STATE_SPECTATING)
    {
        if(!pData[playerid][pLoggedIn])
        {
            return KickEx(playerid);
        }
    }
    if(newstate == PLAYER_STATE_WASTED)
    {
        if(pData[playerid][pLoggedIn] && pData[playerid][pSpawned])
        {
            pData[playerid][pInjured] = true;
            pData[playerid][pInjuryTime] = 60 * 60;

            new query[128];
            mysql_format(SQL, query, sizeof(query), "UPDATE `player_characters` SET `char_injured` = 1, `char_injury_time` = %d WHERE `char_id` = %d", pData[playerid][pInjuryTime], pData[playerid][pID]);
            mysql_pquery(SQL, query);

            if(TDInfo[playerid][DyingTDShown])
                Hide_DyingTD(playerid);
            if(TDInfo[playerid][HBETDShown])
                Hide_HBETD(playerid);
            if(!TDInfo[playerid][InjuryTDShown])
                Show_InjuryTD(playerid);

            //SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
            SetPlayerHealthEx(playerid, 100);

            GetPlayerPos(playerid, pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ]);
            GetPlayerFacingAngle(playerid, pData[playerid][pPosA]);
            pData[playerid][pPosZ] -= 0.3;

            SetSpawnInfo(playerid, NO_TEAM, pData[playerid][pSkin], pData[playerid][pPosX], pData[playerid][pPosY], pData[playerid][pPosZ], pData[playerid][pPosA], WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
            TogglePlayerSpectating(playerid, false);
            
            if(IsPlayerInAnyVehicle(playerid))
                RemovePlayerFromVehicle(playerid, true);
            
            SpawnPlayer(playerid);
            ApplyAnimation(playerid, "WUZI", "CS_DEAD_GUY", 4.1, false, false, false, true, 0, SYNC_ALL);
        }
    }
    return 1;
}
