#pragma once

#include "Slime.h"
#include "Mushroom.h"
#include "MonsterBone.h"
#include "../Step_4_mandatory/Player.h"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void BattleAssist(Player& player, Monster& monster);

void ExtractDropItem( const Monster& monster, string& itemName, int& price);