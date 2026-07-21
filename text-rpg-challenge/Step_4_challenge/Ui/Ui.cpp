#include "../include/Ui/Ui.h"

int MainUi()
{

    int answer;
    
    MainTitle();
    std::cout << "1.Enter Dungeon" << std::endl;
    std::cout << "2.Check Inventory" << std::endl;
    std::cout << "3.Alchemy Workshop" << std::endl;
    std::cout << "4.Quit" << std::endl;
    StartLine();
    std::cout << "choose: ";
    std::cin >> answer;
    CutLine();

    return answer;

}

void ViewStatus(const Player& player)
{

    StartLine();
    std::cout << "Name: " << player.GetName() << " Job: " << player.GetJob() << " Level: " << player.GetLevel() << std::endl;
    std::cout << "HP: " << player.GetHp() << " MP: " << player.GetMp() << " Power: " << player.GetPower() << " Defence: " << player.GetDefence() << std::endl;
    std::cout << "Exp: " << player.GetExp() << "/" << player.GetMaxExp() << std::endl;
    CutLine();

}

void PrintGetExp(const Player& player, int exp)
{

    StartLine();
    std::cout << "Get Exp!" << std::endl;
    std::cout << "Get +" << exp << std::endl;
    std::cout << "Current Exp: " << player.GetExp() << "/" << player.GetMaxExp() << std::endl;
    CutLine();

}

void LevelUpMsg(int before, int after, int upStatus[])
{

    StartLine();
    std::cout << "LevelUp!" << std::endl;
    std::cout << before << "->" << after << "(" << after - before << ")" << std::endl;
    std::cout << "Hp +" << upStatus[0] << " Mp +" << upStatus[1] << std::endl;
    std::cout << "Power +" << upStatus[2] << " Defence +" << upStatus[3] << std::endl;
    CutLine();

}

void MainTitle()
{

    std::cout << std::endl;
    StartLine();
    std::cout << "[Dungeon Escape RPG]" << std::endl;
    StartLine();

}


void CutLine()
{

    std::cout << "=================================================" << std::endl;
    std::cout << std::endl;

}


void StartLine()
{

    std::cout << "=================================================" << std::endl;

}

void ShowItemInfo(const std::string Iventory)
{
    StartLine();
    std::cout << Iventory << std::endl;
    StartLine();
}


void ShowAllRecipes(const std::vector<PotionRecipe>& recipeBook)
{

    for( auto loop = recipeBook.begin(); loop != recipeBook.end(); ++loop)
    {

        std::cout << loop->GetRecipe() << std::endl;

    }

}

void SearchByName(const std::string name, const std::vector<PotionRecipe>& recipeBook)
{

    for( auto loop = recipeBook.begin(); loop != recipeBook.end(); ++loop)
    {

        if(name == loop->GetName())
        {

            std::cout << loop->GetRecipe() << std::endl;
            return;

        }

    }

    std::cout << "can't find that potion" << std::endl;

}

void SearchByIngredient(const std::string ingredient, const std::vector<PotionRecipe>& recipeBook)
{

    bool find = false;

    for(auto Inventoryloop = recipeBook.begin(); Inventoryloop != recipeBook.end(); ++Inventoryloop)
    {

        for(auto matterloop = Inventoryloop->GetHead(); matterloop != nullptr; matterloop = matterloop->nextIngredient)
        {

            if(ingredient == matterloop->ingredientName)
            {


                std::cout << Inventoryloop->GetRecipe() << std::endl;
                find = true;
                break;

            }

        }
        
    }
    if(find == false)
    {

        std::cout << "can't find that potion" << std::endl;

    }

}



void AlchemyUi(const std::vector<PotionRecipe>& recipeBook)
{
    while(true)
    {

        int answer = -1;
        
        StartLine();
        std::cout << "[Potion Table]" << std::endl;
        StartLine();
        std::cout << "1.Show all recipes" << std::endl;
        std::cout << "2.Search by potion name" << std::endl;
        std::cout << "3.Search by matter" << std::endl;
        std::cout << "0.Go back" << std::endl;
        StartLine();
        std::cout << "choose: ";
        std::cin >> answer;
        CutLine();

        std::string userAnswer;
        if( answer == 2 || answer == 3 )
        {

            StartLine();
            std::cout << "Search: ";
            std::cin >> userAnswer;
            CutLine();

        }
        switch (answer)
        {
        case 1:

            StartLine();
            ShowAllRecipes(recipeBook);
            CutLine();
            break;
        
        case 2:
            
            StartLine();
            SearchByName(userAnswer, recipeBook);
            CutLine();
            break;
        
        case 3:
        
            StartLine();
            SearchByIngredient(userAnswer, recipeBook);
            CutLine();
            break;
        
        default:
            return;
        }

    }

}
