#include "Thief.h"

Thief::Thief(string name, int hp, int mp, int power, int defence, int level)
:Player(name, hp, mp, power, defence, level)
{
    this->job = "Thief";
    this->power = power + 30;
    this->printStatus();

}

void Thief::attack( Monster* monster )
{
    
    int InsertDmg = monster->GetHp() - ( monster->GetDefence() - this->power );

    monster->SetHp( InsertDmg <= 0 ? 1 : InsertDmg ); 
    cout << "Thief" << name << "'s Dagger Throw!" << endl; 

}

