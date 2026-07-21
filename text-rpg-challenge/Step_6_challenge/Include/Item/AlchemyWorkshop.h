#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "RecipeBook.h"
#include "../Ui/Ui.h"

void defalutRecipe(std::vector<PotionRecipe>& recipeBook);

void setPotion(int count, int* p_HpPotion, int* p_MpPotion);