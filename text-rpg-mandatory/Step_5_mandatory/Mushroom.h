#pragma once

#include "MonsterBone.h"
#include "../Step_4_mandatory/Player.h"

#include <iostream>
#include <string>

using namespace std;

class Mushroom : public Monster
{

public:

    Mushroom(string name = "Mushroom", string ItemName = "Mushroom Cap", int hp = 270, int power = 5, int defence = 3, int ItemPrice = 20);

    void attack(Player* player);

    void Buff();

};
