#include "../include/Monster/Velkhana.h"

#include "../include/Player/PlayerStatus.h"

Velkhana::Velkhana(std::string name, std::string ItemName, int hp, int power, int defence, int ItemPrice, std::string skill, int expReward)
:Monster(name, hp, power, defence, skill, expReward)
{ 

    this->DropItemName = ItemName;
    this->DropItemPrice = ItemPrice;

}

void Velkhana::Buff()
{
    std::cout << "Velkhana covered itself in fresh ice!" << std::endl;
    std::cout << "Attack increased!" << std::endl;
    std::cout << "The thin ice is easy to shatter." << std::endl;
    std::cout << "Defense decreased!" << std::endl;
    this->buffStack += 1;
    this->power += 5;
    this->defence -= 2;
}

bool Velkhana::Ultimate(Player& player)
{
    int Damage = this->GetPower() * 2 - player.GetDefence();
    
    int DamageCalc = Damage <= 0 ? player.GetHp() - 1 : player.GetHp() - Damage;

    if(this->buffStack < 6){ return true; }
    std::cout << this->GetJob() << " " << this->GetName() << "'s Absolute Zero!" << std::endl; 
    std::cout << this->GetName() << "'s attack: " << DamageCalc << "(basic:" << this->GetPower() * 2 <<")" << std::endl;
    player.SetHp(DamageCalc); 

    this->defence += 12;
    this->power -= 30;
    this->buffStack = 0;
    return false;

}