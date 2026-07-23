#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "../Player/PlayerStatus.h"

#include "JobArcher.h"
#include "JobMagician.h"
#include "JobThief.h"
#include "JobWarrior.h"


Player* JobSelect(std::string name, int stat[]);