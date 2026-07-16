#include "Battle.h"

void BattleAssist(Player& player, Monster& monster){
    
    int playerDmg = player.GetPower() - monster.GetDefence();
    int monsterDmg = monster.GetPower() - player.GetDefence();

    cout<< "< Battle Begin! >" << endl;
    cout<< player.GetName() << "(" << player.GetJob() << ")" << " vs " << monster.GetName() << endl;
    cout << "====================================================" << endl;
    cout << endl;

    while( player.GetHp() > 0 && monster.GetHp() > 0 ){

        cout << "====================================================" << endl;
        cout<<"---Now Player Turn---"<< endl;
        player.attack(&monster);
        cout<<"Player attack: " << (playerDmg <= 0 ? 1 : playerDmg) << "(basic:" << player.GetPower() <<")" << endl;
        cout << "====================================================" << endl;
        cout << endl;

        if(monster.GetHp() > 0)
        {
            cout <<"===================================================="<< endl;
            cout<<"---Now Monster Turn---"<< endl;

            if( rand()% 2 == 0 ){

                monster.attack(&player);
                cout<<"Monster attack: " << (monsterDmg <= 0 ? 1 : monsterDmg) << "(basic:" << monster.GetPower() <<")" << endl;

            }else{

                cout<<"Monster action: ";
                monster.Buff();

            }
            cout << "====================================================" << endl;
            cout << endl;

        }
        else
        {

            cout << "====================================================" << endl;
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