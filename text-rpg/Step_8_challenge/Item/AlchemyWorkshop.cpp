#include "../include/Item/AlchemyWorkshop.h"

#include "../include/Ui/Ui.h"


bool AlchemyWorkShop::ReserchPotion(const std::string& name)
{
    if(potionStock_.find(name) != potionStock_.end()){ return true; }
    return false;
}

void AlchemyWorkShop::InsertWorkShop(std::string name)
{ 
    if(ReserchPotion(name)){ std::cout << "AlchemyWorkShop got " << name << std::endl; return; }
    this->potionStock_[name] = 3;
    std::cout << name << " is join AlchemyWorkShop!" << std::endl;
}

bool AlchemyWorkShop::DispensePotion(std::string name)
{   
    if(!ReserchPotion(name)){ std::cout << "Can't find " << name << std::endl; return false; }
    if(this->potionStock_[name] <= 0){ std::cout << "No more " << name << "(stock: " << this->GetStock(name) << ")" << std::endl; return false; }
    this->potionStock_[name] = this->potionStock_[name] - 1;
    std::cout << "Dispense: " << name << "(stock: " << this->GetStock(name) << ")" << std::endl;
    return true;
}

bool AlchemyWorkShop::ReturnPotion(std::string name)
{
    if(!ReserchPotion(name)){ std::cout << "Can't find " << name << std::endl; return false; }
    if(this->potionStock_[name] >= 3){ std::cout << "Now full " << name << "(stock: " << this->GetStock(name) << ")" << std::endl; return false; }
    this->potionStock_[name] = this->potionStock_[name] + 1;
    std::cout << "Return Bottle: " << name << "(stock: " << this->GetStock(name) << ")" << std::endl;
    return true;
}

int AlchemyWorkShop::GetStock(std::string name)
{
    if(!ReserchPotion(name)){ std::cout << "Can't find " << name << std::endl; return 0; }
    return this->potionStock_[name];
}

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