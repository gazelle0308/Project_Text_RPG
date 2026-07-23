#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "Item.h"

/*-------------------------Potion-----------------------------*/

class Potion : public Item
{
private:

    bool Used;

public:

    Potion(std::string name, int price, int count = 1, bool canSell = true);
    void potionUse();

};
