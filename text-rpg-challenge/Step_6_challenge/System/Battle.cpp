#include "../include/System/Battle.h"

void BattleAssist(Player& player, Monster& monster, Inventory<Item>& inventory){
    
    int DamageView = 0;
    std::string inventoryInfo = ItemInfo(inventory);

    std::cout<< "< Battle Begin! >" << std::endl;
    std::cout<< player.GetName() << "(" << player.GetJob() << ")" << " vs " << monster.GetName() << std::endl;
    CutLine();

    while( player.GetHp() > 0 && monster.GetHp() > 0 )
    {
        int action;
        int itemNumber;
        int changeStatus;

        StartLine();
        std::cout<<"---Now Player Turn---"<< std::endl;
        std::cout<<"1.Attack 2.Use Item" << std::endl;
        std::cout<<"Input Your action: ";
        std::cin >> action;
        CutLine();

        switch (action)
        {
        case 1:
            StartLine();
            player.attack(&monster);
            CutLine();
            break;
        
        case 2:
            ShowItemInfo(inventoryInfo);
            std::cout<<"Be careful! If the item cannot be used," << std::endl;
            std::cout<<"the action will end without taking effect." << std::endl;
            std::cout<<"Input Item Number: ";
            std::cin >> itemNumber;
            CutLine();

            StartLine();
            if(reserchUse(inventory, itemNumber))
            {
                inventory[itemNumber - 1].SetCount(inventory[itemNumber - 1].GetCount() - 1); 
                if(inventory[itemNumber - 1].GetName() == "HpPotion")
                {
                    changeStatus = player.GetHp();
                    std::cout<<"Before Hp: " << player.GetHp() << " -> ";
                    player.SetHp(std::min(player.GetHp() + 50, player.GetMaxHp()));
                    std::cout<<"After Hp: " << player.GetHp() << std::endl;
                    changeStatus = player.GetHp() - changeStatus;
                    std::cout<<"Use HpPotion!"<< std::endl;
                    std::cout<<"Heal Hp: " << changeStatus << std::endl;
                }
                else if(inventory[itemNumber - 1].GetName() == "MpPotion")
                {
                    changeStatus = player.GetMp();
                    std::cout<<"Before Hp: " << player.GetMp() << "-> ";
                    player.SetMp(std::min(player.GetMp() + 50, player.GetMaxMp()));
                    std::cout<<"After Hp: " << player.GetMp() << std::endl;
                    changeStatus = player.GetMp() - changeStatus;
                    std::cout<<"Use MpPotion!"<< std::endl;
                    std::cout<<"Heal Mp: " << changeStatus << std::endl;
                }
            }
            else{ std::cout<<"can't use this item"<< std::endl; }
            CutLine();
            break;
        default:
            std::cout<<"ERR Input Retry!" << std::endl;
            continue;
        }

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