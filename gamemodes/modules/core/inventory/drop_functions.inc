Item_Delete(dropid)
{
	if(!DropData[dropid][droppedExist]) 
		return 1;

	if(DestroyDynamicObject(DropData[dropid][droppedObject]))
		DropData[dropid][droppedObject] = STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;

	if(DestroyDynamic3DTextLabel(DropData[dropid][droppedLabel]))
		DropData[dropid][droppedLabel] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_STREAMER_ID;

	DropData[dropid][droppedExist] = false;
	DropData[dropid][droppedItemID] = -1;
	DropData[dropid][droppedItemQuantity] = 0;
	//DropData[dropid][droppedMetaData] =;

	DropData[dropid][droppedWeaponID] = 0;
	DropData[dropid][droppedWeaponCond] = 0.0;
	DropData[dropid][droppedWeaponGrade] = 0;
	DropData[dropid][droppedWeaponAmmo] = 0;
	DropData[dropid][droppedWeaponSerial][0] = EOS;

	//DropData[dropid][droppedDNA][0] = EOS;
	DropData[dropid][droppedPos][0] = 0.0;
	DropData[dropid][droppedPos][1] = 0.0;
	DropData[dropid][droppedPos][2] = 0.0;
	DropData[dropid][droppedWorld] = 0;
	DropData[dropid][droppedInt] = 0;

	Iter_Remove(Drops, dropid);

	new query[64];
	mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `dropped_items` WHERE `dropped_id` = %d", dropid);
	mysql_pquery(g_SQL, query);
	return 1;
}

Item_FindNearestDrops(playerid)
{
	new count = 0;
	for(new i = 0; i < MAX_INVENTORY_SLOTS; i++) NearestItems[playerid][i] = -1;
	foreach(new i : Drops)
	{
		if(count >= MAX_INVENTORY_SLOTS) break;

		if(!IsPlayerInRangeOfPoint(playerid, 3.5, DropData[i][droppedPos][0], DropData[i][droppedPos][1], DropData[i][droppedPos][2]))
			continue;

		NearestItems[playerid][count] = i;
		count++;
	}
	return 1;
}

Item_Drop(itemid, quantity, Float:x, Float:y, Float:z, world, int, WEAPON:weaponid = WEAPON:0, Float:condition = 0.0, grade = 0, ammo = 0, const serial[] = EOS)
{
	new dropid = Iter_Free(Drops), 
		str[64],
		query[768];

	if(quantity < 1) return 0;

	if(IsValidItem(itemid) == IsValidWeapon(weaponid)) return 0;

	if(dropid <= -1) return 0;

	DropData[dropid][droppedExist] = true;
	if(IsValidItem(itemid) && !IsValidWeapon(weaponid)) // Item
	{
		DropData[dropid][droppedItemID] = itemid;
		DropData[dropid][droppedItemQuantity] = quantity;
		//DropData[dropid][droppedMetaData] =;

		DropData[dropid][droppedWeaponID] = 0;
		DropData[dropid][droppedWeaponCond] = 0.0;
		DropData[dropid][droppedWeaponGrade] = 0;
		DropData[dropid][droppedWeaponAmmo] = 0;
		DropData[dropid][droppedWeaponSerial][0] = EOS;

		DropData[dropid][droppedObject] = CreateDynamicObject(2663, x, y, z, 0.0, 0.0, 0.0, world, int, -1, 100.0, 100.0);

		format(str, sizeof(str), "%s | %dx | %.2f kg", Items[itemid][Name], quantity, (Items[itemid][Weight] * quantity) / 1000.0);
		DropData[dropid][droppedLabel] = CreateDynamic3DTextLabel(str, -1, x, y, z + 0.3, 8.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, world, int, -1, 8.0);
	}
	else if(!IsValidItem(itemid) && IsValidWeapon(weaponid)) // Weapon
	{
		DropData[dropid][droppedItemID] = _:weaponid;
		DropData[dropid][droppedItemQuantity] = 1;

		DropData[dropid][droppedWeaponID] = weaponid;
		DropData[dropid][droppedWeaponCond] = condition;
		DropData[dropid][droppedWeaponGrade] = grade;
		DropData[dropid][droppedWeaponAmmo] = ammo;
		strcopy(DropData[dropid][droppedWeaponSerial], serial, 16);

		DropData[dropid][droppedObject] = CreateDynamicObject(GetWeaponModel(weaponid), x, y, z + 0.3, 0.0, 0.0, 0.0, world, int, -1, 100.0, 100.0);
		if(DestroyDynamic3DTextLabel(DropData[dropid][droppedLabel])) DropData[dropid][droppedLabel] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_STREAMER_ID;
	}
	//strcopy(DropData[dropid][droppedDNA][0], dna, 64);
	DropData[dropid][droppedPos][0] = x;
	DropData[dropid][droppedPos][1] = y;
	DropData[dropid][droppedPos][2] = z;
	DropData[dropid][droppedWorld] = world;
	DropData[dropid][droppedInt] = int;
	DropData[dropid][droppedExpiryTime] = gettime() + 7200; // 2 jam

	Iter_Add(Drops, dropid);

	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `dropped_items` (`dropped_id`, `dropped_item_id`, `dropped_item_quantity`, `dropped_weapon_id`, `dropped_weapon_cond`, `dropped_weapon_grade`, `dropped_weapon_ammo`, `dropped_weapon_serial`, `dropped_pos_x`, `dropped_pos_y`, `dropped_pos_z`, `dropped_world`, `dropped_int`, `dropped_expiry_time`) \
		VALUES (%d, %d, %d, %d, %f, %d, %d, '%e', %f, %f, %f, %d, %d, %d)", 
		dropid, DropData[dropid][droppedItemID], DropData[dropid][droppedItemQuantity], DropData[dropid][droppedWeaponID], DropData[dropid][droppedWeaponCond], DropData[dropid][droppedWeaponGrade], DropData[dropid][droppedWeaponAmmo], DropData[dropid][droppedWeaponSerial], DropData[dropid][droppedPos][0], DropData[dropid][droppedPos][1], DropData[dropid][droppedPos][2], DropData[dropid][droppedWorld], DropData[dropid][droppedInt], DropData[dropid][droppedExpiryTime]);
	mysql_pquery(g_SQL, query);
	return 1;
}

Inventory_DropItem(playerid, slotid, quantity = 1)
{
    if(!InvData[playerid][slotid][invExist])
        return 0; // Drop item gagal dieksekusi

    new
        Float:x,
        Float:y,
        Float:z;

    if(quantity < 1 || > 500) return SendClientMessage(playerid, -1, "Yang bener masukin jumlah itemnya kocak");
    if(Inventory_Remove(playerid, InvData[playerid][slotid][invItemID], quantity, slotid))
    {
        Inventory_RefreshSlot(playerid, slotid);
        GetPlayerPos(playerid, x, y, z);
        Item_Drop(InvData[playerid][slotid][invItemID], quantity, x, y, z - 1.7, pData[playerid][pVirtualWorld], pData[playerid][pInterior]);
    }
    
    return 1;
}

function:LoadDroppedItems(tick)
{
	new dropid,
		str[64],
		rows = cache_num_rows();
	if(rows)
	{
		for(new x = 0; x < rows; x++)
		{
			cache_get_value_name_int(x, "dropped_id", dropid);
			DropData[dropid][droppedExist] = true;

			cache_get_value_name_int(x, "dropped_item_id", DropData[dropid][droppedItemID]);
			cache_get_value_name_int(x, "dropped_item_quantity", DropData[dropid][droppedItemQuantity]);

			cache_get_value_name_int(x, "dropped_weapon_id", DropData[dropid][droppedWeaponID]);
			cache_get_value_name_float(x, "dropped_weapon_cond", DropData[dropid][droppedWeaponCond]);
			cache_get_value_name_int(x, "dropped_weapon_grade", DropData[dropid][droppedWeaponGrade]);
			cache_get_value_name_int(x, "dropped_weapon_ammo", DropData[dropid][droppedWeaponAmmo]);
			cache_get_value_name(x, "dropped_weapon_serial", DropData[dropid][droppedWeaponSerial]);

			cache_get_value_name_float(x, "dropped_pos_x", DropData[dropid][droppedPos][0]);
			cache_get_value_name_float(x, "dropped_pos_y", DropData[dropid][droppedPos][1]);
			cache_get_value_name_float(x, "dropped_pos_z", DropData[dropid][droppedPos][2]);

			cache_get_value_name_int(x, "dropped_world", DropData[dropid][droppedWorld]);
			cache_get_value_name_int(x, "dropped_int", DropData[dropid][droppedInt]);
			
			cache_get_value_name_int(x, "dropped_expiry_time", DropData[dropid][droppedExpiryTime]);
			
			if(DropData[dropid][droppedItemID] == DropData[dropid][droppedWeaponID])
			{
				DropData[dropid][droppedObject] = CreateDynamicObject(GetWeaponModel(WEAPON:DropData[dropid][droppedWeaponID]), DropData[dropid][droppedPos][0], DropData[dropid][droppedPos][1], DropData[dropid][droppedPos][2], 0.0, 0.0, 0.0, DropData[dropid][droppedWorld], DropData[dropid][droppedInt], -1, 100.0, 100.0);
				if(DestroyDynamic3DTextLabel(DropData[dropid][droppedLabel])) DropData[dropid][droppedLabel] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_STREAMER_ID;
			}
			else if(DropData[dropid][droppedItemID] != DropData[dropid][droppedWeaponID] && DropData[dropid][droppedWeaponID] == 0)
			{
				DropData[dropid][droppedObject] = CreateDynamicObject(2663, DropData[dropid][droppedPos][0], DropData[dropid][droppedPos][1], DropData[dropid][droppedPos][2], 0.0, 0.0, 0.0, DropData[dropid][droppedWorld], DropData[dropid][droppedInt], -1, 100.0, 100.0);
				format(str, sizeof(str), "%s | %dx | %s kg", Items[DropData[dropid][droppedItemID]][Name], DropData[dropid][droppedItemQuantity], (Items[DropData[dropid][droppedItemID]][Weight] * DropData[dropid][droppedItemQuantity]) / 1000.0);
				DropData[dropid][droppedLabel] = CreateDynamic3DTextLabel(str, -1, DropData[dropid][droppedPos][0], DropData[dropid][droppedPos][1], DropData[dropid][droppedPos][2], 8.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, DropData[dropid][droppedWorld], DropData[dropid][droppedInt], -1, 8.0);
			}

			Iter_Add(Drops, dropid);
		}
		printf("[MySQL] Loaded %d rows from `dropped_items` in %d ms.", rows, GetTickCount() - tick);
	}
}