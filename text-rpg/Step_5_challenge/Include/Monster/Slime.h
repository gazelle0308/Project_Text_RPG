#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "MonsterBone.h"

class Slime : public Monster
{

public:

    Slime(std::string name = "Slime", std::string ItemName = "Slime Jelly", int hp = 300, int power = 7, int defence = 5, int ItemPrice = 30, std::string skill = "Jump acttack!", int expReward = 30);

    void Buff();

};
