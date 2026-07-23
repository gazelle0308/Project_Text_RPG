#include "../include/System/Battle.h"

void BattleAssist(Player& player, Monster& monster){
    
    int DamageView = 0;

    std::cout<< "< Battle Begin! >" << std::endl;
    std::cout<< player.GetName() << "(" << player.GetJob() << ")" << " vs " << monster.GetName() << std::endl;
    CutLine();

    while( player.GetHp() > 0 && monster.GetHp() > 0 )
    {

        StartLine();
        std::cout<<"---Now Player Turn---"<< std::endl;
        player.attack(&monster);
        CutLine();

        if(monster.GetHp() > 0)
        {
            StartLine();
            std::cout<<"---Now Monster Turn---"<< std::endl;

            if(rand()% 2 == 0){

                DamageView = Attack(monster, player);
                BattleMsg(monster, DamageView);
            }else{

                std::cout<<"Monster action: ";
                monster.Buff();

            }
            CutLine();

        }
        else
        {

            StartLine();
            std::cout << "You Win!" << std::endl;
            std::cout << "Got: " << monster.GetDropItemName() << std::endl;
            GetPlayerExp(player, monster);
            CutLine();

        }
    }
}


void ExtractDropItem( const Monster& monster, std::string& itemName, int& price)
{

    itemName = monster.GetDropItemName();
    price = monster.GetDropItemPrice();

}

void GetPlayerExp(Player& player, Monster& monster)
{ player.HuntRewardExp(monster.GetExpReward()); }