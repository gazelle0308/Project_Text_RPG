#include "../include/Monster/Kobold.h"

Kobold::Kobold(std::string name, std::string ItemName, int hp, int power, int defence, int ItemPrice, std::string skill, int expReward)
:Monster(name, hp, power, defence, skill, expReward)
{ 

    this->DropItemName = ItemName;
    this->DropItemPrice = ItemPrice;

}

void Kobold::Buff()
{
    std::cout << "Kobold rolled around in the mud!" << std::endl;
    std::cout << "Kobold's HP and defense increased!" << std::endl;
    this->hp += 5;
    this->defence += 1;
}