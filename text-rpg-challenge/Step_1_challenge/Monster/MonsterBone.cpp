#include "../include/Monster/MonsterBone.h"

Monster::Monster::Monster(std::string name, int hp, int power, int defence, std::string skill): name(name), hp(hp), power(power), defence(defence), skill(skill){}

//Getter
int Monster::GetHp() const{ return this->hp; } 
int Monster::GetPower() const{ return this->power; }
int Monster::GetDefence() const{ return this->defence; }
int Monster::GetDropItemPrice() const{ return this->DropItemPrice; }

std::string Monster::GetName() const{ return this->name; }
std::string Monster::GetDropItemName() const{ return this->DropItemName; }

std::string Monster::GetSkill() const{ return this->skill; }


//Setter
void Monster::SetHp(int hp){ this->hp = hp; }
void Monster::SetPower(int power){ this->power = power; }
void Monster::SetDefence(int defence){ this->defence = defence; }
void Monster::SetDropItemPrice(int price){ this->DropItemPrice = price; }

void Monster::SetName(std::string name){ this->name = name; }
void Monster::SetDropItemName(std::string item){ this->DropItemName = item; }

void Monster::SetSkill(std::string skill){ this->skill = skill; }

