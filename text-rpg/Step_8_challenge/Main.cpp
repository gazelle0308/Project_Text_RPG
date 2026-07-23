#include "include/Item/Inventory.h"
#include "include/Item/AlchemyWorkshop.h"
#include "include/Item/Potion.h"

#include "include/Player/PlayerStatus.h"
#include "include/Job/JobSelect.h"

#include "Include/Monster/MonsterBone.h"
#include "Include/Monster/Mushroom.h"
#include "Include/Monster/Slime.h"
#include "Include/Monster/Goblin.h"
#include "Include/Monster/Kobold.h"
#include "Include/Monster/Orc.h"
#include "Include/Monster/Lizardman.h"
#include "Include/Monster/Nergigante.h"
#include "Include/Monster/Velkhana.h"

#include "Include/System/Dungeon.h"
#include "Include/System/Battle.h"

#include "Include/Ui/Ui.h"

int main()
{

    const int SIZE = 4;

    std::string name;

    int stat[SIZE] = {0};
    int HpPotion,MpPotion;
    int roomChoose;

    bool isGameStart = false;

    Inventory<Item> Inventory;

    AlchemyWorkShop alchemyWorkShop;

    std::vector<PotionRecipe> potionRecipe;

    std::vector<Room> roomData;
    Room roomOne;
    roomOne.SetClear(false);
    roomOne.SetRoomOpen(true);
    roomOne.SetRoomNum(1);
    Room roomTwo;
    roomTwo.SetClear(false);
    roomTwo.SetRoomOpen(false);
    roomTwo.SetRoomNum(2);
    Room roomThree;
    roomThree.SetClear(false);
    roomThree.SetRoomOpen(false);
    roomThree.SetRoomNum(3);
    Room roomBoss;
    roomBoss.SetClear(false);
    roomBoss.SetRoomOpen(false);
    roomBoss.SetRoomNum(4);

    roomData.push_back(std::move(roomOne));
    roomData.push_back(std::move(roomTwo));
    roomData.push_back(std::move(roomThree));
    roomData.push_back(std::move(roomBoss));

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
            while(true)
            {
                StartLine();
                std::cout << "[Dungeon Room]" << std::endl;
                StartLine();
                std::cout << "Room 1: Slime/Mushroom (Hp: 270~300, Attack: 5~7, Defence: 3~5) -> " << (roomData[0].GetClear()? "Clear":"Non Clear") << std::endl;
                std::cout << "Room 2: " << (!roomData[1].GetRoomOpen()? "Unlocked...":"Goblin/Kobold (Hp: 350~400, Attack: 30~45, Defence: 15~20)") << " -> " << (roomData[1].GetClear()? "Clear":"Non Clear") << std::endl;
                std::cout << "Room 3: " << (!roomData[2].GetRoomOpen()? "Unlocked...":"Orc/Lizardman (Hp: 370~400, Attack: 50~60, Defence: 15~25)") << " -> " << (roomData[2].GetClear()? "Clear":"Non Clear") << std::endl;
                std::cout << "Boss Room(4): " << (!roomData[3].GetRoomOpen()? "Unlocked...":"Nergigante/Velkana (Hp: 450~550, Attack: 70~75, Defence: 45~50)") << std::endl;
                StartLine();
                std::cout << "choose Enter room: ";
                std::cin >> roomChoose;
                CutLine();
                if(roomData[roomChoose - 1].GetRoomOpen()){ break; }
                std::cout << "Can't Insert Room/Not Enough Room" << std::endl;
            }

            switch (roomChoose)
            {
            case 1:
                if( rand() % 2 == 0 ) { roomData[roomChoose - 1].SetEntity(std::make_unique<Mushroom>()); }
                else { roomData[roomChoose - 1].SetEntity(std::make_unique<Slime>()); }
                break;
            
            case 2:
                if( rand() % 2 == 0 ) { roomData[roomChoose - 1].SetEntity(std::make_unique<Goblin>()); }
                else { roomData[roomChoose - 1].SetEntity(std::make_unique<Kobold>()); }
                break;

            case 3:
                if( rand() % 2 == 0 ) { roomData[roomChoose - 1].SetEntity(std::make_unique<Orc>()); }
                else { roomData[roomChoose - 1].SetEntity(std::make_unique<Lizardman>()); }
                break;

            case 4:
                if( rand() % 2 == 0 ) { roomData[roomChoose - 1].SetEntity(std::make_unique<Nergigante>()); }
                else { roomData[roomChoose - 1].SetEntity(std::make_unique<Velkhana>()); }
                break;

            default:
                break;

            }



            //아이템 정보 버퍼
            std::string dropName = "";
            int dropPrice = 0;

            BattleAssist(*player, roomData[roomChoose - 1].GetEntity(), Inventory);

            if(player->GetHp() <= 0)
            {
                StartLine();
                std::cout << "You Died" << std::endl;
                std::cout << "Game Over!" << std::endl;
                CutLine();
                break;
            }
            if(roomChoose == 4)
            {
                StartLine();
                std::cout << "Boss Clear!" << std::endl;
                std::cout << "Game Win!" << std::endl;
                CutLine();
                break;
            }
            else
            { 
                roomData[roomChoose - 1].SetClear(true); 
                roomData[roomChoose].SetRoomOpen(true); 
            }

            //전투 진행 및 처치 시 아이템 등록
            ExtractDropItem( roomData[roomChoose - 1].GetEntity(), dropName, dropPrice );
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
