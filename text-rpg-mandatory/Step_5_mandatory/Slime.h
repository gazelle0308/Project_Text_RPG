#pragma once

#include "MonsterBone.h"
#include "../Step_4_mandatory/Player.h"

#include <iostream>
#include <string>

using namespace std;

class Slime : public Monster
{

public:

    Slime(string name = "Slime", string ItemName = "Slime Jelly", int hp = 300, int power = 7, int defence = 5, int ItemPrice = 30);

    void attack(Player* player);

    void Buff();

};
