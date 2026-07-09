#include "Warrior.h"

Warrior::Warrior(string name, int hp, int mp, int power, int defence, int level)
:Player(name, hp, mp, power, defence, level)
{ 
    this->job = "Warrior"; 
    this->defence = defence + 30;
    this->printStatus();
}

void Warrior::attack(){ cout << "Warrior" << name << "'s Slash!" << endl; }

