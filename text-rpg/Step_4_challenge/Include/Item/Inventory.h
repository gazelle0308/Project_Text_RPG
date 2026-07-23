#pragma once

#include <sstream>

#include "../Common.h"
#include "../Constants.h"

#include "Item.h"

/*-------------------------Inventory-----------------------------*/

std::string ItemInfo(const std::vector<Item>& Inventory);
bool reserchUse(const std::vector<Item>& Inventory, int itemNumber);
void InsertInventory(const Item& item, std::vector<Item>& Inventory);
void DeleteInventory(const Item* item, std::vector<Item>& Inventory);
Item BuildItem(const std::string name, const int price, const int count = 1);