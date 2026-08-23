new floodtest[MAX_PLAYERS];
YCMD:ftest(playerid, params[], help)
{
    if(Flood_Check(floodtest[playerid], 1000)) 
        return SendClientMessage(playerid, -1, "Jangan Spam");
    
    SendClientMessage(playerid, -1, "Oke, aman");
    return 1;
}

YCMD:testrupiah(playerid, params[], help)
{
    if(isnull(params))
    {
        SendClientMessage(playerid, -1,
            "SYNTAX: /testrupiah <rupiah-format>");
        return 1;
    }

    SendClientMessage(playerid, -1, "Input: \"%s\" | Valid: %s", params, IsRupiahFormat(params) ? ("YA") : ("TIDAK"));

    if(!IsRupiahFormat(params))
        return 1;

    new money = ReturnRupiahToInteger(params);

    SendClientMessage(playerid, -1, "Integer: %d", money);
    SendClientMessage(playerid, -1, "Format ulang: %s", FormatRupiah(money));
    return 1;
}

YCMD:myvar(playerid, params[], help)
{
    if(help)
    {
        SendClientMessage(playerid, -1, "Menampilkan semua data variabel player.");
        return 1;
    }

    new str[1024];

    format(str, sizeof(str),
        "Player ID: %d\nAccount ID: %d\nSpawned: %d\nLoggedIn: %d\n\n\
        Name: %s\nUCP: %s\nAdmin Level: %d\nAdmin Name: %s\n\n\
        Money: %d\nBank Money: %d\nLevel: %d\nDrunk: %d\n\n\
        Health: %.2f\nArmour: %.2f\n\n\
        Skin: %d\nDOB: %s\nGender: %d\nHeight: %d\nWeight: %d\n\n\
        Origin: %d\nDomicile: %d\n\n\
        Pos: %.2f %.2f %.2f %.2f\nInterior: %d VW: %d\n\n\
        Hunger: %.2f Thirst: %.2f Stress: %.2f\n",
        pData[playerid][pID],
        pData[playerid][pAccountID],
        pData[playerid][pSpawned],
        pData[playerid][pLoggedIn],

        pData[playerid][pName],
        pData[playerid][pUCP],
        pData[playerid][pAdminLevel],
        pData[playerid][pAdminName],

        pData[playerid][pMoney],
        pData[playerid][pBankMoney],
        pData[playerid][pLevel],
        pData[playerid][pDrunkLevel],

        pData[playerid][pHealth],
        pData[playerid][pArmour],

        pData[playerid][pSkin],
        pData[playerid][pDOB],
        pData[playerid][pGender],
        pData[playerid][pHeight],
        pData[playerid][pWeight],

        pData[playerid][pOrigin],
        pData[playerid][pDomicile],

        pData[playerid][pPosX],
        pData[playerid][pPosY],
        pData[playerid][pPosZ],
        pData[playerid][pPosA],

        pData[playerid][pInterior],
        pData[playerid][pVirtualWorld],

        pData[playerid][pHunger],
        pData[playerid][pThirst],
        pData[playerid][pStress]
    );

    Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Self Variables", str, "Close", "");

    return 1;
}

static s_actortarget[2] = STREAMER_TAG_ACTOR:INVALID_STREAMER_ID;
YCMD:target(playerid, params[], help)
{
    for(new x = 0; x < sizeof(s_actortarget); x++)
    {
        if(s_actortarget[x] == STREAMER_TAG_ACTOR:INVALID_STREAMER_ID)
        {
            new Float:POS[4];
            GetPlayerPos(playerid, POS[0], POS[1], POS[2]);
            GetPlayerFacingAngle(playerid, POS[3]);
            s_actortarget[x] = CreateDynamicActor(pData[playerid][pSkin], POS[0], POS[1], POS[2], POS[3]);
            break;
        }
    }
    return 1;
}

YCMD:dtarget(playerid, params[], help)
{
    for(new x = 0; x < sizeof(s_actortarget); x++)
    {
        if(DestroyDynamicActor(s_actortarget[x]))
            s_actortarget[x] = STREAMER_TAG_ACTOR:INVALID_STREAMER_ID;
    }
    return 1;
}

YCMD:wtest(playerid, params[], help)
{
    new
        weapid,
        ammo;

    if(sscanf(params, "dd", weapid, ammo))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "SYNTAX: "F_COLOR_WHITE"/wtest <weaponid> <ammo>");

    if((weapid < 1 || weapid > 46) || (weapid < 22 && weapid > 18))
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"ID Senjata tidak valid.");

    if(ammo < 1 || ammo > 50000)
        return SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Jumlah peluru tidak dapat kurang dari 1 atau lebih dari 50.000.");
    
    GivePlayerWeapon(playerid, WEAPON:weapid, ammo);
    return 1;
}

static s_pickup[2] = STREAMER_TAG_PICKUP:INVALID_STREAMER_ID;
YCMD:pickup(playerid, params[], help)
{
    for(new x = 0; x < sizeof(s_pickup); x++)
    {
        if(s_pickup[x] == STREAMER_TAG_PICKUP:INVALID_STREAMER_ID)
        {
            new Float:POS[3];
            GetPlayerPos(playerid, POS[0], POS[1], POS[2]);
            if(!isnull(params))
                POS[2] += strval(params);
            s_pickup[x] = CreateDynamicPickup(1317, 2, POS[0], POS[1], POS[2], 0, 0, -1, 15.0);
            break;
        }
    }
    return 1;
}

YCMD:dpickup(playerid, params[], help)
{
    for(new x = 0; x < sizeof(s_pickup); x++)
    {
        if(DestroyDynamicPickup(s_pickup[x]))
            s_pickup[x] = STREAMER_TAG_ACTOR:INVALID_STREAMER_ID;
    }
    return 1;
}