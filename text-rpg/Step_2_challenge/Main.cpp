#include "include/Item/Inventory.h"
#include "include/Item/AlchemyWorkshop.h"

#include "include/Player/PlayerStatus.h"
#include "include/Job/JobSelect.h"

#include "Include/Monster/MonsterBone.h"
#include "Include/Monster/Mushroom.h"
#include "Include/Monster/Slime.h"

#include "Include/System/Battle.h"

#include "Include/Ui/Ui.h"

int main()
{

    const int SIZE = 4;

    std::string name;

    int stat[SIZE] = {0};
    int HpPotion,MpPotion;

    bool isGameStart = false;

    std::vector<Item> Inventory;

    std::vector<PotionRecipe> potionRecipe;

    setPotion(5, &HpPotion, &MpPotion);
    Item potion = BuildItem("HpPotion", 50, HpPotion);
    InsertInventory(potion, Inventory);
    potion = BuildItem("MpPotion", 50, MpPotion);
    InsertInventory(potion, Inventory);

    SetupStatus(name, stat);
    CheckStatus(stat);

    Player* player = nullptr;

    while(player == nullptr)
    {

        player = JobSelect(name, stat);
        
    }
    isGameStart = UpgradeStatus(*player, Inventory); 
    defalutRecipe(potionRecipe);

    while(isGameStart)
    {

        int play = MainUi();

        if( play == 1 )
        {

            std::unique_ptr<Monster> monster = nullptr;

            if( rand() % 2 == 0 ) { monster = std::make_unique<Mushroom>(); }
            else { monster = std::make_unique<Slime>(); }

            //아이템 정보 버퍼
            std::string dropName = "";
            int dropPrice = 0;

            BattleAssist( *player, *monster );

            if( player->GetHp() <= 0 )
            {

                std::cout << "You Died" << std::endl;
                break;

            }

            //전투 진행 및 처치 시 아이템 등록
            ExtractDropItem( *monster, dropName, dropPrice );
            Item item = BuildItem( dropName, dropPrice );
            InsertInventory( item, Inventory );

        }
        else if(play == 2)
        {

            StartLine();
            for( auto loop = Inventory.begin(); loop != Inventory.end(); ++loop)
            {

                ItemInfo(*loop);

            }
            CutLine();

        }
        else if(play == 3)
        {

            AlchemyUi(potionRecipe);

        }
        else
        {

            isGameStart = false;

        }

    }
    
    delete player;
    return 0;

}
