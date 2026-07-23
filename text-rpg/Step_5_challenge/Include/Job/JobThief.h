#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "../Monster/MonsterBone.h"

#include "../Player/PlayerStatus.h"

class Thief : public Player
{

public:

    Thief(std::string name, int hp = 50, int mp = 50, int power = 20, int defence = 20, int level = 1, std::string skill = "Dagger Throw!");
    
    void attack(Monster* monster);
    
};