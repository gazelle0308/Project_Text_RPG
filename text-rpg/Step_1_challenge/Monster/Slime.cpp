#include "../include/Monster/Slime.h"

Slime::Slime(std::string name, std::string ItemName, int hp, int power, int defence, int ItemPrice, std::string skill)
:Monster(name, hp, power, defence, skill)
{ 

    this->DropItemName = ItemName;
    this->DropItemPrice = ItemPrice;

}

void Slime::Buff()
{

    std::cout<<"Slime's Jump!"<<std::endl;
    std::cout<<"(No Effect)"<<std::endl;

}