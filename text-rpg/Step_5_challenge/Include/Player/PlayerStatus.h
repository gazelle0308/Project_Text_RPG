#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "../Item/Inventory.h"

class Monster;

class Player
{

public:

//virtual
    virtual void attack(Monster* monster) = 0;
    virtual ~Player() = default;

//Getter
    int GetLevel() const;
    int GetExp() const;
    int GetMaxExp() const;

    int GetHp() const;
    int GetMp() const;
    int GetMaxHp() const;
    int GetMaxMp() const;
    int GetPower() const;
    int GetDefence() const;

    std::string GetName() const;
    std::string GetJob() const;

    std::string GetSkill() const;
    
    void GetGroupStatus(int (&status)[4]);

//Setter
    void SetLevel(int level);
    void SetExp(int exp);
    void SetMaxExp(int maxExp);


    void SetHp(int hp);
    void SetMp(int mp);
    void SetMaxHp(int maxHp);
    void SetMaxMp(int maxMp);
    void SetPower(int power);
    void SetDefence(int defence);

    void SetName(std::string name);
    void SetJob(std::string job);
    
    void SetSkill(std::string job);

//Function
    void LevelUpPlayer();
    void HuntRewardExp(int exp);

protected:  

    Player(std::string name, int level = 1, int hp = 50, int mp = 50, int power = 20, int defence = 20, std::string skill = "Punch!");

    int level;
    int exp;
    int maxExp;


    int hp;
    int mp;
    int maxHp;
    int maxMp;
    int power;
    int defence;

    std::string name;
    std::string job;

    std::string skill;

};


void SetupStatus(std::string& Name, int Status[]);

void CheckStatus(int Status[]);

bool UpgradeStatus(Player& player, Inventory<Item>& item);

bool IsOutRange(int value, int min = 0, int max = 100);