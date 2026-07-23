#pragma once

#include "Player.h"
#include "../Step_5_mandatory/MonsterBone.h"

#include <iostream>
#include <string>

using namespace std;

class Archer : public Player
{

public:

    Archer(string name, int hp = 50, int mp = 50, int power = 50, int defence = 50, int level = 1);

    void attack(Monster* monster);

};