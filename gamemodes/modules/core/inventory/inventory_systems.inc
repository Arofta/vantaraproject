hook OnClickDynamicTextDraw(playerid, Text:textid)
{
    if(textid == InvButtonTD[4])
    {
        Hide_InvTD(playerid);
    }
    else if(textid == InvButtonTD[0])
    {
        Dialog_Show(playerid, "InvInputAmount", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Inventorry Input Amount", "Silahkan masukkan jumlah item yang valid.", "Input", "Batal");
    }
    return 1;
}

hook OnClickDynamicPlayerTextDraw(playerid, PlayerText:textid)
{
    if(SelectedSlot[playerid] != -1 && (SelectedSlot[playerid] / MAX_SLOTS_PER_PAGE) == CurrInvPage[playerid] && textid == InvSlotPTD[playerid][SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE])
    {
        PlayerTextDrawColour(playerid, InvSlotPTD[playerid][SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE], 66);
        PlayerTextDrawShow(playerid, InvSlotPTD[playerid][SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE]);
        SelectedSlot[playerid] = -1;
        SelectedType[playerid] = -1;
    }
    if(SelectedSlot[playerid] != -1 && (SelectedSlot[playerid] / MAX_SLOTS_PER_PAGE) == CurrContainerPage[playerid] && textid == ContainerSlotPTD[playerid][SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE])
    {
        PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE], 66);
        PlayerTextDrawShow(playerid, ContainerSlotPTD[playerid][SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE]);
        SelectedSlot[playerid] = -1;
        SelectedType[playerid] = -1;
    }
    else if(textid == InvPagePTD[playerid][0])
    {
        if(CurrInvPage[playerid] == 0)
            return 1;
        CurrInvPage[playerid] = 0;
        Inventory_RefreshPage(playerid);
    }
    else if(textid == InvPagePTD[playerid][1])
    {
        if(CurrInvPage[playerid] == 1)
            return 1;
        CurrInvPage[playerid] = 1;
        Inventory_RefreshPage(playerid);
    }
    else if(textid == ContainerPagePTD[playerid][0])
    {
        if(CurrInvPage[playerid] == 0)
            return 1;
        CurrContainerPage[playerid] = 0;
        //Container_RefreshPage(playerid);
    }
    else if(textid == ContainerPagePTD[playerid][1])
    {
        if(CurrInvPage[playerid] == 1)
            return 1;
        CurrContainerPage[playerid] = 0; // nanti set 1
        SendClientMessage(playerid, -1, "Coming Soon!");
        //Container_RefreshPage(playerid);
    }
    else
    {
        for(new i = 0; i < MAX_SLOTS_PER_PAGE; i++)
        {
            if(textid == InvSlotPTD[playerid][i])
            {
                if(SelectedSlot[playerid] != -1)
                {
                    new slot = CurrInvPage[playerid] * MAX_SLOTS_PER_PAGE + i,
                        SelectedIndex = SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE;

                    if(InvData[playerid][SelectedSlot[playerid]][invExist] && !InvData[playerid][slot][invExist])
                    {
                        InvData[playerid][slot][invExist] = true;
                        InvData[playerid][slot][invItemID] = InvData[playerid][SelectedSlot[playerid]][invItemID];
                        InvData[playerid][slot][invQuantity] = InvData[playerid][SelectedSlot[playerid]][invQuantity];

                        InvData[playerid][SelectedSlot[playerid]][invExist] = false;
                        InvData[playerid][SelectedSlot[playerid]][invItemID] = -1;
                        InvData[playerid][SelectedSlot[playerid]][invQuantity] = 0;
                        
                        new oldSlot = SelectedSlot[playerid];
                        SelectedSlot[playerid] = -1;
                        SelectedType[playerid] = -1;

                        Inventory_RefreshSlot(playerid, oldSlot);
                        Inventory_RefreshSlot(playerid, slot);
                        return 1;
                    }
                    else if(SelectedType[playerid] == 0)
                    {
                        PlayerTextDrawColour(playerid, InvSlotPTD[playerid][SelectedIndex], 66);
                        PlayerTextDrawShow(playerid, InvSlotPTD[playerid][SelectedIndex]);
                    }
                    else if(SelectedType[playerid] == 1)
                    {
                        new dropid = NearestItems[playerid][SelectedSlot[playerid]];
                        if(DropData[dropid][droppedExist] && dropid != -1 && !InvData[playerid][slot][invExist])
                        {
                            InvData[playerid][slot][invExist] = true;
                            InvData[playerid][slot][invItemID] = DropData[dropid][droppedItemID];
                            InvData[playerid][slot][invQuantity] = DropData[dropid][droppedItemQuantity];

                            Item_Delete(dropid);

                            ApplyAnimation(playerid, "CARRY", "liftup", 4.1, false, false, false, false, 0);
                            PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][SelectedIndex], 66);
                            PlayerTextDrawShow(playerid, ContainerSlotPTD[playerid][SelectedIndex]);
                        }
                    }
                }

                SelectedSlot[playerid] = CurrInvPage[playerid] * MAX_SLOTS_PER_PAGE + i;
                SelectedType[playerid] = 0;

                PlayerTextDrawColour(playerid, InvSlotPTD[playerid][i], 0xFFD70066);
                PlayerTextDrawShow(playerid, InvSlotPTD[playerid][i]);
                break;
            }
            else if(textid == ContainerSlotPTD[playerid][i])
            {
                if(SelectedSlot[playerid] != -1)
                {
                    new slot = CurrContainerPage[playerid] * MAX_SLOTS_PER_PAGE + i,
                        SelectedIndex = SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE;
                        
                    if(SelectedType[playerid] == 0)
                    {
                        if((AmountInput[playerid] < 1 || AmountInput[playerid] > 500) || AmountInput[playerid] > InvData[playerid][SelectedSlot[playerid]][invQuantity]) return SendClientMessage(playerid, -1, "Yang bener masukin jumlah itemnya kocak");

                        new itemid = InvData[playerid][SelectedSlot[playerid]][invItemID];
                        if(Inventory_Remove(playerid, itemid, AmountInput[playerid], SelectedSlot[playerid]))
                        {
                            new Float:x, Float:y, Float:z;
                            GetPlayerPos(playerid, x, y, z);
                            if(Item_Drop(itemid, AmountInput[playerid], x, y, z - 0.7, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid)))
                            {
                                ApplyAnimation(playerid, "CARRY", "putdwn", 4.1, false, false, false, false, 0);
                            }
                            else
                            {
                                Inventory_Add(playerid, itemid, AmountInput[playerid], SelectedSlot[playerid]);

                                new oldSlot = SelectedSlot[playerid];
                                SelectedSlot[playerid] = -1;
                                SelectedType[playerid] = -1;
                                Inventory_RefreshSlot(playerid, oldSlot);
                            }
                        }
                    }
                    else if(SelectedType[playerid] == 1)
                    {
                        PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][SelectedIndex], 66);
                        PlayerTextDrawShow(playerid, ContainerSlotPTD[playerid][SelectedIndex]);
                    }
                }
                SelectedSlot[playerid] = CurrContainerPage[playerid] * MAX_SLOTS_PER_PAGE + i;
                SelectedType[playerid] = 1;
                
                PlayerTextDrawColour(playerid, ContainerSlotPTD[playerid][i], 0xFFD70066);
                PlayerTextDrawShow(playerid, ContainerSlotPTD[playerid][i]);
                break;
            }
        }
    }
    return 1;
}

Dialog:InvInputAmount(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    if(!IsNumericEx(inputtext))
        return Dialog_Show(playerid, "InvInputAmount", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Inventory Input Amount", "Jumlah item hanya dapat diisi dengan angka. Silahkan masukkan jumlah item yang valid.", "Input", "Batal");

    new amount = strval(inputtext);

    if(amount < 1 || amount > 500)
        return Dialog_Show(playerid, "InvInputAmount", DIALOG_STYLE_INPUT, ""VANTARA"Vantara Roleplay"F_COLOR_WHITE" - Inventory Input Amount", "Jumlah item yang dimasukkan minimal 1 dan maksimal 500 dalam 1 aksi. Silahkan masukkan jumlah item yang valid.", "Input", "Batal");

    AmountInput[playerid] = amount;
    PlayerTextDrawSetString(playerid, InvTextPTD[playerid][3], "%d", amount);
    return 1;
}