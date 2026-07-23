#include "../include/Item/Potion.h"

/*-------------------------Potion-----------------------------*/

Potion::Potion(std::string name, int price, int count, bool canSell)
:Item(name, price, count, canSell){}

void Potion::potionUse()
{

    this->Used = true;

}