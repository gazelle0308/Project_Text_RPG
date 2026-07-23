#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "MonsterBone.h"

class Goblin : public Monster
{

public:

    Goblin(std::string name = "Goblin", std::string ItemName = "Goblin's Ears", int hp = 400, int power = 30, int defence = 15, int ItemPrice = 50, std::string skill = "Swing club!", int expReward = 50);

    void Buff();

};
