#include "Mushroom.h"

Mushroom::Mushroom( string name, string ItemName, int hp, int power, int defence, int ItemPrice)
:Monster(name, hp, power, defence)
{ 

    this->DropItemName = ItemName;
    this->DropItemPrice = ItemPrice;

}

void Mushroom::attack( Player* player )
{

    int InsertDmg = player->GetHp() - ( player->GetDefence() - this->power );

    cout<<"Mushroom's Jump acttack!"<<endl;
    player->SetHp( InsertDmg <= 0 ? 1 : InsertDmg ); 

}

void Mushroom::Buff()
{

    cout<<"Mushroom's Spread Spore!"<<endl;
    cout<<"Mushroom's defence increased!"<<endl;
    this->defence += 2;

}