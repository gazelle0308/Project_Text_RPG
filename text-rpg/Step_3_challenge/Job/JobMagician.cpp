#include "../include/Job/JobMagician.h"

#include "../include/Ui/Ui.h"

Magician::Magician( std::string name, int hp, int mp, int power, int defence, int level, std::string skill)
:Player(name, hp, mp, power, defence, level, skill)
{ 
    
    this->job = "Magician"; 
    this->mp = mp + 30;

}

void Magician::attack( Monster* monster )
{
    
    int InsertDmg = this->power - monster->GetDefence();
    int DamageView = (this->power - monster->GetDefence()) <= 0 ? 1 : (this->power - monster->GetDefence());

    monster->SetHp( InsertDmg <= 0 ? monster->GetHp() - 1 : monster->GetHp() - InsertDmg ); 
    std::cout << this->GetName() << "'s attack: " << DamageView << "(basic:" << this->GetPower() <<")" << std::endl;
    std::cout << "Magician " << name << "'s Fireball!" << std::endl; 

}