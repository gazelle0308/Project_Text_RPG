#include "../include/Job/JobArcher.h"

#include "../include/Ui/Ui.h"

Archer::Archer(std::string name, int hp, int mp, int power, int defence, int level, std::string skill)
:Player(name, hp, mp, power, defence, level, skill)
{ 

    this->job = "Archer"; 
    this->hp = hp + 30;
    
}

void Archer::attack( Monster* monster )
{

    int InsertDmg = (this->power - monster->GetDefence()) / 3;
    int DamageView = (this->power - monster->GetDefence()) / 3 <= 0 ? 1 : (this->power - monster->GetDefence()) / 3;

    for(int loop = 0; loop < 3; loop = loop + 1)
    { 
        monster->SetHp( InsertDmg <= 0 ? monster->GetHp() - 1 : monster->GetHp() - InsertDmg ); 
        std::cout << this->GetName() << "'s attack: " << DamageView << "(basic:" << this->GetPower() / 3 <<")" << std::endl;
    }
    std::cout << "Archer " << name << "'s Triple Shoot!" << std::endl;

}
