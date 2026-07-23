#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "Item.h"

/*-------------------------Inventory-----------------------------*/

void InsertInventory(const Item& item, std::vector<Item>& Inventory);
void DeleteInventory(const Item* item, std::vector<Item>& Inventory);
Item BuildItem(const std::string name, const int price, const int count = 1);