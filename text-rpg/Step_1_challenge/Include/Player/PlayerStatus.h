#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "../Item/Inventory.h"

class Player
{

public:

//virtual
    virtual ~Player() = default;

//Getter
    int GetLevel() const;

    int GetHp() const;
    int GetMp() const;
    int GetPower() const;
    int GetDefence() const;

    std::string GetName() const;
    std::string GetJob() const;

    std::string GetSkill() const;

//Setter
    void SetLevel(int level);

    void SetHp(int hp);
    void SetMp(int mp);
    void SetPower(int power);
    void SetDefence(int defence);

    void SetName(std::string name);
    void SetJob(std::string job);
    
    void SetSkill(std::string job);

protected:  

    Player(std::string name, int level = 1, int hp = 50, int mp = 50, int power = 20, int defence = 20, std::string skill = "Punch!");

    int level;

    int hp;
    int mp;
    int power;
    int defence;

    std::string name;
    std::string job;

    std::string skill;

};


void SetupStatus(std::string& Name, int Status[]);

void CheckStatus(int Status[]);

bool UpgradeStatus(Player& player, std::vector<Item>& item);

bool IsOutRange(int value, int min = 0, int max = 100);