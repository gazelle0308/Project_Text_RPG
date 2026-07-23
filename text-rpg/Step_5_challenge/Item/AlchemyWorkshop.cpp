#include "../include/Item/AlchemyWorkshop.h"

void defalutRecipe(std::vector<PotionRecipe>& recipeBook)
{

    std::shared_ptr<IngredientNode> HpPotionRecipe = CreateIngredient("Water", 1);
    std::shared_ptr<IngredientNode> MpPotionRecipe = CreateIngredient("Water", 1);


    std::shared_ptr<IngredientNode> HpPotionMatter= CreateIngredient("MushroomCap", 2);
    std::shared_ptr<IngredientNode> MpPotionMatter = CreateIngredient("SlimeJelly", 2);


    LinkIngredient(HpPotionRecipe, HpPotionMatter);
    LinkIngredient(MpPotionRecipe, MpPotionMatter);

    PotionRecipe HpPotion( "HpPotion", HpPotionRecipe);
    PotionRecipe MpPotion( "MpPotion", MpPotionRecipe);

    RecipeBook(HpPotion, recipeBook);
    RecipeBook(MpPotion, recipeBook);

}

void setPotion(int count, int* p_HpPotion, int* p_MpPotion)
{

    *p_HpPotion = count;
    *p_MpPotion = count;

}