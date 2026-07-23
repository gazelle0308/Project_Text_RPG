#include "../include/Item/PotionRecipe.h"

#include "../include/Ui/Ui.h"

/*-------------------------RecipeBook-----------------------------*/
void RecipeBook(const PotionRecipe& recipe, std::vector<PotionRecipe>& book)
{
    for( auto loop = book.begin(); loop != book.end(); ++loop )
    {

        if(loop->GetName() == recipe.GetName())
        {

            StartLine();
            std::cout << "Is in recipebook" << std::endl;
            CutLine();
            break;

        }

    }
    book.push_back(recipe);

}
