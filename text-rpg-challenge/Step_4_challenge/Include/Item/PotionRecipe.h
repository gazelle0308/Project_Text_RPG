#pragma once

#include <sstream>

#include "../Common.h"
#include "../Constants.h"

/*-------------------------ingredient-----------------------------*/
struct IngredientNode
{

    int count;
    std::string ingredientName;
    std::shared_ptr<IngredientNode> nextIngredient = nullptr;

};

std::shared_ptr<IngredientNode> CreateIngredient(const std::string& ingredient, const int count);

void LinkIngredient(std::shared_ptr<IngredientNode> ingredientOne, std::shared_ptr<IngredientNode> ingredientTwo);



/*-------------------------PotionRecipe-----------------------------*/
class PotionRecipe
{

protected:

    std::shared_ptr<IngredientNode> head = nullptr;
    std::string name;
    std::string recipe;

public:

    PotionRecipe(std::string name, std::shared_ptr<IngredientNode> head);

//function
    void ViewRecipe();

//Setter
    void SetName(const std::string name);
    void SetHead(std::shared_ptr<IngredientNode> recipe);

//Getter
    std::string GetName() const;
    std::shared_ptr<IngredientNode> GetHead() const;
    std::string GetRecipe() const;

}; 

