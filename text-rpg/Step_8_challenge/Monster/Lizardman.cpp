#include "../include/Monster/Lizardman.h"

Lizardman::Lizardman(std::string name, std::string ItemName, int hp, int power, int defence, int ItemPrice, std::string skill, int expReward)
:Monster(name, hp, power, defence, skill, expReward)
{ 

    this->DropItemName = ItemName;
    this->DropItemPrice = ItemPrice;

}

void Lizardman::Buff()
{
    std::cout << "Lizardman performed a Blood Ritual!" << std::endl;
    std::cout << "Lizardman sacrificed HP for power!" << std::endl;
    this->hp -= 15;
    this->power += 5;
}