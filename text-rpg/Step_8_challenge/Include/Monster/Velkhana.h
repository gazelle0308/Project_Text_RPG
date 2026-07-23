#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "MonsterBone.h"

class Player;

class Velkhana : public Monster
{
private:

    int buffStack;

public:

    Velkhana(std::string name = "Velkhana", std::string ItemName = "Velkhana's Ice Tail", int hp = 450, int power = 75, int defence = 45, int ItemPrice = 150, std::string skill = "Dropping Icicles!", int expReward = 100);

    void Buff();
    bool Ultimate(Player& player);

};
