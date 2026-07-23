#include "../include/Item/Inventory.h"

/*-------------------------Inventory-----------------------------*/

std::string ItemInfo(const std::vector<Item>& Inventory)
{
    std::ostringstream oss;
    int itemNum = 1;

    for( auto loop = Inventory.begin(); loop != Inventory.end(); ++loop)
    {
        
        oss << itemNum << "." << loop->GetName() << "(" << loop->GetPrice() << "G) x" << loop->GetCount() << std::endl;
        itemNum = itemNum + 1;

    }

    return oss.str();

}


bool reserchUse(const std::vector<Item>& Inventory, int itemNumber)
{

    if (itemNumber <= 0 || itemNumber >= Inventory.size()){ std::cout << "Out of Inventory range!" << std::endl; return false; }
    //return Inventory[itemNumber - 1].CanUse();
    return true;

}


void InsertInventory(const Item& item, std::vector<Item>& Inventory){

    for( auto loop = Inventory.begin(); loop != Inventory.end(); loop = loop + 1)
    {
        if(loop->GetName() == item.GetName()){ loop->SetCount(loop->GetCount() + 1); return; }
    }
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