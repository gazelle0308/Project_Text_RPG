#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "MonsterBone.h"

class Player;

class Nergigante : public Monster
{

private:

    int buffStack;

public:

    Nergigante(std::string name = "Nergigante", std::string ItemName = "Nergigante's Big Horn", int hp = 550, int power = 70, int defence = 50, int ItemPrice = 130, std::string skill = "Foreleg Scratch!", int expReward = 100);

    void Buff();
    bool Ultimate(Player& player);

};
