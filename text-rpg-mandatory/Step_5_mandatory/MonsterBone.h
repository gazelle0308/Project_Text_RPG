#pragma once

#include <iostream>
#include <string>

using namespace std;

class Player;

class Monster
{
public:

//virtual
    virtual void attack(Player* player) = 0;
    virtual void Buff() = 0;
    virtual ~Monster() = default;

//Getter
    string GetName() const;
    string GetDropItemName() const;

    int GetHp() const;
    int GetPower() const;
    int GetDefence() const;
    int GetDropItemPrice() const;

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