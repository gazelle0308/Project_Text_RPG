#include "../include/Item/Item.h"


/*-------------------------Item-----------------------------*/

Item::Item(std::string name, int price, int count, bool canSell)
:name(name), price(price), count(count), canSell(canSell){}

//Setter
void Item::SetCanSell(bool canSell){ this->canSell = canSell; }

void Item::SetCount(int count){ this->count = count; }
void Item::SetPrice(int price){ this->price = price; }

void Item::SetName(std::string name){ this->name = name; }


//Getter
bool Item::GetCanSell() const{ return this->canSell; }

int Item::GetCount() const{ return this->count; }
int Item::GetPrice() const{ return this->price; }

std::string Item::GetName() const{ return this->name; }