#include "../Step_1_mandatory/CharacterSetup.h"


#include "../Step_2_mandatory/SetupCheck.h"


#include "../Step_3_mandatory/UpgradeSetup.h"


#include "../Step_4_mandatory/Player.h"
#include "../Step_4_mandatory/SelectClass.h"


#include "../Step_5_mandatory/Battle.h"
#include "../Step_5_mandatory/Slime.h"
#include "../Step_5_mandatory/Mushroom.h"
#include "../Step_5_mandatory/MonsterBone.h"


#include "../Step_6_mandatory/Inventory.h"
#include "../Step_6_mandatory/Ui.h"

#include "../Step_7_mandatory/AlchemyWorkshop.h"

int main()
{

    const int SIZE = 4;

    string name;

    int stat[SIZE] = {0};

    bool isGameStart = false;

    vector<Item> Inventory;

    vector<Potion> PotionInventory;


    SetupStatus(name, stat);
    SetupCheck(stat);
    isGameStart = UpgradeSetup(stat); 
    defalutPotion(PotionInventory);

    Player* player = nullptr;

    while(player == nullptr)
    {

        player = SelectClass(name, stat);
        
    }

    while( isGameStart )
    {

        int play = printUi();

        if( play == 1 )
        {

            unique_ptr<Monster> monster = nullptr;

            if( rand() % 2 == 0 ) { monster = make_unique<Mushroom>(); }
            else { monster = make_unique<Slime>(); }

            //아이템 정보 버퍼
            string dropName = "";
            int dropPrice = 0;

            BattleAssist( *player, *monster );

            if( player->GetHp() <= 0 )
            {

                cout << "You Died" << endl;
                break;

            }

            //전투 진행 및 처치 시 아이템 등록
            ExtractDropItem( *monster, dropName, dropPrice );
            Item item = BuildItem( dropName, dropPrice );
            InsertInventory( item, Inventory );

        }
        else if(play == 2)
        {
            cout << "=================================================" << endl;
            for( auto loop = Inventory.begin(); loop != Inventory.end(); ++loop)
            {

                loop->PrintInfo();

            }
            cout << "=================================================" << endl;
            cout << endl;

        }
        else if(play == 3)
        {

            AlchemyUi(PotionInventory);

        }
        else
        {

            isGameStart = false;

        }
    }
    
    delete player;
    return 0;

}
