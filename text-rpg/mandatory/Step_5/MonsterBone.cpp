#include "MonsterBone.h"
#include "../Step_4_mandatory/Player.h"

Monster::Monster::Monster(string name, int hp, int power, int defence): name(name), hp(hp), power(power), defence(defence){}

//Getter
string Monster::GetName() const{ return this->name; }
string Monster::GetDropItemName() const{ return this->DropItemName; }

int Monster::GetHp() const{ return this->hp; } 
int Monster::GetPower() const{ return this->power; }
int Monster::GetDefence() const{ return this->defence; }
int Monster::GetDropItemPrice() const{ return this->DropItemPrice; }

//Setter
void Monster::SetName(string name){ this->name = name; }
void Monster::SetDropItemName(string item){ this->DropItemName = item; }

void Monster::SetHp(int hp){ this->hp = hp; }
void Monster::SetPower(int power){ this->power = power; }
void Monster::SetDefence(int defence){ this->defence = defence; }
void Monster::SetDropItemPrice(int price){ this->DropItemPrice = price; }