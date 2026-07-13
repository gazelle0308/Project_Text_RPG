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
    
    int InsertDmg = this->power - monster->GetDefence();

    monster->SetHp( InsertDmg <= 0 ? monster->GetHp() - 1 : monster->GetHp() - InsertDmg ); 
    cout << "Magician " << name << "'s Fireball!" << endl; 

}
