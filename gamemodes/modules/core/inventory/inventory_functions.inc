#include <YSI_Coding\y_hooks>

#define MAX_INVENTORY_SLOTS     40
#define MAX_SLOTS_PER_PAGE      20

// #define MAX_BOX_SHOWN_AT_ONCE   5

enum e_MetaData 
{
    bool:IsExpired,
    OwnerID,
    ID
};

enum e_InventoryData
{
    bool:invExist,
    invItemID,
    invQuantity,
    e_MetaData:invMetaData
};
new InvData[MAX_PLAYERS][MAX_INVENTORY_SLOTS][e_InventoryData];

new SelectedSlot[MAX_PLAYERS] = -1;
new SelectedType[MAX_PLAYERS] = -1; // 0: Inventory | 1: Container
new CurrInvPage[MAX_PLAYERS] = 0;
new CurrContainerPage[MAX_PLAYERS] = 0;

// enum e_ItemBoxInfo
// {
//     bool:BoxUsed,
//     BoxModelID,
//     BoxItemName[32],
//     BoxTitle[44]
// };
// new iBoxInfo[MAX_PLAYERS][MAX_BOX_SHOWN_AT_ONCE][e_ItemBoxInfo];

enum e_InventoryItems
{
    Name[32],
    Model,
    Float:Zoom,
    Float:RotX,
    Float:RotY,
    Float:RotZ,
    bool:Stackable,
    bool:Usable
};

new const Items[][e_InventoryItems] = {
    {"Smartphone", 1234, 1.0, 1.0, 1.0, 1.0, false, true}, // 0
    {"Radio", 1234, 1.0, 1.0, 1.0, 1.0, false, true}, // 1
    {"KTP", 1234, 1.0, 1.0, 1.0, 1.0, false, true} // 2
};

enum e_ItemIDs
{
    ITEM_SMARTPHONE,
    ITEM_RADIO,
    ITEM_KTP
};

stock bool:Inventory_IsValidItemID(const itemID)
{
    if(itemID >= 0 && itemID < sizeof(Items))
        return true;
    return false;
}

stock Inventory_GetFreeSlot(playerid)
{
    for(new x = 0; x < MAX_INVENTORY_SLOTS; x++)
    {
        if(!InvData[playerid][x][invExist])
            return x;
    }
    return -1; // Tidak ada free slot
}

stock Inventory_GetFreeSlotEx(playerid, const itemID)
{
    new 
        fSlot = -1,
        eSlot = -1;
    for(new x = 0; x < MAX_INVENTORY_SLOTS; x++)
    {
        if(!InvData[playerid][x][invExist])
        {
            if(fSlot == -1)
                fSlot = x;
        }
        else
        {
            if(InvData[playerid][x][invItemID] == itemID)
                if(eSlot == -1)
                    eSlot = x;
        }

        if(fSlot > -1 && eSlot > -1)
            break;
    }

    if(Inventory_IsItemStackable(itemID) == 1) // Jika item stackable
    {
        if(eSlot == -1) // Jika tidak ada item yang sama di inventory
            return fSlot; // return slot kosong

        return eSlot; // return slot id dengan item id yang sama (hanya untuk item stackable)
    }
    else // Jika bukan item stackable
    {
        return fSlot; // return slot kosong
    }
}

stock Inventory_GetItemID(const itemName[])
{
    for(new x = 0; x < sizeof(Items); x++)
    {
        if(!strcmp(itemName, Items[x], true))
            return x;
    }
    return -1; // Tidak ditemukan item dengan nama tersebut
}

stock Inventory_GetItemName(const itemID)
{
    new str[32];
    if(itemID < 0 || itemID > sizeof(Items))
        return -1; // ItemID tidak valid
    strcopy(str, Items[itemID][Name]);
    return str;
}

stock Inventory_HasItem(playerid, const itemID) // Sekaligus GetItemSlot
{
    for(new x = 0; x < MAX_INVENTORY_SLOTS; x++)
    {
        if(InvData[playerid][x][invExist])
            if(InvData[playerid][x][invItemID] == id)
                return x;
    }
    return -1;
}

stock Inventory_IsItemStackable(const itemID)
{
    if(itemID < 0 || itemID > sizeof(Items))
        return -1; // ItemID Tidak valid
    if(Items[itemID][Stackable])
        return 1;
    else
        return 0;
}

stock Inventory_Add(playerid, const itemID, quantity = 1) // catatan, item stackable hanya ditambahkan sebanyak 1 walaupun kuantitas dari parameter lebih dari 1
{
    new 
        slotID = Inventory_GetFreeSlotEx(playerid, itemID),
        iQuery[512];

    if(quantity < 1)
        return 0;

    if(Inventory_IsItemStackable(itemID) == 0) // Jika item unstackable, maka quantity akan di set menjadi 1
        quantity = 1;

    printf("quantity: %d", quantity);
    
    if(slotID > -1)
    {
        if(!InvData[playerid][slotID][invExist])
        {
            InvData[playerid][slotID][invExist] = true;
            InvData[playerid][slotID][invItemID] = itemID;
            InvData[playerid][slotID][invQuantity] = quantity;
        }
        else
        {
            InvData[playerid][slotID][invQuantity] += quantity;
        }

        mysql_format(SQL, iQuery, sizeof(iQuery), "INSERT INTO `player_inventory` (`inv_owner_id`, `inv_slot_id`, `inv_item_id`, `inv_quantity`, `inv_metadata`) VALUES (%d, %d, %d, %d, '') ON DUPLICATE KEY UPDATE `inv_quantity` = `inv_quantity` + %d", pData[playerid][pID], slotID, itemID, quantity, quantity);
        mysql_pquery(SQL, iQuery);
        return 1;
    }
    else
    {
        SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Tas kamu tidak memiliki ruang kosong untuk menerima item.");
    }
    return 0;
}

stock Inventory_Remove(playerid, const itemID, quantity = 1) // Catatan: Inventory_Remove hanya remove item pada 1 slot dan tidak peduli kuantitas, bahkan jika item tersebut adalah unstackable item.
{
    new
        slotID = Inventory_HasItem(playerid, const itemID),
        iQuery[512];

    if(quantity < 1)
        return 0;

    if(slotID > -1)
    {
        InvData[playerid][slotID][invQuantity] -= quantity;
        if(InvData[playerid][slotID][invQuantity] < 1)
        {
            InvData[playerid][slotID][invExist] = false;
            InvData[playerid][slotID][invItemID] = -1;
            InvData[playerid][slotID][invQuantity] = 0;

            mysql_format(SQL, iQuery, sizeof(iQuery), "DELETE FROM `player_inventory` WHERE `inv_owner_id` = %d AND `inv_slot_id` = %d", pData[playerid][pID], slotID)
            mysql_pquery(SQL, iQuery);
        }
        else
        {
            mysql_format(SQL, iQuery, sizeof(iQuery), "UPDATE `player_inventory` SET `inv_quantity` = `inv_quantity` - %d WHERE `inv_owner_id` = %d AND `inv_slot_id` = %d", quantity, pData[playerid][pID], slotID);
            mysql_pquery(SQL, iQuery);
        }
        return 1;
    }
    return 0;
}

stock Inventory_Clear(playerid)
{
	for(new x = 0; x < MAX_INVENTORY_SLOTS; x++)
	{
	    if(InvData[playerid][x][invExists])
	    {
	        InvData[playerid][x][invExists] = false;
			InvData[playerid][x][invItemID] = 0;
	        InvData[playerid][x][invQuantity] = 0;
		}
	}

	new iQuery[64];
	mysql_format(SQL, iQuery, sizeof(iQuery), "DELETE FROM `player_inventory` WHERE `inv_owner_id` = %d", pData[playerid][pID]);
	return mysql_pquery(SQL, iQuery);
}

stock Show_InvTD(playerid)
{
    for(new x = 0; x < 20; x++)
    {
        if(x < 2) PlayerTextDrawShow(playerid, InvPagePTD[playerid][x]);
        if(x < 4) 
        {
            TextDrawShowForPlayer(playerid, InvTextTD[x]);
            PlayerTextDrawShow(playerid, InvTextPTD[playerid][x]);
        }
        if(x < 5) TextDrawShowForPlayer(playerid, InvButtonTD[x]);
        if(x < 6) TextDrawShowForPlayer(playerid, InvBaseTD[x]);
        
        PlayerTextDrawShow(playerid, InvSlotPTD[playerid][x]);
        if(InvData[playerid][x][invExist])
        {
            PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][x], Items[InvData[playerid][x][invItemID]][Model]);
            PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][x], Items[InvData[playerid][x][invItemID]][RotX], Items[InvData[playerid][x][invItemID]][RotY], Items[InvData[playerid][x][invItemID]][RotZ], Items[InvData[playerid][x][invItemID]][Zoom]);
            PlayerTextDrawShow(playerid, InvModelPTD[playerid][x]);
            
            PlayerTextDrawSetString(playerid, InvNamePTD[playerid][x], "%s", Items[InvData[playerid][x][invItemID]][Name]);
            PlayerTextDrawShow(playerid, InvNamePTD[playerid][x]);
            
            PlayerTextDrawSetString(playerid, InvQuantityPTD[playerid][x], "%dx", InvData[playerid][x][invQuantity]);
            PlayerTextDrawShow(playerid, InvQuantityPTD[playerid][x]);
        }
    }
    PlayerTextDrawShow(playerid, InvWeightBarPTD[playerid]);

    TDInfo[playerid][InvTDShown] = true;
    CurrContainerPage[playerid] = 0;
    CurrInvPage[playerid] = 0;
    SelectedSlot[playerid] = -1;
    SelectedType[playerid] = -1;
    SelectTextDraw(playerid, 0x00000066);
    return 1;
}

stock Hide_InvTD(playerid)
{
    for(new x = 0; x < 20; x++)
    {
        if(x < 2) PlayerTextDrawHide(playerid, InvPagePTD[playerid][x]);
        if(x < 4) 
        {
            TextDrawHideForPlayer(playerid, InvTextTD[x]);
            PlayerTextDrawHide(playerid, InvTextPTD[playerid][x]);
        }
        if(x < 5) TextDrawHideForPlayer(playerid, InvButtonTD[x]);
        if(x < 6) TextDrawHideForPlayer(playerid, InvBaseTD[x]);
        
        PlayerTextDrawHide(playerid, InvSlotPTD[playerid][x]);
        PlayerTextDrawHide(playerid, InvModelPTD[playerid][x]);
        PlayerTextDrawHide(playerid, InvNamePTD[playerid][x]);
        PlayerTextDrawHide(playerid, InvQuantityPTD[playerid][x]);
    }
    PlayerTextDrawHide(playerid, InvWeightBarPTD[playerid]);

    TDInfo[playerid][InvTDShown] = false;
    CurrContainerPage[playerid] = 0;
    CurrInvPage[playerid] = 0;
    SelectedSlot[playerid] = -1;
    SelectedType[playerid] = -1;
    CancelSelectTextDraw(playerid);
    return 1;
}

/*
stock Show_InvTD(playerid)
{
    for(new i = 0; i < 35; i++)
    {
        if(i < 2)
        {
            PlayerTextDrawShow(playerid, InvPage[playerid][i]);
            PlayerTextDrawShow(playerid, ContainerPage[playerid][i]);
        }

        if(i < 3)
            PlayerTextDrawShow(playerid, ContainerModeText[playerid][i]);

        if(i < 4)
            TextDrawShowForPlayer(playerid, ExtraButton[i]);

        if(i < 5)
            TextDrawShowForPlayer(playerid, Button[i]);

        if(i < 20)
        {
            TextDrawShowForPlayer(playerid, InvSlot[i]);
            TextDrawShowForPlayer(playerid, ContainerSlot[i]);

            if(InvData[playerid][i][invExist])
            {
                PlayerTextDrawSetPreviewModel(playerid, InvPrevModel[playerid][i], Items[InvData[playerid][i][invItemID]][Model]);
                PlayerTextDrawShow(playerid, InvPrevModel[playerid][i]);

                PlayerTextDrawSetString(playerid, InvItemName[playerid][i], "%s", Items[InvData[playerid][i][invItemID]][Name]);
                PlayerTextDrawShow(playerid, InvItemName[playerid][i]);

                PlayerTextDrawSetString(playerid, InvItemAmount[playerid][i], "%dx", InvData[playerid][i][invQuantity]);
                PlayerTextDrawShow(playerid, InvItemAmount[playerid][i]);
            }

            //PlayerTextDrawShow(playerid, ContainerPrevModel[playerid][i]);
            //PlayerTextDrawShow(playerid, ContainerItemName[playerid][i]);
            //PlayerTextDrawShow(playerid, ContainerItemAmount[playerid][i]);
        }
        TextDrawShowForPlayer(playerid, BaseInvTD[i]);
    }

    PlayerTextDrawSetString(playerid, InvPlayerName[playerid], "%s", pData[playerid][pName]);
    PlayerTextDrawShow(playerid, InvPlayerName[playerid]);

    PlayerTextDrawShow(playerid, InvWeightBar[playerid]);
    PlayerTextDrawShow(playerid, InvWeightText[playerid]);
    PlayerTextDrawShow(playerid, InvPageText[playerid]);

    PlayerTextDrawSetString(playerid, ContainerTitle[playerid], "On The Ground");
    PlayerTextDrawShow(playerid, ContainerTitle[playerid]);

    PlayerTextDrawShow(playerid, ContainerWeightBar[playerid]);
    PlayerTextDrawShow(playerid, ContainerWeightText[playerid]);
    PlayerTextDrawShow(playerid, ContainerPageText[playerid]);

    PlayerTextDrawShow(playerid, AmountTD[playerid]);

    TDInfo[playerid][InvTDShown] = true;
    CurrContainerPage[playerid] = 0;
    CurrInvPage[playerid] = 0;
    SelectedSlot[playerid] = -1;
    SelectedType[playerid] = -1;
    SelectTextDraw(playerid, 0x00000066);
    return 1;
}

stock Hide_InvTD(playerid)
{
    for(new i = 0; i < 35; i++)
    {
        if(i < 2)
        {
            PlayerTextDrawHide(playerid, InvPage[playerid][i]);
            PlayerTextDrawHide(playerid, ContainerPage[playerid][i]);
        }

        if(i < 3)
            PlayerTextDrawHide(playerid, ContainerModeText[playerid][i]);

        if(i < 4)
            TextDrawHideForPlayer(playerid, ExtraButton[i]);

        if(i < 5)
            TextDrawHideForPlayer(playerid, Button[i]);

        if(i < 20)
        {
            TextDrawHideForPlayer(playerid, InvSlot[i]);
            TextDrawHideForPlayer(playerid, ContainerSlot[i]);

            PlayerTextDrawHide(playerid, InvPrevModel[playerid][i]);
            PlayerTextDrawHide(playerid, InvItemName[playerid][i]);
            PlayerTextDrawHide(playerid, InvItemAmount[playerid][i]);

            PlayerTextDrawHide(playerid, ContainerPrevModel[playerid][i]);
            PlayerTextDrawHide(playerid, ContainerItemName[playerid][i]);
            PlayerTextDrawHide(playerid, ContainerItemAmount[playerid][i]);
        }
        TextDrawHideForPlayer(playerid, BaseInvTD[i]);
    }

    PlayerTextDrawHide(playerid, InvPlayerName[playerid]);
    PlayerTextDrawHide(playerid, InvWeightBar[playerid]);
    PlayerTextDrawHide(playerid, InvWeightText[playerid]);
    PlayerTextDrawHide(playerid, InvPageText[playerid]);

    PlayerTextDrawHide(playerid, ContainerTitle[playerid]);
    PlayerTextDrawHide(playerid, ContainerWeightBar[playerid]);
    PlayerTextDrawHide(playerid, ContainerWeightText[playerid]);
    PlayerTextDrawHide(playerid, ContainerPageText[playerid]);

    PlayerTextDrawHide(playerid, AmountTD[playerid]);

    TDInfo[playerid][InvTDShown] = false;
    CurrContainerPage[playerid] = 0;
    CurrInvPage[playerid] = 0;
    SelectedSlot[playerid] = -1;
    SelectedType[playerid] = -1;
    CancelSelectTextDraw(playerid);
    return 1;
}*/

// stock Show_ItemBox(playerid, interval, modelid, const title[], const itemName[])
// {
//     if(!iBoxInfo[playerid][x][BoxUsed])
//     iBoxInfo[playerid][]
//     return 0;
// }
// 
// stock Hide_ItemBox(playerid, slot)
// {
//     
// }