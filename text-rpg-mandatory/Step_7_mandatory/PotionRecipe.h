#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;


struct Ingredient
{

    string name;
    int count;

};

struct RecipeNode
{

    Ingredient matter;
    shared_ptr<RecipeNode> nextMatter = nullptr;

};


class Potion
{

protected:

    string name;
    shared_ptr<RecipeNode> head = nullptr;

public:

    Potion(string name, shared_ptr<RecipeNode> recipe);

//function
    void PrintRecipe() const;

//Setter
    void setName(const string name);
    void setRecipe(shared_ptr<RecipeNode> recipe);

//Getter
    string getName() const;
    shared_ptr<RecipeNode> getRecipe() const;

}; 

Ingredient createIngredient(const string name, const int count);

shared_ptr<RecipeNode> createRecipe(const Ingredient& matter);


void InsertRecipe(shared_ptr<RecipeNode> matterOne, shared_ptr<RecipeNode> matterTwo);

void PotionInventory(const Potion& potion, vector<Potion>& Inventory);


void ShowAllRecipes(const vector<Potion>& Inventory);
void SearchByName(const string name, const vector<Potion>& Inventory);
void SearchByIngredient(const string ingredient, const vector<Potion>& Inventory);