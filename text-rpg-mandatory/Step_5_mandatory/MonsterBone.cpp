#include "MonsterBone.h"

Monster::Monster(string name, int hp, int power, int defence){}

//Getter
string Monster::GetName(){ return this->name; }
string Monster::GetDropItemName(){ return this->DropItemName; }

int Monster::GetHp(){ return this->hp; }
int Monster::GetPower(){ return this->power; }
int Monster::GetDefence(){ return this->defence; }
int Monster::GetDropItemPrice(){ return this->DropItemPrice; }

//Setter
void Monster::SetName(string name){ this->name = name; }
void Monster::SetDropItemName(string item){ this->DropItemName = item; }

void Monster::SetHp(int hp){ this->hp = hp; }
void Monster::SetPower(int power){ this->power = power; }
void Monster::SetDefence(int defence){ this->defence = defence; }
void Monster::SetDropItemPrice(int price){ this->DropItemPrice = price; }