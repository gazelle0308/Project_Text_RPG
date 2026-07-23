#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "MonsterBone.h"

class Kobold : public Monster
{

public:

    Kobold(std::string name = "Kobold", std::string ItemName = "Kobold's Fang", int hp = 350, int power = 45, int defence = 20, int ItemPrice = 60, std::string skill = "Throw Stone!", int expReward = 50);

    void Buff();

};
