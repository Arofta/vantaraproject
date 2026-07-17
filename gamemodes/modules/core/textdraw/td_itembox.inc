new Text: ItemBoxTD[10];
new PlayerText: Model_ItemBoxPTD[MAX_PLAYERS][5];
new PlayerText: Title_ItemBoxPTD[MAX_PLAYERS][5];
new PlayerText: Name_ItemBoxPTD[MAX_PLAYERS][5];

Create_ItemBoxTD()
{
    ItemBoxTD[0] = TextDrawCreate(293.000, 365.000, "LD_SPAC:white");
    TextDrawTextSize(ItemBoxTD[0], 38.000, 3.000);
    TextDrawAlignment(ItemBoxTD[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ItemBoxTD[0], -2686721);
    TextDrawSetShadow(ItemBoxTD[0], 0);
    TextDrawSetOutline(ItemBoxTD[0], 0);
    TextDrawBackgroundColour(ItemBoxTD[0], 255);
    TextDrawFont(ItemBoxTD[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ItemBoxTD[0], true);

    ItemBoxTD[1] = TextDrawCreate(333.000, 365.000, "LD_SPAC:white");
    TextDrawTextSize(ItemBoxTD[1], 38.000, 3.000);
    TextDrawAlignment(ItemBoxTD[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ItemBoxTD[1], -2686721);
    TextDrawSetShadow(ItemBoxTD[1], 0);
    TextDrawSetOutline(ItemBoxTD[1], 0);
    TextDrawBackgroundColour(ItemBoxTD[1], 255);
    TextDrawFont(ItemBoxTD[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ItemBoxTD[1], true);

    ItemBoxTD[2] = TextDrawCreate(373.000, 365.000, "LD_SPAC:white");
    TextDrawTextSize(ItemBoxTD[2], 38.000, 3.000);
    TextDrawAlignment(ItemBoxTD[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ItemBoxTD[2], -2686721);
    TextDrawSetShadow(ItemBoxTD[2], 0);
    TextDrawSetOutline(ItemBoxTD[2], 0);
    TextDrawBackgroundColour(ItemBoxTD[2], 255);
    TextDrawFont(ItemBoxTD[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ItemBoxTD[2], true);

    ItemBoxTD[3] = TextDrawCreate(413.000, 365.000, "LD_SPAC:white");
    TextDrawTextSize(ItemBoxTD[3], 38.000, 3.000);
    TextDrawAlignment(ItemBoxTD[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ItemBoxTD[3], -2686721);
    TextDrawSetShadow(ItemBoxTD[3], 0);
    TextDrawSetOutline(ItemBoxTD[3], 0);
    TextDrawBackgroundColour(ItemBoxTD[3], 255);
    TextDrawFont(ItemBoxTD[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ItemBoxTD[3], true);

    ItemBoxTD[4] = TextDrawCreate(453.000, 365.000, "LD_SPAC:white");
    TextDrawTextSize(ItemBoxTD[4], 38.000, 3.000);
    TextDrawAlignment(ItemBoxTD[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ItemBoxTD[4], -2686721);
    TextDrawSetShadow(ItemBoxTD[4], 0);
    TextDrawSetOutline(ItemBoxTD[4], 0);
    TextDrawBackgroundColour(ItemBoxTD[4], 255);
    TextDrawFont(ItemBoxTD[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ItemBoxTD[4], true);

    ItemBoxTD[5] = TextDrawCreate(293.000, 368.000, "LD_SPAC:white");
    TextDrawTextSize(ItemBoxTD[5], 38.000, 44.000);
    TextDrawAlignment(ItemBoxTD[5], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ItemBoxTD[5], 66);
    TextDrawSetShadow(ItemBoxTD[5], 0);
    TextDrawSetOutline(ItemBoxTD[5], 0);
    TextDrawBackgroundColour(ItemBoxTD[5], 255);
    TextDrawFont(ItemBoxTD[5], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ItemBoxTD[5], true);

    ItemBoxTD[6] = TextDrawCreate(333.000, 368.000, "LD_SPAC:white");
    TextDrawTextSize(ItemBoxTD[6], 38.000, 44.000);
    TextDrawAlignment(ItemBoxTD[6], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ItemBoxTD[6], 66);
    TextDrawSetShadow(ItemBoxTD[6], 0);
    TextDrawSetOutline(ItemBoxTD[6], 0);
    TextDrawBackgroundColour(ItemBoxTD[6], 255);
    TextDrawFont(ItemBoxTD[6], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ItemBoxTD[6], true);

    ItemBoxTD[7] = TextDrawCreate(373.000, 368.000, "LD_SPAC:white");
    TextDrawTextSize(ItemBoxTD[7], 38.000, 44.000);
    TextDrawAlignment(ItemBoxTD[7], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ItemBoxTD[7], 66);
    TextDrawSetShadow(ItemBoxTD[7], 0);
    TextDrawSetOutline(ItemBoxTD[7], 0);
    TextDrawBackgroundColour(ItemBoxTD[7], 255);
    TextDrawFont(ItemBoxTD[7], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ItemBoxTD[7], true);

    ItemBoxTD[8] = TextDrawCreate(413.000, 368.000, "LD_SPAC:white");
    TextDrawTextSize(ItemBoxTD[8], 38.000, 44.000);
    TextDrawAlignment(ItemBoxTD[8], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ItemBoxTD[8], 66);
    TextDrawSetShadow(ItemBoxTD[8], 0);
    TextDrawSetOutline(ItemBoxTD[8], 0);
    TextDrawBackgroundColour(ItemBoxTD[8], 255);
    TextDrawFont(ItemBoxTD[8], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ItemBoxTD[8], true);

    ItemBoxTD[9] = TextDrawCreate(453.000, 368.000, "LD_SPAC:white");
    TextDrawTextSize(ItemBoxTD[9], 38.000, 44.000);
    TextDrawAlignment(ItemBoxTD[9], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ItemBoxTD[9], 66);
    TextDrawSetShadow(ItemBoxTD[9], 0);
    TextDrawSetOutline(ItemBoxTD[9], 0);
    TextDrawBackgroundColour(ItemBoxTD[9], 255);
    TextDrawFont(ItemBoxTD[9], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ItemBoxTD[9], true);

    return 1;
}

Create_ItemboxPTD(playerid)
{
    Model_ItemBoxPTD[playerid][0] = CreatePlayerTextDraw(playerid, 293.000, 368.000, "_");
    PlayerTextDrawTextSize(playerid, Model_ItemBoxPTD[playerid][0], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, Model_ItemBoxPTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, Model_ItemBoxPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, Model_ItemBoxPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, Model_ItemBoxPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, Model_ItemBoxPTD[playerid][0], 0);
    PlayerTextDrawFont(playerid, Model_ItemBoxPTD[playerid][0], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, Model_ItemBoxPTD[playerid][0], false);
    PlayerTextDrawSetPreviewModel(playerid, Model_ItemBoxPTD[playerid][0], 2972);
    PlayerTextDrawSetPreviewRot(playerid, Model_ItemBoxPTD[playerid][0], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, Model_ItemBoxPTD[playerid][0], 0, 0);

    Model_ItemBoxPTD[playerid][1] = CreatePlayerTextDraw(playerid, 333.000, 368.000, "_");
    PlayerTextDrawTextSize(playerid, Model_ItemBoxPTD[playerid][1], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, Model_ItemBoxPTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, Model_ItemBoxPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, Model_ItemBoxPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, Model_ItemBoxPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, Model_ItemBoxPTD[playerid][1], 0);
    PlayerTextDrawFont(playerid, Model_ItemBoxPTD[playerid][1], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, Model_ItemBoxPTD[playerid][1], false);
    PlayerTextDrawSetPreviewModel(playerid, Model_ItemBoxPTD[playerid][1], 2972);
    PlayerTextDrawSetPreviewRot(playerid, Model_ItemBoxPTD[playerid][1], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, Model_ItemBoxPTD[playerid][1], 0, 0);

    Model_ItemBoxPTD[playerid][2] = CreatePlayerTextDraw(playerid, 373.000, 368.000, "_");
    PlayerTextDrawTextSize(playerid, Model_ItemBoxPTD[playerid][2], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, Model_ItemBoxPTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, Model_ItemBoxPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, Model_ItemBoxPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, Model_ItemBoxPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, Model_ItemBoxPTD[playerid][2], 0);
    PlayerTextDrawFont(playerid, Model_ItemBoxPTD[playerid][2], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, Model_ItemBoxPTD[playerid][2], false);
    PlayerTextDrawSetPreviewModel(playerid, Model_ItemBoxPTD[playerid][2], 2972);
    PlayerTextDrawSetPreviewRot(playerid, Model_ItemBoxPTD[playerid][2], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, Model_ItemBoxPTD[playerid][2], 0, 0);

    Model_ItemBoxPTD[playerid][3] = CreatePlayerTextDraw(playerid, 413.000, 368.000, "_");
    PlayerTextDrawTextSize(playerid, Model_ItemBoxPTD[playerid][3], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, Model_ItemBoxPTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, Model_ItemBoxPTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, Model_ItemBoxPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, Model_ItemBoxPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, Model_ItemBoxPTD[playerid][3], 0);
    PlayerTextDrawFont(playerid, Model_ItemBoxPTD[playerid][3], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, Model_ItemBoxPTD[playerid][3], false);
    PlayerTextDrawSetPreviewModel(playerid, Model_ItemBoxPTD[playerid][3], 2972);
    PlayerTextDrawSetPreviewRot(playerid, Model_ItemBoxPTD[playerid][3], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, Model_ItemBoxPTD[playerid][3], 0, 0);

    Model_ItemBoxPTD[playerid][4] = CreatePlayerTextDraw(playerid, 453.000, 368.000, "_");
    PlayerTextDrawTextSize(playerid, Model_ItemBoxPTD[playerid][4], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, Model_ItemBoxPTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, Model_ItemBoxPTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, Model_ItemBoxPTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, Model_ItemBoxPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, Model_ItemBoxPTD[playerid][4], 0);
    PlayerTextDrawFont(playerid, Model_ItemBoxPTD[playerid][4], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, Model_ItemBoxPTD[playerid][4], false);
    PlayerTextDrawSetPreviewModel(playerid, Model_ItemBoxPTD[playerid][4], 2972);
    PlayerTextDrawSetPreviewRot(playerid, Model_ItemBoxPTD[playerid][4], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, Model_ItemBoxPTD[playerid][4], 0, 0);

    Title_ItemBoxPTD[playerid][0] = CreatePlayerTextDraw(playerid, 295.000, 370.000, "Received 999x");
    PlayerTextDrawLetterSize(playerid, Title_ItemBoxPTD[playerid][0], 0.149, 0.999);
    PlayerTextDrawTextSize(playerid, Title_ItemBoxPTD[playerid][0], 329.000, 37.000);
    PlayerTextDrawAlignment(playerid, Title_ItemBoxPTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, Title_ItemBoxPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, Title_ItemBoxPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, Title_ItemBoxPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, Title_ItemBoxPTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, Title_ItemBoxPTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, Title_ItemBoxPTD[playerid][0], true);

    Title_ItemBoxPTD[playerid][1] = CreatePlayerTextDraw(playerid, 335.000, 370.000, "Received 999x");
    PlayerTextDrawLetterSize(playerid, Title_ItemBoxPTD[playerid][1], 0.149, 0.999);
    PlayerTextDrawTextSize(playerid, Title_ItemBoxPTD[playerid][1], 369.000, 37.000);
    PlayerTextDrawAlignment(playerid, Title_ItemBoxPTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, Title_ItemBoxPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, Title_ItemBoxPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, Title_ItemBoxPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, Title_ItemBoxPTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, Title_ItemBoxPTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, Title_ItemBoxPTD[playerid][1], true);

    Title_ItemBoxPTD[playerid][2] = CreatePlayerTextDraw(playerid, 375.000, 370.000, "Received 999x");
    PlayerTextDrawLetterSize(playerid, Title_ItemBoxPTD[playerid][2], 0.149, 0.999);
    PlayerTextDrawTextSize(playerid, Title_ItemBoxPTD[playerid][2], 409.000, 37.000);
    PlayerTextDrawAlignment(playerid, Title_ItemBoxPTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, Title_ItemBoxPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, Title_ItemBoxPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, Title_ItemBoxPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, Title_ItemBoxPTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, Title_ItemBoxPTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, Title_ItemBoxPTD[playerid][2], true);

    Title_ItemBoxPTD[playerid][3] = CreatePlayerTextDraw(playerid, 415.000, 370.000, "Received 999x");
    PlayerTextDrawLetterSize(playerid, Title_ItemBoxPTD[playerid][3], 0.149, 0.999);
    PlayerTextDrawTextSize(playerid, Title_ItemBoxPTD[playerid][3], 449.000, 37.000);
    PlayerTextDrawAlignment(playerid, Title_ItemBoxPTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, Title_ItemBoxPTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, Title_ItemBoxPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, Title_ItemBoxPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, Title_ItemBoxPTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, Title_ItemBoxPTD[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, Title_ItemBoxPTD[playerid][3], true);

    Title_ItemBoxPTD[playerid][4] = CreatePlayerTextDraw(playerid, 455.000, 370.000, "Received 999x");
    PlayerTextDrawLetterSize(playerid, Title_ItemBoxPTD[playerid][4], 0.149, 0.999);
    PlayerTextDrawTextSize(playerid, Title_ItemBoxPTD[playerid][4], 489.000, 37.000);
    PlayerTextDrawAlignment(playerid, Title_ItemBoxPTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, Title_ItemBoxPTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, Title_ItemBoxPTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, Title_ItemBoxPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, Title_ItemBoxPTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, Title_ItemBoxPTD[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, Title_ItemBoxPTD[playerid][4], true);

    Name_ItemBoxPTD[playerid][0] = CreatePlayerTextDraw(playerid, 313.000, 401.000, "Nasi Padang");
    PlayerTextDrawLetterSize(playerid, Name_ItemBoxPTD[playerid][0], 0.119, 0.898);
    PlayerTextDrawTextSize(playerid, Name_ItemBoxPTD[playerid][0], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, Name_ItemBoxPTD[playerid][0], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, Name_ItemBoxPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, Name_ItemBoxPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, Name_ItemBoxPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, Name_ItemBoxPTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, Name_ItemBoxPTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, Name_ItemBoxPTD[playerid][0], true);

    Name_ItemBoxPTD[playerid][1] = CreatePlayerTextDraw(playerid, 353.000, 401.000, "Nasi Padang");
    PlayerTextDrawLetterSize(playerid, Name_ItemBoxPTD[playerid][1], 0.119, 0.898);
    PlayerTextDrawTextSize(playerid, Name_ItemBoxPTD[playerid][1], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, Name_ItemBoxPTD[playerid][1], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, Name_ItemBoxPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, Name_ItemBoxPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, Name_ItemBoxPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, Name_ItemBoxPTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, Name_ItemBoxPTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, Name_ItemBoxPTD[playerid][1], true);

    Name_ItemBoxPTD[playerid][2] = CreatePlayerTextDraw(playerid, 393.000, 401.000, "Nasi Padang");
    PlayerTextDrawLetterSize(playerid, Name_ItemBoxPTD[playerid][2], 0.119, 0.898);
    PlayerTextDrawTextSize(playerid, Name_ItemBoxPTD[playerid][2], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, Name_ItemBoxPTD[playerid][2], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, Name_ItemBoxPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, Name_ItemBoxPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, Name_ItemBoxPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, Name_ItemBoxPTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, Name_ItemBoxPTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, Name_ItemBoxPTD[playerid][2], true);

    Name_ItemBoxPTD[playerid][3] = CreatePlayerTextDraw(playerid, 433.000, 401.000, "Nasi Padang");
    PlayerTextDrawLetterSize(playerid, Name_ItemBoxPTD[playerid][3], 0.119, 0.898);
    PlayerTextDrawTextSize(playerid, Name_ItemBoxPTD[playerid][3], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, Name_ItemBoxPTD[playerid][3], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, Name_ItemBoxPTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, Name_ItemBoxPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, Name_ItemBoxPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, Name_ItemBoxPTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, Name_ItemBoxPTD[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, Name_ItemBoxPTD[playerid][3], true);

    Name_ItemBoxPTD[playerid][4] = CreatePlayerTextDraw(playerid, 473.000, 401.000, "Nasi Padang");
    PlayerTextDrawLetterSize(playerid, Name_ItemBoxPTD[playerid][4], 0.119, 0.898);
    PlayerTextDrawTextSize(playerid, Name_ItemBoxPTD[playerid][4], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, Name_ItemBoxPTD[playerid][4], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, Name_ItemBoxPTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, Name_ItemBoxPTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, Name_ItemBoxPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, Name_ItemBoxPTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, Name_ItemBoxPTD[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, Name_ItemBoxPTD[playerid][4], true);

    return 1;
}

Destroy_ItemBoxPTD(playerid)
{
    for(new i = 0; i < 5; i++)
    {
        PlayerTextDrawDestroy(playerid, Model_ItemBoxPTD);
        PlayerTextDrawDestroy(playerid, Title_ItemBoxPTD);
        PlayerTextDrawDestroy(playerid, Name_ItemBoxPTD);
        Model_ItemBoxPTD[i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        Title_ItemBoxPTD[i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        Name_ItemBoxPTD[i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
    }
}