new Text:InjuryTD[19];
new Text:DyingTD[1];
new PlayerText:InjuryPTD[MAX_PLAYERS][3];

Create_InjuryTD()
{
    InjuryTD[0] = TextDrawCreate(-200.000, 300.000, "PARTICLE:lamp_shad_64");
    TextDrawTextSize(InjuryTD[0], 1000.000, 150.000);
    TextDrawAlignment(InjuryTD[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[0], -16776961);
    TextDrawSetShadow(InjuryTD[0], 0);
    TextDrawSetOutline(InjuryTD[0], 0);
    TextDrawBackgroundColour(InjuryTD[0], 255);
    TextDrawFont(InjuryTD[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[0], true);

    InjuryTD[1] = TextDrawCreate(-200.000, 139.000, "PARTICLE:lamp_shad_64");
    TextDrawTextSize(InjuryTD[1], 1000.000, -150.000);
    TextDrawAlignment(InjuryTD[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[1], -16776961);
    TextDrawSetShadow(InjuryTD[1], 0);
    TextDrawSetOutline(InjuryTD[1], 0);
    TextDrawBackgroundColour(InjuryTD[1], 255);
    TextDrawFont(InjuryTD[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[1], true);

    InjuryTD[2] = TextDrawCreate(500.000, 54.000, "PARTICLE:lamp_shad_64");
    TextDrawTextSize(InjuryTD[2], 300.000, 400.000);
    TextDrawAlignment(InjuryTD[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[2], -16776961);
    TextDrawSetShadow(InjuryTD[2], 0);
    TextDrawSetOutline(InjuryTD[2], 0);
    TextDrawBackgroundColour(InjuryTD[2], 255);
    TextDrawFont(InjuryTD[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[2], true);

    InjuryTD[3] = TextDrawCreate(500.000, 387.000, "PARTICLE:lamp_shad_64");
    TextDrawTextSize(InjuryTD[3], 300.000, -400.000);
    TextDrawAlignment(InjuryTD[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[3], -16776961);
    TextDrawSetShadow(InjuryTD[3], 0);
    TextDrawSetOutline(InjuryTD[3], 0);
    TextDrawBackgroundColour(InjuryTD[3], 255);
    TextDrawFont(InjuryTD[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[3], true);

    InjuryTD[4] = TextDrawCreate(-160.000, 54.000, "PARTICLE:lamp_shad_64");
    TextDrawTextSize(InjuryTD[4], 300.000, 400.000);
    TextDrawAlignment(InjuryTD[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[4], -16776961);
    TextDrawSetShadow(InjuryTD[4], 0);
    TextDrawSetOutline(InjuryTD[4], 0);
    TextDrawBackgroundColour(InjuryTD[4], 255);
    TextDrawFont(InjuryTD[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[4], true);

    InjuryTD[5] = TextDrawCreate(-160.000, 387.000, "PARTICLE:lamp_shad_64");
    TextDrawTextSize(InjuryTD[5], 300.000, -400.000);
    TextDrawAlignment(InjuryTD[5], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[5], -16776961);
    TextDrawSetShadow(InjuryTD[5], 0);
    TextDrawSetOutline(InjuryTD[5], 0);
    TextDrawBackgroundColour(InjuryTD[5], 255);
    TextDrawFont(InjuryTD[5], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[5], true);

    InjuryTD[6] = TextDrawCreate(0.000, 0.000, "LD_SPAC:white");
    TextDrawTextSize(InjuryTD[6], 640.000, 450.000);
    TextDrawAlignment(InjuryTD[6], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[6], -16777086);
    TextDrawSetShadow(InjuryTD[6], 0);
    TextDrawSetOutline(InjuryTD[6], 0);
    TextDrawBackgroundColour(InjuryTD[6], 255);
    TextDrawFont(InjuryTD[6], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[6], true);

    InjuryTD[7] = TextDrawCreate(-103.000, 49.000, "PARTICLE:lamp_shad_64");
    TextDrawTextSize(InjuryTD[7], 869.000, 411.000);
    TextDrawAlignment(InjuryTD[7], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[7], -16776961);
    TextDrawSetShadow(InjuryTD[7], 0);
    TextDrawSetOutline(InjuryTD[7], 0);
    TextDrawBackgroundColour(InjuryTD[7], 255);
    TextDrawFont(InjuryTD[7], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[7], true);

    InjuryTD[8] = TextDrawCreate(-87.000, 187.000, "PARTICLE:lamp_shad_64");
    TextDrawTextSize(InjuryTD[8], 877.000, -250.000);
    TextDrawAlignment(InjuryTD[8], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[8], -16776961);
    TextDrawSetShadow(InjuryTD[8], 0);
    TextDrawSetOutline(InjuryTD[8], 0);
    TextDrawBackgroundColour(InjuryTD[8], 255);
    TextDrawFont(InjuryTD[8], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[8], true);

    InjuryTD[9] = TextDrawCreate(315.000, 142.000, "KAMU SEDANG PINGSAN");
    TextDrawLetterSize(InjuryTD[9], 0.459, 2.099);
    TextDrawAlignment(InjuryTD[9], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(InjuryTD[9], -1);
    TextDrawSetShadow(InjuryTD[9], 0);
    TextDrawSetOutline(InjuryTD[9], 0);
    TextDrawBackgroundColour(InjuryTD[9], 150);
    TextDrawFont(InjuryTD[9], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(InjuryTD[9], true);

    InjuryTD[10] = TextDrawCreate(335.000, 338.000, "LD_SPAC:white");
    TextDrawTextSize(InjuryTD[10], 21.000, 20.000);
    TextDrawAlignment(InjuryTD[10], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[10], -1);
    TextDrawSetShadow(InjuryTD[10], 0);
    TextDrawSetOutline(InjuryTD[10], 0);
    TextDrawBackgroundColour(InjuryTD[10], 255);
    TextDrawFont(InjuryTD[10], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[10], true);

    InjuryTD[11] = TextDrawCreate(304.000, 338.000, "LD_SPAC:white");
    TextDrawTextSize(InjuryTD[11], 21.000, 20.000);
    TextDrawAlignment(InjuryTD[11], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[11], -1);
    TextDrawSetShadow(InjuryTD[11], 0);
    TextDrawSetOutline(InjuryTD[11], 0);
    TextDrawBackgroundColour(InjuryTD[11], 255);
    TextDrawFont(InjuryTD[11], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[11], true);

    InjuryTD[12] = TextDrawCreate(273.000, 338.000, "LD_SPAC:white");
    TextDrawTextSize(InjuryTD[12], 21.000, 20.000);
    TextDrawAlignment(InjuryTD[12], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[12], -1);
    TextDrawSetShadow(InjuryTD[12], 0);
    TextDrawSetOutline(InjuryTD[12], 0);
    TextDrawBackgroundColour(InjuryTD[12], 255);
    TextDrawFont(InjuryTD[12], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InjuryTD[12], true);

    InjuryTD[13] = TextDrawCreate(297.000, 338.000, ":       :");
    TextDrawLetterSize(InjuryTD[13], 0.428, 2.098);
    TextDrawAlignment(InjuryTD[13], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InjuryTD[13], -1);
    TextDrawSetShadow(InjuryTD[13], 0);
    TextDrawSetOutline(InjuryTD[13], 0);
    TextDrawBackgroundColour(InjuryTD[13], 150);
    TextDrawFont(InjuryTD[13], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(InjuryTD[13], true);

    InjuryTD[14] = TextDrawCreate(315.000, 248.000, "Tekan [Y] Untuk Accept Death (Dalam beberapa skenario anda akan terkena koma)");
    TextDrawLetterSize(InjuryTD[14], 0.250, 1.199);
    TextDrawTextSize(InjuryTD[14], 80.000, 186.000);
    TextDrawAlignment(InjuryTD[14], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(InjuryTD[14], -1);
    TextDrawSetShadow(InjuryTD[14], 0);
    TextDrawSetOutline(InjuryTD[14], 0);
    TextDrawBackgroundColour(InjuryTD[14], 150);
    TextDrawFont(InjuryTD[14], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(InjuryTD[14], true);

    InjuryTD[15] = TextDrawCreate(315.000, 270.000, "Tekan [N] Untuk mengirim signal kepada Paramedis");
    TextDrawLetterSize(InjuryTD[15], 0.250, 1.199);
    TextDrawTextSize(InjuryTD[15], 80.000, 186.000);
    TextDrawAlignment(InjuryTD[15], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(InjuryTD[15], -1);
    TextDrawSetShadow(InjuryTD[15], 0);
    TextDrawSetOutline(InjuryTD[15], 0);
    TextDrawBackgroundColour(InjuryTD[15], 150);
    TextDrawFont(InjuryTD[15], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(InjuryTD[15], true);

    InjuryTD[16] = TextDrawCreate(315.000, 316.000, "Kamu akan kehabisan darah dalam waktu:");
    TextDrawLetterSize(InjuryTD[16], 0.250, 1.599);
    TextDrawTextSize(InjuryTD[16], 80.000, 186.000);
    TextDrawAlignment(InjuryTD[16], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(InjuryTD[16], -1);
    TextDrawSetShadow(InjuryTD[16], 0);
    TextDrawSetOutline(InjuryTD[16], 0);
    TextDrawBackgroundColour(InjuryTD[16], 150);
    TextDrawFont(InjuryTD[16], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(InjuryTD[16], true);

    InjuryTD[17] = TextDrawCreate(260.000, 248.000, "[Y]");
    TextDrawLetterSize(InjuryTD[17], 0.250, 1.199);
    TextDrawTextSize(InjuryTD[17], 80.000, 186.000);
    TextDrawAlignment(InjuryTD[17], TEXT_DRAW_ALIGN_RIGHT);
    TextDrawColour(InjuryTD[17], 8388863);
    TextDrawSetShadow(InjuryTD[17], 0);
    TextDrawSetOutline(InjuryTD[17], 0);
    TextDrawBackgroundColour(InjuryTD[17], 150);
    TextDrawFont(InjuryTD[17], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(InjuryTD[17], true);

    InjuryTD[18] = TextDrawCreate(274.000, 270.000, "[N]");
    TextDrawLetterSize(InjuryTD[18], 0.260, 1.199);
    TextDrawTextSize(InjuryTD[18], 80.000, 186.000);
    TextDrawAlignment(InjuryTD[18], TEXT_DRAW_ALIGN_RIGHT);
    TextDrawColour(InjuryTD[18], 8388863);
    TextDrawSetShadow(InjuryTD[18], 0);
    TextDrawSetOutline(InjuryTD[18], 0);
    TextDrawBackgroundColour(InjuryTD[18], 150);
    TextDrawFont(InjuryTD[18], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(InjuryTD[18], true);

    DyingTD[0] = TextDrawCreate(0.000, 0.000, "LD_SPAC:white");
    TextDrawTextSize(DyingTD[0], 640.000, 450.000);
    TextDrawAlignment(DyingTD[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(DyingTD[0], -16777116);
    TextDrawSetShadow(DyingTD[0], 0);
    TextDrawSetOutline(DyingTD[0], 0);
    TextDrawBackgroundColour(DyingTD[0], 255);
    TextDrawFont(DyingTD[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(DyingTD[0], true);

    return 1;
}

Create_InjuryPTD(playerid)
{
    InjuryPTD[playerid][0] = CreatePlayerTextDraw(playerid, 346.000, 338.000, "00");
    PlayerTextDrawLetterSize(playerid, InjuryPTD[playerid][0], 0.458, 2.098);
    PlayerTextDrawAlignment(playerid, InjuryPTD[playerid][0], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, InjuryPTD[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, InjuryPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InjuryPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, InjuryPTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, InjuryPTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InjuryPTD[playerid][0], true);

    InjuryPTD[playerid][1] = CreatePlayerTextDraw(playerid, 315.000, 338.000, "00");
    PlayerTextDrawLetterSize(playerid, InjuryPTD[playerid][1], 0.458, 2.098);
    PlayerTextDrawAlignment(playerid, InjuryPTD[playerid][1], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, InjuryPTD[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, InjuryPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InjuryPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, InjuryPTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, InjuryPTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InjuryPTD[playerid][1], true);

    InjuryPTD[playerid][2] = CreatePlayerTextDraw(playerid, 283.899, 338.000, "00");
    PlayerTextDrawLetterSize(playerid, InjuryPTD[playerid][2], 0.458, 2.098);
    PlayerTextDrawAlignment(playerid, InjuryPTD[playerid][2], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, InjuryPTD[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, InjuryPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InjuryPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, InjuryPTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, InjuryPTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InjuryPTD[playerid][2], true);

    return 1;
}

Destroy_InjuryPTD(playerid)
{
    for(new i = 0; i < 3; i++)
    {
        PlayerTextDrawDestroy(playerid, InjuryPTD[playerid][i]);
        InjuryPTD[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
    }
    return 1;
}

stock Show_InjuryTD(playerid)
{
    for(new i = 0; i < 19; i++)
    {
        TextDrawShowForPlayer(playerid, InjuryTD[i]);

        if(i < 3)
            PlayerTextDrawShow(playerid, InjuryPTD[playerid][i]);
    }
    TDInfo[playerid][InjuryTDShown] = true;
    return 1;
}

stock Hide_InjuryTD(playerid)
{
    for(new i = 0; i < 19; i++)
    {
        TextDrawHideForPlayer(playerid, InjuryTD[i]);

        if(i < 3)
            PlayerTextDrawHide(playerid, InjuryPTD[playerid][i]);
    }
    TDInfo[playerid][InjuryTDShown] = false;
    return 1;
}

stock Show_DyingTD(playerid)
{
    for(new i = 0; i < 6; i++)
    {
        TextDrawShowForPlayer(playerid, InjuryTD[i]);
    }
    TextDrawShowForPlayer(playerid, DyingTD[0]);
    TDInfo[playerid][DyingTDShown] = true;
    return 1;
}

stock Hide_DyingTD(playerid)
{
    for(new i = 0; i < 6; i++)
    {
        TextDrawHideForPlayer(playerid, InjuryTD[i]);
    }
    TextDrawHideForPlayer(playerid, DyingTD[0]);
    TDInfo[playerid][DyingTDShown] = false;
    return 1;
}
