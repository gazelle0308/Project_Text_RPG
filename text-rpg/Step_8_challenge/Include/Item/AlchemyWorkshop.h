#pragma once

#include <map>

#include "../Common.h"
#include "../Constants.h"

#include "RecipeBook.h"
#include "../Ui/Ui.h"

class AlchemyWorkShop
{

public:

    bool ReserchPotion(const std::string& name);

    void InsertWorkShop(std::string name);

    bool DispensePotion(std::string name);
    bool ReturnPotion(std::string name);

    int GetStock(std::string name);

    AlchemyWorkShop() = default;

private:

    std::map<std::string, int> potionStock_;

};


void defalutRecipe(std::vector<PotionRecipe>& recipeBook);

void setPotion(int count, int* p_HpPotion, int* p_MpPotion);
