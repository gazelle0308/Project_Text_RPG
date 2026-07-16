#pragma once

#include <sstream>

#include "../Common.h"
#include "../Constants.h"

#include "PotionRecipe.h"

/*-------------------------RecipeBook-----------------------------*/
void RecipeBook(const PotionRecipe& recipe, std::vector<PotionRecipe>& book);
