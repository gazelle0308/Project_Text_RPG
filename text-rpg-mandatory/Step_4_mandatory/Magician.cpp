#include "Magician.h"

Magician::Magician(string name, int level, int hp, int mp, int power, int defence)
:Player(name, level, hp, mp, power, defence)
{ 
    
    this->job = "Magician"; 
    this->mp = mp + 30;
    this->printStatus();

}

void Magician::attack( Monster* monster )
{
    
    int InsertDmg = monster->GetHp() - ( monster->GetDefence() - this->power );

    monster->SetHp( InsertDmg <= 0 ? 1 : InsertDmg ); 
    cout << "Magician" << name << "'s Fireball!" << endl; 

}
