#include "../include/Item/PotionRecipe.h"

#include "../include/Ui/Ui.h"

/*-------------------------ingredient-----------------------------*/
std::shared_ptr<IngredientNode> CreateIngredient(const std::string& ingredient, const int count)
{

    auto recipe = std::make_shared<IngredientNode>();

    recipe->ingredientName = ingredient;
    recipe->count = count;

    return recipe;

}

void LinkIngredient(std::shared_ptr<IngredientNode> matterOne, std::shared_ptr<IngredientNode> matterTwo){ matterOne->nextIngredient = matterTwo; }


/*-------------------------PotionRecipe-----------------------------*/
PotionRecipe::PotionRecipe(std::string name, std::shared_ptr<IngredientNode> head):name(name), head(head){ViewRecipe();}

//ClassFunction
void PotionRecipe::ViewRecipe()
{

    std::ostringstream oss;

    oss << this->name << "(";
    for(std::shared_ptr<IngredientNode> loop = head; loop != nullptr; loop = loop->nextIngredient)
    {

        oss << loop->ingredientName << " x" << loop->count;
        if(loop->nextIngredient != nullptr){ oss << ", "; }
        
    }
    oss << ")";
    this->recipe = oss.str();

}

//Setter
void PotionRecipe::SetName(const std::string name){ this->name = name; }

void PotionRecipe::SetHead(std::shared_ptr<IngredientNode> head){ this->head = head; }


//Getter
std::string PotionRecipe::GetName() const{ return this->name;}

std::shared_ptr<IngredientNode> PotionRecipe::GetHead() const { return this->head; }

std::string PotionRecipe::GetRecipe() const{ return this->recipe;}