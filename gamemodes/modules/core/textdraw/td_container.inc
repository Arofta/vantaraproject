new Text:ContainerBaseTD[5],
    PlayerText:ContainerSlotPTD[MAX_PLAYERS][20],
    PlayerText:ContainerModelPTD[MAX_PLAYERS][20],
    PlayerText:ContainerNamePTD[MAX_PLAYERS][20],
    PlayerText:ContainerQuantityPTD[MAX_PLAYERS][20],
    PlayerText:ContainerPagePTD[MAX_PLAYERS][2],
    PlayerText:ContainerWeightBarPTD[MAX_PLAYERS],
    PlayerText:ContainerTextPTD[MAX_PLAYERS][3];

Create_ContainerTD()
{
    ContainerBaseTD[0] = TextDrawCreate(405.000, 136.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerBaseTD[0], 219.000, 200.000);
    TextDrawAlignment(ContainerBaseTD[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerBaseTD[0], 66);
    TextDrawSetShadow(ContainerBaseTD[0], 0);
    TextDrawSetOutline(ContainerBaseTD[0], 0);
    TextDrawBackgroundColour(ContainerBaseTD[0], 255);
    TextDrawFont(ContainerBaseTD[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerBaseTD[0], true);

    ContainerBaseTD[1] = TextDrawCreate(405.000, 121.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerBaseTD[1], 99.000, 12.000);
    TextDrawAlignment(ContainerBaseTD[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerBaseTD[1], 66);
    TextDrawSetShadow(ContainerBaseTD[1], 0);
    TextDrawSetOutline(ContainerBaseTD[1], 0);
    TextDrawBackgroundColour(ContainerBaseTD[1], 255);
    TextDrawFont(ContainerBaseTD[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerBaseTD[1], true);

    ContainerBaseTD[2] = TextDrawCreate(611.000, 121.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerBaseTD[2], 13.000, 12.000);
    TextDrawAlignment(ContainerBaseTD[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerBaseTD[2], 66);
    TextDrawSetShadow(ContainerBaseTD[2], 0);
    TextDrawSetOutline(ContainerBaseTD[2], 0);
    TextDrawBackgroundColour(ContainerBaseTD[2], 255);
    TextDrawFont(ContainerBaseTD[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerBaseTD[2], true);

    ContainerBaseTD[3] = TextDrawCreate(506.000, 121.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerBaseTD[3], 103.000, 12.000);
    TextDrawAlignment(ContainerBaseTD[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerBaseTD[3], 66);
    TextDrawSetShadow(ContainerBaseTD[3], 0);
    TextDrawSetOutline(ContainerBaseTD[3], 0);
    TextDrawBackgroundColour(ContainerBaseTD[3], 255);
    TextDrawFont(ContainerBaseTD[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerBaseTD[3], true);

    ContainerBaseTD[4] = TextDrawCreate(508.000, 123.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerBaseTD[4], 99.000, 7.000);
    TextDrawAlignment(ContainerBaseTD[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerBaseTD[4], -928055041);
    TextDrawSetShadow(ContainerBaseTD[4], 0);
    TextDrawSetOutline(ContainerBaseTD[4], 0);
    TextDrawBackgroundColour(ContainerBaseTD[4], 255);
    TextDrawFont(ContainerBaseTD[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerBaseTD[4], true);
}

Create_ContainerPTD(playerid)
{
    ContainerSlotPTD[playerid][0] = CreatePlayerTextDraw(playerid, 411.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][0], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][0], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][0], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][0], true);

    ContainerSlotPTD[playerid][1] = CreatePlayerTextDraw(playerid, 451.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][1], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][1], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][1], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][1], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][1], true);

    ContainerSlotPTD[playerid][2] = CreatePlayerTextDraw(playerid, 491.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][2], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][2], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][2], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][2], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][2], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][2], true);

    ContainerSlotPTD[playerid][3] = CreatePlayerTextDraw(playerid, 531.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][3], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][3], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][3], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][3], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][3], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][3], true);

    ContainerSlotPTD[playerid][4] = CreatePlayerTextDraw(playerid, 571.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][4], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][4], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][4], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][4], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][4], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][4], true);

    ContainerSlotPTD[playerid][5] = CreatePlayerTextDraw(playerid, 411.000, 190.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][5], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][5], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][5], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][5], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][5], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][5], true);

    ContainerSlotPTD[playerid][6] = CreatePlayerTextDraw(playerid, 451.000, 190.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][6], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][6], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][6], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][6], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][6], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][6], true);

    ContainerSlotPTD[playerid][7] = CreatePlayerTextDraw(playerid, 491.000, 190.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][7], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][7], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][7], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][7], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][7], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][7], true);

    ContainerSlotPTD[playerid][8] = CreatePlayerTextDraw(playerid, 531.000, 190.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][8], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][8], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][8], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][8], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][8], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][8], true);

    ContainerSlotPTD[playerid][9] = CreatePlayerTextDraw(playerid, 571.000, 190.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][9], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][9], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][9], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][9], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][9], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][9], true);

    ContainerSlotPTD[playerid][10] = CreatePlayerTextDraw(playerid, 411.000, 237.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][10], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][10], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][10], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][10], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][10], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][10], true);

    ContainerSlotPTD[playerid][11] = CreatePlayerTextDraw(playerid, 451.000, 237.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][11], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][11], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][11], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][11], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][11], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][11], true);

    ContainerSlotPTD[playerid][12] = CreatePlayerTextDraw(playerid, 491.000, 237.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][12], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][12], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][12], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][12], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][12], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][12], true);

    ContainerSlotPTD[playerid][13] = CreatePlayerTextDraw(playerid, 531.000, 237.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][13], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][13], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][13], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][13], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][13], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][13], true);

    ContainerSlotPTD[playerid][14] = CreatePlayerTextDraw(playerid, 571.000, 237.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][14], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][14], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][14], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][14], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][14], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][14], true);

    ContainerSlotPTD[playerid][15] = CreatePlayerTextDraw(playerid, 411.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][15], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][15], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][15], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][15], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][15], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][15], true);

    ContainerSlotPTD[playerid][16] = CreatePlayerTextDraw(playerid, 451.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][16], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][16], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][16], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][16], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][16], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][16], true);

    ContainerSlotPTD[playerid][17] = CreatePlayerTextDraw(playerid, 491.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][17], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][17], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][17], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][17], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][17], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][17], true);

    ContainerSlotPTD[playerid][18] = CreatePlayerTextDraw(playerid, 531.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][18], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][18], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][18], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][18], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][18], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][18], true);

    ContainerSlotPTD[playerid][19] = CreatePlayerTextDraw(playerid, 571.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerSlotPTD[playerid][19], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerSlotPTD[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][19], 66);
    PlayerTextDrawSetShadow(playerid, ContainerSlotPTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, ContainerSlotPTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerSlotPTD[playerid][19], 255);
    PlayerTextDrawFont(playerid, ContainerSlotPTD[playerid][19], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerSlotPTD[playerid][19], true);
    PlayerTextDrawSetSelectable(playerid, ContainerSlotPTD[playerid][19], true);

    ContainerModelPTD[playerid][0] = CreatePlayerTextDraw(playerid, 411.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][0], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][0], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][0], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][0], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][0], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][0], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][0], 0, 0);

    ContainerNamePTD[playerid][0] = CreatePlayerTextDraw(playerid, 413.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][0], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][0], 447.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][0], true);

    ContainerModelPTD[playerid][1] = CreatePlayerTextDraw(playerid, 451.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][1], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][1], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][1], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][1], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][1], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][1], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][1], 0, 0);

    ContainerNamePTD[playerid][1] = CreatePlayerTextDraw(playerid, 453.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][1], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][1], 487.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][1], true);

    ContainerModelPTD[playerid][2] = CreatePlayerTextDraw(playerid, 491.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][2], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][2], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][2], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][2], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][2], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][2], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][2], 0, 0);

    ContainerNamePTD[playerid][2] = CreatePlayerTextDraw(playerid, 493.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][2], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][2], 527.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][2], true);

    ContainerModelPTD[playerid][3] = CreatePlayerTextDraw(playerid, 531.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][3], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][3], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][3], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][3], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][3], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][3], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][3], 0, 0);

    ContainerNamePTD[playerid][3] = CreatePlayerTextDraw(playerid, 533.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][3], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][3], 567.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][3], true);

    ContainerModelPTD[playerid][4] = CreatePlayerTextDraw(playerid, 571.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][4], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][4], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][4], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][4], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][4], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][4], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][4], 0, 0);

    ContainerNamePTD[playerid][4] = CreatePlayerTextDraw(playerid, 573.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][4], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][4], 607.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][4], true);

    ContainerModelPTD[playerid][5] = CreatePlayerTextDraw(playerid, 411.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][5], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][5], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][5], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][5], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][5], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][5], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][5], 0, 0);

    ContainerNamePTD[playerid][5] = CreatePlayerTextDraw(playerid, 413.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][5], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][5], 447.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][5], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][5], true);

    ContainerModelPTD[playerid][6] = CreatePlayerTextDraw(playerid, 451.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][6], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][6], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][6], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][6], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][6], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][6], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][6], 0, 0);

    ContainerNamePTD[playerid][6] = CreatePlayerTextDraw(playerid, 453.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][6], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][6], 487.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][6], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][6], true);

    ContainerModelPTD[playerid][7] = CreatePlayerTextDraw(playerid, 491.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][7], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][7], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][7], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][7], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][7], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][7], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][7], 0, 0);

    ContainerNamePTD[playerid][7] = CreatePlayerTextDraw(playerid, 493.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][7], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][7], 527.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][7], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][7], true);

    ContainerModelPTD[playerid][8] = CreatePlayerTextDraw(playerid, 531.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][8], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][8], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][8], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][8], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][8], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][8], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][8], 0, 0);

    ContainerNamePTD[playerid][8] = CreatePlayerTextDraw(playerid, 533.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][8], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][8], 567.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][8], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][8], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][8], true);

    ContainerModelPTD[playerid][9] = CreatePlayerTextDraw(playerid, 571.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][9], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][9], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][9], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][9], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][9], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][9], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][9], 0, 0);

    ContainerNamePTD[playerid][9] = CreatePlayerTextDraw(playerid, 573.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][9], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][9], 607.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][9], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][9], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][9], true);

    ContainerModelPTD[playerid][10] = CreatePlayerTextDraw(playerid, 411.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][10], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][10], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][10], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][10], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][10], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][10], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][10], 0, 0);

    ContainerNamePTD[playerid][10] = CreatePlayerTextDraw(playerid, 413.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][10], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][10], 447.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][10], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][10], true);

    ContainerModelPTD[playerid][11] = CreatePlayerTextDraw(playerid, 451.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][11], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][11], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][11], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][11], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][11], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][11], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][11], 0, 0);

    ContainerNamePTD[playerid][11] = CreatePlayerTextDraw(playerid, 453.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][11], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][11], 487.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][11], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][11], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][11], true);

    ContainerModelPTD[playerid][12] = CreatePlayerTextDraw(playerid, 491.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][12], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][12], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][12], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][12], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][12], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][12], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][12], 0, 0);

    ContainerNamePTD[playerid][12] = CreatePlayerTextDraw(playerid, 493.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][12], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][12], 527.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][12], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][12], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][12], true);

    ContainerModelPTD[playerid][13] = CreatePlayerTextDraw(playerid, 531.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][13], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][13], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][13], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][13], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][13], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][13], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][13], 0, 0);

    ContainerNamePTD[playerid][13] = CreatePlayerTextDraw(playerid, 533.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][13], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][13], 567.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][13], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][13], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][13], true);

    ContainerModelPTD[playerid][14] = CreatePlayerTextDraw(playerid, 571.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][14], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][14], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][14], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][14], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][14], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][14], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][14], 0, 0);

    ContainerNamePTD[playerid][14] = CreatePlayerTextDraw(playerid, 573.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][14], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][14], 607.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][14], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][14], true);

    ContainerModelPTD[playerid][15] = CreatePlayerTextDraw(playerid, 411.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][15], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][15], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][15], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][15], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][15], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][15], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][15], 0, 0);

    ContainerNamePTD[playerid][15] = CreatePlayerTextDraw(playerid, 413.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][15], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][15], 447.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][15], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][15], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][15], true);

    ContainerModelPTD[playerid][16] = CreatePlayerTextDraw(playerid, 451.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][16], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][16], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][16], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][16], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][16], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][16], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][16], 0, 0);

    ContainerNamePTD[playerid][16] = CreatePlayerTextDraw(playerid, 453.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][16], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][16], 487.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][16], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][16], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][16], true);

    ContainerModelPTD[playerid][17] = CreatePlayerTextDraw(playerid, 491.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][17], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][17], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][17], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][17], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][17], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][17], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][17], 0, 0);

    ContainerNamePTD[playerid][17] = CreatePlayerTextDraw(playerid, 493.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][17], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][17], 527.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][17], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][17], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][17], true);

    ContainerModelPTD[playerid][18] = CreatePlayerTextDraw(playerid, 531.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][18], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][18], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][18], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][18], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][18], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][18], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][18], 0, 0);

    ContainerNamePTD[playerid][18] = CreatePlayerTextDraw(playerid, 533.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][18], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][18], 567.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][18], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][18], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][18], true);

    ContainerModelPTD[playerid][19] = CreatePlayerTextDraw(playerid, 571.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerModelPTD[playerid][19], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerModelPTD[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModelPTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModelPTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModelPTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][19], 0);
    PlayerTextDrawFont(playerid, ContainerModelPTD[playerid][19], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerModelPTD[playerid][19], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][19], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][19], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerModelPTD[playerid][19], 0, 0);

    ContainerNamePTD[playerid][19] = CreatePlayerTextDraw(playerid, 573.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerNamePTD[playerid][19], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerNamePTD[playerid][19], 607.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerNamePTD[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerNamePTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, ContainerNamePTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, ContainerNamePTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerNamePTD[playerid][19], 150);
    PlayerTextDrawFont(playerid, ContainerNamePTD[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerNamePTD[playerid][19], true);

    ContainerQuantityPTD[playerid][0] = CreatePlayerTextDraw(playerid, 446.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][0], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][0], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][0], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][0], true);

    ContainerQuantityPTD[playerid][1] = CreatePlayerTextDraw(playerid, 486.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][1], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][1], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][1], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][1], true);

    ContainerQuantityPTD[playerid][2] = CreatePlayerTextDraw(playerid, 526.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][2], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][2], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][2], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][2], true);

    ContainerQuantityPTD[playerid][3] = CreatePlayerTextDraw(playerid, 566.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][3], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][3], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][3], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][3], true);

    ContainerQuantityPTD[playerid][4] = CreatePlayerTextDraw(playerid, 606.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][4], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][4], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][4], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][4], true);

    ContainerQuantityPTD[playerid][5] = CreatePlayerTextDraw(playerid, 446.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][5], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][5], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][5], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][5], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][5], true);

    ContainerQuantityPTD[playerid][6] = CreatePlayerTextDraw(playerid, 486.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][6], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][6], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][6], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][6], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][6], true);

    ContainerQuantityPTD[playerid][7] = CreatePlayerTextDraw(playerid, 526.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][7], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][7], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][7], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][7], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][7], true);

    ContainerQuantityPTD[playerid][8] = CreatePlayerTextDraw(playerid, 566.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][8], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][8], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][8], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][8], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][8], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][8], true);

    ContainerQuantityPTD[playerid][9] = CreatePlayerTextDraw(playerid, 606.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][9], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][9], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][9], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][9], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][9], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][9], true);

    ContainerQuantityPTD[playerid][10] = CreatePlayerTextDraw(playerid, 446.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][10], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][10], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][10], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][10], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][10], true);

    ContainerQuantityPTD[playerid][11] = CreatePlayerTextDraw(playerid, 486.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][11], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][11], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][11], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][11], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][11], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][11], true);

    ContainerQuantityPTD[playerid][12] = CreatePlayerTextDraw(playerid, 526.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][12], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][12], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][12], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][12], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][12], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][12], true);

    ContainerQuantityPTD[playerid][13] = CreatePlayerTextDraw(playerid, 566.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][13], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][13], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][13], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][13], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][13], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][13], true);

    ContainerQuantityPTD[playerid][14] = CreatePlayerTextDraw(playerid, 606.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][14], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][14], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][14], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][14], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][14], true);

    ContainerQuantityPTD[playerid][15] = CreatePlayerTextDraw(playerid, 446.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][15], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][15], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][15], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][15], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][15], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][15], true);

    ContainerQuantityPTD[playerid][16] = CreatePlayerTextDraw(playerid, 486.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][16], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][16], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][16], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][16], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][16], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][16], true);

    ContainerQuantityPTD[playerid][17] = CreatePlayerTextDraw(playerid, 526.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][17], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][17], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][17], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][17], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][17], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][17], true);

    ContainerQuantityPTD[playerid][18] = CreatePlayerTextDraw(playerid, 566.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][18], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][18], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][18], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][18], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][18], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][18], true);

    ContainerQuantityPTD[playerid][19] = CreatePlayerTextDraw(playerid, 606.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerQuantityPTD[playerid][19], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerQuantityPTD[playerid][19], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerQuantityPTD[playerid][19], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerQuantityPTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, ContainerQuantityPTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, ContainerQuantityPTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerQuantityPTD[playerid][19], 150);
    PlayerTextDrawFont(playerid, ContainerQuantityPTD[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerQuantityPTD[playerid][19], true);

    ContainerPagePTD[playerid][0] = CreatePlayerTextDraw(playerid, 611.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerPagePTD[playerid][0], 7.000, 92.500);
    PlayerTextDrawAlignment(playerid, ContainerPagePTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPagePTD[playerid][0], 66);
    PlayerTextDrawSetShadow(playerid, ContainerPagePTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPagePTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPagePTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, ContainerPagePTD[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerPagePTD[playerid][0], true);
    PlayerTextDrawSetSelectable(playerid, ContainerPagePTD[playerid][0], true);

    ContainerPagePTD[playerid][1] = CreatePlayerTextDraw(playerid, 611.000, 235.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerPagePTD[playerid][1], 7.000, 92.500);
    PlayerTextDrawAlignment(playerid, ContainerPagePTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPagePTD[playerid][1], 66);
    PlayerTextDrawSetShadow(playerid, ContainerPagePTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPagePTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPagePTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, ContainerPagePTD[playerid][1], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerPagePTD[playerid][1], true);
    PlayerTextDrawSetSelectable(playerid, ContainerPagePTD[playerid][1], true);

    ContainerWeightBarPTD[playerid] = CreatePlayerTextDraw(playerid, 508.000, 123.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerWeightBarPTD[playerid], 99.000, 7.000);
    PlayerTextDrawAlignment(playerid, ContainerWeightBarPTD[playerid], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerWeightBarPTD[playerid], -1703681);
    PlayerTextDrawSetShadow(playerid, ContainerWeightBarPTD[playerid], 0);
    PlayerTextDrawSetOutline(playerid, ContainerWeightBarPTD[playerid], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerWeightBarPTD[playerid], 255);
    PlayerTextDrawFont(playerid, ContainerWeightBarPTD[playerid], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerWeightBarPTD[playerid], true);

    ContainerTextPTD[playerid][0] = CreatePlayerTextDraw(playerid, 406.000, 121.000, "Fristname_Lastnameeeeeee");
    PlayerTextDrawLetterSize(playerid, ContainerTextPTD[playerid][0], 0.230, 1.190);
    PlayerTextDrawAlignment(playerid, ContainerTextPTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerTextPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ContainerTextPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerTextPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerTextPTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, ContainerTextPTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerTextPTD[playerid][0], true);

    ContainerTextPTD[playerid][1] = CreatePlayerTextDraw(playerid, 615.000, 121.000, "2");
    PlayerTextDrawLetterSize(playerid, ContainerTextPTD[playerid][1], 0.230, 1.190);
    PlayerTextDrawAlignment(playerid, ContainerTextPTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerTextPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ContainerTextPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerTextPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerTextPTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, ContainerTextPTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerTextPTD[playerid][1], true);

    ContainerTextPTD[playerid][2] = CreatePlayerTextDraw(playerid, 557.000, 122.000, "25.0 / 25.0 kg");
    PlayerTextDrawLetterSize(playerid, ContainerTextPTD[playerid][2], 0.209, 0.990);
    PlayerTextDrawAlignment(playerid, ContainerTextPTD[playerid][2], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, ContainerTextPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ContainerTextPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerTextPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerTextPTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, ContainerTextPTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerTextPTD[playerid][2], true);
}

Destroy_ContainerPTD(playerid)
{
    for(new x = 0; x < 20; x++)
    {
        if(x < 2)
            PlayerTextDrawDestroy(playerid, ContainerPagePTD[playerid][x]);
        if(x < 3)
            PlayerTextDrawDestroy(playerid, ContainerTextPTD[playerid][x]);

        PlayerTextDrawDestroy(playerid, ContainerSlotPTD[playerid][x]);
        PlayerTextDrawDestroy(playerid, ContainerModelPTD[playerid][x]);
        PlayerTextDrawDestroy(playerid, ContainerNamePTD[playerid][x]);
        PlayerTextDrawDestroy(playerid, ContainerQuantityPTD[playerid][x]);
    }
    PlayerTextDrawDestroy(playerid, ContainerWeightBarPTD[playerid]);
}