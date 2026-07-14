#include "../Step_1_mandatory/CharacterSetup.h"


#include "../Step_2_mandatory/SetupCheck.h"


#include "../Step_3_mandatory/UpgradeSetup.h"


#include "../Step_4_mandatory/Player.h"
#include "../Step_4_mandatory/SelectClass.h"


#include "../Step_5_mandatory/Battle.h"
#include "../Step_5_mandatory/Slime.h"
#include "../Step_5_mandatory/Mushroom.h"
#include "../Step_5_mandatory/MonsterBone.h"


int main()
{

    const int SIZE = 4;

    string name;

    int stat[SIZE] = {0};

    bool isGameStart = false;

    SetupStatus(name, stat);
    SetupCheck(stat);
    isGameStart = UpgradeSetup(stat); 

    Player* player = nullptr;

    while(player == nullptr)
    {

        player = SelectClass(name, stat);
        
    }
    
    int loop = 0;

    while(player->GetHp() > 0 && loop < 5 )
    {

        unique_ptr<Monster> monster = nullptr;

        if( rand() % 2 == 0 ) { monster = make_unique<Mushroom>(); }
        else { monster = make_unique<Slime>(); }

        BattleAssist( *player, *monster );
        loop = loop + 1;

        if( player->GetHp() <= 0 )
        {

            cout << "You Died" << endl;
            break;

        }

    }
    
    delete player;
    return 0;

}
