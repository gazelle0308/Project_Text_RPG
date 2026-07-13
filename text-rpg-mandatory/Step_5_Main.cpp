#include "Step_1_mandatory/CharacterSetup.h"


#include "Step_2_mandatory/SetupCheck.h"


#include "Step_3_mandatory/UpgradeSetup.h"


#include "Step_4_mandatory/SelectClass.h"


#include "Step_5_mandatory/Battle.h"


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
    while(player->GetHp() > 0)
    {
        Monster* monster = nullptr;

        if( rand()% 2 == 0 ) { monster = new Mushroom(); }
        else { monster = new Slime(); }

        BattleAssist( player, monster );
        delete monster;

    }
    
    delete player;
    return 0;

}
