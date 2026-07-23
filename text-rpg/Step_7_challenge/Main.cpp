#include "include/Item/Inventory.h"
#include "include/Item/AlchemyWorkshop.h"
#include "include/Item/Potion.h"

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

    Inventory<Item> Inventory;

    AlchemyWorkShop alchemyWorkShop;

    std::vector<PotionRecipe> potionRecipe;

    setPotion(5, &HpPotion, &MpPotion);
    Potion potion("HpPotion", 50, HpPotion);
    InsertInventory(potion, Inventory);


    potion.SetName("MpPotion");
    potion.SetCount(MpPotion);
    InsertInventory(potion, Inventory);
    Item bottle = BuildItem("Bottle", 10, 0);
    InsertInventory(bottle, Inventory);

    SetupStatus(name, stat);
    
    CheckStatus(stat);

    Player* player = nullptr;

    while(player == nullptr){ player = JobSelect(name, stat); }

    isGameStart = UpgradeStatus(*player, Inventory); 
    defalutRecipe(potionRecipe);
    alchemyWorkShop.InsertWorkShop("HpPotion");
    alchemyWorkShop.InsertWorkShop("MpPotion");

    while(isGameStart)
    {

        int play = MainUi();
        int changeCheck[2] = {};
        std::string inventoryInfo;

        if( play == 1 )
        {

            std::unique_ptr<Monster> monster = nullptr;

            if( rand() % 2 == 0 ) { monster = std::make_unique<Mushroom>(); }
            else { monster = std::make_unique<Slime>(); }

            //아이템 정보 버퍼
            std::string dropName = "";
            int dropPrice = 0;

            BattleAssist(*player, *monster, Inventory);

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
            SortCallable(Inventory); 
            inventoryInfo = ItemInfo(Inventory);
            ShowItemInfo(inventoryInfo); 
        }
        else if(play == 3){ AlchemyUi(potionRecipe, alchemyWorkShop, Inventory); }
        else if(play == 4){ ViewStatus(*player); }
        else if(play == 5){ isGameStart = false; }
        else{ std::cout<<"ERR Input Retry!" << std::endl; }
    }
    
    delete player;
    return 0;

}
