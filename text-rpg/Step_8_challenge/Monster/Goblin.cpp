#include "../include/Monster/Goblin.h"

Goblin::Goblin(std::string name, std::string ItemName, int hp, int power, int defence, int ItemPrice, std::string skill, int expReward)
:Monster(name, hp, power, defence, skill, expReward)
{ 

    this->DropItemName = ItemName;
    this->DropItemPrice = ItemPrice;

}

void Goblin::Buff()
{
    std::cout << "Goblin performed a strange dance!" << std::endl;
    std::cout << "Goblin's HP and power increased!" << std::endl;
    this->hp += 5;
    this->power += 1;
}