#include "../include/Job/JobWarrior.h"

#include "../include/Ui/Ui.h"

Warrior::Warrior(std::string name, int hp, int mp, int power, int defence, int level, std::string skill)
:Player(name, hp, mp, power, defence, level, skill)
{ 
    this->job = "Warrior"; 
    this->defence = defence + 30;
}

void Warrior::attack( Monster* monster )
{ 
    
    int InsertDmg = this->power - monster->GetDefence();
    int DamageView = (this->power - monster->GetDefence()) / 5 <= 0 ? 1 : (this->power - monster->GetDefence()) / 5;

    monster->SetHp( InsertDmg <= 0 ? monster->GetHp() - 1 : monster->GetHp() - InsertDmg ); 
    std::cout << this->GetName() << "'s attack: " << DamageView << "(basic:" << this->GetPower() <<")" << std::endl;
    std::cout << "Warrior " << name << "'s Slash!" << std::endl; 
}
