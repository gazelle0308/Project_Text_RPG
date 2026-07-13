#include "Battle.h"

void BattleAssist( Player& player, Monster& monster ){

    while( player.GetHp() > 0 && monster.GetHp() > 0 ){

        cout<< "< Battle Begin! >" << endl;
        cout<< player.GetName() << "(" << player.GetJob() << ")" << " vs " << monster.GetName() << endl;
        cout<<"---Now Player Turn---"<< endl;
        cout<<"Player acttack: " << monster.GetDefence() - player.GetPower() << "(basic:" << player.GetPower() <<")" << endl;
        player.attack( &monster );

        cout<< player.GetName() << "(" << player.GetJob() << ")" << " vs " << monster.GetName() << endl;
        cout<<"---Now Monster Turn---"<< endl;

        if( rand()% 2 == 0 ){

            cout<<"Monster acttack: " << monster.GetDefence() - player.GetPower() << "(basic:" << player.GetPower() <<")" << endl;
            monster.attack( &player );

        }else{

            cout<<"Monster action: ";
            monster.Buff();

        }
    }
}