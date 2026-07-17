# 📦 INVENTORY SYSTEM FUNCTION LIST

---

# 🔧 CORE (wajib ada — dasar sistem inventory)

Inventory_Add(playerid, itemid, quantity = 1)
- untuk menambahkan item ke inventory pemain
- otomatis mencari slot kosong atau stackable slot
- jika inventory penuh → return 0
- jika berhasil → return 1

Inventory_Remove(playerid, slot, quantity = 1)
- mengurangi item pada slot tertentu
- jika quantity habis → slot dikosongkan
- return 1 jika berhasil, 0 jika gagal

Inventory_Clear(playerid)
- menghapus semua item player
- biasanya dipakai saat logout / reset data

Inventory_GetFreeSlot(playerid)
- mencari slot kosong pertama
- return slot index
- return -1 jika penuh

Inventory_GetItemID(playerid, slot)
- mengambil item ID di slot tertentu
- return itemid atau 0 jika kosong

Inventory_GetItemName(itemid, dest[], len)
- mengambil nama item dari ID
- untuk UI / chat / tooltip

---

# 📊 SLOT & DATA ACCESS (akses data mentah inventory)

Inventory_GetItemAtSlot(playerid, slot)
- mengambil seluruh data item di slot (id, qty, metadata jika ada)
- dipakai untuk UI dan logic internal

Inventory_SetItemAtSlot(playerid, slot, itemid, quantity)
- set langsung isi slot
- override isi lama tanpa check

Inventory_IsSlotEmpty(playerid, slot)
- mengecek apakah slot kosong
- return 1 jika kosong, 0 jika terisi

Inventory_GetItemAmount(playerid, slot)
- mengambil jumlah item di slot
- untuk item stackable

---

# 🔄 STACKING SYSTEM (penting untuk item stack seperti ammo, consumable)

Inventory_CanStack(itemid)
- mengecek apakah item bisa di-stack
- return 1 jika bisa, 0 jika tidak

Inventory_FindStackableSlot(playerid, itemid)
- mencari slot yang sudah ada item sama dan masih bisa ditambah
- return slot atau -1 jika tidak ada

Inventory_AddStack(playerid, itemid, amount)
- menambahkan item dengan sistem stack
- otomatis gabungkan ke slot existing jika ada
- fallback ke slot kosong jika perlu

---

# 🔍 QUERY & SEARCH (dipakai sistem lain seperti shop, crafting, quest)

Inventory_HasItem(playerid, itemid, amount = 1)
- mengecek apakah player punya item cukup
- return 1 jika cukup, 0 jika tidak

Inventory_GetItemCount(playerid, itemid)
- menghitung total item dari semua slot
- penting untuk crafting / requirement system

Inventory_FindItemSlot(playerid, itemid)
- mencari slot pertama yang berisi item tertentu
- return slot atau -1

---

# 🔁 MOVE / SWAP SYSTEM (UI modern / drag & drop)

Inventory_MoveItem(playerid, fromSlot, toSlot)
- memindahkan item dari satu slot ke slot lain
- handle overwrite jika perlu

Inventory_SwapSlot(playerid, slotA, slotB)
- menukar isi dua slot
- dipakai untuk drag & drop UI

---

# ⚙️ VALIDATION & RULE SYSTEM (anti bug & exploit)

Inventory_IsValidSlot(slot)
- memastikan slot dalam range valid
- return 1 jika valid, 0 jika tidak

Inventory_CanCarry(playerid, itemid, quantity)
- mengecek apakah player masih bisa membawa item
- berdasarkan slot limit atau weight system

Inventory_GetUsedSlots(playerid)
- menghitung slot yang terisi
- untuk UI capacity (contoh: 12/20)

---

# 💾 DATABASE LAYER (MySQL / persistence)

Inventory_Save(playerid)
- menyimpan seluruh inventory ke database
- biasanya saat logout / periodic save

Inventory_Load(playerid)
- load inventory dari database saat login

Inventory_UpdateSlot(playerid, slot)
- update hanya 1 slot ke database
- lebih efisien dari full save

---

# 🔧 ADVANCED SYSTEM (fitur inventory modern)

Inventory_Sort(playerid)
- merapikan inventory (mengisi slot kosong ke depan)
- membuat UI lebih clean

Inventory_UseItem(playerid, slot)
- handler utama penggunaan item
- semua efek item dipusatkan di sini

Inventory_DropItem(playerid, slot, quantity = 1)
- membuang item ke dunia
- biasanya spawn pickup object

Inventory_TransferItem(playerid, targetid, slot, quantity)
- memberikan item ke player lain
- digunakan untuk trade / give system

---