new Text: BaseInvTD[35];
new Text: InvSlot[20];
new Text: ContainerSlot[20];
new Text: Button[5];
new Text: ExtraButton[4];

/*
Button[0] = Close Button
Button[1] = Amount Button
Button[2] = Use Button
Button[3] = Give Button
Button[4] = Info Button

ExtraButton[0] = Perlihatkan
ExtraButton[1] = P. Sekitar (Perlihatkan Sekitar)
ExtraButton[2] = Lihat
ExtraButton[3] = Batal
*/

new PlayerText: InvPage[MAX_PLAYERS][2];
new PlayerText: InvPrevModel[MAX_PLAYERS][20];
new PlayerText: InvItemName[MAX_PLAYERS][20];
new PlayerText: InvItemAmount[MAX_PLAYERS][20];
new PlayerText: InvPlayerName[MAX_PLAYERS];
new PlayerText: InvWeightBar[MAX_PLAYERS];
new PlayerText: InvWeightText[MAX_PLAYERS];
new PlayerText: InvPageText[MAX_PLAYERS];

new PlayerText: ContainerPage[MAX_PLAYERS][2];
new PlayerText: ContainerPrevModel[MAX_PLAYERS][20];
new PlayerText: ContainerItemName[MAX_PLAYERS][20];
new PlayerText: ContainerItemAmount[MAX_PLAYERS][20];
new PlayerText: ContainerTitle[MAX_PLAYERS];
new PlayerText: ContainerWeightBar[MAX_PLAYERS];
new PlayerText: ContainerWeightText[MAX_PLAYERS];
new PlayerText: ContainerPageText[MAX_PLAYERS];
new PlayerText: ContainerModeText[MAX_PLAYERS][3];

new PlayerText: AmountTD[MAX_PLAYERS];

Create_InvTD()
{
    BaseInvTD[0] = TextDrawCreate(90.000, 133.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[0], 496.000, 225.000);
    TextDrawAlignment(BaseInvTD[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[0], 66);
    TextDrawSetShadow(BaseInvTD[0], 0);
    TextDrawSetOutline(BaseInvTD[0], 0);
    TextDrawBackgroundColour(BaseInvTD[0], 255);
    TextDrawFont(BaseInvTD[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[0], true);

    BaseInvTD[1] = TextDrawCreate(96.000, 153.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[1], 204.000, 199.000);
    TextDrawAlignment(BaseInvTD[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[1], 66);
    TextDrawSetShadow(BaseInvTD[1], 0);
    TextDrawSetOutline(BaseInvTD[1], 0);
    TextDrawBackgroundColour(BaseInvTD[1], 255);
    TextDrawFont(BaseInvTD[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[1], true);

    BaseInvTD[2] = TextDrawCreate(90.000, 132.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[2], 496.000, 5.000);
    TextDrawAlignment(BaseInvTD[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[2], -2686721);
    TextDrawSetShadow(BaseInvTD[2], 0);
    TextDrawSetOutline(BaseInvTD[2], 0);
    TextDrawBackgroundColour(BaseInvTD[2], 255);
    TextDrawFont(BaseInvTD[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[2], true);

    BaseInvTD[3] = TextDrawCreate(310.000, 153.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[3], 56.000, 199.000);
    TextDrawAlignment(BaseInvTD[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[3], 66);
    TextDrawSetShadow(BaseInvTD[3], 0);
    TextDrawSetOutline(BaseInvTD[3], 0);
    TextDrawBackgroundColour(BaseInvTD[3], 255);
    TextDrawFont(BaseInvTD[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[3], true);

    BaseInvTD[4] = TextDrawCreate(96.000, 138.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[4], 90.000, 13.000);
    TextDrawAlignment(BaseInvTD[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[4], 66);
    TextDrawSetShadow(BaseInvTD[4], 0);
    TextDrawSetOutline(BaseInvTD[4], 0);
    TextDrawBackgroundColour(BaseInvTD[4], 255);
    TextDrawFont(BaseInvTD[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[4], true);

    BaseInvTD[5] = TextDrawCreate(188.000, 138.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[5], 112.000, 13.000);
    TextDrawAlignment(BaseInvTD[5], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[5], 66);
    TextDrawSetShadow(BaseInvTD[5], 0);
    TextDrawSetOutline(BaseInvTD[5], 0);
    TextDrawBackgroundColour(BaseInvTD[5], 255);
    TextDrawFont(BaseInvTD[5], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[5], true);

    BaseInvTD[6] = TextDrawCreate(190.000, 140.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[6], 108.000, 8.000);
    TextDrawAlignment(BaseInvTD[6], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[6], -2139094785);
    TextDrawSetShadow(BaseInvTD[6], 0);
    TextDrawSetOutline(BaseInvTD[6], 0);
    TextDrawBackgroundColour(BaseInvTD[6], 255);
    TextDrawFont(BaseInvTD[6], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[6], true);

    BaseInvTD[7] = TextDrawCreate(369.000, 153.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[7], 204.000, 199.000);
    TextDrawAlignment(BaseInvTD[7], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[7], 66);
    TextDrawSetShadow(BaseInvTD[7], 0);
    TextDrawSetOutline(BaseInvTD[7], 0);
    TextDrawBackgroundColour(BaseInvTD[7], 255);
    TextDrawFont(BaseInvTD[7], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[7], true);

    BaseInvTD[8] = TextDrawCreate(369.000, 138.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[8], 90.000, 13.000);
    TextDrawAlignment(BaseInvTD[8], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[8], 66);
    TextDrawSetShadow(BaseInvTD[8], 0);
    TextDrawSetOutline(BaseInvTD[8], 0);
    TextDrawBackgroundColour(BaseInvTD[8], 255);
    TextDrawFont(BaseInvTD[8], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[8], true);

    BaseInvTD[9] = TextDrawCreate(461.000, 138.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[9], 70.000, 13.000);
    TextDrawAlignment(BaseInvTD[9], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[9], 66);
    TextDrawSetShadow(BaseInvTD[9], 0);
    TextDrawSetOutline(BaseInvTD[9], 0);
    TextDrawBackgroundColour(BaseInvTD[9], 255);
    TextDrawFont(BaseInvTD[9], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[9], true);

    BaseInvTD[10] = TextDrawCreate(463.000, 140.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[10], 66.000, 8.000);
    TextDrawAlignment(BaseInvTD[10], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[10], -2139094785);
    TextDrawSetShadow(BaseInvTD[10], 0);
    TextDrawSetOutline(BaseInvTD[10], 0);
    TextDrawBackgroundColour(BaseInvTD[10], 255);
    TextDrawFont(BaseInvTD[10], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[10], true);

    BaseInvTD[11] = TextDrawCreate(313.000, 288.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[11], 50.000, 2.000);
    TextDrawAlignment(BaseInvTD[11], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[11], -1);
    TextDrawSetShadow(BaseInvTD[11], 0);
    TextDrawSetOutline(BaseInvTD[11], 0);
    TextDrawBackgroundColour(BaseInvTD[11], 255);
    TextDrawFont(BaseInvTD[11], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[11], true);

    BaseInvTD[12] = TextDrawCreate(577.000, 131.800, "X");
    TextDrawLetterSize(BaseInvTD[12], 0.418, 0.597);
    TextDrawTextSize(BaseInvTD[12], 3.000, 0.000);
    TextDrawAlignment(BaseInvTD[12], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(BaseInvTD[12], -1);
    TextDrawSetShadow(BaseInvTD[12], 0);
    TextDrawSetOutline(BaseInvTD[12], 0);
    TextDrawBackgroundColour(BaseInvTD[12], 150);
    TextDrawFont(BaseInvTD[12], TEXT_DRAW_FONT_3);
    TextDrawSetProportional(BaseInvTD[12], true);

    BaseInvTD[13] = TextDrawCreate(318.000, 244.798, "BERIKAN");
    TextDrawLetterSize(BaseInvTD[13], 0.310, 1.399);
    TextDrawTextSize(BaseInvTD[13], 3.000, 0.000);
    TextDrawAlignment(BaseInvTD[13], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[13], -1);
    TextDrawSetShadow(BaseInvTD[13], 0);
    TextDrawSetOutline(BaseInvTD[13], 0);
    TextDrawBackgroundColour(BaseInvTD[13], 150);
    TextDrawFont(BaseInvTD[13], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(BaseInvTD[13], true);

    BaseInvTD[14] = TextDrawCreate(327.000, 266.799, "INFO");
    TextDrawLetterSize(BaseInvTD[14], 0.298, 1.399);
    TextDrawTextSize(BaseInvTD[14], 3.000, 0.000);
    TextDrawAlignment(BaseInvTD[14], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[14], -1);
    TextDrawSetShadow(BaseInvTD[14], 0);
    TextDrawSetOutline(BaseInvTD[14], 0);
    TextDrawBackgroundColour(BaseInvTD[14], 150);
    TextDrawFont(BaseInvTD[14], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(BaseInvTD[14], true);

    BaseInvTD[15] = TextDrawCreate(319.299, 195.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[15], 3.598, 23.000);
    TextDrawAlignment(BaseInvTD[15], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[15], -1);
    TextDrawSetShadow(BaseInvTD[15], 0);
    TextDrawSetOutline(BaseInvTD[15], 0);
    TextDrawBackgroundColour(BaseInvTD[15], 255);
    TextDrawFont(BaseInvTD[15], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[15], true);

    BaseInvTD[16] = TextDrawCreate(328.000, 201.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[16], 7.000, 9.000);
    TextDrawAlignment(BaseInvTD[16], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[16], -1061109505);
    TextDrawSetShadow(BaseInvTD[16], 0);
    TextDrawSetOutline(BaseInvTD[16], 0);
    TextDrawBackgroundColour(BaseInvTD[16], 255);
    TextDrawFont(BaseInvTD[16], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[16], true);

    BaseInvTD[17] = TextDrawCreate(327.000, 194.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[17], 11.000, 6.000);
    TextDrawAlignment(BaseInvTD[17], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[17], -1061109505);
    TextDrawSetShadow(BaseInvTD[17], 0);
    TextDrawSetOutline(BaseInvTD[17], 0);
    TextDrawBackgroundColour(BaseInvTD[17], 255);
    TextDrawFont(BaseInvTD[17], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[17], true);

    BaseInvTD[18] = TextDrawCreate(325.000, 195.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[18], 7.000, 23.000);
    TextDrawAlignment(BaseInvTD[18], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[18], -1);
    TextDrawSetShadow(BaseInvTD[18], 0);
    TextDrawSetOutline(BaseInvTD[18], 0);
    TextDrawBackgroundColour(BaseInvTD[18], 255);
    TextDrawFont(BaseInvTD[18], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[18], true);

    BaseInvTD[19] = TextDrawCreate(332.000, 207.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[19], 7.000, 9.000);
    TextDrawAlignment(BaseInvTD[19], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[19], -1061109505);
    TextDrawSetShadow(BaseInvTD[19], 0);
    TextDrawSetOutline(BaseInvTD[19], 0);
    TextDrawBackgroundColour(BaseInvTD[19], 255);
    TextDrawFont(BaseInvTD[19], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[19], true);

    BaseInvTD[20] = TextDrawCreate(332.000, 209.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[20], 7.000, 9.000);
    TextDrawAlignment(BaseInvTD[20], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[20], -1);
    TextDrawSetShadow(BaseInvTD[20], 0);
    TextDrawSetOutline(BaseInvTD[20], 0);
    TextDrawBackgroundColour(BaseInvTD[20], 255);
    TextDrawFont(BaseInvTD[20], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[20], true);

    BaseInvTD[21] = TextDrawCreate(330.000, 187.798, "/");
    TextDrawLetterSize(BaseInvTD[21], 2.128, 3.400);
    TextDrawTextSize(BaseInvTD[21], 376.000, -82.000);
    TextDrawAlignment(BaseInvTD[21], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[21], -1061109505);
    TextDrawSetShadow(BaseInvTD[21], 0);
    TextDrawSetOutline(BaseInvTD[21], 0);
    TextDrawBackgroundColour(BaseInvTD[21], 150);
    TextDrawFont(BaseInvTD[21], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(BaseInvTD[21], true);

    BaseInvTD[22] = TextDrawCreate(326.000, 188.798, "/");
    TextDrawLetterSize(BaseInvTD[22], 2.128, 3.299);
    TextDrawTextSize(BaseInvTD[22], 382.000, -65.000);
    TextDrawAlignment(BaseInvTD[22], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[22], -1);
    TextDrawSetShadow(BaseInvTD[22], 0);
    TextDrawSetOutline(BaseInvTD[22], 0);
    TextDrawBackgroundColour(BaseInvTD[22], 150);
    TextDrawFont(BaseInvTD[22], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(BaseInvTD[22], true);

    BaseInvTD[23] = TextDrawCreate(332.000, 195.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[23], 5.000, 6.000);
    TextDrawAlignment(BaseInvTD[23], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[23], -1);
    TextDrawSetShadow(BaseInvTD[23], 0);
    TextDrawSetOutline(BaseInvTD[23], 0);
    TextDrawBackgroundColour(BaseInvTD[23], 255);
    TextDrawFont(BaseInvTD[23], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[23], true);

    BaseInvTD[24] = TextDrawCreate(316.000, 222.800, "GUNAKAN");
    TextDrawLetterSize(BaseInvTD[24], 0.289, 1.399);
    TextDrawTextSize(BaseInvTD[24], 3.000, 0.000);
    TextDrawAlignment(BaseInvTD[24], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[24], -1);
    TextDrawSetShadow(BaseInvTD[24], 0);
    TextDrawSetOutline(BaseInvTD[24], 0);
    TextDrawBackgroundColour(BaseInvTD[24], 150);
    TextDrawFont(BaseInvTD[24], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(BaseInvTD[24], true);

    BaseInvTD[25] = TextDrawCreate(319.000, 213.000, "LD_BEAT:chit");
    TextDrawTextSize(BaseInvTD[25], 4.000, 4.000);
    TextDrawAlignment(BaseInvTD[25], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[25], -1448498689);
    TextDrawSetShadow(BaseInvTD[25], 0);
    TextDrawSetOutline(BaseInvTD[25], 0);
    TextDrawBackgroundColour(BaseInvTD[25], 255);
    TextDrawFont(BaseInvTD[25], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[25], true);

    BaseInvTD[26] = TextDrawCreate(337.500, 292.000, "PERLIHATKAN");
    TextDrawLetterSize(BaseInvTD[26], 0.200, 1.399);
    TextDrawTextSize(BaseInvTD[26], 363.000, 0.000);
    TextDrawAlignment(BaseInvTD[26], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(BaseInvTD[26], -1);
    TextDrawSetShadow(BaseInvTD[26], 0);
    TextDrawSetOutline(BaseInvTD[26], 0);
    TextDrawBackgroundColour(BaseInvTD[26], 150);
    TextDrawFont(BaseInvTD[26], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(BaseInvTD[26], true);

    BaseInvTD[27] = TextDrawCreate(337.500, 321.000, "LIHAT");
    TextDrawLetterSize(BaseInvTD[27], 0.200, 1.399);
    TextDrawTextSize(BaseInvTD[27], 363.000, 0.000);
    TextDrawAlignment(BaseInvTD[27], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(BaseInvTD[27], -1);
    TextDrawSetShadow(BaseInvTD[27], 0);
    TextDrawSetOutline(BaseInvTD[27], 0);
    TextDrawBackgroundColour(BaseInvTD[27], 150);
    TextDrawFont(BaseInvTD[27], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(BaseInvTD[27], true);

    BaseInvTD[28] = TextDrawCreate(301.000, 138.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[28], 7.000, 13.000);
    TextDrawAlignment(BaseInvTD[28], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[28], 66);
    TextDrawSetShadow(BaseInvTD[28], 0);
    TextDrawSetOutline(BaseInvTD[28], 0);
    TextDrawBackgroundColour(BaseInvTD[28], 255);
    TextDrawFont(BaseInvTD[28], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[28], true);

    BaseInvTD[29] = TextDrawCreate(574.000, 138.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[29], 7.000, 13.000);
    TextDrawAlignment(BaseInvTD[29], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[29], 66);
    TextDrawSetShadow(BaseInvTD[29], 0);
    TextDrawSetOutline(BaseInvTD[29], 0);
    TextDrawBackgroundColour(BaseInvTD[29], 255);
    TextDrawFont(BaseInvTD[29], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[29], true);

    BaseInvTD[30] = TextDrawCreate(337.500, 306.000, "P. SEKITAR");
    TextDrawLetterSize(BaseInvTD[30], 0.230, 1.399);
    TextDrawTextSize(BaseInvTD[30], 363.000, 180.000);
    TextDrawAlignment(BaseInvTD[30], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(BaseInvTD[30], -1);
    TextDrawSetShadow(BaseInvTD[30], 0);
    TextDrawSetOutline(BaseInvTD[30], 0);
    TextDrawBackgroundColour(BaseInvTD[30], 150);
    TextDrawFont(BaseInvTD[30], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(BaseInvTD[30], true);

    BaseInvTD[31] = TextDrawCreate(337.500, 335.000, "BATAL");
    TextDrawLetterSize(BaseInvTD[31], 0.200, 1.399);
    TextDrawTextSize(BaseInvTD[31], 363.000, 0.000);
    TextDrawAlignment(BaseInvTD[31], TEXT_DRAW_ALIGN_CENTER);
    TextDrawColour(BaseInvTD[31], -1);
    TextDrawSetShadow(BaseInvTD[31], 0);
    TextDrawSetOutline(BaseInvTD[31], 0);
    TextDrawBackgroundColour(BaseInvTD[31], 150);
    TextDrawFont(BaseInvTD[31], TEXT_DRAW_FONT_1);
    TextDrawSetProportional(BaseInvTD[31], true);

    BaseInvTD[32] = TextDrawCreate(532.000, 138.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[32], 13.000, 13.000);
    TextDrawAlignment(BaseInvTD[32], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[32], 66);
    TextDrawSetShadow(BaseInvTD[32], 0);
    TextDrawSetOutline(BaseInvTD[32], 0);
    TextDrawBackgroundColour(BaseInvTD[32], 255);
    TextDrawFont(BaseInvTD[32], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[32], true);
    TextDrawSetSelectable(BaseInvTD[32], true);

    BaseInvTD[33] = TextDrawCreate(546.000, 138.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[33], 13.000, 13.000);
    TextDrawAlignment(BaseInvTD[33], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[33], 66);
    TextDrawSetShadow(BaseInvTD[33], 0);
    TextDrawSetOutline(BaseInvTD[33], 0);
    TextDrawBackgroundColour(BaseInvTD[33], 255);
    TextDrawFont(BaseInvTD[33], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[33], true);
    TextDrawSetSelectable(BaseInvTD[33], true);

    BaseInvTD[34] = TextDrawCreate(560.000, 138.000, "LD_SPAC:white");
    TextDrawTextSize(BaseInvTD[34], 13.000, 13.000);
    TextDrawAlignment(BaseInvTD[34], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(BaseInvTD[34], 66);
    TextDrawSetShadow(BaseInvTD[34], 0);
    TextDrawSetOutline(BaseInvTD[34], 0);
    TextDrawBackgroundColour(BaseInvTD[34], 255);
    TextDrawFont(BaseInvTD[34], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(BaseInvTD[34], true);
    TextDrawSetSelectable(BaseInvTD[34], true);

    InvSlot[0] = TextDrawCreate(99.000, 157.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[0], 38.000, 44.000);
    TextDrawAlignment(InvSlot[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[0], 66);
    TextDrawSetShadow(InvSlot[0], 0);
    TextDrawSetOutline(InvSlot[0], 0);
    TextDrawBackgroundColour(InvSlot[0], 255);
    TextDrawFont(InvSlot[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[0], true);
    TextDrawSetSelectable(InvSlot[0], true);

    InvSlot[1] = TextDrawCreate(139.000, 157.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[1], 38.000, 44.000);
    TextDrawAlignment(InvSlot[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[1], 66);
    TextDrawSetShadow(InvSlot[1], 0);
    TextDrawSetOutline(InvSlot[1], 0);
    TextDrawBackgroundColour(InvSlot[1], 255);
    TextDrawFont(InvSlot[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[1], true);
    TextDrawSetSelectable(InvSlot[1], true);

    InvSlot[2] = TextDrawCreate(179.000, 157.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[2], 38.000, 44.000);
    TextDrawAlignment(InvSlot[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[2], 66);
    TextDrawSetShadow(InvSlot[2], 0);
    TextDrawSetOutline(InvSlot[2], 0);
    TextDrawBackgroundColour(InvSlot[2], 255);
    TextDrawFont(InvSlot[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[2], true);
    TextDrawSetSelectable(InvSlot[2], true);

    InvSlot[3] = TextDrawCreate(219.000, 157.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[3], 38.000, 44.000);
    TextDrawAlignment(InvSlot[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[3], 66);
    TextDrawSetShadow(InvSlot[3], 0);
    TextDrawSetOutline(InvSlot[3], 0);
    TextDrawBackgroundColour(InvSlot[3], 255);
    TextDrawFont(InvSlot[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[3], true);
    TextDrawSetSelectable(InvSlot[3], true);

    InvSlot[4] = TextDrawCreate(259.000, 157.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[4], 38.000, 44.000);
    TextDrawAlignment(InvSlot[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[4], 66);
    TextDrawSetShadow(InvSlot[4], 0);
    TextDrawSetOutline(InvSlot[4], 0);
    TextDrawBackgroundColour(InvSlot[4], 255);
    TextDrawFont(InvSlot[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[4], true);
    TextDrawSetSelectable(InvSlot[4], true);

    InvSlot[5] = TextDrawCreate(99.000, 206.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[5], 38.000, 44.000);
    TextDrawAlignment(InvSlot[5], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[5], 66);
    TextDrawSetShadow(InvSlot[5], 0);
    TextDrawSetOutline(InvSlot[5], 0);
    TextDrawBackgroundColour(InvSlot[5], 255);
    TextDrawFont(InvSlot[5], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[5], true);
    TextDrawSetSelectable(InvSlot[5], true);

    InvSlot[6] = TextDrawCreate(139.000, 206.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[6], 38.000, 44.000);
    TextDrawAlignment(InvSlot[6], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[6], 66);
    TextDrawSetShadow(InvSlot[6], 0);
    TextDrawSetOutline(InvSlot[6], 0);
    TextDrawBackgroundColour(InvSlot[6], 255);
    TextDrawFont(InvSlot[6], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[6], true);
    TextDrawSetSelectable(InvSlot[6], true);

    InvSlot[7] = TextDrawCreate(179.000, 206.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[7], 38.000, 44.000);
    TextDrawAlignment(InvSlot[7], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[7], 66);
    TextDrawSetShadow(InvSlot[7], 0);
    TextDrawSetOutline(InvSlot[7], 0);
    TextDrawBackgroundColour(InvSlot[7], 255);
    TextDrawFont(InvSlot[7], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[7], true);
    TextDrawSetSelectable(InvSlot[7], true);

    InvSlot[8] = TextDrawCreate(219.000, 206.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[8], 38.000, 44.000);
    TextDrawAlignment(InvSlot[8], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[8], 66);
    TextDrawSetShadow(InvSlot[8], 0);
    TextDrawSetOutline(InvSlot[8], 0);
    TextDrawBackgroundColour(InvSlot[8], 255);
    TextDrawFont(InvSlot[8], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[8], true);
    TextDrawSetSelectable(InvSlot[8], true);

    InvSlot[9] = TextDrawCreate(259.000, 206.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[9], 38.000, 44.000);
    TextDrawAlignment(InvSlot[9], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[9], 66);
    TextDrawSetShadow(InvSlot[9], 0);
    TextDrawSetOutline(InvSlot[9], 0);
    TextDrawBackgroundColour(InvSlot[9], 255);
    TextDrawFont(InvSlot[9], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[9], true);
    TextDrawSetSelectable(InvSlot[9], true);

    InvSlot[10] = TextDrawCreate(99.000, 255.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[10], 38.000, 44.000);
    TextDrawAlignment(InvSlot[10], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[10], 66);
    TextDrawSetShadow(InvSlot[10], 0);
    TextDrawSetOutline(InvSlot[10], 0);
    TextDrawBackgroundColour(InvSlot[10], 255);
    TextDrawFont(InvSlot[10], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[10], true);
    TextDrawSetSelectable(InvSlot[10], true);

    InvSlot[11] = TextDrawCreate(139.000, 255.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[11], 38.000, 44.000);
    TextDrawAlignment(InvSlot[11], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[11], 66);
    TextDrawSetShadow(InvSlot[11], 0);
    TextDrawSetOutline(InvSlot[11], 0);
    TextDrawBackgroundColour(InvSlot[11], 255);
    TextDrawFont(InvSlot[11], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[11], true);
    TextDrawSetSelectable(InvSlot[11], true);

    InvSlot[12] = TextDrawCreate(179.000, 255.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[12], 38.000, 44.000);
    TextDrawAlignment(InvSlot[12], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[12], 66);
    TextDrawSetShadow(InvSlot[12], 0);
    TextDrawSetOutline(InvSlot[12], 0);
    TextDrawBackgroundColour(InvSlot[12], 255);
    TextDrawFont(InvSlot[12], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[12], true);
    TextDrawSetSelectable(InvSlot[12], true);

    InvSlot[13] = TextDrawCreate(219.000, 255.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[13], 38.000, 44.000);
    TextDrawAlignment(InvSlot[13], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[13], 66);
    TextDrawSetShadow(InvSlot[13], 0);
    TextDrawSetOutline(InvSlot[13], 0);
    TextDrawBackgroundColour(InvSlot[13], 255);
    TextDrawFont(InvSlot[13], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[13], true);
    TextDrawSetSelectable(InvSlot[13], true);

    InvSlot[14] = TextDrawCreate(259.000, 255.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[14], 38.000, 44.000);
    TextDrawAlignment(InvSlot[14], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[14], 66);
    TextDrawSetShadow(InvSlot[14], 0);
    TextDrawSetOutline(InvSlot[14], 0);
    TextDrawBackgroundColour(InvSlot[14], 255);
    TextDrawFont(InvSlot[14], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[14], true);
    TextDrawSetSelectable(InvSlot[14], true);

    InvSlot[15] = TextDrawCreate(99.000, 304.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[15], 38.000, 44.000);
    TextDrawAlignment(InvSlot[15], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[15], 66);
    TextDrawSetShadow(InvSlot[15], 0);
    TextDrawSetOutline(InvSlot[15], 0);
    TextDrawBackgroundColour(InvSlot[15], 255);
    TextDrawFont(InvSlot[15], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[15], true);
    TextDrawSetSelectable(InvSlot[15], true);

    InvSlot[16] = TextDrawCreate(139.000, 304.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[16], 38.000, 44.000);
    TextDrawAlignment(InvSlot[16], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[16], 66);
    TextDrawSetShadow(InvSlot[16], 0);
    TextDrawSetOutline(InvSlot[16], 0);
    TextDrawBackgroundColour(InvSlot[16], 255);
    TextDrawFont(InvSlot[16], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[16], true);
    TextDrawSetSelectable(InvSlot[16], true);

    InvSlot[17] = TextDrawCreate(179.000, 304.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[17], 38.000, 44.000);
    TextDrawAlignment(InvSlot[17], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[17], 66);
    TextDrawSetShadow(InvSlot[17], 0);
    TextDrawSetOutline(InvSlot[17], 0);
    TextDrawBackgroundColour(InvSlot[17], 255);
    TextDrawFont(InvSlot[17], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[17], true);
    TextDrawSetSelectable(InvSlot[17], true);

    InvSlot[18] = TextDrawCreate(219.000, 304.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[18], 38.000, 44.000);
    TextDrawAlignment(InvSlot[18], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[18], 66);
    TextDrawSetShadow(InvSlot[18], 0);
    TextDrawSetOutline(InvSlot[18], 0);
    TextDrawBackgroundColour(InvSlot[18], 255);
    TextDrawFont(InvSlot[18], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[18], true);
    TextDrawSetSelectable(InvSlot[18], true);

    InvSlot[19] = TextDrawCreate(259.000, 304.000, "LD_SPAC:white");
    TextDrawTextSize(InvSlot[19], 38.000, 44.000);
    TextDrawAlignment(InvSlot[19], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(InvSlot[19], 66);
    TextDrawSetShadow(InvSlot[19], 0);
    TextDrawSetOutline(InvSlot[19], 0);
    TextDrawBackgroundColour(InvSlot[19], 255);
    TextDrawFont(InvSlot[19], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(InvSlot[19], true);
    TextDrawSetSelectable(InvSlot[19], true);

    ContainerSlot[0] = TextDrawCreate(372.000, 157.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[0], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[0], 66);
    TextDrawSetShadow(ContainerSlot[0], 0);
    TextDrawSetOutline(ContainerSlot[0], 0);
    TextDrawBackgroundColour(ContainerSlot[0], 255);
    TextDrawFont(ContainerSlot[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[0], true);
    TextDrawSetSelectable(ContainerSlot[0], true);

    ContainerSlot[1] = TextDrawCreate(412.000, 157.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[1], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[1], 66);
    TextDrawSetShadow(ContainerSlot[1], 0);
    TextDrawSetOutline(ContainerSlot[1], 0);
    TextDrawBackgroundColour(ContainerSlot[1], 255);
    TextDrawFont(ContainerSlot[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[1], true);
    TextDrawSetSelectable(ContainerSlot[1], true);

    ContainerSlot[2] = TextDrawCreate(452.000, 157.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[2], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[2], 66);
    TextDrawSetShadow(ContainerSlot[2], 0);
    TextDrawSetOutline(ContainerSlot[2], 0);
    TextDrawBackgroundColour(ContainerSlot[2], 255);
    TextDrawFont(ContainerSlot[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[2], true);
    TextDrawSetSelectable(ContainerSlot[2], true);

    ContainerSlot[3] = TextDrawCreate(492.000, 157.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[3], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[3], 66);
    TextDrawSetShadow(ContainerSlot[3], 0);
    TextDrawSetOutline(ContainerSlot[3], 0);
    TextDrawBackgroundColour(ContainerSlot[3], 255);
    TextDrawFont(ContainerSlot[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[3], true);
    TextDrawSetSelectable(ContainerSlot[3], true);

    ContainerSlot[4] = TextDrawCreate(532.000, 157.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[4], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[4], 66);
    TextDrawSetShadow(ContainerSlot[4], 0);
    TextDrawSetOutline(ContainerSlot[4], 0);
    TextDrawBackgroundColour(ContainerSlot[4], 255);
    TextDrawFont(ContainerSlot[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[4], true);
    TextDrawSetSelectable(ContainerSlot[4], true);

    ContainerSlot[5] = TextDrawCreate(372.000, 206.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[5], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[5], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[5], 66);
    TextDrawSetShadow(ContainerSlot[5], 0);
    TextDrawSetOutline(ContainerSlot[5], 0);
    TextDrawBackgroundColour(ContainerSlot[5], 255);
    TextDrawFont(ContainerSlot[5], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[5], true);
    TextDrawSetSelectable(ContainerSlot[5], true);

    ContainerSlot[6] = TextDrawCreate(412.000, 206.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[6], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[6], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[6], 66);
    TextDrawSetShadow(ContainerSlot[6], 0);
    TextDrawSetOutline(ContainerSlot[6], 0);
    TextDrawBackgroundColour(ContainerSlot[6], 255);
    TextDrawFont(ContainerSlot[6], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[6], true);
    TextDrawSetSelectable(ContainerSlot[6], true);

    ContainerSlot[7] = TextDrawCreate(452.000, 206.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[7], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[7], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[7], 66);
    TextDrawSetShadow(ContainerSlot[7], 0);
    TextDrawSetOutline(ContainerSlot[7], 0);
    TextDrawBackgroundColour(ContainerSlot[7], 255);
    TextDrawFont(ContainerSlot[7], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[7], true);
    TextDrawSetSelectable(ContainerSlot[7], true);

    ContainerSlot[8] = TextDrawCreate(492.000, 206.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[8], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[8], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[8], 66);
    TextDrawSetShadow(ContainerSlot[8], 0);
    TextDrawSetOutline(ContainerSlot[8], 0);
    TextDrawBackgroundColour(ContainerSlot[8], 255);
    TextDrawFont(ContainerSlot[8], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[8], true);
    TextDrawSetSelectable(ContainerSlot[8], true);

    ContainerSlot[9] = TextDrawCreate(532.000, 206.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[9], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[9], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[9], 66);
    TextDrawSetShadow(ContainerSlot[9], 0);
    TextDrawSetOutline(ContainerSlot[9], 0);
    TextDrawBackgroundColour(ContainerSlot[9], 255);
    TextDrawFont(ContainerSlot[9], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[9], true);
    TextDrawSetSelectable(ContainerSlot[9], true);

    ContainerSlot[10] = TextDrawCreate(372.000, 255.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[10], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[10], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[10], 66);
    TextDrawSetShadow(ContainerSlot[10], 0);
    TextDrawSetOutline(ContainerSlot[10], 0);
    TextDrawBackgroundColour(ContainerSlot[10], 255);
    TextDrawFont(ContainerSlot[10], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[10], true);
    TextDrawSetSelectable(ContainerSlot[10], true);

    ContainerSlot[11] = TextDrawCreate(412.000, 255.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[11], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[11], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[11], 66);
    TextDrawSetShadow(ContainerSlot[11], 0);
    TextDrawSetOutline(ContainerSlot[11], 0);
    TextDrawBackgroundColour(ContainerSlot[11], 255);
    TextDrawFont(ContainerSlot[11], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[11], true);
    TextDrawSetSelectable(ContainerSlot[11], true);

    ContainerSlot[12] = TextDrawCreate(452.000, 255.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[12], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[12], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[12], 66);
    TextDrawSetShadow(ContainerSlot[12], 0);
    TextDrawSetOutline(ContainerSlot[12], 0);
    TextDrawBackgroundColour(ContainerSlot[12], 255);
    TextDrawFont(ContainerSlot[12], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[12], true);
    TextDrawSetSelectable(ContainerSlot[12], true);

    ContainerSlot[13] = TextDrawCreate(492.000, 255.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[13], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[13], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[13], 66);
    TextDrawSetShadow(ContainerSlot[13], 0);
    TextDrawSetOutline(ContainerSlot[13], 0);
    TextDrawBackgroundColour(ContainerSlot[13], 255);
    TextDrawFont(ContainerSlot[13], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[13], true);
    TextDrawSetSelectable(ContainerSlot[13], true);

    ContainerSlot[14] = TextDrawCreate(532.000, 255.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[14], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[14], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[14], 66);
    TextDrawSetShadow(ContainerSlot[14], 0);
    TextDrawSetOutline(ContainerSlot[14], 0);
    TextDrawBackgroundColour(ContainerSlot[14], 255);
    TextDrawFont(ContainerSlot[14], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[14], true);
    TextDrawSetSelectable(ContainerSlot[14], true);

    ContainerSlot[15] = TextDrawCreate(372.000, 304.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[15], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[15], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[15], 66);
    TextDrawSetShadow(ContainerSlot[15], 0);
    TextDrawSetOutline(ContainerSlot[15], 0);
    TextDrawBackgroundColour(ContainerSlot[15], 255);
    TextDrawFont(ContainerSlot[15], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[15], true);
    TextDrawSetSelectable(ContainerSlot[15], true);

    ContainerSlot[16] = TextDrawCreate(412.000, 304.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[16], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[16], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[16], 66);
    TextDrawSetShadow(ContainerSlot[16], 0);
    TextDrawSetOutline(ContainerSlot[16], 0);
    TextDrawBackgroundColour(ContainerSlot[16], 255);
    TextDrawFont(ContainerSlot[16], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[16], true);
    TextDrawSetSelectable(ContainerSlot[16], true);

    ContainerSlot[17] = TextDrawCreate(452.000, 304.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[17], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[17], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[17], 66);
    TextDrawSetShadow(ContainerSlot[17], 0);
    TextDrawSetOutline(ContainerSlot[17], 0);
    TextDrawBackgroundColour(ContainerSlot[17], 255);
    TextDrawFont(ContainerSlot[17], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[17], true);
    TextDrawSetSelectable(ContainerSlot[17], true);

    ContainerSlot[18] = TextDrawCreate(492.000, 304.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[18], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[18], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[18], 66);
    TextDrawSetShadow(ContainerSlot[18], 0);
    TextDrawSetOutline(ContainerSlot[18], 0);
    TextDrawBackgroundColour(ContainerSlot[18], 255);
    TextDrawFont(ContainerSlot[18], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[18], true);
    TextDrawSetSelectable(ContainerSlot[18], true);

    ContainerSlot[19] = TextDrawCreate(532.000, 304.000, "LD_SPAC:white");
    TextDrawTextSize(ContainerSlot[19], 38.000, 44.000);
    TextDrawAlignment(ContainerSlot[19], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ContainerSlot[19], 66);
    TextDrawSetShadow(ContainerSlot[19], 0);
    TextDrawSetOutline(ContainerSlot[19], 0);
    TextDrawBackgroundColour(ContainerSlot[19], 255);
    TextDrawFont(ContainerSlot[19], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ContainerSlot[19], true);
    TextDrawSetSelectable(ContainerSlot[19], true);

    Button[0] = TextDrawCreate(568.000, 132.000, "LD_SPAC:white");
    TextDrawTextSize(Button[0], 18.000, 6.000);
    TextDrawAlignment(Button[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(Button[0], -16776961);
    TextDrawSetShadow(Button[0], 0);
    TextDrawSetOutline(Button[0], 0);
    TextDrawBackgroundColour(Button[0], 255);
    TextDrawFont(Button[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(Button[0], true);
    TextDrawSetSelectable(Button[0], true);

    Button[1] = TextDrawCreate(313.000, 158.000, "LD_SPAC:white");
    TextDrawTextSize(Button[1], 50.000, 21.000);
    TextDrawAlignment(Button[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(Button[1], 66);
    TextDrawSetShadow(Button[1], 0);
    TextDrawSetOutline(Button[1], 0);
    TextDrawBackgroundColour(Button[1], 255);
    TextDrawFont(Button[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(Button[1], true);
    TextDrawSetSelectable(Button[1], true);

    Button[2] = TextDrawCreate(313.000, 181.000, "LD_SPAC:white");
    TextDrawTextSize(Button[2], 50.000, 58.000);
    TextDrawAlignment(Button[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(Button[2], 66);
    TextDrawSetShadow(Button[2], 0);
    TextDrawSetOutline(Button[2], 0);
    TextDrawBackgroundColour(Button[2], 255);
    TextDrawFont(Button[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(Button[2], true);
    TextDrawSetSelectable(Button[2], true);

    Button[3] = TextDrawCreate(313.000, 241.000, "LD_SPAC:white");
    TextDrawTextSize(Button[3], 50.000, 21.000);
    TextDrawAlignment(Button[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(Button[3], 66);
    TextDrawSetShadow(Button[3], 0);
    TextDrawSetOutline(Button[3], 0);
    TextDrawBackgroundColour(Button[3], 255);
    TextDrawFont(Button[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(Button[3], true);
    TextDrawSetSelectable(Button[3], true);

    Button[4] = TextDrawCreate(313.000, 263.500, "LD_SPAC:white");
    TextDrawTextSize(Button[4], 50.000, 21.000);
    TextDrawAlignment(Button[4], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(Button[4], 66);
    TextDrawSetShadow(Button[4], 0);
    TextDrawSetOutline(Button[4], 0);
    TextDrawBackgroundColour(Button[4], 255);
    TextDrawFont(Button[4], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(Button[4], true);
    TextDrawSetSelectable(Button[4], true);

    ExtraButton[0] = TextDrawCreate(313.000, 293.000, "LD_SPAC:white");
    TextDrawTextSize(ExtraButton[0], 50.000, 13.000);
    TextDrawAlignment(ExtraButton[0], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ExtraButton[0], 66);
    TextDrawSetShadow(ExtraButton[0], 0);
    TextDrawSetOutline(ExtraButton[0], 0);
    TextDrawBackgroundColour(ExtraButton[0], 255);
    TextDrawFont(ExtraButton[0], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ExtraButton[0], true);
    TextDrawSetSelectable(ExtraButton[0], true);

    ExtraButton[1] = TextDrawCreate(313.000, 307.000, "LD_SPAC:white");
    TextDrawTextSize(ExtraButton[1], 50.000, 13.000);
    TextDrawAlignment(ExtraButton[1], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ExtraButton[1], 66);
    TextDrawSetShadow(ExtraButton[1], 0);
    TextDrawSetOutline(ExtraButton[1], 0);
    TextDrawBackgroundColour(ExtraButton[1], 255);
    TextDrawFont(ExtraButton[1], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ExtraButton[1], true);
    TextDrawSetSelectable(ExtraButton[1], true);

    ExtraButton[2] = TextDrawCreate(313.000, 321.600, "LD_SPAC:white");
    TextDrawTextSize(ExtraButton[2], 50.000, 13.000);
    TextDrawAlignment(ExtraButton[2], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ExtraButton[2], 66);
    TextDrawSetShadow(ExtraButton[2], 0);
    TextDrawSetOutline(ExtraButton[2], 0);
    TextDrawBackgroundColour(ExtraButton[2], 255);
    TextDrawFont(ExtraButton[2], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ExtraButton[2], true);
    TextDrawSetSelectable(ExtraButton[2], true);

    ExtraButton[3] = TextDrawCreate(313.000, 336.000, "LD_SPAC:white");
    TextDrawTextSize(ExtraButton[3], 50.000, 13.000);
    TextDrawAlignment(ExtraButton[3], TEXT_DRAW_ALIGN_LEFT);
    TextDrawColour(ExtraButton[3], 66);
    TextDrawSetShadow(ExtraButton[3], 0);
    TextDrawSetOutline(ExtraButton[3], 0);
    TextDrawBackgroundColour(ExtraButton[3], 255);
    TextDrawFont(ExtraButton[3], TEXT_DRAW_FONT_SPRITE_DRAW);
    TextDrawSetProportional(ExtraButton[3], true);
    TextDrawSetSelectable(ExtraButton[3], true);

    return 1;
}

Create_InvPTD(playerid)
{
    InvPage[playerid][0] = CreatePlayerTextDraw(playerid, 301.000, 153.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvPage[playerid][0], 6.000, 100.000);
    PlayerTextDrawAlignment(playerid, InvPage[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPage[playerid][0], -2686721);
    PlayerTextDrawSetShadow(playerid, InvPage[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InvPage[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPage[playerid][0], 255);
    PlayerTextDrawFont(playerid, InvPage[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvPage[playerid][0], true);
    PlayerTextDrawSetSelectable(playerid, InvPage[playerid][0], true);

    InvPage[playerid][1] = CreatePlayerTextDraw(playerid, 301.000, 253.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvPage[playerid][1], 6.000, 99.000);
    PlayerTextDrawAlignment(playerid, InvPage[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPage[playerid][1], 66);
    PlayerTextDrawSetShadow(playerid, InvPage[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InvPage[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPage[playerid][1], 255);
    PlayerTextDrawFont(playerid, InvPage[playerid][1], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvPage[playerid][1], true);
    PlayerTextDrawSetSelectable(playerid, InvPage[playerid][1], true);

    InvPrevModel[playerid][0] = CreatePlayerTextDraw(playerid, 99.000, 157.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][0], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][0], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][0], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][0], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][0], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][0], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][0], 0, 0);

    InvPrevModel[playerid][1] = CreatePlayerTextDraw(playerid, 139.000, 157.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][1], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][1], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][1], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][1], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][1], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][1], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][1], 0, 0);

    InvPrevModel[playerid][2] = CreatePlayerTextDraw(playerid, 179.000, 157.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][2], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][2], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][2], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][2], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][2], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][2], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][2], 0, 0);

    InvPrevModel[playerid][3] = CreatePlayerTextDraw(playerid, 219.000, 157.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][3], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][3], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][3], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][3], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][3], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][3], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][3], 0, 0);

    InvPrevModel[playerid][4] = CreatePlayerTextDraw(playerid, 259.000, 157.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][4], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][4], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][4], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][4], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][4], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][4], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][4], 0, 0);

    InvPrevModel[playerid][5] = CreatePlayerTextDraw(playerid, 99.000, 206.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][5], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][5], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][5], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][5], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][5], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][5], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][5], 0, 0);

    InvPrevModel[playerid][6] = CreatePlayerTextDraw(playerid, 139.000, 206.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][6], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][6], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][6], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][6], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][6], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][6], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][6], 0, 0);

    InvPrevModel[playerid][7] = CreatePlayerTextDraw(playerid, 179.000, 206.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][7], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][7], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][7], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][7], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][7], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][7], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][7], 0, 0);

    InvPrevModel[playerid][8] = CreatePlayerTextDraw(playerid, 219.000, 206.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][8], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][8], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][8], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][8], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][8], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][8], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][8], 0, 0);

    InvPrevModel[playerid][9] = CreatePlayerTextDraw(playerid, 259.000, 206.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][9], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][9], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][9], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][9], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][9], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][9], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][9], 0, 0);

    InvPrevModel[playerid][10] = CreatePlayerTextDraw(playerid, 99.000, 255.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][10], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][10], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][10], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][10], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][10], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][10], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][10], 0, 0);

    InvPrevModel[playerid][11] = CreatePlayerTextDraw(playerid, 139.000, 255.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][11], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][11], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][11], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][11], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][11], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][11], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][11], 0, 0);

    InvPrevModel[playerid][12] = CreatePlayerTextDraw(playerid, 179.000, 255.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][12], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][12], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][12], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][12], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][12], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][12], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][12], 0, 0);

    InvPrevModel[playerid][13] = CreatePlayerTextDraw(playerid, 219.000, 255.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][13], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][13], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][13], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][13], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][13], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][13], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][13], 0, 0);

    InvPrevModel[playerid][14] = CreatePlayerTextDraw(playerid, 259.000, 255.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][14], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][14], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][14], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][14], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][14], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][14], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][14], 0, 0);

    InvPrevModel[playerid][15] = CreatePlayerTextDraw(playerid, 99.000, 304.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][15], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][15], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][15], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][15], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][15], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][15], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][15], 0, 0);

    InvPrevModel[playerid][16] = CreatePlayerTextDraw(playerid, 139.000, 304.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][16], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][16], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][16], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][16], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][16], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][16], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][16], 0, 0);

    InvPrevModel[playerid][17] = CreatePlayerTextDraw(playerid, 179.000, 304.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][17], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][17], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][17], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][17], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][17], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][17], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][17], 0, 0);

    InvPrevModel[playerid][18] = CreatePlayerTextDraw(playerid, 219.000, 304.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][18], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][18], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][18], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][18], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][18], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][18], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][18], 0, 0);

    InvPrevModel[playerid][19] = CreatePlayerTextDraw(playerid, 259.000, 304.000, "_");
    PlayerTextDrawTextSize(playerid, InvPrevModel[playerid][19], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, InvPrevModel[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPrevModel[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, InvPrevModel[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, InvPrevModel[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][19], 0);
    PlayerTextDrawFont(playerid, InvPrevModel[playerid][19], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, InvPrevModel[playerid][19], false);
    PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][19], 2972);
    PlayerTextDrawSetPreviewRot(playerid, InvPrevModel[playerid][19], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, InvPrevModel[playerid][19], 0, 0);

    InvItemName[playerid][0] = CreatePlayerTextDraw(playerid, 101.000, 159.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][0], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][0], 137.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][0], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][0], true);

    InvItemName[playerid][1] = CreatePlayerTextDraw(playerid, 141.000, 159.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][1], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][1], 177.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][1], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][1], true);

    InvItemName[playerid][2] = CreatePlayerTextDraw(playerid, 181.000, 159.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][2], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][2], 217.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][2], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][2], true);

    InvItemName[playerid][3] = CreatePlayerTextDraw(playerid, 221.000, 159.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][3], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][3], 257.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][3], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][3], true);

    InvItemName[playerid][4] = CreatePlayerTextDraw(playerid, 261.000, 159.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][4], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][4], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][4], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][4], true);

    InvItemName[playerid][5] = CreatePlayerTextDraw(playerid, 101.000, 208.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][5], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][5], 137.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][5], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][5], true);

    InvItemName[playerid][6] = CreatePlayerTextDraw(playerid, 141.000, 208.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][6], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][6], 177.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][6], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][6], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][6], true);

    InvItemName[playerid][7] = CreatePlayerTextDraw(playerid, 181.000, 208.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][7], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][7], 217.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][7], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][7], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][7], true);

    InvItemName[playerid][8] = CreatePlayerTextDraw(playerid, 221.000, 208.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][8], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][8], 257.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][8], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][8], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][8], true);

    InvItemName[playerid][9] = CreatePlayerTextDraw(playerid, 261.000, 208.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][9], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][9], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][9], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][9], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][9], true);

    InvItemName[playerid][10] = CreatePlayerTextDraw(playerid, 101.000, 256.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][10], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][10], 137.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][10], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][10], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][10], true);

    InvItemName[playerid][11] = CreatePlayerTextDraw(playerid, 141.000, 256.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][11], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][11], 177.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][11], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][11], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][11], true);

    InvItemName[playerid][12] = CreatePlayerTextDraw(playerid, 181.000, 256.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][12], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][12], 217.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][12], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][12], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][12], true);

    InvItemName[playerid][13] = CreatePlayerTextDraw(playerid, 221.000, 256.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][13], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][13], 257.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][13], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][13], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][13], true);

    InvItemName[playerid][14] = CreatePlayerTextDraw(playerid, 261.000, 256.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][14], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][14], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][14], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][14], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][14], true);

    InvItemName[playerid][15] = CreatePlayerTextDraw(playerid, 101.000, 305.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][15], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][15], 137.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][15], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][15], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][15], true);

    InvItemName[playerid][16] = CreatePlayerTextDraw(playerid, 141.000, 305.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][16], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][16], 177.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][16], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][16], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][16], true);

    InvItemName[playerid][17] = CreatePlayerTextDraw(playerid, 181.000, 305.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][17], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][17], 217.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][17], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][17], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][17], true);

    InvItemName[playerid][18] = CreatePlayerTextDraw(playerid, 221.000, 305.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][18], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][18], 257.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][18], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][18], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][18], true);

    InvItemName[playerid][19] = CreatePlayerTextDraw(playerid, 261.000, 305.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, InvItemName[playerid][19], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemName[playerid][19], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemName[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvItemName[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, InvItemName[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, InvItemName[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemName[playerid][19], 150);
    PlayerTextDrawFont(playerid, InvItemName[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemName[playerid][19], true);

    InvItemAmount[playerid][0] = CreatePlayerTextDraw(playerid, 134.000, 191.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][0], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][0], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][0], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][0], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][0], true);

    InvItemAmount[playerid][1] = CreatePlayerTextDraw(playerid, 174.000, 191.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][1], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][1], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][1], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][1], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][1], true);

    InvItemAmount[playerid][2] = CreatePlayerTextDraw(playerid, 214.000, 191.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][2], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][2], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][2], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][2], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][2], true);

    InvItemAmount[playerid][3] = CreatePlayerTextDraw(playerid, 254.000, 191.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][3], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][3], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][3], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][3], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][3], true);

    InvItemAmount[playerid][4] = CreatePlayerTextDraw(playerid, 294.000, 191.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][4], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][4], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][4], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][4], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][4], true);

    InvItemAmount[playerid][5] = CreatePlayerTextDraw(playerid, 134.000, 240.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][5], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][5], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][5], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][5], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][5], true);

    InvItemAmount[playerid][6] = CreatePlayerTextDraw(playerid, 174.000, 240.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][6], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][6], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][6], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][6], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][6], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][6], true);

    InvItemAmount[playerid][7] = CreatePlayerTextDraw(playerid, 214.000, 240.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][7], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][7], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][7], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][7], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][7], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][7], true);

    InvItemAmount[playerid][8] = CreatePlayerTextDraw(playerid, 254.000, 240.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][8], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][8], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][8], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][8], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][8], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][8], true);

    InvItemAmount[playerid][9] = CreatePlayerTextDraw(playerid, 294.000, 240.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][9], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][9], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][9], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][9], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][9], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][9], true);

    InvItemAmount[playerid][10] = CreatePlayerTextDraw(playerid, 134.000, 289.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][10], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][10], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][10], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][10], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][10], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][10], true);

    InvItemAmount[playerid][11] = CreatePlayerTextDraw(playerid, 174.000, 289.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][11], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][11], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][11], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][11], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][11], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][11], true);

    InvItemAmount[playerid][12] = CreatePlayerTextDraw(playerid, 214.000, 289.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][12], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][12], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][12], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][12], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][12], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][12], true);

    InvItemAmount[playerid][13] = CreatePlayerTextDraw(playerid, 254.000, 289.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][13], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][13], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][13], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][13], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][13], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][13], true);

    InvItemAmount[playerid][14] = CreatePlayerTextDraw(playerid, 294.000, 289.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][14], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][14], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][14], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][14], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][14], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][14], true);

    InvItemAmount[playerid][15] = CreatePlayerTextDraw(playerid, 134.000, 338.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][15], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][15], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][15], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][15], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][15], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][15], true);

    InvItemAmount[playerid][16] = CreatePlayerTextDraw(playerid, 174.000, 338.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][16], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][16], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][16], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][16], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][16], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][16], true);

    InvItemAmount[playerid][17] = CreatePlayerTextDraw(playerid, 214.000, 338.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][17], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][17], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][17], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][17], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][17], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][17], true);

    InvItemAmount[playerid][18] = CreatePlayerTextDraw(playerid, 254.000, 338.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][18], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][18], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][18], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][18], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][18], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][18], true);

    InvItemAmount[playerid][19] = CreatePlayerTextDraw(playerid, 294.000, 338.000, "999x");
    PlayerTextDrawLetterSize(playerid, InvItemAmount[playerid][19], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, InvItemAmount[playerid][19], 297.000, 37.000);
    PlayerTextDrawAlignment(playerid, InvItemAmount[playerid][19], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, InvItemAmount[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, InvItemAmount[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, InvItemAmount[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, InvItemAmount[playerid][19], 150);
    PlayerTextDrawFont(playerid, InvItemAmount[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvItemAmount[playerid][19], true);

    InvPlayerName[playerid] = CreatePlayerTextDraw(playerid, 98.000, 139.000, "Firstname_Lastnameeeeeee (999)");
    PlayerTextDrawLetterSize(playerid, InvPlayerName[playerid], 0.170, 1.098);
    PlayerTextDrawTextSize(playerid, InvPlayerName[playerid], 297.000, 35.000);
    PlayerTextDrawAlignment(playerid, InvPlayerName[playerid], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvPlayerName[playerid], -1);
    PlayerTextDrawSetShadow(playerid, InvPlayerName[playerid], 0);
    PlayerTextDrawSetOutline(playerid, InvPlayerName[playerid], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPlayerName[playerid], 150);
    PlayerTextDrawFont(playerid, InvPlayerName[playerid], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvPlayerName[playerid], true);

    InvWeightBar[playerid] = CreatePlayerTextDraw(playerid, 190.000, 140.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, InvWeightBar[playerid], 108.000, 8.000);
    PlayerTextDrawAlignment(playerid, InvWeightBar[playerid], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvWeightBar[playerid], -2686721);
    PlayerTextDrawSetShadow(playerid, InvWeightBar[playerid], 0);
    PlayerTextDrawSetOutline(playerid, InvWeightBar[playerid], 0);
    PlayerTextDrawBackgroundColour(playerid, InvWeightBar[playerid], 255);
    PlayerTextDrawFont(playerid, InvWeightBar[playerid], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, InvWeightBar[playerid], true);

    InvWeightText[playerid] = CreatePlayerTextDraw(playerid, 225.000, 140.000, "0.2kg /50kg");
    PlayerTextDrawLetterSize(playerid, InvWeightText[playerid], 0.187, 0.698);
    PlayerTextDrawTextSize(playerid, InvWeightText[playerid], 297.000, 35.000);
    PlayerTextDrawAlignment(playerid, InvWeightText[playerid], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, InvWeightText[playerid], -1);
    PlayerTextDrawSetShadow(playerid, InvWeightText[playerid], 0);
    PlayerTextDrawSetOutline(playerid, InvWeightText[playerid], 0);
    PlayerTextDrawBackgroundColour(playerid, InvWeightText[playerid], 150);
    PlayerTextDrawFont(playerid, InvWeightText[playerid], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvWeightText[playerid], true);

    ContainerPage[playerid][0] = CreatePlayerTextDraw(playerid, 574.000, 153.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerPage[playerid][0], 6.000, 100.000);
    PlayerTextDrawAlignment(playerid, ContainerPage[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPage[playerid][0], -2686721);
    PlayerTextDrawSetShadow(playerid, ContainerPage[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPage[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPage[playerid][0], 255);
    PlayerTextDrawFont(playerid, ContainerPage[playerid][0], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerPage[playerid][0], true);
    PlayerTextDrawSetSelectable(playerid, ContainerPage[playerid][0], true);

    ContainerPage[playerid][1] = CreatePlayerTextDraw(playerid, 574.000, 253.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerPage[playerid][1], 6.000, 99.000);
    PlayerTextDrawAlignment(playerid, ContainerPage[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPage[playerid][1], 66);
    PlayerTextDrawSetShadow(playerid, ContainerPage[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPage[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPage[playerid][1], 255);
    PlayerTextDrawFont(playerid, ContainerPage[playerid][1], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerPage[playerid][1], true);
    PlayerTextDrawSetSelectable(playerid, ContainerPage[playerid][1], true);

    ContainerPrevModel[playerid][0] = CreatePlayerTextDraw(playerid, 372.000, 157.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][0], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][0], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][0], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][0], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][0], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][0], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][0], 0, 0);

    ContainerPrevModel[playerid][1] = CreatePlayerTextDraw(playerid, 412.000, 157.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][1], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][1], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][1], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][1], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][1], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][1], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][1], 0, 0);

    ContainerPrevModel[playerid][2] = CreatePlayerTextDraw(playerid, 452.000, 157.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][2], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][2], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][2], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][2], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][2], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][2], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][2], 0, 0);

    ContainerPrevModel[playerid][3] = CreatePlayerTextDraw(playerid, 492.000, 157.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][3], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][3], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][3], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][3], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][3], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][3], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][3], 0, 0);

    ContainerPrevModel[playerid][4] = CreatePlayerTextDraw(playerid, 532.000, 157.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][4], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][4], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][4], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][4], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][4], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][4], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][4], 0, 0);

    ContainerPrevModel[playerid][5] = CreatePlayerTextDraw(playerid, 372.000, 206.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][5], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][5], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][5], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][5], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][5], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][5], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][5], 0, 0);

    ContainerPrevModel[playerid][6] = CreatePlayerTextDraw(playerid, 412.000, 206.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][6], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][6], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][6], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][6], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][6], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][6], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][6], 0, 0);

    ContainerPrevModel[playerid][7] = CreatePlayerTextDraw(playerid, 452.000, 206.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][7], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][7], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][7], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][7], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][7], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][7], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][7], 0, 0);

    ContainerPrevModel[playerid][8] = CreatePlayerTextDraw(playerid, 492.000, 206.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][8], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][8], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][8], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][8], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][8], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][8], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][8], 0, 0);

    ContainerPrevModel[playerid][9] = CreatePlayerTextDraw(playerid, 532.000, 206.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][9], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][9], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][9], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][9], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][9], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][9], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][9], 0, 0);

    ContainerPrevModel[playerid][10] = CreatePlayerTextDraw(playerid, 372.000, 255.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][10], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][10], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][10], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][10], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][10], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][10], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][10], 0, 0);

    ContainerPrevModel[playerid][11] = CreatePlayerTextDraw(playerid, 412.000, 255.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][11], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][11], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][11], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][11], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][11], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][11], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][11], 0, 0);

    ContainerPrevModel[playerid][12] = CreatePlayerTextDraw(playerid, 452.000, 255.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][12], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][12], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][12], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][12], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][12], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][12], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][12], 0, 0);

    ContainerPrevModel[playerid][13] = CreatePlayerTextDraw(playerid, 492.000, 255.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][13], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][13], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][13], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][13], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][13], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][13], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][13], 0, 0);

    ContainerPrevModel[playerid][14] = CreatePlayerTextDraw(playerid, 532.000, 255.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][14], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][14], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][14], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][14], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][14], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][14], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][14], 0, 0);

    ContainerPrevModel[playerid][15] = CreatePlayerTextDraw(playerid, 372.000, 304.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][15], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][15], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][15], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][15], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][15], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][15], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][15], 0, 0);

    ContainerPrevModel[playerid][16] = CreatePlayerTextDraw(playerid, 412.000, 304.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][16], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][16], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][16], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][16], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][16], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][16], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][16], 0, 0);

    ContainerPrevModel[playerid][17] = CreatePlayerTextDraw(playerid, 452.000, 304.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][17], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][17], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][17], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][17], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][17], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][17], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][17], 0, 0);

    ContainerPrevModel[playerid][18] = CreatePlayerTextDraw(playerid, 492.000, 304.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][18], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][18], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][18], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][18], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][18], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][18], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][18], 0, 0);

    ContainerPrevModel[playerid][19] = CreatePlayerTextDraw(playerid, 532.000, 304.000, "_");
    PlayerTextDrawTextSize(playerid, ContainerPrevModel[playerid][19], 38.000, 44.000);
    PlayerTextDrawAlignment(playerid, ContainerPrevModel[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerPrevModel[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPrevModel[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPrevModel[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][19], 0);
    PlayerTextDrawFont(playerid, ContainerPrevModel[playerid][19], TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawSetProportional(playerid, ContainerPrevModel[playerid][19], false);
    PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][19], 2972);
    PlayerTextDrawSetPreviewRot(playerid, ContainerPrevModel[playerid][19], 0.000, 0.000, 0.000, 1.049);
    PlayerTextDrawSetPreviewVehicleColours(playerid, ContainerPrevModel[playerid][19], 0, 0);

    ContainerItemName[playerid][0] = CreatePlayerTextDraw(playerid, 374.000, 159.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][0], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][0], 410.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][0], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][0], true);

    ContainerItemName[playerid][1] = CreatePlayerTextDraw(playerid, 414.000, 159.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][1], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][1], 450.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][1], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][1], true);

    ContainerItemName[playerid][2] = CreatePlayerTextDraw(playerid, 454.000, 159.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][2], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][2], 490.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][2], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][2], true);

    ContainerItemName[playerid][3] = CreatePlayerTextDraw(playerid, 494.000, 159.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][3], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][3], 530.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][3], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][3], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][3], true);

    ContainerItemName[playerid][4] = CreatePlayerTextDraw(playerid, 534.000, 159.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][4], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][4], 570.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][4], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][4], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][4], true);

    ContainerItemName[playerid][5] = CreatePlayerTextDraw(playerid, 374.000, 208.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][5], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][5], 410.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][5], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][5], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][5], true);

    ContainerItemName[playerid][6] = CreatePlayerTextDraw(playerid, 414.000, 208.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][6], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][6], 450.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][6], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][6], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][6], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][6], true);

    ContainerItemName[playerid][7] = CreatePlayerTextDraw(playerid, 454.000, 208.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][7], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][7], 490.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][7], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][7], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][7], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][7], true);

    ContainerItemName[playerid][8] = CreatePlayerTextDraw(playerid, 494.000, 208.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][8], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][8], 530.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][8], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][8], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][8], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][8], true);

    ContainerItemName[playerid][9] = CreatePlayerTextDraw(playerid, 534.000, 208.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][9], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][9], 570.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][9], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][9], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][9], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][9], true);

    ContainerItemName[playerid][10] = CreatePlayerTextDraw(playerid, 374.000, 256.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][10], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][10], 410.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][10], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][10], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][10], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][10], true);

    ContainerItemName[playerid][11] = CreatePlayerTextDraw(playerid, 414.000, 256.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][11], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][11], 450.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][11], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][11], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][11], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][11], true);

    ContainerItemName[playerid][12] = CreatePlayerTextDraw(playerid, 454.000, 256.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][12], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][12], 490.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][12], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][12], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][12], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][12], true);

    ContainerItemName[playerid][13] = CreatePlayerTextDraw(playerid, 494.000, 256.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][13], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][13], 530.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][13], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][13], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][13], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][13], true);

    ContainerItemName[playerid][14] = CreatePlayerTextDraw(playerid, 534.000, 256.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][14], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][14], 570.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][14], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][14], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][14], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][14], true);

    ContainerItemName[playerid][15] = CreatePlayerTextDraw(playerid, 374.000, 305.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][15], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][15], 410.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][15], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][15], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][15], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][15], true);

    ContainerItemName[playerid][16] = CreatePlayerTextDraw(playerid, 414.000, 305.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][16], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][16], 450.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][16], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][16], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][16], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][16], true);

    ContainerItemName[playerid][17] = CreatePlayerTextDraw(playerid, 454.000, 305.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][17], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][17], 490.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][17], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][17], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][17], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][17], true);

    ContainerItemName[playerid][18] = CreatePlayerTextDraw(playerid, 494.000, 305.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][18], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][18], 530.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][18], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][18], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][18], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][18], true);

    ContainerItemName[playerid][19] = CreatePlayerTextDraw(playerid, 534.000, 305.000, "Item Name");
    PlayerTextDrawLetterSize(playerid, ContainerItemName[playerid][19], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemName[playerid][19], 570.000, 37.000);
    PlayerTextDrawAlignment(playerid, ContainerItemName[playerid][19], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerItemName[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemName[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemName[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemName[playerid][19], 150);
    PlayerTextDrawFont(playerid, ContainerItemName[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemName[playerid][19], true);

    ContainerItemAmount[playerid][0] = CreatePlayerTextDraw(playerid, 407.000, 191.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][0], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][0], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][0], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][0], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][0], true);

    ContainerItemAmount[playerid][1] = CreatePlayerTextDraw(playerid, 447.000, 191.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][1], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][1], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][1], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][1], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][1], true);

    ContainerItemAmount[playerid][2] = CreatePlayerTextDraw(playerid, 487.000, 191.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][2], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][2], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][2], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][2], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][2], true);

    ContainerItemAmount[playerid][3] = CreatePlayerTextDraw(playerid, 527.000, 191.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][3], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][3], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][3], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][3], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][3], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][3], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][3], true);

    ContainerItemAmount[playerid][4] = CreatePlayerTextDraw(playerid, 567.000, 191.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][4], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][4], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][4], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][4], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][4], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][4], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][4], true);

    ContainerItemAmount[playerid][5] = CreatePlayerTextDraw(playerid, 407.000, 240.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][5], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][5], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][5], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][5], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][5], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][5], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][5], true);

    ContainerItemAmount[playerid][6] = CreatePlayerTextDraw(playerid, 447.000, 240.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][6], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][6], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][6], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][6], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][6], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][6], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][6], true);

    ContainerItemAmount[playerid][7] = CreatePlayerTextDraw(playerid, 487.000, 240.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][7], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][7], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][7], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][7], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][7], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][7], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][7], true);

    ContainerItemAmount[playerid][8] = CreatePlayerTextDraw(playerid, 527.000, 240.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][8], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][8], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][8], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][8], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][8], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][8], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][8], true);

    ContainerItemAmount[playerid][9] = CreatePlayerTextDraw(playerid, 567.000, 240.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][9], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][9], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][9], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][9], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][9], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][9], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][9], true);

    ContainerItemAmount[playerid][10] = CreatePlayerTextDraw(playerid, 407.000, 289.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][10], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][10], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][10], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][10], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][10], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][10], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][10], true);

    ContainerItemAmount[playerid][11] = CreatePlayerTextDraw(playerid, 447.000, 289.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][11], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][11], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][11], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][11], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][11], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][11], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][11], true);

    ContainerItemAmount[playerid][12] = CreatePlayerTextDraw(playerid, 487.000, 289.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][12], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][12], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][12], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][12], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][12], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][12], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][12], true);

    ContainerItemAmount[playerid][13] = CreatePlayerTextDraw(playerid, 527.000, 289.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][13], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][13], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][13], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][13], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][13], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][13], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][13], true);

    ContainerItemAmount[playerid][14] = CreatePlayerTextDraw(playerid, 567.000, 289.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][14], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][14], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][14], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][14], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][14], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][14], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][14], true);

    ContainerItemAmount[playerid][15] = CreatePlayerTextDraw(playerid, 407.000, 338.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][15], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][15], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][15], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][15], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][15], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][15], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][15], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][15], true);

    ContainerItemAmount[playerid][16] = CreatePlayerTextDraw(playerid, 447.000, 338.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][16], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][16], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][16], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][16], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][16], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][16], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][16], true);

    ContainerItemAmount[playerid][17] = CreatePlayerTextDraw(playerid, 487.000, 338.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][17], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][17], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][17], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][17], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][17], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][17], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][17], true);

    ContainerItemAmount[playerid][18] = CreatePlayerTextDraw(playerid, 527.000, 338.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][18], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][18], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][18], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][18], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][18], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][18], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][18], true);

    ContainerItemAmount[playerid][19] = CreatePlayerTextDraw(playerid, 567.000, 338.000, "999x");
    PlayerTextDrawLetterSize(playerid, ContainerItemAmount[playerid][19], 0.170, 0.999);
    PlayerTextDrawTextSize(playerid, ContainerItemAmount[playerid][19], 297.000, 47.000);
    PlayerTextDrawAlignment(playerid, ContainerItemAmount[playerid][19], TEXT_DRAW_ALIGN_RIGHT);
    PlayerTextDrawColour(playerid, ContainerItemAmount[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, ContainerItemAmount[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, ContainerItemAmount[playerid][19], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerItemAmount[playerid][19], 150);
    PlayerTextDrawFont(playerid, ContainerItemAmount[playerid][19], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerItemAmount[playerid][19], true);

    ContainerTitle[playerid] = CreatePlayerTextDraw(playerid, 371.000, 139.000, "Firstname_Lastnameeeeeee (999)");
    PlayerTextDrawLetterSize(playerid, ContainerTitle[playerid], 0.170, 1.098);
    PlayerTextDrawTextSize(playerid, ContainerTitle[playerid], 297.000, 35.000);
    PlayerTextDrawAlignment(playerid, ContainerTitle[playerid], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerTitle[playerid], -1);
    PlayerTextDrawSetShadow(playerid, ContainerTitle[playerid], 0);
    PlayerTextDrawSetOutline(playerid, ContainerTitle[playerid], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerTitle[playerid], 150);
    PlayerTextDrawFont(playerid, ContainerTitle[playerid], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerTitle[playerid], true);

    ContainerWeightBar[playerid] = CreatePlayerTextDraw(playerid, 463.000, 140.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ContainerWeightBar[playerid], 66.000, 8.000);
    PlayerTextDrawAlignment(playerid, ContainerWeightBar[playerid], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerWeightBar[playerid], -2686721);
    PlayerTextDrawSetShadow(playerid, ContainerWeightBar[playerid], 0);
    PlayerTextDrawSetOutline(playerid, ContainerWeightBar[playerid], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerWeightBar[playerid], 255);
    PlayerTextDrawFont(playerid, ContainerWeightBar[playerid], TEXT_DRAW_FONT_SPRITE_DRAW);
    PlayerTextDrawSetProportional(playerid, ContainerWeightBar[playerid], true);

    ContainerWeightText[playerid] = CreatePlayerTextDraw(playerid, 479.000, 140.000, "0.2kg /50kg");
    PlayerTextDrawLetterSize(playerid, ContainerWeightText[playerid], 0.187, 0.698);
    PlayerTextDrawTextSize(playerid, ContainerWeightText[playerid], 541.000, 35.000);
    PlayerTextDrawAlignment(playerid, ContainerWeightText[playerid], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerWeightText[playerid], -1);
    PlayerTextDrawSetShadow(playerid, ContainerWeightText[playerid], 0);
    PlayerTextDrawSetOutline(playerid, ContainerWeightText[playerid], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerWeightText[playerid], 150);
    PlayerTextDrawFont(playerid, ContainerWeightText[playerid], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerWeightText[playerid], true);

    InvPageText[playerid] = CreatePlayerTextDraw(playerid, 304.000, 139.000, "2");
    PlayerTextDrawLetterSize(playerid, InvPageText[playerid], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, InvPageText[playerid], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, InvPageText[playerid], -1);
    PlayerTextDrawSetShadow(playerid, InvPageText[playerid], 0);
    PlayerTextDrawSetOutline(playerid, InvPageText[playerid], 0);
    PlayerTextDrawBackgroundColour(playerid, InvPageText[playerid], 150);
    PlayerTextDrawFont(playerid, InvPageText[playerid], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, InvPageText[playerid], true);

    ContainerPageText[playerid] = CreatePlayerTextDraw(playerid, 577.000, 139.000, "2");
    PlayerTextDrawLetterSize(playerid, ContainerPageText[playerid], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, ContainerPageText[playerid], TEXT_DRAW_ALIGN_CENTER);
    PlayerTextDrawColour(playerid, ContainerPageText[playerid], -1);
    PlayerTextDrawSetShadow(playerid, ContainerPageText[playerid], 0);
    PlayerTextDrawSetOutline(playerid, ContainerPageText[playerid], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerPageText[playerid], 150);
    PlayerTextDrawFont(playerid, ContainerPageText[playerid], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerPageText[playerid], true);

    ContainerModeText[playerid][0] = CreatePlayerTextDraw(playerid, 536.000, 138.000, "D");
    PlayerTextDrawLetterSize(playerid, ContainerModeText[playerid][0], 0.250, 1.299);
    PlayerTextDrawTextSize(playerid, ContainerModeText[playerid][0], 541.000, 35.000);
    PlayerTextDrawAlignment(playerid, ContainerModeText[playerid][0], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModeText[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModeText[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModeText[playerid][0], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModeText[playerid][0], 150);
    PlayerTextDrawFont(playerid, ContainerModeText[playerid][0], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerModeText[playerid][0], true);

    ContainerModeText[playerid][1] = CreatePlayerTextDraw(playerid, 550.000, 138.000, "C");
    PlayerTextDrawLetterSize(playerid, ContainerModeText[playerid][1], 0.250, 1.299);
    PlayerTextDrawTextSize(playerid, ContainerModeText[playerid][1], 541.000, 35.000);
    PlayerTextDrawAlignment(playerid, ContainerModeText[playerid][1], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModeText[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModeText[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModeText[playerid][1], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModeText[playerid][1], 150);
    PlayerTextDrawFont(playerid, ContainerModeText[playerid][1], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerModeText[playerid][1], true);

    ContainerModeText[playerid][2] = CreatePlayerTextDraw(playerid, 564.000, 138.000, "P");
    PlayerTextDrawLetterSize(playerid, ContainerModeText[playerid][2], 0.250, 1.299);
    PlayerTextDrawTextSize(playerid, ContainerModeText[playerid][2], 541.000, 35.000);
    PlayerTextDrawAlignment(playerid, ContainerModeText[playerid][2], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, ContainerModeText[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ContainerModeText[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ContainerModeText[playerid][2], 0);
    PlayerTextDrawBackgroundColour(playerid, ContainerModeText[playerid][2], 150);
    PlayerTextDrawFont(playerid, ContainerModeText[playerid][2], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, ContainerModeText[playerid][2], true);

    AmountTD[playerid] = CreatePlayerTextDraw(playerid, 318.000, 161.800, "JUMLAH");
    PlayerTextDrawLetterSize(playerid, AmountTD[playerid], 0.328, 1.299);
    PlayerTextDrawTextSize(playerid, AmountTD[playerid], 3.000, 0.000);
    PlayerTextDrawAlignment(playerid, AmountTD[playerid], TEXT_DRAW_ALIGN_LEFT);
    PlayerTextDrawColour(playerid, AmountTD[playerid], -1);
    PlayerTextDrawSetShadow(playerid, AmountTD[playerid], 0);
    PlayerTextDrawSetOutline(playerid, AmountTD[playerid], 0);
    PlayerTextDrawBackgroundColour(playerid, AmountTD[playerid], 150);
    PlayerTextDrawFont(playerid, AmountTD[playerid], TEXT_DRAW_FONT_1);
    PlayerTextDrawSetProportional(playerid, AmountTD[playerid], true);

    return 1;
}

Destroy_InvPTD(playerid)
{
    for(new i = 0; i < 20; i++)
    {
        if(i < 2)
        {
            PlayerTextDrawDestroy(playerid, InvPage[playerid][i]);
            PlayerTextDrawDestroy(playerid, ContainerPage[playerid][i]);
            InvPage[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
            ContainerPage[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        }

        if(i < 3)
        {
            PlayerTextDrawDestroy(playerid, ContainerModeText[playerid][i]);
            ContainerModeText[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        }

        PlayerTextDrawDestroy(playerid, InvPrevModel[playerid][i]);
        PlayerTextDrawDestroy(playerid, InvItemName[playerid][i]);
        PlayerTextDrawDestroy(playerid, InvItemAmount[playerid][i]);

        PlayerTextDrawDestroy(playerid, ContainerPrevModel[playerid][i]);
        PlayerTextDrawDestroy(playerid, ContainerItemName[playerid][i]);
        PlayerTextDrawDestroy(playerid, ContainerItemAmount[playerid][i]);

        InvPrevModel[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        InvItemName[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        InvItemAmount[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;

        ContainerPrevModel[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        ContainerItemName[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
        ContainerItemAmount[playerid][i] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
    }

    PlayerTextDrawDestroy(playerid, InvPlayerName[playerid]);
    PlayerTextDrawDestroy(playerid, InvWeightBar[playerid]);
    PlayerTextDrawDestroy(playerid, InvWeightText[playerid]);
    PlayerTextDrawDestroy(playerid, InvPageText[playerid]);

    PlayerTextDrawDestroy(playerid, ContainerTitle[playerid]);
    PlayerTextDrawDestroy(playerid, ContainerWeightBar[playerid]);
    PlayerTextDrawDestroy(playerid, ContainerWeightText[playerid]);
    PlayerTextDrawDestroy(playerid, ContainerPageText[playerid]);

    PlayerTextDrawDestroy(playerid, AmountTD[playerid]);

    InvPlayerName[playerid] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
    InvWeightBar[playerid] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
    InvWeightText[playerid] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
    InvPageText[playerid] = PlayerText:INVALID_PLAYER_TEXT_DRAW;

    ContainerTitle[playerid] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
    ContainerWeightBar[playerid] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
    ContainerWeightText[playerid] = PlayerText:INVALID_PLAYER_TEXT_DRAW;
    ContainerPageText[playerid] = PlayerText:INVALID_PLAYER_TEXT_DRAW;

    AmountTD[playerid] = PlayerText:INVALID_PLAYER_TEXT_DRAW;

    return 1;
}