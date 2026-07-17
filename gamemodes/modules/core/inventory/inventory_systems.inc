/* // Ini System v1
hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    // if(clickedid == SelectedSlot[playerid])
    // {
    //     if(SelectedType[playerid] == 0)
    //         PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
    //     else if(SelectedType[playerid] == 1)
    //         PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][SelectedSlot[playerid]], 0);
    //     SelectedSlot[playerid] = -1;
    //     SelectedType[playerid] = -1;
    // }
    for(new x = 0; x < MAX_SLOTS_PER_PAGE; x++)
    {
        if(clickedid == InvSlot[x])
        {
            if(CurrInvPage[playerid] == 0)
            {
                if(SelectedSlot[playerid] != -1)
                {
                    if(SelectedType[playerid] == 0)
                        PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                    else if(SelectedType[playerid] == 1)
                        PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][SelectedSlot[playerid]], 0);
                }

                SelectedSlot[playerid] = x;
                SelectedType[playerid] = 0;
                PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][x], 0xFFD70033);
            }
            else if(CurrInvPage[playerid] == 1)
            {
                if(SelectedSlot[playerid] != -1)
                {
                    if(SelectedType[playerid] == 0)
                        PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                    else if(SelectedType[playerid] == 1)
                        PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                }

                SelectedSlot[playerid] = x + 20;
                SelectedType[playerid] = 0;
                PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0xFFD70033);
            }
            break;
        }
        else if(clickedid == ContainerSlot[x])
        {
            if(CurrContainerPage[playerid] == 0)
            {
                if(SelectedSlot[playerid] != -1)
                {
                    if(SelectedType[playerid] == 0)
                        PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                    else if(SelectedType[playerid] == 1)
                        PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][SelectedSlot[playerid]], 0);
                }

                SelectedSlot[playerid] = x;
                SelectedType[playerid] = 1;
                PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][x], 0xFFD70033);
            }
            else if(CurrContainerPage[playerid] == 1)
            {
                if(SelectedSlot[playerid] != -1)
                {
                    if(SelectedType[playerid] == 0)
                        PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                    else if(SelectedType[playerid] == 1)
                        PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                }

                SelectedSlot[playerid] = x + 20;
                SelectedType[playerid] = 1;
                PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0xFFD70033);
            }
            break;
        }
    }
    
    return 1;
}

hook OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    if(playertextid == InvPage[playerid][0]) // Jika player klik Page 1
    {
        debugmsg(playerid, "InvPage TD 1 (0) clicked");
        if(CurrInvPage[playerid] == 1) // pastikan player saat ini sedang melihat page 2
        {
            debugmsg(playerid, "InvPage TD 1 (0) responeded");
            for(new x = 0; x < MAX_SLOTS_PER_PAGE; x++) // render isi inv page 1
            {
                if(!InvData[playerid][x][invExist])
                {
                    PlayerTextDrawHide(playerid, InvPrevModel[playerid][x]);
                    PlayerTextDrawHide(playerid, InvItemName[playerid][x]);
                    PlayerTextDrawHide(playerid, InvItemAmount[playerid][x]);
                    continue;
                }

                PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][x], Items[InvData[playerid][x][invItemID]][Model]);
                PlayerTextDrawSetString(playerid, InvItemName[playerid][x], Items[InvData[playerid][x][invItemID]][Name]);
                PlayerTextDrawSetString(playerid, InvItemAmount[playerid][x], "%dx", InvData[playerid][x][invQuantity]);
            }

            CurrInvPage[playerid] = 0;
            PlayerTextDrawColour(playerid, InvPage[playerid][0], 0xFFD70066);
            PlayerTextDrawColour(playerid, InvPage[playerid][1], 66);
        }
    }
    else if(playertextid == InvPage[playerid][1]) // Jika player klik Page 2
    {
        debugmsg(playerid, "InvPage TD 2 (1) clicked");
        if(CurrInvPage[playerid] == 0) // pastikan player saat ini sedang melihat page 1
        {
            debugmsg(playerid, "InvPage TD 2 (1) responeded");
            for(new x = 0; x < MAX_SLOTS_PER_PAGE; x++) // render isi inv page 2
            {
                if(!InvData[playerid][x + 20][invExist])
                {
                    PlayerTextDrawHide(playerid, InvPrevModel[playerid][x]);
                    PlayerTextDrawHide(playerid, InvItemName[playerid][x]);
                    PlayerTextDrawHide(playerid, InvItemAmount[playerid][x]);
                    continue;
                }

                PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][x], Items[InvData[playerid][x + 20][invItemID]][Model]);
                PlayerTextDrawSetString(playerid, InvItemName[playerid][x], Items[InvData[playerid][x + 20][invItemID]][Name]);
                PlayerTextDrawSetString(playerid, InvItemAmount[playerid][x], "%dx", InvData[playerid][x + 20][invQuantity]);
            }

            CurrInvPage[playerid] = 1;
            PlayerTextDrawColour(playerid, InvPage[playerid][0], 66);
            PlayerTextDrawColour(playerid, InvPage[playerid][1], 0xFFD70066);
        }
    }
    else if(playertextid == ContainerPage[playerid][0]) // Jika player klik Container Page 1
    {
        debugmsg(playerid, "ContainerPage TD 1 (0) clicked");
        if(CurrContainerPage[playerid] == 1) // pastikan player saat ini sedang melihat page 2
        {
            debugmsg(playerid, "ContainerPage TD 1 (0) responeded");
            for(new x = 0; x < MAX_SLOTS_PER_PAGE; x++) // render isi container page 1
            {
                if(!InvData[playerid][x][invExist])
                {
                    PlayerTextDrawHide(playerid, ContainerPrevModel[playerid][x]);
                    PlayerTextDrawHide(playerid, ContainerItemName[playerid][x]);
                    PlayerTextDrawHide(playerid, ContainerItemAmount[playerid][x]);
                    continue;
                }

                PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][x], Items[InvData[playerid][x][invItemID]][Model]);
                PlayerTextDrawSetString(playerid, ContainerItemName[playerid][x], Items[InvData[playerid][x][invItemID]][Name]);
                PlayerTextDrawSetString(playerid, ContainerItemAmount[playerid][x], "%dx", InvData[playerid][x][invQuantity]);
            }

            if(SelectedSlot[playerid] != -1)
            {
                if(SelectedType[playerid] == 0)
                    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                else if(SelectedType[playerid] == 1)
                    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][SelectedSlot[playerid]], 0);
            }

            CurrContainerPage[playerid] = 0;
            PlayerTextDrawColour(playerid, ContainerPage[playerid][0], 0xFFD70066);
            PlayerTextDrawColour(playerid, ContainerPage[playerid][1], 66);
        }
    }
    else if(playertextid == ContainerPage[playerid][1]) // Jika player klik Container Page 2
    {
        debugmsg(playerid, "ContainerPage TD 2 (1) clicked");
        if(CurrContainerPage[playerid] == 0) // pastikan player saat ini sedang melihat page 1
        {
            debugmsg(playerid, "ContainerPage TD 2 (1) responeded");
            for(new x = 0; x < MAX_SLOTS_PER_PAGE; x++) // render isi container page 2
            {
                if(!InvData[playerid][x + 20][invExist])
                {
                    PlayerTextDrawHide(playerid, ContainerPrevModel[playerid][x]);
                    PlayerTextDrawHide(playerid, ContainerItemName[playerid][x]);
                    PlayerTextDrawHide(playerid, ContainerItemAmount[playerid][x]);
                    continue;
                }

                PlayerTextDrawSetPreviewModel(playerid, ContainerPrevModel[playerid][x], Items[InvData[playerid][x + 20][invItemID]][Model]);
                PlayerTextDrawSetString(playerid, ContainerItemName[playerid][x], Items[InvData[playerid][x + 20][invItemID]][Name]);
                PlayerTextDrawSetString(playerid, ContainerItemAmount[playerid][x], "%dx", InvData[playerid][x + 20][invQuantity]);
            }

            if(SelectedSlot[playerid] != -1)
            {
                if(SelectedType[playerid] == 0)
                    PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                else if(SelectedType[playerid] == 1)
                    PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][SelectedSlot[playerid]], 0xFFD70033);
            }

            CurrContainerPage[playerid] = 1;
            PlayerTextDrawColour(playerid, ContainerPage[playerid][0], 66);
            PlayerTextDrawColour(playerid, ContainerPage[playerid][1], 0xFFD70066);
        }
    }
    return 1;
}
*/
/* // Ini System v2
hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    new clickedEx = clickedid;
    debugmsg(playerid, sprintf("clickedid: %d", clickedEx));
    for(new x = 0; x < MAX_SLOTS_PER_PAGE; x++)
    {
        if(clickedid == InvSlot[x])
        {
            debugmsg(playerid, sprintf("InvSlotTD: %d", x));
            break;
        }
        else if(clickedid == ContainerSlot[x])
        {
            debugmsg(playerid, sprintf("ContainerSlotTD: %d", x));
            break;
        }
    }
}

hook OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
    new playertextEx = playertextid;
    debugmsg(playerid, sprintf("playertextid: %d", playertextEx));
    if(playertextid == InvPage[playerid][0])
    {
        debugmsg(playerid, "InvPage TD 1 (0) clicked");
        printf("playertextid: %d", playertextid);
    }
    else if(playertextid == InvPage[playerid][1])
    {
        debugmsg(playerid, "InvPage TD 2 (1) clicked");
        printf("playertextid: %d", playertextid);
    }
    else if(playertextid == ContainerPage[playerid][0])
    {
        debugmsg(playerid, "ContainerPage TD 1 (0) clicked");
        printf("playertextid: %d", playertextid);
    }
    else if(playertextid == ContainerPage[playerid][1])
    {
        debugmsg(playerid, "ContainerPage TD 2 (1) clicked");
        printf("playertextid: %d", playertextid);
    }
    return 1;
}*/

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    for(new x = 0; x < MAX_SLOTS_PER_PAGE; x++)
    {
        if(clickedid == InvSlotTD[x])
        {
            if(CurrInvPage[playerid] == 0)
            {
                if(SelectedSlot[playerid] != -1)
                {
                    if(SelectedType[playerid] == 0)
                        PlayerTextDrawBackgroundColour(playerid, InvModelPTD[playerid][SelectedSlot[playerid]], 0);
                    else if(SelectedType[playerid] == 1)
                        PlayerTextDrawBackgroundColour(playerid, ContainerModelPTD[playerid][SelectedSlot[playerid]], 0);
                }

                SelectedSlot[playerid] = x;
                SelectedType[playerid] = 0;
                PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][x], 0xFFD70033);
            }
            else if(CurrInvPage[playerid] == 1)
            {
                if(SelectedSlot[playerid] != -1)
                {
                    if(SelectedType[playerid] == 0)
                        PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                    else if(SelectedType[playerid] == 1)
                        PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                }

                SelectedSlot[playerid] = x + 20;
                SelectedType[playerid] = 0;
                PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0xFFD70033);
            }
            break;
        }
        else if(clickedid == ContainerSlot[x])
        {
            if(CurrContainerPage[playerid] == 0)
            {
                if(SelectedSlot[playerid] != -1)
                {
                    if(SelectedType[playerid] == 0)
                        PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                    else if(SelectedType[playerid] == 1)
                        PlayerTextDrawBackgroundColour(playerid, ContainerPrevModel[playerid][SelectedSlot[playerid]], 0);
                }

                SelectedSlot[playerid] = x;
                SelectedType[playerid] = 1;
                PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][x], 0xFFD70033);
            }
            else if(CurrContainerPage[playerid] == 1)
            {
                if(SelectedSlot[playerid] != -1)
                {
                    if(SelectedType[playerid] == 0)
                        PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                    else if(SelectedType[playerid] == 1)
                        PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0);
                }

                SelectedSlot[playerid] = x + 20;
                SelectedType[playerid] = 1;
                PlayerTextDrawBackgroundColour(playerid, InvPrevModel[playerid][SelectedSlot[playerid]], 0xFFD70033);
            }
            break;
        }
    }
    return 1;
}
