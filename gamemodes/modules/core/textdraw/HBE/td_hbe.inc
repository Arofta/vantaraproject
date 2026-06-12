new Text:HBETD[12];
new PlayerText:HBEPTD[MAX_PLAYERS][5];

/*
    0: Hunger
    1: Thirst
    2: Stress
    3: Radio
    4: Microphone
*/
Create_HBETD()
{
    HBETD[0] = TextDrawCreate(300.000, 412.000, "LD_BEAT:chit");
    TextDrawTextSize(HBETD[0], 32.000, 38.000);
    TextDrawAlignment(HBETD[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[0], 12582761);
    TextDrawSetShadow(HBETD[0], 0);
    TextDrawSetOutline(HBETD[0], 0);
    TextDrawBackgroundColour(HBETD[0], 255);
    TextDrawFont(HBETD[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(HBETD[0], true);

    HBETD[1] = TextDrawCreate(274.000, 412.000, "LD_BEAT:chit");
    TextDrawTextSize(HBETD[1], 32.000, 38.000);
    TextDrawAlignment(HBETD[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[1], -7602071);
    TextDrawSetShadow(HBETD[1], 0);
    TextDrawSetOutline(HBETD[1], 0);
    TextDrawBackgroundColour(HBETD[1], 255);
    TextDrawFont(HBETD[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(HBETD[1], true);

    HBETD[2] = TextDrawCreate(326.000, 412.000, "LD_BEAT:chit");
    TextDrawTextSize(HBETD[2], 32.000, 38.000);
    TextDrawAlignment(HBETD[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[2], -16777111);
    TextDrawSetShadow(HBETD[2], 0);
    TextDrawSetOutline(HBETD[2], 0);
    TextDrawBackgroundColour(HBETD[2], 255);
    TextDrawFont(HBETD[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(HBETD[2], true);

    HBETD[3] = TextDrawCreate(283.500, 423.000, "HUD:radar_burgerShot");
    TextDrawTextSize(HBETD[3], 13.000, 15.000);
    TextDrawAlignment(HBETD[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[3], -1);
    TextDrawSetShadow(HBETD[3], 0);
    TextDrawSetOutline(HBETD[3], 0);
    TextDrawBackgroundColour(HBETD[3], 255);
    TextDrawFont(HBETD[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(HBETD[3], true);

    HBETD[4] = TextDrawCreate(309.500, 423.000, "HUD:radar_centre");
    TextDrawTextSize(HBETD[4], 13.000, 15.000);
    TextDrawAlignment(HBETD[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[4], -1);
    TextDrawSetShadow(HBETD[4], 0);
    TextDrawSetOutline(HBETD[4], 0);
    TextDrawBackgroundColour(HBETD[4], 255);
    TextDrawFont(HBETD[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(HBETD[4], true);

    HBETD[5] = TextDrawCreate(333.000, 421.000, "HUD:radar_light");
    TextDrawTextSize(HBETD[5], 18.000, 20.000);
    TextDrawAlignment(HBETD[5], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[5], -1962934017);
    TextDrawSetShadow(HBETD[5], 0);
    TextDrawSetOutline(HBETD[5], 0);
    TextDrawBackgroundColour(HBETD[5], 255);
    TextDrawFont(HBETD[5], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(HBETD[5], true);

    HBETD[6] = TextDrawCreate(-2.000, 412.000, "LD_BEAT:chit");
    TextDrawTextSize(HBETD[6], 32.000, 38.000);
    TextDrawAlignment(HBETD[6], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[6], -151);
    TextDrawSetShadow(HBETD[6], 0);
    TextDrawSetOutline(HBETD[6], 0);
    TextDrawBackgroundColour(HBETD[6], 255);
    TextDrawFont(HBETD[6], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(HBETD[6], true);

    HBETD[7] = TextDrawCreate(66.000, 412.000, "LD_BEAT:chit");
    TextDrawTextSize(HBETD[7], 32.000, 38.000);
    TextDrawAlignment(HBETD[7], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[7], -151);
    TextDrawSetShadow(HBETD[7], 0);
    TextDrawSetOutline(HBETD[7], 0);
    TextDrawBackgroundColour(HBETD[7], 255);
    TextDrawFont(HBETD[7], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(HBETD[7], true);

    HBETD[8] = TextDrawCreate(27.000, 420.000, "Microphone");
    TextDrawLetterSize(HBETD[8], 0.210, 0.999);
    TextDrawAlignment(HBETD[8], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[8], -1);
    TextDrawSetShadow(HBETD[8], 0);
    TextDrawSetOutline(HBETD[8], 0);
    TextDrawBackgroundColour(HBETD[8], 150);
    TextDrawFont(HBETD[8], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(HBETD[8], true);

    HBETD[9] = TextDrawCreate(94.500, 420.000, "Radio");
    TextDrawLetterSize(HBETD[9], 0.210, 0.999);
    TextDrawAlignment(HBETD[9], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[9], -1);
    TextDrawSetShadow(HBETD[9], 0);
    TextDrawSetOutline(HBETD[9], 0);
    TextDrawBackgroundColour(HBETD[9], 150);
    TextDrawFont(HBETD[9], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(HBETD[9], true);

    HBETD[10] = TextDrawCreate(75.500, 423.000, "HUD:radar_RYDER");
    TextDrawTextSize(HBETD[10], 13.000, 15.000);
    TextDrawAlignment(HBETD[10], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[10], -1);
    TextDrawSetShadow(HBETD[10], 0);
    TextDrawSetOutline(HBETD[10], 0);
    TextDrawBackgroundColour(HBETD[10], 255);
    TextDrawFont(HBETD[10], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(HBETD[10], true);

    HBETD[11] = TextDrawCreate(8.000, 423.399, "HUD:radar_MCSTRAP");
    TextDrawTextSize(HBETD[11], 13.000, 15.000);
    TextDrawAlignment(HBETD[11], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(HBETD[11], -1);
    TextDrawSetShadow(HBETD[11], 0);
    TextDrawSetOutline(HBETD[11], 0);
    TextDrawBackgroundColour(HBETD[11], 255);
    TextDrawFont(HBETD[11], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(HBETD[11], true);

    return 1;
}

Create_HBEPTD(playerid)
{
    HBEPTD[playerid][0] = CreatePlayerTextDraw(playerid, 290.000, 437.000, "100");
    PlayerTextDrawLetterSize(playerid, HBEPTD[playerid][0], 0.280, 0.999);
    PlayerTextDrawAlignment(playerid, HBEPTD[playerid][0], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, HBEPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, HBEPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, HBEPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, HBEPTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, HBEPTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, HBEPTD[playerid][0], true);

    HBEPTD[playerid][1] = CreatePlayerTextDraw(playerid, 315.700, 437.000, "100");
    PlayerTextDrawLetterSize(playerid, HBEPTD[playerid][1], 0.280, 0.999);
    PlayerTextDrawAlignment(playerid, HBEPTD[playerid][1], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, HBEPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, HBEPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, HBEPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, HBEPTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, HBEPTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, HBEPTD[playerid][1], true);

    HBEPTD[playerid][2] = CreatePlayerTextDraw(playerid, 341.500, 437.000, "100");
    PlayerTextDrawLetterSize(playerid, HBEPTD[playerid][2], 0.280, 0.999);
    PlayerTextDrawAlignment(playerid, HBEPTD[playerid][2], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, HBEPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, HBEPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, HBEPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, HBEPTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, HBEPTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, HBEPTD[playerid][2], true);

    HBEPTD[playerid][3] = CreatePlayerTextDraw(playerid, 94.500, 429.000, "~g~on");
    PlayerTextDrawLetterSize(playerid, HBEPTD[playerid][3], 0.210, 0.999);
    PlayerTextDrawAlignment(playerid, HBEPTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HBEPTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, HBEPTD[playerid][3], 1);
    PlayerTextDrawSetOutline(playerid, HBEPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, HBEPTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, HBEPTD[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, HBEPTD[playerid][3], true);

    HBEPTD[playerid][4] = CreatePlayerTextDraw(playerid, 27.000, 429.000, "~b~normal");
    PlayerTextDrawLetterSize(playerid, HBEPTD[playerid][4], 0.210, 0.999);
    PlayerTextDrawAlignment(playerid, HBEPTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, HBEPTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, HBEPTD[playerid][4], 1);
    PlayerTextDrawSetOutline(playerid, HBEPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, HBEPTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, HBEPTD[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, HBEPTD[playerid][4], true);

    return 1;
}

Destroy_HBEPTD(playerid)
{
    for(new i = 0; i < 5; i++)
    {
        PlayerTextDrawDestroy(playerid, HBEPTD[playerid][i]);
        HBEPTD[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
    return 1;
}

stock Show_HBETD(playerid)
{
    for(new i = 0; i < 12; i++)
    {
        if(i < 5)
            PlayerTextDrawShow(playerid, HBEPTD[playerid][i]);

        TextDrawShowForPlayer(playerid, HBETD[i]);
    }
    return 1;
}

stock Hide_HBETD(playerid)
{
    for(new i = 0; i < 12; i++)
    {
        if(i < 5)
            PlayerTextDrawHide(playerid, HBEPTD[playerid][i]);

        TextDrawHideForPlayer(playerid, HBETD[i]);
    }
    return 1;
}


