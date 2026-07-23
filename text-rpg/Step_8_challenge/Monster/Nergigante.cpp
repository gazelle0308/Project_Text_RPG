#include "../include/Monster/Nergigante.h"

#include "../include/Player/PlayerStatus.h"

Nergigante::Nergigante(std::string name, std::string ItemName, int hp, int power, int defence, int ItemPrice, std::string skill, int expReward)
:Monster(name, hp, power, defence, skill, expReward)
{ 

    this->DropItemName = ItemName;
    this->DropItemPrice = ItemPrice;

}

void Nergigante::Buff()
{
    std::cout << "Nergigante regenerated its spikes!" << std::endl;
    std::cout << "Attack increased!" << std::endl;
    std::cout << "Its newly grown spikes are still soft." << std::endl;
    std::cout << "Defense decreased!" << std::endl;
    this->buffStack += 1;
    this->power += 5;
    this->defence -= 2;
}


bool Nergigante::Ultimate(Player& player)
{
    int Damage = this->GetPower() * 2 - player.GetDefence();
    
    int DamageCalc = Damage <= 0 ? player.GetHp() - 1 : player.GetHp() - Damage;

    if(this->buffStack < 6){ return true; }
    std::cout << this->GetJob() << " " << this->GetName() << "'s Heaven's Ruin!" << std::endl; 
    std::cout << this->GetName() << "'s attack: " << DamageCalc << "(basic:" << this->GetPower() * 2 <<")" << std::endl;
    player.SetHp(DamageCalc); 

    this->defence += 12;
    this->power -= 30;
    this->buffStack = 0;
    return false;
}