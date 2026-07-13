#include "Battle.h"

void BattleAssist(Player& player, Monster& monster){

    cout<< "< Battle Begin! >" << endl;
    cout<< player.GetName() << "(" << player.GetJob() << ")" << " vs " << monster.GetName() << endl;
    cout << "====================================================" << endl;

    while( player.GetHp() > 0 && monster.GetHp() > 0 ){

        cout<<"---Now Player Turn---"<< endl;
        player.attack(&monster);
        cout<<"Player attack: " << player.GetPower() - monster.GetDefence() << "(basic:" << player.GetPower() <<")" << endl;
        cout << "====================================================" << endl;

        if(monster.GetHp() > 0)
        {
            cout<<"---Now Monster Turn---"<< endl;

            if( rand()% 2 == 0 ){

                monster.attack(&player);
                cout<<"Monster attack: " << player.GetPower() - monster.GetDefence() << "(basic:" << player.GetPower() <<")" << endl;

            }else{

                cout<<"Monster action: ";
                monster.Buff();

            }

            cout << "====================================================" << endl;

        }
        else
        {

            cout << "You Win!" << endl;
            cout << "Got: " << monster.GetDropItemName() << endl;
            cout << "====================================================" << endl;
            cout << endl;

        }
    }
}


void ExtractDropItem( const Monster& monster, string& itemName, int& price){

    itemName = monster.GetDropItemName();
    price = monster.GetDropItemPrice();

}