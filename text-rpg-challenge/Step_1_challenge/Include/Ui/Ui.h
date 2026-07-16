#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "../Player/PlayerStatus.h"

#include "../Item/Inventory.h"
#include "../Item/RecipeBook.h"

int MainUi();

void ViewStatus(const Player& player);

void MainTitle();

void CutLine();

void StartLine();

template <typename Entity>
void BattleMsg(const Entity& attacker, int DamageView)
{

    std::cout << attacker.GetJob() << " " << attacker.GetName() << "'s " << attacker.GetSkill() << std::endl; 
    std::cout << attacker.GetName() << "'s attack: " << DamageView << "(basic:" << attacker.GetPower() <<")" << std::endl;

}

void ItemInfo(const Item& item);


void ShowAllRecipes(const std::vector<PotionRecipe>& recipeBook);
void SearchByName(const std::string name, const std::vector<PotionRecipe>& recipeBook);
void SearchByIngredient(const std::string ingredient, const std::vector<PotionRecipe>& recipeBook);


void AlchemyUi(const std::vector<PotionRecipe>& recipeBook);
