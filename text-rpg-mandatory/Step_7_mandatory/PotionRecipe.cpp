#include "PotionRecipe.h"


Potion::Potion(string name, shared_ptr<RecipeNode> recipe):name(name), head(recipe){}

void Potion::PrintRecipe() const
{

    cout << name << "(";

    for(shared_ptr<RecipeNode> loop = head; loop != nullptr; loop = loop->nextMatter)
    {
        cout << loop->matter.name
            << " x"
            << loop->matter.count;

        if(loop->nextMatter != nullptr){ cout << ", "; }
    }

    cout << ")" << endl;

}

void Potion::setName(const string name){ this->name = name; }

void Potion::setRecipe(shared_ptr<RecipeNode> recipe){ this->head = recipe; }

string Potion::getName() const{ return this->name;}

shared_ptr<RecipeNode> Potion::getRecipe() const { return this->head; }


void ShowAllRecipes(const vector<Potion>& Inventory)
{

    for( auto loop = Inventory.begin(); loop != Inventory.end(); ++loop)
    {

        loop->PrintRecipe();

    }

}

void SearchByName(const string name, const vector<Potion>& Inventory)
{

    for( auto loop = Inventory.begin(); loop != Inventory.end(); ++loop)
    {

        if(name == loop->getName())
        {

            loop->PrintRecipe();
            return;

        }

    }

    cout << "can't find that potion" << endl;

}

void SearchByIngredient(const string ingredient, const vector<Potion>& Inventory)
{

    bool find = false;

    for(auto Inventoryloop = Inventory.begin(); Inventoryloop != Inventory.end(); ++Inventoryloop)
    {

        for(auto matterloop = Inventoryloop->getRecipe(); matterloop != nullptr; matterloop = matterloop->nextMatter)
        {

            if(ingredient == matterloop->matter.name)
            {


                Inventoryloop->PrintRecipe();
                find = true;
                break;

            }

        }
        
    }
    if(find == false)
    {

        cout << "can't find that potion" << endl;

    }

}



Ingredient createIngredient(const string name, const int count)
{

    Ingredient ingredient;

    ingredient.name = name;
    ingredient.count = count;

    return ingredient;

}

shared_ptr<RecipeNode> createRecipe(const Ingredient& matter)
{

    auto recipe = make_shared<RecipeNode>();

    recipe->matter = matter;

    return recipe;

}

void InsertRecipe(shared_ptr<RecipeNode> matterOne, shared_ptr<RecipeNode> matterTwo){ matterOne->nextMatter = matterTwo; }


void PotionInventory(const Potion& potion, vector<Potion>& Inventory)
{

    Inventory.push_back(potion);

}
