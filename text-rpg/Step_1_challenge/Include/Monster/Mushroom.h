#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "MonsterBone.h"

class Mushroom : public Monster
{

public:

    Mushroom(std::string name = "Mushroom", std::string ItemName = "Mushroom Cap", int hp = 270, int power = 5, int defence = 3, int ItemPrice = 20, std::string skill = "Jump acttack!");

    void Buff();

};
