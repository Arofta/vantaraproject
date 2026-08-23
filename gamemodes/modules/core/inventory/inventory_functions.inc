#include <YSI_Coding\y_hooks>

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
new AmountInput[MAX_PLAYERS] = 0; // jumlah item.
new CurrInvPage[MAX_PLAYERS] = 0;
new CurrContainerPage[MAX_PLAYERS] = 0;
new CurrContainerMode[MAX_PLAYERS] = 0; // 0 = mode drop, 1 mode mobil, 2 mode geledah, 3 mode house/property storage
new CurrContainerViewID[MAX_PLAYERS] = -1;

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
    Weight, // dalam satuan gram. nilainya tidak boleh dibawah 10
    Float:RotX,
    Float:RotY,
    Float:RotZ,
    Float:Zoom,
    bool:Stackable,
    bool:Usable
};

new const Items[][e_InventoryItems] = {
    {"dummy", 1234, 15000, 1.0, 1.0, 1.0, 1.0, false, false}, // 0
    {"Brass Knuckle", 331, 250, 1.0, 1.0, 1.0, 1.0, false, true}, // 1
    {"Stik Golf", 333, 450, 1.0, 1.0, 1.0, 1.0, false, true}, // 2
    {"Baton", 334, 500, 1.0, 1.0, 1.0, 1.0, false, true}, // 3
    {"Pisau", 335, 300, 1.0, 1.0, 1.0, 1.0, false, true}, // 4
    {"Pemukul Bisbol", 336, 850, 1.0, 1.0, 1.0, 1.0, false, true}, // 5
    {"Sekop", 337, 1500, 1.0, 1.0, 1.0, 1.0, false, true}, // 6
    {"Stik Biliar", 338, 550, 1.0, 1.0, 1.0, 1.0, false, true}, // 7
    {"Katana", 339, 1250, 1.0, 1.0, 1.0, 1.0, false, true}, // 8
    {"Gergaji Mesin", 341, 4500, 1.0, 1.0, 1.0, 1.0, false, true}, // 9
    {"Dildo Besar", 321, 450, 1.0, 1.0, 1.0, 1.0, false, true}, // 10
    {"Dildo Kecil", 322, 200, 1.0, 1.0, 1.0, 1.0, false, true}, // 11
    {"Vibrator Besar", 323, 450, 1.0, 1.0, 1.0, 1.0, false, true}, // 12
    {"Vibrator Kecil", 324, 200, 1.0, 1.0, 1.0, 1.0, false, true}, // 13
    {"Buket Bunga", 325, 500, 1.0, 1.0, 1.0, 1.0, false, true}, // 14
    {"Tongkat Jalan", 326, 600, 1.0, 1.0, 1.0, 1.0, false, true}, // 15
    {"Granat", 342, 400, 1.0, 1.0, 1.0, 1.0, false, true}, // 16
    {"Gas Air Mata", 343, 450, 1.0, 1.0, 1.0, 1.0, false, true}, // 17
    {"Bom Molotov", 344, 1000, 1.0, 1.0, 1.0, 1.0, false, true}, // 18
    {"dummy2", 1234, 15000, 1.0, 1.0, 1.0, 1.0, false, true}, // 19
    {"dummy3", 1234, 15000, 1.0, 1.0, 1.0, 1.0, false, true}, // 20
    {"dummy4", 1234, 15000, 1.0, 1.0, 1.0, 1.0, false, true}, // 21
    {"Colt 45", 346, 950, 1.0, 1.0, 1.0, 1.0, false, true}, // 22
    {"Silenced Pistol", 347, 1300, 1.0, 1.0, 1.0, 1.0, false, true}, // 23
    {"Desert Eagle", 348, 1800, 1.0, 1.0, 1.0, 1.0, false, true}, // 24
    {"Shotgun", 349, 3400, 1.0, 1.0, 1.0, 1.0, false, true}, // 25
    {"Sawn-off Shotgun", 350, 2400, 1.0, 1.0, 1.0, 1.0, false, true}, // 26
    {"Combat Shotgun", 351, 4600, 1.0, 1.0, 1.0, 1.0, false, true}, // 27
    {"Micro UZI", 352, 2900, 1.0, 1.0, 1.0, 1.0, false, true}, // 28
    {"MP5", 353, 3500, 1.0, 1.0, 1.0, 1.0, false, true}, // 29
    {"AK47", 355, 4300, 1.0, 1.0, 1.0, 1.0, false, true}, // 30
    {"M4", 356, 3500, 1.0, 1.0, 1.0, 1.0, false, true}, // 31
    {"TEC9", 372, 1400, 1.0, 1.0, 1.0, 1.0, false, true}, // 32
    {"Rifle", 357, 3400, 1.0, 1.0, 1.0, 1.0, false, true}, // 33
    {"Sniper", 358, 6200, 1.0, 1.0, 1.0, 1.0, false, true}, // 34
    {"Bazoka", 359, 7000, 1.0, 1.0, 1.0, 1.0, false, true}, // 35
    {"Heat Seeker", 360, 15200, 1.0, 1.0, 1.0, 1.0, false, true}, // 36
    {"Flamethrower", 361, 19500, 1.0, 1.0, 1.0, 1.0, false, true}, // 37
    {"Minigun", 362, 39000, 1.0, 1.0, 1.0, 1.0, false, true}, // 38
    {"Sticky Bomb", 363, 1500, 1.0, 1.0, 1.0, 1.0, false, true}, // 39
    {"Detonator", 364, 300, 1.0, 1.0, 1.0, 1.0, false, true}, // 40
    {"Pilox", 365, 500, 1.0, 1.0, 1.0, 1.0, false, true}, // 41
    {"APAR", 366, 3700, 1.0, 1.0, 1.0, 1.0, false, true}, // 42
    {"Kamera", 367, 900, 1.0, 1.0, 1.0, 1.0, false, true}, // 43
    {"Night Goggles", 368, 850, 1.0, 1.0, 1.0, 1.0, false, true}, // 44
    {"Thermal Goggles", 369, 1000, 1.0, 1.0, 1.0, 1.0, false, true}, // 45
    {"Parasut", 371, 8000, 1.0, 1.0, 1.0, 1.0, false, true}, // 46
    {"Smartphone", 1234, 235, 1.0, 1.0, 1.0, 1.0, false, true}, // 47
    {"Radio", 1234, 400, 1.0, 1.0, 1.0, 1.0, false, true}, // 48
    {"KTP", 1234, 10, 1.0, 1.0, 1.0, 1.0, false, true} // 49
};

// enum e_ItemIDs
// {
//     ITEM_SMARTPHONE,
//     ITEM_RADIO,
//     ITEM_KTP
// };

bool:IsValidItem(const itemid)
{
    return (itemid >= 0 && itemid < sizeof(Items));
}

Inventory_GetFreeSlot(playerid)
{
    for(new x = 0; x < MAX_INVENTORY_SLOTS; x++)
    {
        if(!InvData[playerid][x][invExist])
            return x;
    }
    return -1; // Tidak ada free slot
}

Inventory_GetFreeSlotEx(playerid, const itemid)
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
            if(InvData[playerid][x][invItemID] == itemid)
                if(eSlot == -1)
                    eSlot = x;
        }

        if(fSlot > -1 && eSlot > -1)
            break;
    }

    if(Inventory_IsItemStackable(itemid) == 1) // Jika item stackable
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

Inventory_GetItemID(const itemName[])
{
    for(new x = 0; x < sizeof(Items); x++)
    {
        if(!strcmp(itemName, Items[x], true))
            return x;
    }
    return -1; // Tidak ditemukan item dengan nama tersebut
}

Inventory_GetItemName(const itemid)
{
    new str[32];
    if(!IsValidItem(itemid))
        return -1; // ItemID tidak valid
    strcopy(str, Items[itemid][Name]);
    return str;
}

Inventory_GetSlotWeight(playerid, slotid)
{
    new str[16];
    format(str, sizeof(str), "%.2f", Items[InvData[playerid][slotid][invItemID]][Weight] * InvData[playerid][slotid][invQuantity]);
    return str;
}

Inventory_GetTotalWeight(playerid)
{
    new str[16];
    format(str, sizeof(str), "%.2f", pData[playerid][pInvTotalWeight] / 1000);
    return str;
}

Inventory_GetMaxWeight(playerid)
{
    switch(pData[playerid][pVIP])
    {
        case 1: // Silver 958 (1)
        {
            return 30000; // 30kg
        }

        case 2: // Silver 999 (2)
        {
            return 35000; // 35 kg
        }

        case 3: // Gold 16K (3)
        {
            return 45000; // 45 kg
        }

        case 4: // Gold 20K (4)
        {
            return 65000; // 65 kg
        }

        case 5: // Gold 24K (5)
        {
            return 90000; // 90 kg
        }

        default:
        {
            return 25000; // 25kg
        }
    }
    return 1;
}

Inventory_HasItem(playerid, const itemid) // Sekaligus GetItemSlot
{
    for(new x = 0; x < MAX_INVENTORY_SLOTS; x++)
    {
        if(InvData[playerid][x][invExist])
            if(InvData[playerid][x][invItemID] == itemid)
                return x;
    }
    return -1;
}

Inventory_IsItemStackable(const itemid)
{
    if(!IsValidItem(itemid))
        return -1; // ItemID Tidak valid
    return Items[itemid][Stackable];
}

Inventory_Add(playerid, const itemid, quantity = 1, slotid = -1) // catatan: item stackable hanya ditambahkan sebanyak 1 walaupun kuantitas dari parameter lebih dari 1.
{
    new iQuery[512];

    if(slotid < 0)
        slotid = Inventory_GetFreeSlotEx(playerid, itemid);
    else if(InvData[playerid][slotid][invExist] && (InvData[playerid][slotid][invItemID] != itemid || Inventory_IsItemStackable(InvData[playerid][slotid][invItemID]) == 0))
        return 0; // gagal

    if(quantity < 1)
        return 0;

    if(Inventory_IsItemStackable(itemid) == 0) // Jika item unstackable, maka quantity akan di set menjadi 1
        quantity = 1;
    
    if(slotid > -1)
    {
        if(!InvData[playerid][slotid][invExist])
        {
            InvData[playerid][slotid][invExist] = true;
            InvData[playerid][slotid][invItemID] = itemid;
            InvData[playerid][slotid][invQuantity] = quantity;
        }
        else
        {
            InvData[playerid][slotid][invQuantity] += quantity;
        }

        pData[playerid][pInvTotalWeight] += (Items[itemid][Weight] * InvData[playerid][slotid][invQuantity]);
        Inventory_RefreshWeightBar(playerid);
        mysql_format(g_SQL, iQuery, sizeof(iQuery), "INSERT INTO `player_inventory` (`inv_owner_id`, `inv_slot_id`, `inv_item_id`, `inv_quantity`, `inv_metadata`) VALUES (%d, %d, %d, %d, '') ON DUPLICATE KEY UPDATE `inv_quantity` = `inv_quantity` + %d", pData[playerid][pID], slotid, itemid, quantity, quantity);
        mysql_pquery(g_SQL, iQuery);
        return 1;
    }
    else
    {
        SendClientMessage(playerid, COLOR_LIGHTBLUE, "ERROR: "F_COLOR_WHITE"Tas kamu tidak memiliki ruang kosong untuk menerima item.");
    }
    return 0;
}

Inventory_Remove(playerid, const itemid, quantity = 1, slotid = -1) // Catatan: Inventory_Remove hanya remove item pada 1 slot dan tidak peduli kuantitas, bahkan jika item tersebut adalah unstackable item.
{
    new iQuery[512];

    if(slotid < 0)
        slotid = Inventory_HasItem(playerid, itemid);
    else if(!InvData[playerid][slotid][invExist] || InvData[playerid][slotid][invItemID] != itemid)
        return 0;

    if(quantity < 1)
        return 0;

    if(slotid > -1)
    {
        //InvData[playerid][slotid][invQuantity] -= quantity;
        if(InvData[playerid][slotid][invQuantity] <= quantity)
        {
            pData[playerid][pInvTotalWeight] -= Items[itemid][Weight] * InvData[playerid][slotid][invQuantity];

            InvData[playerid][slotid][invExist] = false;
            InvData[playerid][slotid][invItemID] = -1;
            InvData[playerid][slotid][invQuantity] = 0;

            mysql_format(g_SQL, iQuery, sizeof(iQuery), "DELETE FROM `player_inventory` WHERE `inv_owner_id` = %d AND `inv_slot_id` = %d", pData[playerid][pID], slotid);
            mysql_pquery(g_SQL, iQuery);
        }
        else
        {
            pData[playerid][pInvTotalWeight] -= Items[itemid][Weight] * quantity;

            InvData[playerid][slotid][invQuantity] -= quantity;
            mysql_format(g_SQL, iQuery, sizeof(iQuery), "UPDATE `player_inventory` SET `inv_quantity` = `inv_quantity` - %d WHERE `inv_owner_id` = %d AND `inv_slot_id` = %d", quantity, pData[playerid][pID], slotid);
            mysql_pquery(g_SQL, iQuery);
        }

        Inventory_RefreshWeightBar(playerid);
        return 1;
    }
    return 0;
}

Inventory_Clear(playerid)
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

    pData[playerid][pInvTotalWeight] = 0;

	new iQuery[64];
	mysql_format(g_SQL, iQuery, sizeof(iQuery), "DELETE FROM `player_inventory` WHERE `inv_owner_id` = %d", pData[playerid][pID]);
	return mysql_pquery(g_SQL, iQuery);
}

Inventory_RefreshWeightBar(playerid)
{
    if(!TDInfo[playerid][InvTDShown])
        return 0;

    PlayerTextDrawSetString(playerid, InvTextPTD[playerid][2], "%s / %d kg", Inventory_GetTotalWeight(playerid), Inventory_GetMaxWeight(playerid) / 1000);
    PlayerTextDrawTextSize(playerid, InvWeightBarPTD[playerid], pData[playerid][pInvTotalWeight] * 99.0 / Inventory_GetMaxWeight(playerid), 7.000);
    PlayerTextDrawShow(playerid, InvWeightBarPTD[playerid]);
    return 1;
}

Inventory_RefreshPage(playerid) // gunakan dengan bijak agar script tetap efisien
{
    new offset = CurrInvPage[playerid] * MAX_SLOTS_PER_PAGE,
        slot = 0,
        itemid = -1;

    if(!TDInfo[playerid][InvTDShown])
        return 0;

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

Inventory_RefreshSlot(playerid, const slot) // Pakai kalau perlu refresh sebuah slot.
{
    if(slot < 0 || slot >= MAX_INVENTORY_SLOTS)
        return 0;
    new index = slot % MAX_SLOTS_PER_PAGE,
        itemid = InvData[playerid][slot][invItemID];

    if(!TDInfo[playerid][InvTDShown])
        return 0;

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

Show_InvTD(playerid)
{
    PlayerTextDrawColour(playerid, InvPagePTD[playerid][0], 0xFFD700FF);
    PlayerTextDrawSetString(playerid, InvTextPTD[playerid][0], pData[playerid][pName]);
    PlayerTextDrawSetString(playerid, ContainerTextPTD[playerid][0], "On The Ground");
    Item_FindNearestDrops(playerid);
    for(new x = 0; x < 2; x++)
    {
        PlayerTextDrawShow(playerid, InvPagePTD[playerid][x]);
        PlayerTextDrawShow(playerid, ContainerPagePTD[playerid][x]);
    }
    for(new x = 0; x < 3; x++) PlayerTextDrawShow(playerid, ContainerTextPTD[playerid][x]);
    for(new x = 0; x < 4; x++)
    {
        TextDrawShowForPlayer(playerid, InvTextTD[x]);
        PlayerTextDrawShow(playerid, InvTextPTD[playerid][x]);
    }
    for(new x = 0; x < 5; x++)
    {
        TextDrawShowForPlayer(playerid, InvButtonTD[x]);
        TextDrawShowForPlayer(playerid, ContainerBaseTD[x]);
    }
    for(new x = 0; x < 6; x++) TextDrawShowForPlayer(playerid, InvBaseTD[x]);
    for(new x = 0; x < 20; x++)
    {
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

        PlayerTextDrawShow(playerid, ContainerSlotPTD[playerid][x]);

        if(NearestItems[playerid][x] >= 0 && NearestItems[playerid][x] < MAX_DROPPED_ITEMS)
        {
            printf("DropID=%d ItemID=%d", NearestItems[playerid][x], DropData[NearestItems[playerid][x]][droppedItemID]);
            PlayerTextDrawSetPreviewModel(playerid, ContainerModelPTD[playerid][x], Items[DropData[NearestItems[playerid][x]][droppedItemID]][Model]);
            PlayerTextDrawSetPreviewRot(playerid, ContainerModelPTD[playerid][x], Items[DropData[NearestItems[playerid][x]][droppedItemID]][RotX], Items[DropData[NearestItems[playerid][x]][droppedItemID]][RotY], Items[DropData[NearestItems[playerid][x]][droppedItemID]][RotZ], Items[DropData[NearestItems[playerid][x]][droppedItemID]][Zoom]);

            PlayerTextDrawShow(playerid, ContainerModelPTD[playerid][x]);

            PlayerTextDrawSetString(playerid, ContainerNamePTD[playerid][x], "%s", Items[DropData[NearestItems[playerid][x]][droppedItemID]][Name]);
            PlayerTextDrawShow(playerid, ContainerNamePTD[playerid][x]);

            PlayerTextDrawSetString(playerid, ContainerQuantityPTD[playerid][x], "%dx", DropData[NearestItems[playerid][x]][droppedItemQuantity]);
            PlayerTextDrawShow(playerid, ContainerQuantityPTD[playerid][x]);
        }
    }
    PlayerTextDrawShow(playerid, InvWeightBarPTD[playerid]);
    PlayerTextDrawShow(playerid, ContainerWeightBarPTD[playerid]); // Container


    TDInfo[playerid][InvTDShown] = true;
    Inventory_RefreshWeightBar(playerid);
    CurrContainerPage[playerid] = 0;
    CurrInvPage[playerid] = 0;
    SelectedSlot[playerid] = -1;
    SelectedType[playerid] = -1;
    SelectTextDraw(playerid, 0x00000066);
    return 1;
}

Hide_InvTD(playerid)
{
    // 2x
    for(new x = 0; x < 2; x++)
    {
        PlayerTextDrawHide(playerid, InvPagePTD[playerid][x]);
        PlayerTextDrawHide(playerid, ContainerPagePTD[playerid][x]);
    }

    // 3x
    for(new x = 0; x < 3; x++)
    {
        PlayerTextDrawHide(playerid, ContainerTextPTD[playerid][x]);
    }

    // 4x
    for(new x = 0; x < 4; x++)
    {
        TextDrawHideForPlayer(playerid, InvTextTD[x]);
        PlayerTextDrawHide(playerid, InvTextPTD[playerid][x]);
    }

    // 5x
    for(new x = 0; x < 5; x++)
    {
        TextDrawHideForPlayer(playerid, InvButtonTD[x]);
        TextDrawHideForPlayer(playerid, ContainerBaseTD[x]);
    }

    // 6x
    for(new x = 0; x < 6; x++)
    {
        TextDrawHideForPlayer(playerid, InvBaseTD[x]);
    }

    // 20x
    for(new x = 0; x < 20; x++)
    {
        PlayerTextDrawHide(playerid, InvSlotPTD[playerid][x]);
        PlayerTextDrawHide(playerid, InvModelPTD[playerid][x]);
        PlayerTextDrawHide(playerid, InvNamePTD[playerid][x]);
        PlayerTextDrawHide(playerid, InvQuantityPTD[playerid][x]);

        PlayerTextDrawHide(playerid, ContainerSlotPTD[playerid][x]);
        PlayerTextDrawHide(playerid, ContainerModelPTD[playerid][x]);
        PlayerTextDrawHide(playerid, ContainerNamePTD[playerid][x]);
        PlayerTextDrawHide(playerid, ContainerQuantityPTD[playerid][x]);
    }
    PlayerTextDrawHide(playerid, InvWeightBarPTD[playerid]);
    PlayerTextDrawHide(playerid, ContainerWeightBarPTD[playerid]); // Container

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