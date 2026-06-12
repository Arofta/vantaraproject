
YCMD:myvar(playerid, params[], help)
{
    if (help)
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