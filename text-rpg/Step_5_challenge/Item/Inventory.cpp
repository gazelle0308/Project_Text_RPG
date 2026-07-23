#include "../include/Item/Inventory.h"

/*-------------------------Inventory-----------------------------*/

std::string ItemInfo(const Inventory<Item>& inventory)
{
    std::ostringstream oss;
    int itemNum = 1;

    for( int loop = 0; loop < inventory.GetSize(); ++loop)
    {
        
        oss << itemNum << "." << inventory[loop].GetName() << "(" << inventory[loop].GetPrice() << "G) x" << inventory[loop].GetCount() << std::endl;
        itemNum = itemNum + 1;

    }

    return oss.str();

}


bool reserchUse(const Inventory<Item>& inventory, int itemNumber)
{

    if ((itemNumber - 1) < 0 || (itemNumber - 1) >= inventory.GetSize()){ std::cout << "Out of Inventory range!" << std::endl; return false; }
    //return Inventory[itemNumber - 1].CanUse();
    return true;

}


void InsertInventory(const Item& item, Inventory<Item>& inventory){

    for(int loop = 0; loop < inventory.GetSize(); loop = loop + 1)
    {
        if(inventory[loop].GetName() == item.GetName()){ inventory[loop].SetCount(inventory[loop].GetCount() + 1); return; }
    }
    inventory.AddItem(item);
}



void DeleteInventory(const Item* item, Inventory<Item>& inventory){

    for(int loop = inventory.GetSize(); loop >= 0;)
    {

        --loop;

        if( inventory[loop].GetName() == item->GetName() )
        {

            inventory.EraseItem(loop);
            break;

        }

    }

}



Item BuildItem(const std::string name, const int price, const int count)
{

    Item item_data(name, price, count);
    return item_data;

}