#pragma once

#include "../Common.h"
#include "../Constants.h"

class Monster
{
public:

//virtual
    virtual void Buff() = 0;
    virtual ~Monster() = default;
    virtual std::string Monster::GetJob() const{ return "Monster"; }

//Getter
    int GetHp() const;
    int GetPower() const;
    int GetDefence() const;
    int GetDropItemPrice() const;

    std::string GetName() const;
    std::string GetDropItemName() const;

    std::string GetSkill() const;

//Setter
    void SetHp(int hp);
    void SetPower(int power);
    void SetDefence(int defence);
    void SetDropItemPrice(int price);

    void SetName(std::string name);
    void SetDropItemName(std::string item);
   
    void SetSkill(std::string job);

protected:

    Monster(std::string name, int hp, int power, int defence, std::string skill = "Tackle!");
    
    int hp;
    int power;
    int defence;
    int DropItemPrice;

    std::string name;
    std::string DropItemName;

    std::string skill;

};