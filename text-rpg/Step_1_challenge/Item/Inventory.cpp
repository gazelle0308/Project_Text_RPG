#include "../include/Item/Inventory.h"

/*-------------------------Inventory-----------------------------*/

void InsertInventory(const Item& item, std::vector<Item>& Inventory){

    Inventory.push_back(item);

}


void DeleteInventory(const Item* item, std::vector<Item>& Inventory){

    for( auto loop = Inventory.end(); loop != Inventory.begin();)
    {

        --loop;

        if( loop->GetName() == item->GetName() )
        {

            Inventory.erase(loop);
            break;

        }

    }

}

Item BuildItem(const std::string name, const int price, const int count)
{

    Item item_data(name, price, count);
    return item_data;

}