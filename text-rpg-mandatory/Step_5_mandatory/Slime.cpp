#include "Slime.h"

Slime::Slime( string name, string ItemName, int hp, int power, int defence, int ItemPrice)
:Monster(name, hp, power, defence)
{ 

    this->DropItemName = ItemName;
    this->DropItemPrice = ItemPrice;

}

void Slime::attack( Player* player )
{

    int InsertDmg = player->GetHp() - ( player->GetDefence() - this->power );

    cout<<"Slime's Jump acttack!"<<endl;
    player->SetHp( InsertDmg <= 0 ? 1 : InsertDmg ); 

}

void Slime::Buff()
{

    cout<<"Slime's Jump!"<<endl;
    cout<<"(No Effect)"<<endl;

}