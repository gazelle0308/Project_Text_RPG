#include "../include/System/Battle.h"

void BattleAssist(Player& player, Monster& monster, std::vector<Item>& inventory){
    
    int DamageView = 0;
    std::string inventoryInfo = ItemInfo(inventory);

    std::cout<< "< Battle Begin! >" << std::endl;
    std::cout<< player.GetName() << "(" << player.GetJob() << ")" << " vs " << monster.GetName() << std::endl;
    CutLine();

    while( player.GetHp() > 0 && monster.GetHp() > 0 )
    {
        int action;
        int itemNumber;

        StartLine();
        std::cout<<"---Now Player Turn---"<< std::endl;
        std::cout<<"1.Attack 2.Use Item" << std::endl;
        std::cout<<"Input Your action: ";
        std::cin >> action;


        switch (action)
        {
        case 1:
            player.attack(&monster);
            break;
        
        case 2:
            ShowItemInfo(inventoryInfo);
            std::cout<<"Be careful! If the item cannot be used," << std::endl;
            std::cout<<"the action will end without taking effect." << std::endl;
            std::cout<<"Input Item Number: ";
            std::cin >> itemNumber;
            if(reserchUse(inventory, itemNumber))
            {
                inventory[itemNumber - 1].SetCount(inventory[itemNumber - 1].GetCount() - 1); 
                if(inventory[itemNumber - 1].GetName() == "HpPotion")
                {
                    player.SetHp(std::min(player.GetHp() + 50, player.GetMaxHp()));
                }
                else if(inventory[itemNumber - 1].GetName() == "MpPotion")
                {
                    player.SetMp(std::min(player.GetMp() + 50, player.GetMaxMp()));
                }
                else
                {
                    std::cout<<"can't use this item"<< std::endl;
                }
            }
            break;
        default:
            std::cout<<"ERR Retry!";
            continue;
        }
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