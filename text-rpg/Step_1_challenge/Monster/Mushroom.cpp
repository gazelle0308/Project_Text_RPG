#include "../include/Monster/Mushroom.h"

Mushroom::Mushroom(std::string name, std::string ItemName, int hp, int power, int defence, int ItemPrice, std::string skill)
:Monster(name, hp, power, defence, skill)
{ 

    this->DropItemName = ItemName;
    this->DropItemPrice = ItemPrice;

}

void Mushroom::Buff()
{

    std::cout<<"Mushroom's Spread Spore!"<<std::endl;
    std::cout<<"Mushroom's defence increased!"<<std::endl;
    this->defence += 2;

}