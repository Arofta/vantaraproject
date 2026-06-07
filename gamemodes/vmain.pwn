#define MIXED_SPELLINGS

// Core
#include <open.mp>
#include <easyDialog>
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
#include <a_mysql>
#include <samp_bcrypt>
#include <streamer>
#include <sscanf2>
#include <textdraw-streamer>

enum e_PlayerData
{
    pID,
    pAccountID,

    bool:pSpawned,
    bool:pLoggedIn,

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

    pInterior,
    pVirtualWorld,

    Float:pHunger,
    Float:pThirst,
    Float:pStress,

    pHungerTime,
    pThirstTime,
    pStressTime,

    pLevel,
    pDrunkLevel,
};

new pData[MAX_PLAYERS][e_PlayerData];

new MySQL:g_SQL;
new g_MySQLRaceCheck[MAX_PLAYERS];

#include "modules/core/gmcore.inc"

main()
{
    print("----------\nVantara Roleplay Main Gamemode Loaded.\n----------");
}

public OnGameModeInit()
{
    EnableStuntBonusForAll(false);

    g_SQL = mysql_connect_file("mysql.ini"); // Connect to server Database using mysql.ini file for credentials. Alternative:
    if(mysql_errno(g_SQL) == 0)
    {
        print("-----------------------------------------------\n");
        print("Database connection is active and ready to use.\n");
        print("-----------------------------------------------\n");
    }
    else
    {
        print("-----------------------------------------------\n");
        print("Failed to connect to database. Check mysql.ini.\n");
        print("-----------------------------------------------\n");
        SendRconCommand("exit"); // Exit the server if database connection fails, since it's required for the gamemode to function properly.
    }

    AddPlayerClass(299, 0.0, 0.0, 0.0, 300.0, WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
    return 1;
}

public OnGameModeExit()
{
    mysql_close(g_SQL);
    return 1;
}

public OnPlayerConnect(playerid)
{
    g_MySQLRaceCheck[playerid] ++;
    tempLoginAttempts[playerid] = 3;
    SetPlayerTeam(playerid, NO_TEAM);
    SendClientMessage(playerid, -1, "Welcome to Vantara Roleplay.");
    
    GetPlayerName(playerid, pData[playerid][pUCP], MAX_PLAYER_NAME);

    TogglePlayerSpectating(playerid, true);
    AccountCheck(playerid);

    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    g_MySQLRaceCheck[playerid] ++;
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{  
    TogglePlayerSpectating(playerid, true);
    return 1;
}

public OnPlayerSpawn(playerid)
{
    return 1;
}

public OnPlayerDeath(playerid, killerid, WEAPON:reason)
{
    return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    return 1;
}
