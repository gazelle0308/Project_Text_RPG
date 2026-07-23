#include "../include/Monster/Orc.h"

Orc::Orc(std::string name, std::string ItemName, int hp, int power, int defence, int ItemPrice, std::string skill, int expReward)
:Monster(name, hp, power, defence, skill, expReward)
{ 

    this->DropItemName = ItemName;
    this->DropItemPrice = ItemPrice;

}

void Orc::Buff()
{
    std::cout << "Orc's War Cry!" << std::endl;
    std::cout << "Orc's power and defense increased!" << std::endl;
    this->power += 1;
    this->defence += 1;
}