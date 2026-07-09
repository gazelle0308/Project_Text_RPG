#include "Thief.h"

Thief::Thief(string name, int hp, int mp, int power, int defence, int level)
:Player(name, hp, mp, power, defence, level)
{
    this->job = "Thief";
    this->power = power + 30;
    this->printStatus();

}

void Thief::attack(){ cout << "Thief" << name << "'s Dagger Throw!" << endl; }

