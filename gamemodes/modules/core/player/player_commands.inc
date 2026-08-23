YCMD:pay(playerid, params[], help)
{
    new targetid, moneyStr[44], Float:POS[3];

    if(sscanf(params, "ds[44]", targetid, moneyStr))
        return SendClientMessage(playerid, -1, "SYNTAX: /pay <playerid> <amount-of-money>");

    if(targetid == playerid)
        return SendClientMessage(playerid, -1, "ERROR: Kamu tidak dapat memberikan uang kepada diri sendiri.");
    
    if(!IsPlayerConnected(targetid) || !pData[targetid][pLoggedIn] || !pData[targetid][pSpawned])
        return SendClientMessage(playerid, -1, "ERROR: Pemain dengan id tersebut tidak terkoneksi ke server atau belum spawn");

    GetPlayerPos(playerid, POS[0], POS[1], POS[2]);
    if(!IsPlayerInRangeOfPoint(playerid, 3.5, POS[0], POS[1], POS[2]))
        return SendClientMessage(playerid, -1, "ERROR: Pemain tersebut berada terlalu jauh dengan karakter anda.");

    if(!IsRupiahFormat(moneyStr))
        return SendClientMessage(playerid, -1, "ERROR: Format Uang tidak valid, contoh format yang valid: {00FF00}1000 10,50 0,05 10.000");

    new money = ReturnRupiahToInteger(moneyStr);

    if(money < 1)  
        return SendClientMessage(playerid, -1, "ERROR: Jumlah uang yang akan diberikan tidak valid, jumlah valid adalah 0.01 s/d 3000");

    if(pData[playerid][pAdminLevel] > 0)
    {
        if(money > 5000000)
            return SendClientMessage(playerid, -1, "ERROR: Admin tidak dapat memberikan uang dalam satu waktu melebihi batas yang sudah ditentukan server (50.000).");
    }
    else if(money > 300000)
        return SendClientMessage(playerid, -1, "ERROR: Jumlah uang yang akan diberikan tidak valid, jumlah valid adalah 0.01 s/d 3000");

    GivePlayerMoneyEx(playerid, -money);
    GivePlayerMoneyEx(targetid, money);

    foreach(new i : Player)
    {
        if(pData[i][pAdminLevel] > 0)
            SendClientMessage(i, Y_YELLOW, "PAY: %s(%d) memberikan uang kepada %s(%d) sebanyak %d.", pData[playerid][pName], playerid, pData[targetid][pName], targetid, FormatRupiah(money));
    }

    SendClientMessage(targetid, -1, "INFO: Anda berhasil memberi uang sejumlah {00FF00}%s{FFFFFF} kepada %s(%d).", FormatRupiah(money), pData[targetid][pName], targetid);
    SendClientMessage(targetid, -1, "INFO: %s(%d) telah memberi uang sejumlah {00FF00}%s{FFFFFF} kepada anda.", pData[playerid][pName], playerid, FormatRupiah(money));
    return 1;
}

YCMD:stats(playerid, params[], help)
{
    ShowPlayerStats(playerid, playerid);
    return 1;
}

YCMD:i(playerid, params[], help)
{
    if(TDInfo[playerid][InvTDShown])
        Hide_InvTD(playerid);
    else
        Show_InvTD(playerid);
    return 1;
}

YCMD:cc(playerid, params[], help)
{
    for(new i = 0; i < 50; i++)
    {
        SendClientMessage(playerid, -1, "\n");
    }
    return 1;
}
