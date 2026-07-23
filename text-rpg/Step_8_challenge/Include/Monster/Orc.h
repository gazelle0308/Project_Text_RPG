#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "MonsterBone.h"

class Orc : public Monster
{

public:

    Orc(std::string name = "Orc", std::string ItemName = "Orc's Tusk", int hp = 400, int power = 50, int defence = 25, int ItemPrice = 70, std::string skill = "Smash big club!", int expReward = 70);

    void Buff();

};
