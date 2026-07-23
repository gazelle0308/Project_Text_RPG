#include "../include/Job/JobArcher.h"

Archer::Archer(std::string name, int hp, int mp, int power, int defence, int level, std::string skill)
:Player(name, hp, mp, power, defence, level, skill)
{ 

    this->job = "Archer"; 
    this->hp = hp + 30;
    
}
