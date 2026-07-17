/*
YCMD:ttd1(playerid, params[], help)
{
    PlayerTextDrawShow(playerid, InvPage[playerid][0]);
    return 1;
}

YCMD:ttd2(playerid, params[], help)
{
    PlayerTextDrawShow(playerid, InvPage[playerid][1]);
    return 1;
}

YCMD:ttd3(playerid, params[], help)
{
    PlayerTextDrawShow(playerid, ContainerPage[playerid][0]);
    return 1;
}

YCMD:ttd4(playerid, params[], help)
{
    PlayerTextDrawShow(playerid, ContainerPage[playerid][1]);
    return 1;
}

YCMD:ttdc(playerid, params[], help)
{
    PlayerTextDrawHide(playerid, InvPage[playerid][0]);
    PlayerTextDrawHide(playerid, InvPage[playerid][1]);
    PlayerTextDrawHide(playerid, ContainerPage[playerid][0]);
    PlayerTextDrawHide(playerid, ContainerPage[playerid][1]);
    return 1;
}

YCMD:tests(playerid, params[], help)
{
    // Loop Textdraw HBE
    for(new x = 0; x < 12; x++)
    {
        printf("HBETD[%d] ID: %d", x, HBETD[x]);
    }
    for(new x = 0; x < 5; x++)
    {
        printf("HBEPTD[%d] ID: %d", x, HBEPTD[playerid][x]);
    }

    // Loop Textdraw Dying & Injury
    for(new x = 0; x < 19; x++)
    {
        printf("InjuryTD[%d] ID: %d", x, InjuryTD[x]);
    }
    printf("DyingTD[0] ID: %d", DyingTD[0]);
    for(new x = 0; x < 3; x++)
    {
        printf("InjuryPTD[%d] ID: %d", x, InjuryPTD[playerid][x]);
    }

    // Loop Textdraw Inventory
    for(new x = 0; x < 35; x++)
    {
        printf("BaseInvTD[%d] ID: %d", x, BaseInvTD[x]);
    }
    for(new x = 0; x < 20; x++)
    {
        printf("InvSlot[%d] ID: %d", x, InvSlot[x]);
    }
    for(new x = 0; x < 20; x++)
    {
        printf("ContainerSlot[%d] ID: %d", x, ContainerSlot[x]);
    }
    for(new x = 0; x < 5; x++)
    {
        printf("Button[%d] ID: %d", x, Button[x]);
    }
    for(new x = 0; x < 4; x++)
    {
        printf("ExtraButton[%d] ID: %d", x, ExtraButton[x]);
    }
    for(new x = 0; x < 2; x++)
    {
        printf("InvPage[%d] ID: %d", x, InvPage[playerid][x]);
    }
    for(new x = 0; x < 20; x++)
    {
        printf("InvPrevModel[%d] ID: %d", x, InvPrevModel[playerid][x]);
    }
    for(new x = 0; x < 20; x++)
    {
        printf("InvItemName[%d] ID: %d", x, InvItemName[playerid][x]);
    }
    for(new x = 0; x < 20; x++)
    {
        printf("InvItemAmount[%d] ID: %d", x, InvItemAmount[playerid][x]);
    }
    printf("InvPlayerName ID: %d", InvPlayerName[playerid]);
    printf("InvWeightBar ID: %d", InvWeightBar[playerid]);
    printf("InvWeightText ID: %d", InvWeightText[playerid]);
    printf("InvPageText ID: %d", InvPageText[playerid]);
    for(new x = 0; x < 2; x++)
    {
        printf("ContainerPage[%d] ID: %d", x, ContainerPage[playerid][x]);
    }
    for(new x = 0; x < 20; x++)
    {
        printf("ContainerPrevModel[%d] ID: %d", x, ContainerPrevModel[playerid][x]);
    }
    for(new x = 0; x < 20; x++)
    {
        printf("ContainerItemName[%d] ID: %d", x, ContainerItemName[playerid][x]);
    }
    for(new x = 0; x < 20; x++)
    {
        printf("ContainerItemAmount[%d] ID: %d", x, ContainerItemAmount[playerid][x]);
    }
    printf("ContainerTitle ID: %d", ContainerTitle[playerid]);
    printf("ContainerWeightBar ID: %d", ContainerWeightBar[playerid]);
    printf("ContainerWeightText ID: %d", ContainerWeightText[playerid]);
    printf("ContainerPageText ID: %d", ContainerPageText[playerid]);
    for(new x = 0; x < 3; x++)
    {
        printf("ContainerModeText[%d] ID: %d", x, ContainerModeText[playerid][x]);
    }
    printf("AmountTD ID: %d", AmountTD[playerid]);
    return 1;
}*/

YCMD:tests(playerid, params[], help)
{
    for(new i; i < 20; i++)
    {
        debugmsg(playerid, sprintf("InvSlotID: %d", InvSlotTD[i]));
    }
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

    Dialog_Show(playerid, "Message", DIALOG_STYLE_MSGBOX, "Vantara Roleplay - Self Variables", str, "Close", "");

    return 1;
}

new actortarget[2] = STREAMER_TAG_ACTOR:INVALID_STREAMER_ID;
YCMD:target(playerid, params[], help)
{
    for(new x = 0; x < sizeof(actortarget); x++)
    {
        if(actortarget[x] == STREAMER_TAG_ACTOR:INVALID_STREAMER_ID)
        {
            new Float:POS[4];
            GetPlayerPos(playerid, POS[0], POS[1], POS[2]);
            GetPlayerFacingAngle(playerid, POS[3]);
            actortarget[x] = CreateDynamicActor(pData[playerid][pSkin], POS[0], POS[1], POS[2], POS[3]);
            break;
        }
    }
    return 1;
}

YCMD:dtarget(playerid, params[], help)
{
    for(new x = 0; x < sizeof(actortarget); x++)
    {
        if(DestroyDynamicActor(actortarget[x]))
            actortarget[x] = STREAMER_TAG_ACTOR:INVALID_STREAMER_ID;
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