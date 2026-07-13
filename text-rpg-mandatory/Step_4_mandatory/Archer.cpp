#include "Archer.h"

Archer::Archer(string name, int hp, int mp, int power, int defence, int level)
:Player(name, hp, mp, power, defence, level)
{ 

    this->job = "Archer"; 
    this->hp = hp + 30;
    this->printStatus();
    
}

void Archer::attack( Monster* monster )
{

    int InsertDmg = monster->GetHp() - ( monster->GetDefence() - this->power );

    monster->SetHp( InsertDmg <= 0 ? 1 : InsertDmg ); 
    cout << "Archer" << name << "'s Shoot!" << endl;

}

