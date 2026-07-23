#include "Inventory.h"

void InsertInventory(const Item& item, vector<Item>& Inventory){

    Inventory.push_back(item);

}

void deleteInventory(const Item* item, vector<Item>& Inventory){

    for( auto loop = Inventory.end(); loop != Inventory.begin();)
    {

        --loop;

        if( loop->name == item->name )
        {

            Inventory.erase(loop);
            break;

        }

    }

}

Item BuildItem( const string name, const int price )
{

    Item item_data;

    item_data.name = name;
    item_data.price = price;

    return item_data;

}