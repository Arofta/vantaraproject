new Text:InvBaseTD[6],
    Text:InvButtonTD[5],
    Text:InvTextTD[4],
    PlayerText:InvSlotPTD[MAX_PLAYERS][20],
    PlayerText:InvModelPTD[MAX_PLAYERS][20],
    PlayerText:InvNamePTD[MAX_PLAYERS][20],
    PlayerText:InvQuantityPTD[MAX_PLAYERS][20],
    PlayerText:InvPagePTD[MAX_PLAYERS][2],
    PlayerText:InvWeightBarPTD[MAX_PLAYERS],
    PlayerText:InvTextPTD[MAX_PLAYERS][4];

Create_InvTD()
{
    InvBaseTD[0] = TextDrawCreate(109.000, 136.000, "LD_SPAC:white");
    TextDrawTextSize(InvBaseTD[0], 219.000, 200.000);
    TextDrawAlignment(InvBaseTD[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvBaseTD[0], 66);
    TextDrawSetShadow(InvBaseTD[0], 0);
    TextDrawSetOutline(InvBaseTD[0], 0);
    TextDrawBackgroundColour(InvBaseTD[0], 255);
    TextDrawFont(InvBaseTD[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvBaseTD[0], true);

    InvBaseTD[1] = TextDrawCreate(109.000, 121.000, "LD_SPAC:white");
    TextDrawTextSize(InvBaseTD[1], 99.000, 12.000);
    TextDrawAlignment(InvBaseTD[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvBaseTD[1], 66);
    TextDrawSetShadow(InvBaseTD[1], 0);
    TextDrawSetOutline(InvBaseTD[1], 0);
    TextDrawBackgroundColour(InvBaseTD[1], 255);
    TextDrawFont(InvBaseTD[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvBaseTD[1], true);

    InvBaseTD[2] = TextDrawCreate(315.000, 121.000, "LD_SPAC:white");
    TextDrawTextSize(InvBaseTD[2], 13.000, 12.000);
    TextDrawAlignment(InvBaseTD[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvBaseTD[2], 66);
    TextDrawSetShadow(InvBaseTD[2], 0);
    TextDrawSetOutline(InvBaseTD[2], 0);
    TextDrawBackgroundColour(InvBaseTD[2], 255);
    TextDrawFont(InvBaseTD[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvBaseTD[2], true);

    InvBaseTD[3] = TextDrawCreate(210.000, 121.000, "LD_SPAC:white");
    TextDrawTextSize(InvBaseTD[3], 103.000, 12.000);
    TextDrawAlignment(InvBaseTD[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvBaseTD[3], 66);
    TextDrawSetShadow(InvBaseTD[3], 0);
    TextDrawSetOutline(InvBaseTD[3], 0);
    TextDrawBackgroundColour(InvBaseTD[3], 255);
    TextDrawFont(InvBaseTD[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvBaseTD[3], true);

    InvBaseTD[4] = TextDrawCreate(212.000, 123.000, "LD_SPAC:white");
    TextDrawTextSize(InvBaseTD[4], 99.000, 7.000);
    TextDrawAlignment(InvBaseTD[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvBaseTD[4], -928055041);
    TextDrawSetShadow(InvBaseTD[4], 0);
    TextDrawSetOutline(InvBaseTD[4], 0);
    TextDrawBackgroundColour(InvBaseTD[4], 255);
    TextDrawFont(InvBaseTD[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvBaseTD[4], true);

    InvBaseTD[5] = TextDrawCreate(333.000, 136.000, "LD_SPAC:white");
    TextDrawTextSize(InvBaseTD[5], 67.000, 161.000);
    TextDrawAlignment(InvBaseTD[5], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvBaseTD[5], 66);
    TextDrawSetShadow(InvBaseTD[5], 0);
    TextDrawSetOutline(InvBaseTD[5], 0);
    TextDrawBackgroundColour(InvBaseTD[5], 255);
    TextDrawFont(InvBaseTD[5], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvBaseTD[5], true);

    InvButtonTD[0] = TextDrawCreate(338.000, 141.000, "LD_SPAC:white");
    TextDrawTextSize(InvButtonTD[0], 57.000, 20.000);
    TextDrawAlignment(InvButtonTD[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvButtonTD[0], 66);
    TextDrawSetShadow(InvButtonTD[0], 0);
    TextDrawSetOutline(InvButtonTD[0], 0);
    TextDrawBackgroundColour(InvButtonTD[0], 255);
    TextDrawFont(InvButtonTD[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvButtonTD[0], true);
    TextDrawSetSelectable(InvButtonTD[0], true);

    InvButtonTD[1] = TextDrawCreate(338.000, 164.000, "LD_SPAC:white");
    TextDrawTextSize(InvButtonTD[1], 57.000, 59.000);
    TextDrawAlignment(InvButtonTD[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvButtonTD[1], 66);
    TextDrawSetShadow(InvButtonTD[1], 0);
    TextDrawSetOutline(InvButtonTD[1], 0);
    TextDrawBackgroundColour(InvButtonTD[1], 255);
    TextDrawFont(InvButtonTD[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvButtonTD[1], true);
    TextDrawSetSelectable(InvButtonTD[1], true);

    InvButtonTD[2] = TextDrawCreate(338.000, 226.000, "LD_SPAC:white");
    TextDrawTextSize(InvButtonTD[2], 57.000, 20.000);
    TextDrawAlignment(InvButtonTD[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvButtonTD[2], 66);
    TextDrawSetShadow(InvButtonTD[2], 0);
    TextDrawSetOutline(InvButtonTD[2], 0);
    TextDrawBackgroundColour(InvButtonTD[2], 255);
    TextDrawFont(InvButtonTD[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvButtonTD[2], true);
    TextDrawSetSelectable(InvButtonTD[2], true);

    InvButtonTD[3] = TextDrawCreate(338.000, 249.000, "LD_SPAC:white");
    TextDrawTextSize(InvButtonTD[3], 57.000, 20.000);
    TextDrawAlignment(InvButtonTD[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvButtonTD[3], 66);
    TextDrawSetShadow(InvButtonTD[3], 0);
    TextDrawSetOutline(InvButtonTD[3], 0);
    TextDrawBackgroundColour(InvButtonTD[3], 255);
    TextDrawFont(InvButtonTD[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvButtonTD[3], true);
    TextDrawSetSelectable(InvButtonTD[3], true);

    InvButtonTD[4] = TextDrawCreate(338.000, 272.000, "LD_SPAC:white");
    TextDrawTextSize(InvButtonTD[4], 57.000, 20.000);
    TextDrawAlignment(InvButtonTD[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvButtonTD[4], 66);
    TextDrawSetShadow(InvButtonTD[4], 0);
    TextDrawSetOutline(InvButtonTD[4], 0);
    TextDrawBackgroundColour(InvButtonTD[4], 255);
    TextDrawFont(InvButtonTD[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvButtonTD[4], true);
    TextDrawSetSelectable(InvButtonTD[4], true);

    InvTextTD[0] = TextDrawCreate(366.000, 206.000, "GUNAKAN");
    TextDrawLetterSize(InvTextTD[0], 0.318, 1.590);
    TextDrawAlignment(InvTextTD[0], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(InvTextTD[0], -1);
    TextDrawSetShadow(InvTextTD[0], 0);
    TextDrawSetOutline(InvTextTD[0], 0);
    TextDrawBackgroundColour(InvTextTD[0], 150);
    TextDrawFont(InvTextTD[0], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(InvTextTD[0], true);

    InvTextTD[1] = TextDrawCreate(366.000, 229.000, "BERIKAN");
    TextDrawLetterSize(InvTextTD[1], 0.318, 1.590);
    TextDrawAlignment(InvTextTD[1], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(InvTextTD[1], -1);
    TextDrawSetShadow(InvTextTD[1], 0);
    TextDrawSetOutline(InvTextTD[1], 0);
    TextDrawBackgroundColour(InvTextTD[1], 150);
    TextDrawFont(InvTextTD[1], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(InvTextTD[1], true);

    InvTextTD[2] = TextDrawCreate(366.000, 252.000, "INFORMASI");
    TextDrawLetterSize(InvTextTD[2], 0.318, 1.590);
    TextDrawAlignment(InvTextTD[2], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(InvTextTD[2], -1);
    TextDrawSetShadow(InvTextTD[2], 0);
    TextDrawSetOutline(InvTextTD[2], 0);
    TextDrawBackgroundColour(InvTextTD[2], 150);
    TextDrawFont(InvTextTD[2], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(InvTextTD[2], true);

    InvTextTD[3] = TextDrawCreate(366.000, 275.000, "TUTUP");
    TextDrawLetterSize(InvTextTD[3], 0.318, 1.590);
    TextDrawAlignment(InvTextTD[3], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(InvTextTD[3], -1);
    TextDrawSetShadow(InvTextTD[3], 0);
    TextDrawSetOutline(InvTextTD[3], 0);
    TextDrawBackgroundColour(InvTextTD[3], 150);
    TextDrawFont(InvTextTD[3], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(InvTextTD[3], true);
}

Create_InvPTD(playerid)
{
    InvSlotPTD[playerid][0] = CreatePlayerTextDraw(playerid, 115.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][0], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][0], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][0], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][0], true);

    InvSlotPTD[playerid][1] = CreatePlayerTextDraw(playerid, 155.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][1], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][1], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][1], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][1], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][1], true);

    InvSlotPTD[playerid][2] = CreatePlayerTextDraw(playerid, 195.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][2], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][2], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][2], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][2], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][2], true);

    InvSlotPTD[playerid][3] = CreatePlayerTextDraw(playerid, 235.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][3], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][3], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][3], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][3], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][3], true);

    InvSlotPTD[playerid][4] = CreatePlayerTextDraw(playerid, 275.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][4], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][4], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][4], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][4], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][4], true);

    InvSlotPTD[playerid][5] = CreatePlayerTextDraw(playerid, 115.000, 190.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][5], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][5], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][5], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][5], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][5], true);

    InvSlotPTD[playerid][6] = CreatePlayerTextDraw(playerid, 155.000, 190.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][6], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][6], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][6], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][6], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][6], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][6], true);

    InvSlotPTD[playerid][7] = CreatePlayerTextDraw(playerid, 195.000, 190.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][7], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][7], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][7], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][7], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][7], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][7], true);

    InvSlotPTD[playerid][8] = CreatePlayerTextDraw(playerid, 235.000, 190.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][8], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][8], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][8], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][8], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][8], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][8], true);

    InvSlotPTD[playerid][9] = CreatePlayerTextDraw(playerid, 275.000, 190.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][9], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][9], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][9], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][9], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][9], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][9], true);

    InvSlotPTD[playerid][10] = CreatePlayerTextDraw(playerid, 115.000, 237.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][10], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][10], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][10], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][10], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][10], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][10], true);

    InvSlotPTD[playerid][11] = CreatePlayerTextDraw(playerid, 155.000, 237.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][11], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][11], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][11], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][11], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][11], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][11], true);

    InvSlotPTD[playerid][12] = CreatePlayerTextDraw(playerid, 195.000, 237.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][12], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][12], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][12], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][12], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][12], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][12], true);

    InvSlotPTD[playerid][13] = CreatePlayerTextDraw(playerid, 235.000, 237.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][13], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][13], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][13], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][13], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][13], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][13], true);

    InvSlotPTD[playerid][14] = CreatePlayerTextDraw(playerid, 275.000, 237.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][14], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][14], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][14], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][14], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][14], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][14], true);

    InvSlotPTD[playerid][15] = CreatePlayerTextDraw(playerid, 115.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][15], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][15], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][15], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][15], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][15], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][15], true);

    InvSlotPTD[playerid][16] = CreatePlayerTextDraw(playerid, 155.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][16], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][16], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][16], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][16], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][16], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][16], true);

    InvSlotPTD[playerid][17] = CreatePlayerTextDraw(playerid, 195.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][17], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][17], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][17], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][17], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][17], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][17], true);

    InvSlotPTD[playerid][18] = CreatePlayerTextDraw(playerid, 235.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][18], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][18], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][18], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][18], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][18], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][18], true);

    InvSlotPTD[playerid][19] = CreatePlayerTextDraw(playerid, 275.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvSlotPTD[playerid][19], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvSlotPTD[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][19], 66);
    PlayerTextDrawSetShadow(playerid, InvSlotPTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, InvSlotPTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, InvSlotPTD[playerid][19], 255);
    PlayerTextDrawFont(playerid, InvSlotPTD[playerid][19], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvSlotPTD[playerid][19], true);
    PlayerTextDrawSetSelectable(playerid, InvSlotPTD[playerid][19], true);

    InvModelPTD[playerid][0] = CreatePlayerTextDraw(playerid, 115.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][0], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][0], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][0], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][0], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][0], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][0], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][0], 0, 0);

    InvNamePTD[playerid][0] = CreatePlayerTextDraw(playerid, 117.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][0], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][0], 151.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][0], true);

    InvQuantityPTD[playerid][0] = CreatePlayerTextDraw(playerid, 150.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][0], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][0], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][0], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][0], true);

    InvModelPTD[playerid][1] = CreatePlayerTextDraw(playerid, 155.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][1], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][1], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][1], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][1], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][1], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][1], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][1], 0, 0);

    InvNamePTD[playerid][1] = CreatePlayerTextDraw(playerid, 157.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][1], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][1], 191.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][1], true);

    InvQuantityPTD[playerid][1] = CreatePlayerTextDraw(playerid, 190.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][1], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][1], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][1], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][1], true);

    InvModelPTD[playerid][2] = CreatePlayerTextDraw(playerid, 195.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][2], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][2], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][2], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][2], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][2], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][2], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][2], 0, 0);

    InvNamePTD[playerid][2] = CreatePlayerTextDraw(playerid, 197.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][2], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][2], 231.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][2], true);

    InvQuantityPTD[playerid][2] = CreatePlayerTextDraw(playerid, 230.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][2], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][2], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][2], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][2], true);

    InvModelPTD[playerid][3] = CreatePlayerTextDraw(playerid, 235.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][3], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][3], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][3], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][3], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][3], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][3], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][3], 0, 0);

    InvNamePTD[playerid][3] = CreatePlayerTextDraw(playerid, 237.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][3], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][3], 271.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][3], true);

    InvQuantityPTD[playerid][3] = CreatePlayerTextDraw(playerid, 270.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][3], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][3], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][3], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][3], true);

    InvModelPTD[playerid][4] = CreatePlayerTextDraw(playerid, 275.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][4], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][4], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][4], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][4], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][4], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][4], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][4], 0, 0);

    InvNamePTD[playerid][4] = CreatePlayerTextDraw(playerid, 277.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][4], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][4], 311.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][4], true);

    InvQuantityPTD[playerid][4] = CreatePlayerTextDraw(playerid, 310.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][4], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][4], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][4], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][4], true);

    InvModelPTD[playerid][5] = CreatePlayerTextDraw(playerid, 115.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][5], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][5], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][5], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][5], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][5], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][5], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][5], 0, 0);

    InvNamePTD[playerid][5] = CreatePlayerTextDraw(playerid, 117.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][5], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][5], 151.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][5], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][5], true);

    InvQuantityPTD[playerid][5] = CreatePlayerTextDraw(playerid, 150.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][5], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][5], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][5], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][5], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][5], true);

    InvModelPTD[playerid][6] = CreatePlayerTextDraw(playerid, 155.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][6], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][6], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][6], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][6], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][6], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][6], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][6], 0, 0);

    InvNamePTD[playerid][6] = CreatePlayerTextDraw(playerid, 157.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][6], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][6], 191.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][6], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][6], true);

    InvQuantityPTD[playerid][6] = CreatePlayerTextDraw(playerid, 190.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][6], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][6], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][6], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][6], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][6], true);

    InvModelPTD[playerid][7] = CreatePlayerTextDraw(playerid, 195.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][7], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][7], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][7], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][7], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][7], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][7], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][7], 0, 0);

    InvNamePTD[playerid][7] = CreatePlayerTextDraw(playerid, 197.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][7], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][7], 231.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][7], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][7], true);

    InvQuantityPTD[playerid][7] = CreatePlayerTextDraw(playerid, 230.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][7], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][7], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][7], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][7], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][7], true);

    InvModelPTD[playerid][8] = CreatePlayerTextDraw(playerid, 235.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][8], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][8], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][8], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][8], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][8], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][8], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][8], 0, 0);

    InvNamePTD[playerid][8] = CreatePlayerTextDraw(playerid, 237.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][8], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][8], 271.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][8], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][8], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][8], true);

    InvQuantityPTD[playerid][8] = CreatePlayerTextDraw(playerid, 270.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][8], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][8], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][8], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][8], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][8], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][8], true);

    InvModelPTD[playerid][9] = CreatePlayerTextDraw(playerid, 275.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][9], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][9], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][9], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][9], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][9], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][9], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][9], 0, 0);

    InvNamePTD[playerid][9] = CreatePlayerTextDraw(playerid, 277.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][9], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][9], 311.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][9], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][9], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][9], true);

    InvQuantityPTD[playerid][9] = CreatePlayerTextDraw(playerid, 310.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][9], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][9], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][9], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][9], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][9], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][9], true);

    InvModelPTD[playerid][10] = CreatePlayerTextDraw(playerid, 115.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][10], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][10], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][10], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][10], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][10], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][10], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][10], 0, 0);

    InvNamePTD[playerid][10] = CreatePlayerTextDraw(playerid, 117.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][10], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][10], 151.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][10], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][10], true);

    InvQuantityPTD[playerid][10] = CreatePlayerTextDraw(playerid, 150.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][10], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][10], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][10], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][10], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][10], true);

    InvModelPTD[playerid][11] = CreatePlayerTextDraw(playerid, 155.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][11], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][11], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][11], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][11], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][11], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][11], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][11], 0, 0);

    InvNamePTD[playerid][11] = CreatePlayerTextDraw(playerid, 157.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][11], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][11], 191.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][11], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][11], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][11], true);

    InvQuantityPTD[playerid][11] = CreatePlayerTextDraw(playerid, 190.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][11], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][11], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][11], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][11], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][11], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][11], true);

    InvModelPTD[playerid][12] = CreatePlayerTextDraw(playerid, 195.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][12], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][12], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][12], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][12], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][12], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][12], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][12], 0, 0);

    InvNamePTD[playerid][12] = CreatePlayerTextDraw(playerid, 197.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][12], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][12], 231.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][12], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][12], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][12], true);

    InvQuantityPTD[playerid][12] = CreatePlayerTextDraw(playerid, 230.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][12], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][12], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][12], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][12], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][12], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][12], true);

    InvModelPTD[playerid][13] = CreatePlayerTextDraw(playerid, 235.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][13], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][13], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][13], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][13], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][13], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][13], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][13], 0, 0);

    InvNamePTD[playerid][13] = CreatePlayerTextDraw(playerid, 237.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][13], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][13], 271.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][13], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][13], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][13], true);

    InvQuantityPTD[playerid][13] = CreatePlayerTextDraw(playerid, 270.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][13], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][13], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][13], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][13], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][13], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][13], true);

    InvModelPTD[playerid][14] = CreatePlayerTextDraw(playerid, 275.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][14], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][14], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][14], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][14], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][14], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][14], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][14], 0, 0);

    InvNamePTD[playerid][14] = CreatePlayerTextDraw(playerid, 277.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][14], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][14], 311.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][14], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][14], true);

    InvQuantityPTD[playerid][14] = CreatePlayerTextDraw(playerid, 310.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][14], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][14], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][14], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][14], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][14], true);

    InvModelPTD[playerid][15] = CreatePlayerTextDraw(playerid, 115.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][15], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][15], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][15], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][15], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][15], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][15], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][15], 0, 0);

    InvNamePTD[playerid][15] = CreatePlayerTextDraw(playerid, 117.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][15], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][15], 151.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][15], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][15], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][15], true);

    InvQuantityPTD[playerid][15] = CreatePlayerTextDraw(playerid, 150.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][15], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][15], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][15], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][15], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][15], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][15], true);

    InvModelPTD[playerid][16] = CreatePlayerTextDraw(playerid, 155.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][16], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][16], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][16], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][16], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][16], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][16], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][16], 0, 0);

    InvNamePTD[playerid][16] = CreatePlayerTextDraw(playerid, 157.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][16], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][16], 191.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][16], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][16], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][16], true);

    InvQuantityPTD[playerid][16] = CreatePlayerTextDraw(playerid, 190.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][16], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][16], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][16], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][16], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][16], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][16], true);

    InvModelPTD[playerid][17] = CreatePlayerTextDraw(playerid, 195.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][17], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][17], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][17], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][17], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][17], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][17], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][17], 0, 0);

    InvNamePTD[playerid][17] = CreatePlayerTextDraw(playerid, 197.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][17], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][17], 231.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][17], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][17], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][17], true);

    InvQuantityPTD[playerid][17] = CreatePlayerTextDraw(playerid, 230.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][17], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][17], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][17], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][17], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][17], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][17], true);

    InvModelPTD[playerid][18] = CreatePlayerTextDraw(playerid, 235.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][18], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][18], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][18], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][18], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][18], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][18], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][18], 0, 0);

    InvNamePTD[playerid][18] = CreatePlayerTextDraw(playerid, 237.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][18], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][18], 271.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][18], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][18], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][18], true);

    InvQuantityPTD[playerid][18] = CreatePlayerTextDraw(playerid, 270.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][18], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][18], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][18], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][18], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][18], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][18], true);

    InvModelPTD[playerid][19] = CreatePlayerTextDraw(playerid, 275.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, InvModelPTD[playerid][19], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvModelPTD[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvModelPTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, InvModelPTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, InvModelPTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][19], 0);
    PlayerTextDrawFont(playerid, InvModelPTD[playerid][19], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvModelPTD[playerid][19], false);
    PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][19], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][19], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvModelPTD[playerid][19], 0, 0);

    InvNamePTD[playerid][19] = CreatePlayerTextDraw(playerid, 277.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvNamePTD[playerid][19], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvNamePTD[playerid][19], 311.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvNamePTD[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvNamePTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, InvNamePTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, InvNamePTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, InvNamePTD[playerid][19], 150);
    PlayerTextDrawFont(playerid, InvNamePTD[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvNamePTD[playerid][19], true);

    InvQuantityPTD[playerid][19] = CreatePlayerTextDraw(playerid, 310.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvQuantityPTD[playerid][19], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvQuantityPTD[playerid][19], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvQuantityPTD[playerid][19], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvQuantityPTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, InvQuantityPTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, InvQuantityPTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, InvQuantityPTD[playerid][19], 150);
    PlayerTextDrawFont(playerid, InvQuantityPTD[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvQuantityPTD[playerid][19], true);

    InvPagePTD[playerid][0] = CreatePlayerTextDraw(playerid, 315.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvPagePTD[playerid][0], 7.000, 92.500);
    PlayerTextDrawAlignment(playerid, InvPagePTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPagePTD[playerid][0], 66);
    PlayerTextDrawSetShadow(playerid, InvPagePTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InvPagePTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPagePTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, InvPagePTD[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvPagePTD[playerid][0], true);
    PlayerTextDrawSetSelectable(playerid, InvPagePTD[playerid][0], true);

    InvPagePTD[playerid][1] = CreatePlayerTextDraw(playerid, 315.000, 235.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvPagePTD[playerid][1], 7.000, 92.500);
    PlayerTextDrawAlignment(playerid, InvPagePTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPagePTD[playerid][1], 66);
    PlayerTextDrawSetShadow(playerid, InvPagePTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InvPagePTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPagePTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, InvPagePTD[playerid][1], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvPagePTD[playerid][1], true);
    PlayerTextDrawSetSelectable(playerid, InvPagePTD[playerid][1], true);

    InvWeightBarPTD[playerid] = CreatePlayerTextDraw(playerid, 212.000, 123.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvWeightBarPTD[playerid], 99.000, 7.000);
    PlayerTextDrawAlignment(playerid, InvWeightBarPTD[playerid], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvWeightBarPTD[playerid], -1703681);
    PlayerTextDrawSetShadow(playerid, InvWeightBarPTD[playerid], 0);
    PlayerTextDrawSetOutline(playerid, InvWeightBarPTD[playerid], 0);
    PlayerTextDrawBackgroundColour(playerid, InvWeightBarPTD[playerid], 255);
    PlayerTextDrawFont(playerid, InvWeightBarPTD[playerid], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvWeightBarPTD[playerid], true);

    InvTextPTD[playerid][0] = CreatePlayerTextDraw(playerid, 110.000, 121.000, "Fristname_Lastnameeeeeee");
    PlayerTextDrawLetterSize(playerid, InvTextPTD[playerid][0], 0.230, 1.190);
    PlayerTextDrawAlignment(playerid, InvTextPTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvTextPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, InvTextPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InvTextPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, InvTextPTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, InvTextPTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvTextPTD[playerid][0], true);

    InvTextPTD[playerid][1] = CreatePlayerTextDraw(playerid, 319.000, 121.000, "2");
    PlayerTextDrawLetterSize(playerid, InvTextPTD[playerid][1], 0.230, 1.190);
    PlayerTextDrawAlignment(playerid, InvTextPTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvTextPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, InvTextPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InvTextPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, InvTextPTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, InvTextPTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvTextPTD[playerid][1], true);

    InvTextPTD[playerid][2] = CreatePlayerTextDraw(playerid, 261.000, 122.000, "25.0 / 25 kg");
    PlayerTextDrawLetterSize(playerid, InvTextPTD[playerid][2], 0.209, 0.990);
    PlayerTextDrawAlignment(playerid, InvTextPTD[playerid][2], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, InvTextPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, InvTextPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InvTextPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, InvTextPTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, InvTextPTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvTextPTD[playerid][2], true);

    InvTextPTD[playerid][3] = CreatePlayerTextDraw(playerid, 366.000, 144.000, "JUMLAH");
    PlayerTextDrawLetterSize(playerid, InvTextPTD[playerid][3], 0.318, 1.590);
    PlayerTextDrawAlignment(playerid, InvTextPTD[playerid][3], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, InvTextPTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, InvTextPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, InvTextPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, InvTextPTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, InvTextPTD[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvTextPTD[playerid][3], true);
}

Destroy_InvPTD(playerid)
{
    for(new x = 0; x < 20; x++)
    {
        if(x < 2)
            PlayerTextDrawDestroy(playerid, InvPagePTD[playerid][x]);
        if(x < 4)
            PlayerTextDrawDestroy(playerid,  InvTextPTD[playerid][x]);
        
        PlayerTextDrawDestroy(playerid, InvModelPTD[playerid][x]);
        PlayerTextDrawDestroy(playerid, InvNamePTD[playerid][x]);
        PlayerTextDrawDestroy(playerid, InvQuantityPTD[playerid][x]);
    }
    PlayerTextDrawDestroy(playerid, InvWeightBarPTD[playerid]);
}