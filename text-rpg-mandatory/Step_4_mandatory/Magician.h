#pragma once

#include "Player.h"

#include <iostream>
#include <string>

using namespace std;

class Magician : public Player
{

public:

    Magician(string name, int hp = 50, int mp = 50, int power = 50, int defence = 50, int level = 1);

    void attack();

};