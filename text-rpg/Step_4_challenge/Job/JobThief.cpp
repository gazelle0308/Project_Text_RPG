#include "../include/Job/JobThief.h"

#include "../include/Ui/Ui.h"

Thief::Thief(std::string name, int hp, int mp, int power, int defence, int level, std::string skill)
:Player(name, hp, mp, power, defence, level, skill)
{
    this->job = "Thief";
    this->power = power + 30;

}

void Thief::attack( Monster* monster )
{
    
    int InsertDmg = (this->power - monster->GetDefence()) / 5;
    int DamageView = (this->power - monster->GetDefence()) / 5 <= 0 ? 1 : (this->power - monster->GetDefence()) / 5;

    for(int loop = 0; loop < 5; loop = loop + 1)
    {
        monster->SetHp( InsertDmg <= 0 ? monster->GetHp() - 1 : monster->GetHp() - InsertDmg );
        std::cout << this->GetName() << "'s attack: " << DamageView << "(basic:" << this->GetPower() / 5 <<")" << std::endl;
    }
    std::cout << "Thief " << name << "'s Rapid Dagger Throw!" << std::endl; 

}
