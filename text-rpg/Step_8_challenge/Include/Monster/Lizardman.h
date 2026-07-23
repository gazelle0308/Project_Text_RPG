#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "MonsterBone.h"

class Lizardman : public Monster
{

public:

    Lizardman(std::string name = "Lizardman", std::string ItemName = "Lizard's Scale", int hp = 370, int power = 60, int defence = 15, int ItemPrice = 70, std::string skill = "Spear acttack!", int expReward = 70);

    void Buff();

};
