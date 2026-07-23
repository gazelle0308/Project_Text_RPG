#include "AlchemyWorkshop.h"

void AlchemyUi(const vector<Potion>& Inventory)
{
    while(true)
    {

        int answer = -1;
        
        cout << "=================================================" << endl;
        cout << "[Potion Table]" << endl;
        cout << "=================================================" << endl;
        cout << "1.Show all recipes" << endl;
        cout << "2.Search by potion name" << endl;
        cout << "3.Search by matter" << endl;
        cout << "0.Go back" << endl;
        cout << "=================================================" << endl;
        cout << "choose: ";
        cin >> answer;
        cout << "=================================================" << endl;
        cout << endl;

        string userAnswer;
        if( answer == 2 || answer == 3 )
        {

            cout << "=================================================" << endl;
            cout << "Search: ";
            cin >> userAnswer;
            cout << "=================================================" << endl;
            cout << endl;

        }
        switch (answer)
        {
        case 1:

            cout << "=================================================" << endl;
            ShowAllRecipes(Inventory);
            cout << "=================================================" << endl;
            cout << endl;
            break;
        
        case 2:
            
            cout << "=================================================" << endl;
            SearchByName(userAnswer, Inventory);
            cout << "=================================================" << endl;
            cout << endl;
            break;
        
        case 3:
        
            cout << "=================================================" << endl;
            SearchByIngredient(userAnswer, Inventory);
            cout << "=================================================" << endl;
            cout << endl;
            break;
        
        default:
            return;
        }

    }

}

void defalutPotion(vector<Potion>& Inventory)
{

    Ingredient Water = createIngredient("Water", 1);
    Ingredient SlimeJelly = createIngredient("Slime Jelly", 2);
    Ingredient MushroomCap = createIngredient("Mushroom Cap", 2);


    shared_ptr<RecipeNode> HpPotionRecipe = createRecipe(Water);
    shared_ptr<RecipeNode> MpPotionRecipe = createRecipe(Water);


    shared_ptr<RecipeNode> HpPotionMatter= createRecipe(MushroomCap);
    shared_ptr<RecipeNode> MpPotionMatter = createRecipe(SlimeJelly);


    InsertRecipe(HpPotionRecipe, HpPotionMatter);
    InsertRecipe(MpPotionRecipe, MpPotionMatter);


    Potion HpPotion( "HpPotion", HpPotionRecipe);
    Potion MpPotion( "MpPotion", MpPotionRecipe);

    PotionInventory(HpPotion, Inventory);
    PotionInventory(MpPotion, Inventory);

}