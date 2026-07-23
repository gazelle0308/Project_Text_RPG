#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "../Player/PlayerStatus.h"

#include "../Item/Inventory.h"
#include "../Item/RecipeBook.h"

class AlchemyWorkShop;

int MainUi();

void ViewStatus(const Player& player);

void PrintGetExp(const Player& player, int exp);

void LevelUpMsg(int before, int after, int upStatus[]);

void MainTitle();

void CutLine();

void StartLine();

template <typename Entity>
void BattleMsg(const Entity& attacker, int DamageView)
{

    std::cout << attacker.GetJob() << " " << attacker.GetName() << "'s " << attacker.GetSkill() << std::endl; 
    std::cout << attacker.GetName() << "'s attack: " << DamageView << "(basic:" << attacker.GetPower() <<")" << std::endl;

}

void ShowItemInfo(const std::string Iventory);


void ShowAllRecipes(const std::vector<PotionRecipe>& recipeBook);
void SearchByName(const std::string name, const std::vector<PotionRecipe>& recipeBook);
void SearchByIngredient(const std::string ingredient, const std::vector<PotionRecipe>& recipeBook);


void AlchemyUi(const std::vector<PotionRecipe>& recipeBook, AlchemyWorkShop& workShop, Inventory<Item>& inventory);
