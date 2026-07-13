#pragma once

#include "../Step_4_mandatory/Player.h"

#include <iostream>
#include <string>

using namespace std;

class Monster
{
public:

//virtual
    virtual void attack( Player* player ) = 0;
    virtual void Buff() = 0;
    virtual ~Monster();

//Getter
    string GetName();
    string GetDropItemName();

    int GetHp();
    int GetPower();
    int GetDefence();
    int GetDropItemPrice();

//Setter
    void SetName(string name);
    void SetDropItemName(string item);
    
    void SetHp(int hp);
    void SetPower(int power);
    void SetDefence(int defence);
    void SetDropItemPrice(int price);

protected:

    Monster(string name, int hp, int power, int defence);
    
    string name;
    string DropItemName;

    int hp;
    int power;
    int defence;
    int DropItemPrice;

};