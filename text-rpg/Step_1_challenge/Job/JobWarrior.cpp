#include "../include/Job/JobWarrior.h"

Warrior::Warrior(std::string name, int hp, int mp, int power, int defence, int level, std::string skill)
:Player(name, hp, mp, power, defence, level, skill)
{ 
    this->job = "Warrior"; 
    this->defence = defence + 30;
}

