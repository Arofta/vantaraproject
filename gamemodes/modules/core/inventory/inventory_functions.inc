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

stock Inventory_RefreshPage(playerid) // gunakan dengan bijak agar script tetap eefisien
{
    new offset = CurrInvPage[playerid] * MAX_SLOTS_PER_PAGE,
        slot = 0,
        itemid = -1;

    if(CurrInvPage[playerid] == 0)
    {
        PlayerTextDrawColour(playerid, InvPagePTD[playerid][0], 0xFFD700FF);
        PlayerTextDrawColour(playerid, InvPagePTD[playerid][1], 66);
    }
    else
    {
        PlayerTextDrawColour(playerid, InvPagePTD[playerid][0], 66);
        PlayerTextDrawColour(playerid, InvPagePTD[playerid][1], 0xFFD700FF);
    }
    PlayerTextDrawShow(playerid, InvPagePTD[playerid][0]);
    PlayerTextDrawShow(playerid, InvPagePTD[playerid][1]);

    for(new x; x < MAX_SLOTS_PER_PAGE; x++)
    {
        slot = offset + x;
        itemid = InvData[playerid][slot][invItemID];

        if(SelectedSlot[playerid] != -1 && (SelectedSlot[playerid] / MAX_SLOTS_PER_PAGE) == CurrInvPage[playerid])
        {
            PlayerTextDrawColour(playerid, InvSlotPTD[playerid][SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE], 0xFFD70066);
            PlayerTextDrawShow(playerid, InvSlotPTD[playerid][SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE]);
        }
        else
        {
            PlayerTextDrawColour(playerid, InvSlotPTD[playerid][SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE], 66);
            PlayerTextDrawShow(playerid, InvSlotPTD[playerid][SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE]);
        }

        if(InvData[playerid][slot][invExist])
        {
            PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][x], Items[itemid][Model]);
            PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][x], Items[itemid][RotX], Items[itemid][RotY], Items[itemid][RotZ], Items[itemid][Zoom]);
            PlayerTextDrawShow(playerid, InvModelPTD[playerid][x]);
            
            PlayerTextDrawSetString(playerid, InvNamePTD[playerid][x], "%s", Items[itemid][Name]);
            PlayerTextDrawShow(playerid, InvNamePTD[playerid][x]);
            
            PlayerTextDrawSetString(playerid, InvQuantityPTD[playerid][x], "%dx", InvData[playerid][slot][invQuantity]);
            PlayerTextDrawShow(playerid, InvQuantityPTD[playerid][x]);
        }
        else
        {
            PlayerTextDrawHide(playerid, InvModelPTD[playerid][x]);
            PlayerTextDrawHide(playerid, InvNamePTD[playerid][x]);
            PlayerTextDrawHide(playerid, InvQuantityPTD[playerid][x]);
        }
    }
    return 1;
}

stock Inventory_RefreshSlot(playerid, const slot) // Pakai kalau perlu refresh isi slot. Isi slot yang dimaksud meliputi, preview model, nama item, quantity.
{
    if(slot < 0 || slot >= MAX_INVENTORY_SLOTS)
        return 0;
    new index = slot % MAX_SLOTS_PER_PAGE,
        itemid = InvData[playerid][slot][invItemID];
    if((slot / MAX_SLOTS_PER_PAGE) == CurrInvPage[playerid])
    {
        if(InvData[playerid][slot][invExist])
        {
            PlayerTextDrawSetPreviewModel(playerid, InvModelPTD[playerid][index], Items[itemid][Model]);
            PlayerTextDrawSetPreviewRot(playerid, InvModelPTD[playerid][index], Items[itemid][RotX], Items[itemid][RotY], Items[itemid][RotZ], Items[itemid][Zoom]);
            PlayerTextDrawShow(playerid, InvModelPTD[playerid][index]);
            
            PlayerTextDrawSetString(playerid, InvNamePTD[playerid][index], "%s", Items[itemid][Name]);
            PlayerTextDrawShow(playerid, InvNamePTD[playerid][index]);
            
            PlayerTextDrawSetString(playerid, InvQuantityPTD[playerid][index], "%dx", InvData[playerid][slot][invQuantity]);
            PlayerTextDrawShow(playerid, InvQuantityPTD[playerid][index]);
        }
        else
        {
            PlayerTextDrawHide(playerid, InvModelPTD[playerid][index]);
            PlayerTextDrawHide(playerid, InvNamePTD[playerid][index]);
            PlayerTextDrawHide(playerid, InvQuantityPTD[playerid][index]);
        }

        if(SelectedSlot[playerid] != -1 && SelectedSlot[playerid] == slot)
        {
            PlayerTextDrawColour(playerid, InvSlotPTD[playerid][index], 0xFFD70066);
            PlayerTextDrawShow(playerid, InvSlotPTD[playerid][index]);
        }
        else
        {
            PlayerTextDrawColour(playerid, InvSlotPTD[playerid][index], 66);
            PlayerTextDrawShow(playerid, InvSlotPTD[playerid][index]);
        }
    }
    return 1;
}

stock Show_InvTD(playerid)
{
    PlayerTextDrawColour(playerid, InvPagePTD[playerid][0], 0xFFD700FF);
    PlayerTextDrawSetString(playerid, InvTextPTD[playerid][0], pData[playerid][pName]);
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

    PlayerTextDrawColour(playerid, InvSlotPTD[playerid][SelectedSlot[playerid] % MAX_SLOTS_PER_PAGE], 66);

    if(CurrInvPage[playerid] == 1)
    {
        PlayerTextDrawColour(playerid, InvPagePTD[playerid][0], 0xFFD700FF);
        PlayerTextDrawColour(playerid, InvPagePTD[playerid][1], 66);
    }

    TDInfo[playerid][InvTDShown] = false;
    CurrContainerPage[playerid] = 0;
    CurrInvPage[playerid] = 0;
    SelectedSlot[playerid] = -1;
    SelectedType[playerid] = -1;
    CancelSelectTextDraw(playerid);
    return 1;
}

/*
stock Show_ItemBox(playerid, interval, modelid, const title[], const itemName[])
{
    if(!iBoxInfo[playerid][x][BoxUsed])
    iBoxInfo[playerid][]
    return 0;
}

stock Hide_ItemBox(playerid, slot)
{
    
}
*/