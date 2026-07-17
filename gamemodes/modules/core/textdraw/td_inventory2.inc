// Inventory
new Text: InvBaseTD[6];
new Text: InvButtonTD[5];
new Text: InvTextTD[4];
new Text: InvSlotTD[20];

new PlayerText: InvModelPTD[MAX_PLAYERS][20];
new PlayerText: InvNamePTD[MAX_PLAYERS][20];
new PlayerText: InvQuantityPTD[MAX_PLAYERS][20];
new PlayerText: InvPagePTD[MAX_PLAYERS][2];
new PlayerText: InvWeightBarPTD[MAX_PLAYERS];
new PlayerText: InvTextPTD[MAX_PLAYERS][4];

// Container
new Text: ContainerBaseTD[5];
new Text: ContainerSlotTD[20];

new PlayerText: ContainerItemModelPTD[MAX_PLAYERS][20];
new PlayerText: ContainerItemNamePTD[MAX_PLAYERS][20];
new PlayerText: ContainerItemQuantityPTD[MAX_PLAYERS][20];
new PlayerText: ContainerPagePTD[MAX_PLAYERS][2];
new PlayerText: ContainerWeightBarPTD[MAX_PLAYERS];
new PlayerText: ContainerTextPTD[MAX_PLAYERS][3];

// Inventory
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

    InvSlotTD[0] = TextDrawCreate(115.000, 143.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[0], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[0], 66);
    TextDrawSetShadow(InvSlotTD[0], 0);
    TextDrawSetOutline(InvSlotTD[0], 0);
    TextDrawBackgroundColour(InvSlotTD[0], 255);
    TextDrawFont(InvSlotTD[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[0], true);
    TextDrawSetSelectable(InvSlotTD[0], true);

    InvSlotTD[1] = TextDrawCreate(155.000, 143.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[1], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[1], 66);
    TextDrawSetShadow(InvSlotTD[1], 0);
    TextDrawSetOutline(InvSlotTD[1], 0);
    TextDrawBackgroundColour(InvSlotTD[1], 255);
    TextDrawFont(InvSlotTD[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[1], true);
    TextDrawSetSelectable(InvSlotTD[1], true);

    InvSlotTD[2] = TextDrawCreate(195.000, 143.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[2], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[2], 66);
    TextDrawSetShadow(InvSlotTD[2], 0);
    TextDrawSetOutline(InvSlotTD[2], 0);
    TextDrawBackgroundColour(InvSlotTD[2], 255);
    TextDrawFont(InvSlotTD[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[2], true);
    TextDrawSetSelectable(InvSlotTD[2], true);

    InvSlotTD[3] = TextDrawCreate(235.000, 143.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[3], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[3], 66);
    TextDrawSetShadow(InvSlotTD[3], 0);
    TextDrawSetOutline(InvSlotTD[3], 0);
    TextDrawBackgroundColour(InvSlotTD[3], 255);
    TextDrawFont(InvSlotTD[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[3], true);
    TextDrawSetSelectable(InvSlotTD[3], true);

    InvSlotTD[4] = TextDrawCreate(275.000, 143.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[4], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[4], 66);
    TextDrawSetShadow(InvSlotTD[4], 0);
    TextDrawSetOutline(InvSlotTD[4], 0);
    TextDrawBackgroundColour(InvSlotTD[4], 255);
    TextDrawFont(InvSlotTD[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[4], true);
    TextDrawSetSelectable(InvSlotTD[4], true);

    InvSlotTD[5] = TextDrawCreate(115.000, 190.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[5], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[5], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[5], 66);
    TextDrawSetShadow(InvSlotTD[5], 0);
    TextDrawSetOutline(InvSlotTD[5], 0);
    TextDrawBackgroundColour(InvSlotTD[5], 255);
    TextDrawFont(InvSlotTD[5], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[5], true);
    TextDrawSetSelectable(InvSlotTD[5], true);

    InvSlotTD[6] = TextDrawCreate(155.000, 190.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[6], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[6], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[6], 66);
    TextDrawSetShadow(InvSlotTD[6], 0);
    TextDrawSetOutline(InvSlotTD[6], 0);
    TextDrawBackgroundColour(InvSlotTD[6], 255);
    TextDrawFont(InvSlotTD[6], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[6], true);
    TextDrawSetSelectable(InvSlotTD[6], true);

    InvSlotTD[7] = TextDrawCreate(195.000, 190.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[7], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[7], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[7], 66);
    TextDrawSetShadow(InvSlotTD[7], 0);
    TextDrawSetOutline(InvSlotTD[7], 0);
    TextDrawBackgroundColour(InvSlotTD[7], 255);
    TextDrawFont(InvSlotTD[7], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[7], true);
    TextDrawSetSelectable(InvSlotTD[7], true);

    InvSlotTD[8] = TextDrawCreate(235.000, 190.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[8], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[8], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[8], 66);
    TextDrawSetShadow(InvSlotTD[8], 0);
    TextDrawSetOutline(InvSlotTD[8], 0);
    TextDrawBackgroundColour(InvSlotTD[8], 255);
    TextDrawFont(InvSlotTD[8], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[8], true);
    TextDrawSetSelectable(InvSlotTD[8], true);

    InvSlotTD[9] = TextDrawCreate(275.000, 190.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[9], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[9], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[9], 66);
    TextDrawSetShadow(InvSlotTD[9], 0);
    TextDrawSetOutline(InvSlotTD[9], 0);
    TextDrawBackgroundColour(InvSlotTD[9], 255);
    TextDrawFont(InvSlotTD[9], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[9], true);
    TextDrawSetSelectable(InvSlotTD[9], true);

    InvSlotTD[10] = TextDrawCreate(115.000, 237.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[10], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[10], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[10], 66);
    TextDrawSetShadow(InvSlotTD[10], 0);
    TextDrawSetOutline(InvSlotTD[10], 0);
    TextDrawBackgroundColour(InvSlotTD[10], 255);
    TextDrawFont(InvSlotTD[10], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[10], true);
    TextDrawSetSelectable(InvSlotTD[10], true);

    InvSlotTD[11] = TextDrawCreate(155.000, 237.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[11], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[11], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[11], 66);
    TextDrawSetShadow(InvSlotTD[11], 0);
    TextDrawSetOutline(InvSlotTD[11], 0);
    TextDrawBackgroundColour(InvSlotTD[11], 255);
    TextDrawFont(InvSlotTD[11], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[11], true);
    TextDrawSetSelectable(InvSlotTD[11], true);

    InvSlotTD[12] = TextDrawCreate(195.000, 237.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[12], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[12], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[12], 66);
    TextDrawSetShadow(InvSlotTD[12], 0);
    TextDrawSetOutline(InvSlotTD[12], 0);
    TextDrawBackgroundColour(InvSlotTD[12], 255);
    TextDrawFont(InvSlotTD[12], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[12], true);
    TextDrawSetSelectable(InvSlotTD[12], true);

    InvSlotTD[13] = TextDrawCreate(235.000, 237.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[13], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[13], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[13], 66);
    TextDrawSetShadow(InvSlotTD[13], 0);
    TextDrawSetOutline(InvSlotTD[13], 0);
    TextDrawBackgroundColour(InvSlotTD[13], 255);
    TextDrawFont(InvSlotTD[13], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[13], true);
    TextDrawSetSelectable(InvSlotTD[13], true);

    InvSlotTD[14] = TextDrawCreate(275.000, 237.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[14], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[14], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[14], 66);
    TextDrawSetShadow(InvSlotTD[14], 0);
    TextDrawSetOutline(InvSlotTD[14], 0);
    TextDrawBackgroundColour(InvSlotTD[14], 255);
    TextDrawFont(InvSlotTD[14], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[14], true);
    TextDrawSetSelectable(InvSlotTD[14], true);

    InvSlotTD[15] = TextDrawCreate(115.000, 284.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[15], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[15], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[15], 66);
    TextDrawSetShadow(InvSlotTD[15], 0);
    TextDrawSetOutline(InvSlotTD[15], 0);
    TextDrawBackgroundColour(InvSlotTD[15], 255);
    TextDrawFont(InvSlotTD[15], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[15], true);
    TextDrawSetSelectable(InvSlotTD[15], true);

    InvSlotTD[16] = TextDrawCreate(155.000, 284.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[16], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[16], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[16], 66);
    TextDrawSetShadow(InvSlotTD[16], 0);
    TextDrawSetOutline(InvSlotTD[16], 0);
    TextDrawBackgroundColour(InvSlotTD[16], 255);
    TextDrawFont(InvSlotTD[16], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[16], true);
    TextDrawSetSelectable(InvSlotTD[16], true);

    InvSlotTD[17] = TextDrawCreate(195.000, 284.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[17], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[17], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[17], 66);
    TextDrawSetShadow(InvSlotTD[17], 0);
    TextDrawSetOutline(InvSlotTD[17], 0);
    TextDrawBackgroundColour(InvSlotTD[17], 255);
    TextDrawFont(InvSlotTD[17], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[17], true);
    TextDrawSetSelectable(InvSlotTD[17], true);

    InvSlotTD[18] = TextDrawCreate(235.000, 284.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[18], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[18], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[18], 66);
    TextDrawSetShadow(InvSlotTD[18], 0);
    TextDrawSetOutline(InvSlotTD[18], 0);
    TextDrawBackgroundColour(InvSlotTD[18], 255);
    TextDrawFont(InvSlotTD[18], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[18], true);
    TextDrawSetSelectable(InvSlotTD[18], true);

    InvSlotTD[19] = TextDrawCreate(275.000, 284.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlotTD[19], 38.000, 44.000);
    TextDrawAlignment(InvSlotTD[19], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlotTD[19], 66);
    TextDrawSetShadow(InvSlotTD[19], 0);
    TextDrawSetOutline(InvSlotTD[19], 0);
    TextDrawBackgroundColour(InvSlotTD[19], 255);
    TextDrawFont(InvSlotTD[19], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlotTD[19], true);
    TextDrawSetSelectable(InvSlotTD[19], true);
    return 1; // textdraw berhasil dibuat
}

Create_InvPTD(playerid)
{
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

    InvTextPTD[playerid][2] = CreatePlayerTextDraw(playerid, 261.000, 122.000, "25.0 / 25.0 kg");
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
    return 1;
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
    return 1;
}

// Container
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

    ContainerSlotTD[0] = TextDrawCreate(411.000, 143.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[0], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[0], 66);
    TextDrawSetShadow(ContainerSlotTD[0], 0);
    TextDrawSetOutline(ContainerSlotTD[0], 0);
    TextDrawBackgroundColour(ContainerSlotTD[0], 255);
    TextDrawFont(ContainerSlotTD[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[0], true);
    TextDrawSetSelectable(ContainerSlotTD[0], true);

    ContainerSlotTD[1] = TextDrawCreate(451.000, 143.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[1], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[1], 66);
    TextDrawSetShadow(ContainerSlotTD[1], 0);
    TextDrawSetOutline(ContainerSlotTD[1], 0);
    TextDrawBackgroundColour(ContainerSlotTD[1], 255);
    TextDrawFont(ContainerSlotTD[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[1], true);
    TextDrawSetSelectable(ContainerSlotTD[1], true);

    ContainerSlotTD[2] = TextDrawCreate(491.000, 143.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[2], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[2], 66);
    TextDrawSetShadow(ContainerSlotTD[2], 0);
    TextDrawSetOutline(ContainerSlotTD[2], 0);
    TextDrawBackgroundColour(ContainerSlotTD[2], 255);
    TextDrawFont(ContainerSlotTD[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[2], true);
    TextDrawSetSelectable(ContainerSlotTD[2], true);

    ContainerSlotTD[3] = TextDrawCreate(531.000, 143.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[3], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[3], 66);
    TextDrawSetShadow(ContainerSlotTD[3], 0);
    TextDrawSetOutline(ContainerSlotTD[3], 0);
    TextDrawBackgroundColour(ContainerSlotTD[3], 255);
    TextDrawFont(ContainerSlotTD[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[3], true);
    TextDrawSetSelectable(ContainerSlotTD[3], true);

    ContainerSlotTD[4] = TextDrawCreate(571.000, 143.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[4], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[4], 66);
    TextDrawSetShadow(ContainerSlotTD[4], 0);
    TextDrawSetOutline(ContainerSlotTD[4], 0);
    TextDrawBackgroundColour(ContainerSlotTD[4], 255);
    TextDrawFont(ContainerSlotTD[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[4], true);
    TextDrawSetSelectable(ContainerSlotTD[4], true);

    ContainerSlotTD[5]= TextDrawCreate(411.000, 190.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[5], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[5], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[5], 66);
    TextDrawSetShadow(ContainerSlotTD[5], 0);
    TextDrawSetOutline(ContainerSlotTD[5], 0);
    TextDrawBackgroundColour(ContainerSlotTD[5], 255);
    TextDrawFont(ContainerSlotTD[5], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[5], true);
    TextDrawSetSelectable(ContainerSlotTD[5], true);

    ContainerSlotTD[6]= TextDrawCreate(451.000, 190.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[6], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[6], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[6], 66);
    TextDrawSetShadow(ContainerSlotTD[6], 0);
    TextDrawSetOutline(ContainerSlotTD[6], 0);
    TextDrawBackgroundColour(ContainerSlotTD[6], 255);
    TextDrawFont(ContainerSlotTD[6], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[6], true);
    TextDrawSetSelectable(ContainerSlotTD[6], true);

    ContainerSlotTD[7]= TextDrawCreate(491.000, 190.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[7], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[7], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[7], 66);
    TextDrawSetShadow(ContainerSlotTD[7], 0);
    TextDrawSetOutline(ContainerSlotTD[7], 0);
    TextDrawBackgroundColour(ContainerSlotTD[7], 255);
    TextDrawFont(ContainerSlotTD[7], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[7], true);
    TextDrawSetSelectable(ContainerSlotTD[7], true);

    ContainerSlotTD[8]= TextDrawCreate(531.000, 190.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[8], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[8], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[8], 66);
    TextDrawSetShadow(ContainerSlotTD[8], 0);
    TextDrawSetOutline(ContainerSlotTD[8], 0);
    TextDrawBackgroundColour(ContainerSlotTD[8], 255);
    TextDrawFont(ContainerSlotTD[8], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[8], true);
    TextDrawSetSelectable(ContainerSlotTD[8], true);

    ContainerSlotTD[9]= TextDrawCreate(571.000, 190.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[9], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[9], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[9], 66);
    TextDrawSetShadow(ContainerSlotTD[9], 0);
    TextDrawSetOutline(ContainerSlotTD[9], 0);
    TextDrawBackgroundColour(ContainerSlotTD[9], 255);
    TextDrawFont(ContainerSlotTD[9], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[9], true);
    TextDrawSetSelectable(ContainerSlotTD[9], true);

    ContainerSlotTD[10]= TextDrawCreate(411.000, 237.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[10], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[10], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[10], 66);
    TextDrawSetShadow(ContainerSlotTD[10], 0);
    TextDrawSetOutline(ContainerSlotTD[10], 0);
    TextDrawBackgroundColour(ContainerSlotTD[10], 255);
    TextDrawFont(ContainerSlotTD[10], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[10], true);
    TextDrawSetSelectable(ContainerSlotTD[10], true);

    ContainerSlotTD[11]= TextDrawCreate(451.000, 237.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[11], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[11], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[11], 66);
    TextDrawSetShadow(ContainerSlotTD[11], 0);
    TextDrawSetOutline(ContainerSlotTD[11], 0);
    TextDrawBackgroundColour(ContainerSlotTD[11], 255);
    TextDrawFont(ContainerSlotTD[11], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[11], true);
    TextDrawSetSelectable(ContainerSlotTD[11], true);

    ContainerSlotTD[12]= TextDrawCreate(491.000, 237.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[12], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[12], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[12], 66);
    TextDrawSetShadow(ContainerSlotTD[12], 0);
    TextDrawSetOutline(ContainerSlotTD[12], 0);
    TextDrawBackgroundColour(ContainerSlotTD[12], 255);
    TextDrawFont(ContainerSlotTD[12], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[12], true);
    TextDrawSetSelectable(ContainerSlotTD[12], true);

    ContainerSlotTD[13]= TextDrawCreate(531.000, 237.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[13], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[13], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[13], 66);
    TextDrawSetShadow(ContainerSlotTD[13], 0);
    TextDrawSetOutline(ContainerSlotTD[13], 0);
    TextDrawBackgroundColour(ContainerSlotTD[13], 255);
    TextDrawFont(ContainerSlotTD[13], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[13], true);
    TextDrawSetSelectable(ContainerSlotTD[13], true);

    ContainerSlotTD[14]= TextDrawCreate(571.000, 237.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[14], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[14], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[14], 66);
    TextDrawSetShadow(ContainerSlotTD[14], 0);
    TextDrawSetOutline(ContainerSlotTD[14], 0);
    TextDrawBackgroundColour(ContainerSlotTD[14], 255);
    TextDrawFont(ContainerSlotTD[14], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[14], true);
    TextDrawSetSelectable(ContainerSlotTD[14], true);

    ContainerSlotTD[15]= TextDrawCreate(411.000, 284.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[15], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[15], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[15], 66);
    TextDrawSetShadow(ContainerSlotTD[15], 0);
    TextDrawSetOutline(ContainerSlotTD[15], 0);
    TextDrawBackgroundColour(ContainerSlotTD[15], 255);
    TextDrawFont(ContainerSlotTD[15], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[15], true);
    TextDrawSetSelectable(ContainerSlotTD[15], true);

    ContainerSlotTD[16]= TextDrawCreate(451.000, 284.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[16], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[16], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[16], 66);
    TextDrawSetShadow(ContainerSlotTD[16], 0);
    TextDrawSetOutline(ContainerSlotTD[16], 0);
    TextDrawBackgroundColour(ContainerSlotTD[16], 255);
    TextDrawFont(ContainerSlotTD[16], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[16], true);
    TextDrawSetSelectable(ContainerSlotTD[16], true);

    ContainerSlotTD[17] = TextDrawCreate(491.000, 284.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[17], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[17], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[17], 66);
    TextDrawSetShadow(ContainerSlotTD[17], 0);
    TextDrawSetOutline(ContainerSlotTD[17], 0);
    TextDrawBackgroundColour(ContainerSlotTD[17], 255);
    TextDrawFont(ContainerSlotTD[17], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[17], true);
    TextDrawSetSelectable(ContainerSlotTD[17], true);

    ContainerSlotTD[18]= TextDrawCreate(531.000, 284.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[18], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[18], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[18], 66);
    TextDrawSetShadow(ContainerSlotTD[18], 0);
    TextDrawSetOutline(ContainerSlotTD[18], 0);
    TextDrawBackgroundColour(ContainerSlotTD[18], 255);
    TextDrawFont(ContainerSlotTD[18], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[18], true);
    TextDrawSetSelectable(ContainerSlotTD[18], true);

    ContainerSlotTD[19]= TextDrawCreate(571.000, 284.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlotTD[19], 38.000, 44.000);
    TextDrawAlignment(ContainerSlotTD[19], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlotTD[19], 66);
    TextDrawSetShadow(ContainerSlotTD[19], 0);
    TextDrawSetOutline(ContainerSlotTD[19], 0);
    TextDrawBackgroundColour(ContainerSlotTD[19], 255);
    TextDrawFont(ContainerSlotTD[19], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlotTD[19], true);
    TextDrawSetSelectable(ContainerSlotTD[19], true);
    return 1;
}

Create_ContainerPTD(playerid)
{
    ContainerItemModelPTD[playerid][0] = CreatePlayerTextDraw(playerid, 411.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][0], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][0], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][0], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][0], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][0], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][0], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][0], 0, 0);

    ContainerItemNamePTD[playerid][0] = CreatePlayerTextDraw(playerid, 413.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][0], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][0], 447.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][0], true);

    ContainerItemModelPTD[playerid][1] = CreatePlayerTextDraw(playerid, 451.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][1], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][1], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][1], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][1], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][1], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][1], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][1], 0, 0);

    ContainerItemNamePTD[playerid][1] = CreatePlayerTextDraw(playerid, 453.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][1], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][1], 487.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][1], true);

    ContainerItemModelPTD[playerid][2] = CreatePlayerTextDraw(playerid, 491.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][2], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][2], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][2], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][2], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][2], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][2], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][2], 0, 0);

    ContainerItemNamePTD[playerid][2] = CreatePlayerTextDraw(playerid, 493.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][2], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][2], 527.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][2], true);

    ContainerItemModelPTD[playerid][3] = CreatePlayerTextDraw(playerid, 531.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][3], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][3], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][3], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][3], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][3], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][3], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][3], 0, 0);

    ContainerItemNamePTD[playerid][3] = CreatePlayerTextDraw(playerid, 533.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][3], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][3], 567.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][3], true);

    ContainerItemModelPTD[playerid][4] = CreatePlayerTextDraw(playerid, 571.000, 143.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][4], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][4], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][4], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][4], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][4], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][4], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][4], 0, 0);

    ContainerItemNamePTD[playerid][4] = CreatePlayerTextDraw(playerid, 573.000, 145.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][4], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][4], 607.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][4], true);

    ContainerItemModelPTD[playerid][5] = CreatePlayerTextDraw(playerid, 411.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][5], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][5], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][5], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][5], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][5], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][5], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][5], 0, 0);

    ContainerItemNamePTD[playerid][5] = CreatePlayerTextDraw(playerid, 413.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][5], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][5], 447.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][5], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][5], true);

    ContainerItemModelPTD[playerid][6] = CreatePlayerTextDraw(playerid, 451.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][6], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][6], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][6], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][6], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][6], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][6], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][6], 0, 0);

    ContainerItemNamePTD[playerid][6] = CreatePlayerTextDraw(playerid, 453.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][6], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][6], 487.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][6], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][6], true);

    ContainerItemModelPTD[playerid][7] = CreatePlayerTextDraw(playerid, 491.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][7], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][7], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][7], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][7], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][7], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][7], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][7], 0, 0);

    ContainerItemNamePTD[playerid][7] = CreatePlayerTextDraw(playerid, 493.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][7], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][7], 527.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][7], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][7], true);

    ContainerItemModelPTD[playerid][8] = CreatePlayerTextDraw(playerid, 531.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][8], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][8], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][8], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][8], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][8], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][8], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][8], 0, 0);

    ContainerItemNamePTD[playerid][8] = CreatePlayerTextDraw(playerid, 533.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][8], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][8], 567.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][8], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][8], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][8], true);

    ContainerItemModelPTD[playerid][9] = CreatePlayerTextDraw(playerid, 571.000, 190.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][9], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][9], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][9], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][9], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][9], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][9], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][9], 0, 0);

    ContainerItemNamePTD[playerid][9] = CreatePlayerTextDraw(playerid, 573.000, 192.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][9], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][9], 607.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][9], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][9], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][9], true);

    ContainerItemModelPTD[playerid][10] = CreatePlayerTextDraw(playerid, 411.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][10], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][10], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][10], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][10], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][10], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][10], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][10], 0, 0);

    ContainerItemNamePTD[playerid][10] = CreatePlayerTextDraw(playerid, 413.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][10], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][10], 447.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][10], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][10], true);

    ContainerItemModelPTD[playerid][11] = CreatePlayerTextDraw(playerid, 451.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][11], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][11], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][11], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][11], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][11], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][11], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][11], 0, 0);

    ContainerItemNamePTD[playerid][11] = CreatePlayerTextDraw(playerid, 453.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][11], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][11], 487.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][11], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][11], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][11], true);

    ContainerItemModelPTD[playerid][12] = CreatePlayerTextDraw(playerid, 491.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][12], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][12], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][12], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][12], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][12], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][12], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][12], 0, 0);

    ContainerItemNamePTD[playerid][12] = CreatePlayerTextDraw(playerid, 493.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][12], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][12], 527.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][12], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][12], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][12], true);

    ContainerItemModelPTD[playerid][13] = CreatePlayerTextDraw(playerid, 531.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][13], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][13], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][13], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][13], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][13], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][13], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][13], 0, 0);

    ContainerItemNamePTD[playerid][13] = CreatePlayerTextDraw(playerid, 533.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][13], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][13], 567.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][13], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][13], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][13], true);

    ContainerItemModelPTD[playerid][14] = CreatePlayerTextDraw(playerid, 571.000, 237.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][14], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][14], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][14], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][14], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][14], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][14], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][14], 0, 0);

    ContainerItemNamePTD[playerid][14] = CreatePlayerTextDraw(playerid, 573.000, 239.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][14], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][14], 607.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][14], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][14], true);

    ContainerItemModelPTD[playerid][15] = CreatePlayerTextDraw(playerid, 411.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][15], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][15], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][15], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][15], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][15], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][15], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][15], 0, 0);

    ContainerItemNamePTD[playerid][15] = CreatePlayerTextDraw(playerid, 413.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][15], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][15], 447.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][15], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][15], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][15], true);

    ContainerItemModelPTD[playerid][16] = CreatePlayerTextDraw(playerid, 451.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][16], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][16], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][16], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][16], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][16], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][16], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][16], 0, 0);

    ContainerItemNamePTD[playerid][16] = CreatePlayerTextDraw(playerid, 453.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][16], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][16], 487.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][16], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][16], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][16], true);

    ContainerItemModelPTD[playerid][17] = CreatePlayerTextDraw(playerid, 491.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][17], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][17], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][17], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][17], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][17], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][17], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][17], 0, 0);

    ContainerItemNamePTD[playerid][17] = CreatePlayerTextDraw(playerid, 493.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][17], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][17], 527.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][17], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][17], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][17], true);

    ContainerItemModelPTD[playerid][18] = CreatePlayerTextDraw(playerid, 531.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][18], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][18], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][18], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][18], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][18], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][18], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][18], 0, 0);

    ContainerItemNamePTD[playerid][18] = CreatePlayerTextDraw(playerid, 533.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][18], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][18], 567.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][18], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][18], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][18], true);

    ContainerItemModelPTD[playerid][19] = CreatePlayerTextDraw(playerid, 571.000, 284.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerItemModelPTD[playerid][19], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerItemModelPTD[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemModelPTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemModelPTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemModelPTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemModelPTD[playerid][19], 0);
    PlayerTextDrawFont(playerid, ContainerItemModelPTD[playerid][19], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerItemModelPTD[playerid][19], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerItemModelPTD[playerid][19], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerItemModelPTD[playerid][19], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerItemModelPTD[playerid][19], 0, 0);

    ContainerItemNamePTD[playerid][19] = CreatePlayerTextDraw(playerid, 573.000, 286.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemNamePTD[playerid][19], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemNamePTD[playerid][19], 607.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemNamePTD[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemNamePTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemNamePTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemNamePTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemNamePTD[playerid][19], 150);
    PlayerTextDrawFont(playerid, ContainerItemNamePTD[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemNamePTD[playerid][19], true);

    ContainerItemQuantityPTD[playerid][0] = CreatePlayerTextDraw(playerid, 446.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][0], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][0], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][0], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][0], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][0], true);

    ContainerItemQuantityPTD[playerid][1] = CreatePlayerTextDraw(playerid, 486.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][1], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][1], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][1], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][1], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][1], true);

    ContainerItemQuantityPTD[playerid][2] = CreatePlayerTextDraw(playerid, 526.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][2], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][2], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][2], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][2], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][2], true);

    ContainerItemQuantityPTD[playerid][3] = CreatePlayerTextDraw(playerid, 566.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][3], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][3], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][3], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][3], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][3], true);

    ContainerItemQuantityPTD[playerid][4] = CreatePlayerTextDraw(playerid, 606.000, 177.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][4], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][4], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][4], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][4], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][4], true);

    ContainerItemQuantityPTD[playerid][5] = CreatePlayerTextDraw(playerid, 446.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][5], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][5], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][5], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][5], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][5], true);

    ContainerItemQuantityPTD[playerid][6] = CreatePlayerTextDraw(playerid, 486.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][6], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][6], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][6], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][6], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][6], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][6], true);

    ContainerItemQuantityPTD[playerid][7] = CreatePlayerTextDraw(playerid, 526.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][7], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][7], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][7], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][7], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][7], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][7], true);

    ContainerItemQuantityPTD[playerid][8] = CreatePlayerTextDraw(playerid, 566.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][8], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][8], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][8], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][8], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][8], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][8], true);

    ContainerItemQuantityPTD[playerid][9] = CreatePlayerTextDraw(playerid, 606.000, 224.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][9], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][9], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][9], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][9], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][9], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][9], true);

    ContainerItemQuantityPTD[playerid][10] = CreatePlayerTextDraw(playerid, 446.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][10], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][10], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][10], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][10], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][10], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][10], true);

    ContainerItemQuantityPTD[playerid][11] = CreatePlayerTextDraw(playerid, 486.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][11], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][11], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][11], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][11], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][11], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][11], true);

    ContainerItemQuantityPTD[playerid][12] = CreatePlayerTextDraw(playerid, 526.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][12], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][12], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][12], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][12], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][12], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][12], true);

    ContainerItemQuantityPTD[playerid][13] = CreatePlayerTextDraw(playerid, 566.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][13], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][13], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][13], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][13], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][13], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][13], true);

    ContainerItemQuantityPTD[playerid][14] = CreatePlayerTextDraw(playerid, 606.000, 271.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][14], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][14], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][14], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][14], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][14], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][14], true);

    ContainerItemQuantityPTD[playerid][15] = CreatePlayerTextDraw(playerid, 446.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][15], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][15], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][15], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][15], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][15], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][15], true);

    ContainerItemQuantityPTD[playerid][16] = CreatePlayerTextDraw(playerid, 486.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][16], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][16], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][16], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][16], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][16], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][16], true);

    ContainerItemQuantityPTD[playerid][17] = CreatePlayerTextDraw(playerid, 526.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][17], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][17], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][17], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][17], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][17], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][17], true);

    ContainerItemQuantityPTD[playerid][18] = CreatePlayerTextDraw(playerid, 566.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][18], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][18], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][18], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][18], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][18], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][18], true);

    ContainerItemQuantityPTD[playerid][19] = CreatePlayerTextDraw(playerid, 606.000, 318.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemQuantityPTD[playerid][19], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemQuantityPTD[playerid][19], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemQuantityPTD[playerid][19], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemQuantityPTD[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemQuantityPTD[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemQuantityPTD[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemQuantityPTD[playerid][19], 150);
    PlayerTextDrawFont(playerid, ContainerItemQuantityPTD[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemQuantityPTD[playerid][19], true);

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
    return 1;
}

Destroy_ContainerPTD(playerid)
{
    for(new x = 0; x < 20; x++)
    {
        if(x < 2)
            PlayerTextDrawDestroy(playerid, ContainerPagePTD[playerid][x]);
        if(x < 3)
            PlayerTextDrawDestroy(playerid, ContainerTextPTD[playerid][x]);

        PlayerTextDrawDestroy(playerid, ContainerItemModelPTD[playerid][x]);
        PlayerTextDrawDestroy(playerid, ContainerItemNamePTD[playerid][x]);
        PlayerTextDrawDestroy(playerid, ContainerItemQuantityPTD[playerid][x]);
    }
    PlayerTextDrawDestroy(playerid, ContainerWeightBarPTD[playerid]);
    return 1;
}