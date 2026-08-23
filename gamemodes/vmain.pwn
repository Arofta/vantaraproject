#define MIXED_SPELLINGS

#define MAX_ADMIN_VEHICLES      100

#define SERVER_VERSION          "v0.6.1a"

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
#include <textdraw-streamer> // textdraw-streamer

// AntiCheat
#include <anticheat>

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

    pInvTotalWeight, // tidak perlu di save ke database.

    InRelaxingArea,

    pBHOP
};
new pData[MAX_PLAYERS][e_PlayerData];

enum e_AntiCheat
{    
    bool:ac_IsS0beitDetected,
    bool:ac_IsCleo1Detected,
    bool:ac_IsCleo2Detected,
    bool:ac_IsCleo3Detected,
    bool:ac_IsCleoMoonloader1Detected,
    bool:ac_IsCleoMoonloader2Detected,
    bool:ac_IsCleo4Detected,
    bool:ac_IsSilentPatchDetected,
    bool:ac_IsSampFuncsDetected,
    bool:ac_IsSampFuncs2Detected,
    bool:ac_IsS0beit2Detected,
    bool:ac_IsModedVorbisDetected,
    bool:ac_IsUltraWhDetected,
    bool:ac_IsSilentAimDetected,
    bool:ac_IsImprovedDeagleDetected,
    bool:ac_IsStealthRemasteredDetected,
    bool:ac_IsSensfixDetected,
    bool:ac_IsS0beit2orRAkNetAnomalyDetected
};
new ACVar[MAX_PLAYERS][e_AntiCheat];

enum e_ServerInfo 
{
    AdminVeh[MAX_ADMIN_VEHICLES],

    bool:ServerLocked,
    ServerPassword[64],
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

new g_Aduty[MAX_PLAYERS];
new g_BHOP[MAX_PLAYERS];

new MySQL:g_SQL;
new g_MySQLRaceCheck[MAX_PLAYERS];

#include "modules/core/gmcore.inc"
#include "modules/utils/utils_debugs.inc"

main()
{
    if(mysql_errno(g_SQL) == 0)
    {
        printf("    |      Vantara Legacy Main Gamemode     |");
        printf("    |                                       |");
        printf("    |              by Arofta                |");
        printf("    |                                       |");
        printf("    |              Funded by                |");
        printf("    |               .PhiBi                  |");
        printf("    |                                       |");
        printf("    |   Est. 23 Jun 2026                    |");
        printf("    |                          Loaded.      |");
        printf("    |     Startup Completed in %4d ms      |", GetTickCount());
        printf("    =========================================");
        printf(" ");
    }
}

public OnGameModeInit()
{
    EnableStuntBonusForAll(false);
    DisableInteriorEnterExits();

    new tick = GetTickCount();
    g_SQL = mysql_connect_file("mysql.ini"); // Connect ke server database pake mysql.ini sebagain media kredensial
    if(mysql_errno(g_SQL) == 0)
    {
        printf("    =========================================");
        printf("    |        Vantara Legacy Database        |");
        printf("    |                                       |");
        printf("    |            Done in %4d ms            |", GetTickCount() - tick);
        printf("    |                                       |");
        printf("    |                          Connected.   |");
        printf("    =========================================");
    }
    else
    {
        printf("    =========================================");
        printf("    |        Vantara Legacy Database        |");
        printf("    |                                       |");
        printf("    |                  Connection Failed.   |");
        printf("    =========================================");
        printf("Gamemode Automatically Shutdown in..");

        new seconds_to_exit = 15;

        inline TickToShutdown()
        {
            printf("> %d..", seconds_to_exit);
            if (--seconds_to_exit <= 0)
            {
                printf("Shutdown Gamemode...");
                SendRconCommand("exit");
            }
        }

        return Timer_CreateCallback(using inline TickToShutdown, 1000, 15);
    }

    //AddCharModel(29, 20001, "hoodie.dff", "hoodie.txd");
    //AddCharModel(2, 20002, "robert.dff", "robert.txd");
    //AddCharModel(203, 20003, "ustadz.dff", "ustadz.txd");
    //AddCharModel(23, 20004, "23.dff", "23.txd");
    //AddCharModel(299, 20005, "wmaff2.dff", "wmaff2.txd");

    // cewek
    AddCharModel(56, 20006, "becky.dff", "becky.txd");
    AddCharModel(56, 20007, "pajtfnl1.dff", "pajtfnl1.txd");
    AddCharModel(55, 20008, "outfttfnl1.dff", "outfttfnl1.txd");
    AddCharModel(193, 20009, "nurgrl3.dff", "nurgrl3.txd");
    AddCharModel(93, 20010, "93.dff", "93.txd");

    // pemerintah
    //AddCharModel(228, 20011, "1-walkot.dff", "1-walkot.txd");
    //AddCharModel(187, 20012, "1-wwalkot.dff", "1-wwalkot.txd");
    AddCharModel(295, 20013, "1-kepdinas.dff", "1-kepdinas.txd");
    AddCharModel(227, 20014, "1-heck.dff", "1-heck.txd");
    AddCharModel(165, 20015, "1-senior.dff", "1-senior.txd");
    AddCharModel(265, 20016, "1-senmud.dff", "1-senmud.txd");
    AddCharModel(147, 20017, "1-honorer.dff", "1-honorer.txd");

    Create_HBETD();
    Create_InjuryTD();
    Create_InvTD();
    Create_ContainerTD();

    SetGameModeText("VRP: "SERVER_VERSION"");

    // Init SInfo Variables
    SInfo[ServerLocked] = false;
    SInfo[ServerPassword] = EOS;
    for(new x = 0; x < MAX_ADMIN_VEHICLES; x++)
    {
        SInfo[AdminVeh][x] = INVALID_VEHICLE_ID;
    }

    AddPlayerClass(299, 0.0, 0.0, 0.0, 300.0, WEAPON_FIST, 0, WEAPON_FIST, 0, WEAPON_FIST, 0);
    return 1;
}

public OnGameModeExit()
{
    mysql_close(g_SQL);
    return 1;
}

public OnPlayerCheatDetected(playerid, cheatid, action)
{   
    switch(cheatid)
    {
        case 1: // S0beit
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}S0beit{FFFFFF} pada client mu (#%d). Kamu ditendang dari server.", cheatid);
            ACVar[playerid][ac_IsS0beitDetected] = true;
            return KickEx(playerid);
        }

        case 2: // CLEO #1
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}CLEO #1{FFFFFF} pada client mu (#%d). Pesan ini hanya sebuah peringatan.", cheatid);
            ACVar[playerid][ac_IsCleo1Detected] = true;
            return 0;
        }

        case 3: // CLEO #2
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}CLEO #2{FFFFFF} pada client mu (#%d). Pesan ini hanya sebuah peringatan.", cheatid);
            ACVar[playerid][ac_IsCleo2Detected] = true;
            return 0;
        }

        case 4: // CLEO #3
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}CLEO #3{FFFFFF} pada client mu (#%d). Pesan ini hanya sebuah peringatan.", cheatid);
            ACVar[playerid][ac_IsCleo3Detected] = true;
            return 0;
        }

        case 5: // CLEO / MoonLoader #1
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}CLEO / MoonLoader #1{FFFFFF} pada client mu (#%d). Pesan ini hanya sebuah peringatan.", cheatid);
            ACVar[playerid][ac_IsCleoMoonloader1Detected] = true;
            return 0;
        }

        case 6: // CLEO / MoonLoader #2
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}CLEO / MoonLoader #2{FFFFFF} pada client mu (#%d). Pesan ini hanya sebuah peringatan.", cheatid);
            ACVar[playerid][ac_IsCleoMoonloader2Detected] = true;
            return 0;
        }

        case 7: // CLEO #4
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}CLEO #4{FFFFFF} pada client mu (#%d). Pesan ini hanya sebuah peringatan.", cheatid);
            ACVar[playerid][ac_IsCleo4Detected] = true;
            return 0;
        }

        case 8: // SilentPatch
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}SilentPatch{FFFFFF} pada client mu (#%d). Pesan ini hanya sebuah peringatan.", cheatid);
            ACVar[playerid][ac_IsSilentPatchDetected] = true;
            return 0;
        }

        case 9: // SAMPFUNCS #1
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}SAMPFUNCS #1{FFFFFF} pada client mu (#%d). Kamu ditendang dari server.", cheatid);
            ACVar[playerid][ac_IsSampFuncsDetected] = true;
            return KickEx(playerid);
        }

        case 10: // SAMPFUNCS #2
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}SAMPFUNCS #2{FFFFFF} pada client mu (#%d). Kamu ditendang dari server.", cheatid);
            ACVar[playerid][ac_IsSampFuncs2Detected] = true;
            return KickEx(playerid);
        }

        case 11: // S0beit #2
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}S0beit #2{FFFFFF} pada client mu (#%d). Kamu ditendang dari server.", cheatid);
            ACVar[playerid][ac_IsS0beit2Detected] = true;
            return KickEx(playerid);
        }

        case 12: // Modified Vorbis File
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}Modified Vorbis File{FFFFFF} pada client mu (#%d). Pesan ini hanya sebuah peringatan.", cheatid);
            ACVar[playerid][ac_IsModedVorbisDetected] = true;
            return 0;
        }

        case 13: // UltraWH
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}UltraWH{FFFFFF} pada client mu (#%d). Pesan ini hanya sebuah peringatan.", cheatid);
            ACVar[playerid][ac_IsUltraWhDetected] = true;
            return 0;
        }

        case 14: // SilentAim
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}SilentAim{FFFFFF} pada client mu (#%d). Kamu ditendang dari server.", cheatid);
            ACVar[playerid][ac_IsSilentAimDetected] = true;
            return KickEx(playerid);
        }

        case 15: // Improved Deagle
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}Improved Deagle{FFFFFF} pada client mu (#%d). Kamu ditendang dari server.", cheatid);
            ACVar[playerid][ac_IsImprovedDeagleDetected] = true;
            return KickEx(playerid);
        }

        case 16: // Stealth Remastered
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}Stealth Remastered{FFFFFF} pada client mu (#%d). Kamu ditendang dari server.", cheatid);
            ACVar[playerid][ac_IsStealthRemasteredDetected] = true;
            return KickEx(playerid);
        }

        case 17: // SensFix
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}SensFix{FFFFFF} pada client mu (#%d). Pesan ini hanya sebuah peringatan.", cheatid);
            ACVar[playerid][ac_IsSensfixDetected] = true;
            return 0;
        }

        case 18: // S0beit v2 / RakNet Anomaly
        {
            SendClientMessage(playerid, -1, "{FF0000}[AntiCheat]{FFFFFF} Terdeteksi adanya {FFFF00}S0beit v2{FFFFFF} pada client mu (#%d). Kamu ditendang dari server.", cheatid);
            ACVar[playerid][ac_IsS0beit2orRAkNetAnomalyDetected] = true;
            return KickEx(playerid);
        }
    }
    return 1;
}

public OnPlayerConnect(playerid)
{
    if(IsPlayerNPC(playerid)) return KickEx(playerid);
    g_MySQLRaceCheck[playerid]++;

    ResetVariables(playerid);

    SetPlayerTeam(playerid, NO_TEAM);
    SendClientMessage(playerid, -1, "Welcome to Vantara Roleplay.");

    Create_HBEPTD(playerid);
    Create_InjuryPTD(playerid);
    Create_InvPTD(playerid);
    Create_ContainerPTD(playerid);

    SetPlayerColor(playerid, 0x7F7F83FF);
    GetPlayerName(playerid, pData[playerid][pUCP], MAX_PLAYER_NAME);

    SetPlayerCinemaScene(playerid, CINEMA_LOGIN);

    AccountCheck(playerid);
    GetPlayerVersion(playerid, pData[playerid][pVersion]);

    if(strcmp(pData[playerid][pVersion], "0.3.7") && strcmp(pData[playerid][pVersion], "0.3.7-R3"))
    {
        //SendClientMessage(playerid, Y_RED, "[WARNING] "YELLOW1"CLIENT SA-MP ANDA TIDAK COCOK DENGAN SERVER KAMI! "ORANGE1"(GUNAKAN 0.3.7 ATAU 0.3.7-R3).");
        //SendClientMessage(playerid, Y_RED, "[WARNING] "YELLOW1"JIKA TERJADI MASALAH, GANTI CLIENT SA-MP ANDA DAN GUNAKAN "ORANGE1"0.3.7 "YELLOW1" ATAU "ORANGE1"0.3.7-R3.");
    }

    return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    g_MySQLRaceCheck[playerid]++;

    Destroy_HBEPTD(playerid);
    Destroy_InjuryPTD(playerid);
    Destroy_InvPTD(playerid);
    Destroy_ContainerPTD(playerid);

    SaveCharacterData(playerid);
    ResetVariables(playerid);
    return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
    SendClientMessage(playerid, -1, "Requesting class...");
    return 1;
}

public OnPlayerRequestSpawn(playerid)
{
    SendClientMessage(playerid, -1, "Requesting Spawn...");
    return 1;
}

public OnPlayerSpawn(playerid)
{
    if(!pData[playerid][pLoggedIn] || !pData[playerid][pSpawned])
    {
        Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Suspected of cheating", "Anda terdeteksi melakukan fake spawn.", "Keluar", "");
        return KickEx(playerid);
    }
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
            if(pData[playerid][pAdminLevel] >= 1 && g_Aduty[playerid])
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
        if(!pData[playerid][pLoggedIn] && !pData[playerid][pSpawned])
            return KickEx(playerid);

        pData[playerid][pInjured] = true;
        pData[playerid][pInjuryTime] = 60 * 60;

        new query[128];
        mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `char_injured` = 1, `char_injury_time` = %d WHERE `char_id` = %d", pData[playerid][pInjuryTime], pData[playerid][pID]);
        mysql_pquery(g_SQL, query);

        if(TDInfo[playerid][DyingTDShown])
            Hide_DyingTD(playerid);
        if(TDInfo[playerid][HBETDShown])
            Hide_HBETD(playerid);
        if(!TDInfo[playerid][InjuryTDShown])
            Show_InjuryTD(playerid);
        
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
        return 1;
    }
    if((newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER) && pData[playerid][pInjured])
    {
        ClearAnimations(playerid, SYNC_ALL);
        ApplyAnimation(playerid, "WUZI", "CS_DEAD_GUY", 4.1, false, false, false, true, 0, SYNC_ALL);
        return 1;
    }
    return 1;
}

public OnPlayerKeyStateChange(playerid, KEY:newkeys, KEY:oldkeys)
{
    if(PRESSED(KEY_JUMP) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && !IsPlayerFalling(playerid) && !pData[playerid][pInjured] && !((newkeys & KEY_AIM) && IsFirearmWeapon(GetPlayerWeapon(playerid))))
    {
        new index = GetPlayerAnimationIndex(playerid);
        if(index && (index < 1061 || index > 1067) && index != 1167)
        {
            if(++g_BHOP[playerid] >= 3)
            {
                ClearAnimations(playerid, SYNC_ALL);
                ApplyAnimation(playerid, "PED", "FALL_COLLAPSE", 4.1, false, true, true, false, 0, SYNC_ALL);
                g_BHOP[playerid] = 0;
            }
            SetTimerEx("__ResetBHOP", 5500, false, "ii", playerid, g_BHOP[playerid]);
        }
    }

    if(PRESSED(KEY_NO) && !pData[playerid][pInjured])
    {
        if(TDInfo[playerid][InvTDShown])
            Hide_InvTD(playerid);
        else
            Show_InvTD(playerid);
    }
    return 1;
}
