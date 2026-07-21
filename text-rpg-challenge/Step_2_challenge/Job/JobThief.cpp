#include "../include/Job/JobThief.h"

Thief::Thief(std::string name, int hp, int mp, int power, int defence, int level, std::string skill)
:Player(name, hp, mp, power, defence, level, skill)
{
    this->job = "Thief";
    this->power = power + 30;

}
