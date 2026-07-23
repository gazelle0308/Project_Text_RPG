#pragma once

#include "Magician.h"
#include "Warrior.h"
#include "Archer.h"
#include "Thief.h"


#include <iostream>
#include <string>

using namespace std;

Player* SelectClass( string name, int stat[] );