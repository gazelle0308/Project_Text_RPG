#include "../include/Player/PlayerStatus.h"

#include "../include/Monster/MonsterBone.h"

#include "../include/Ui/Ui.h"

//Getter
int Player::GetLevel() const{ return this->level; }
int Player::GetExp() const{ return this->exp; }
int Player::GetMaxExp() const{ return this->maxExp; }


int Player::GetHp() const{ return this->hp; }
int Player::GetMp() const{ return this->mp; }
int Player::GetPower() const{ return this->power; }
int Player::GetDefence() const{ return this->defence; }

std::string Player::GetName() const{ return this->name;}
std::string Player::GetJob() const{ return this->job; }

std::string Player::GetSkill() const{ return this->skill; }

void Player::GetGroupStatus(int (&status)[4]) // 위치 임의 지정 0 = hp, 1 = mp, 2 = power, 3 = defence
{

    status[0] = this->hp;
    status[1] = this->mp;
    status[2] = this->power;
    status[3] = this->defence;

}

//Setter
void Player::SetLevel(int level){ this->level = level; }
void Player::SetExp(int exp){ this->exp = exp; }
void Player::SetMaxExp(int maxExp){ this->maxExp = maxExp; }


void Player::SetHp(int hp){ this->hp = hp; }
void Player::SetMp(int mp){ this->mp = mp; }
void Player::SetPower(int power){ this->power = power; }
void Player::SetDefence(int defence){ this->defence = defence; }

void Player::SetName(std::string name){ this->name = name; }
void Player::SetJob(std::string job){ this->job = job; }

void Player::SetSkill(std::string skill){ this->skill = skill; }

//Function

void Player::LevelUpPlayer()
{

    const int SIZE = 4;


    int before = this->level;
    int beforeStatus[SIZE] = {};


    int after;
    int afterStatus[SIZE] = {};


    int changeStatus[SIZE] = {};

    this->GetGroupStatus(beforeStatus);// 0 = hp, 1 = mp, 2 = power, 3 = defence

    while(this->exp >= this->maxExp)
    {

        this->level = this->level + 1;
        this->exp = this->exp - this->maxExp;
        this->maxExp = 100 + (level - 1) * 40;
        this->hp = this->hp + 10 * (level - 1);
        this->mp = this->mp + 10 * (level - 1);
        this->power = this->power + 5 * (level - 1);
        this->defence = this->defence + 5 * (level - 1);

    }

    after = this->level;
    this->GetGroupStatus(afterStatus);// 0 = hp, 1 = mp, 2 = power, 3 = defence


    for(int loop = 0; loop < SIZE; loop = loop + 1){ changeStatus[loop] = afterStatus[loop] - beforeStatus[loop]; }
    LevelUpMsg(before, after, changeStatus);

}

void Player::HuntRewardExp(int exp)
{

    this->exp = this->exp + exp;
    PrintGetExp(*this, exp);
    if(this->exp >= this->maxExp){ LevelUpPlayer(); }

}

//Constructor
Player::Player(std::string name, int hp, int mp, int power, int defence, int level, std::string skill)
:name(name), hp(hp), mp(mp), power(power), defence(defence), level(level), skill(skill)
{
    if(this->job == ""){ this->job = "Adventure"; } 
    this->maxExp = 100; 
    this->exp = 0;
}

void SetupStatus(std::string& Name, int Status[])
{

    MainTitle();
    std::cout << "Input your chracter name: ";
    getline(std::cin, Name);
    std::cout << "Input your character's HP and MP: ";
    std::cin >> Status[0] >> Status[1];
    std::cout << "Input your character's attack and defense: ";
    std::cin >> Status[2] >> Status[3];
    CutLine();
    //stat[0] = HP, stat[1] = MP, stat[2] = 공격력, stat[3] = 방어력

}


void CheckStatus(int Status[])
{
    
    while(true)
    {
        
        if(IsOutRange(Status[0], 50, 100) || IsOutRange(Status[1], 50, 100))
        {

            std::cout << "HP and MP must be at least 50 " << std::endl;
            std::cout << "Please re-enter your character's stats: ";
            std::cin >> Status[0] >> Status[1];
            CutLine();
            continue;

        }
        else if(IsOutRange(Status[2], 20, 40) || IsOutRange(Status[3], 20, 40))
        {

            std::cout << "Attack and Defense must be at least 20" << std::endl << "Please re-enter your character's stats: ";
            std::cin >> Status[2] >> Status[3];
            CutLine();
            continue;

        }
        else
        {

            break;

        }

    }

}

bool UpgradeStatus(Player& player, std::vector<Item>& item)
{
    int choice;
    bool isGameStart = false;
    Item* HpPotion = nullptr;
    Item* MpPotion = nullptr;

    for(auto loop = item.begin(); loop != item.end(); ++loop)
    {

        if(loop->GetName() == "HpPotion")
        {

            HpPotion = &(*loop);

        }
        else if(loop->GetName() == "MpPotion")
        {
            
            MpPotion = &(*loop);

        }

    }

    std::cout << "You have " << HpPotion->GetCount() << " HP Up potions left" << std::endl;
    std::cout << "You have " << MpPotion->GetCount() << " MP Up potions left" << std::endl;
    
    while (!isGameStart)
    {

        std::cout << "<You have a chance to upgrade your stats!>" << std::endl;
        StartLine();
        std::cout << "1.Use HP Up 20" << " 2.Use MP Up 20" << " 3.Power x 2" << std::endl;
        std::cout << "4.Defense x 2" << " 5.Show Stats" << " 0.Start Game" << std::endl;
        StartLine();
        std::cout << "Please choose an option (0-5): ";
        std::cin >> choice;
        CutLine();

        switch(choice)
        {

            case 0:
                isGameStart = true;
                StartLine();
                std::cout << "Starting the game..." << std::endl;
                break;
            case 1:
                if (HpPotion->GetCount() > 0)
                {
                    player.SetHp(player.GetHp() + 20);
                    HpPotion->SetCount(HpPotion->GetCount() - 1);
                    StartLine();
                    std::cout << "HP +20! Current HP: " << player.GetHp() << std::endl;
                    std::cout << "You have " << HpPotion->GetCount() << " HP Up potions left." << std::endl;
                    CutLine();
                    break;
                }
                else
                {
                    StartLine();
                    std::cout << "You don't have any HP Up potions left!" << std::endl;
                    CutLine();
                    break;
                }
                break;
            case 2:
                if (MpPotion->GetCount() > 0)
                {
                    player.SetMp(player.GetMp() + 20);
                    MpPotion->SetCount(MpPotion->GetCount() - 1);
                    StartLine();
                    std::cout << "MP +20! Current MP: " << player.GetMp() << std::endl;
                    std::cout << "You have " << MpPotion->GetCount() << " MP Up potions left." << std::endl;
                    CutLine();
                    break;
                }
                else
                {
                    StartLine();
                    std::cout << "You don't have any MP Up potions left!" << std::endl;
                    CutLine();
                    break;
                }
                break;
            case 3:
                player.SetPower(player.GetPower() * 2);
                StartLine();
                std::cout << "Power x 2! Current Power: " << player.GetPower() << std::endl;
                CutLine();
                break;
            case 4:
                player.SetDefence(player.GetDefence() * 2);
                StartLine();
                std::cout << "Defense x 2! Current Defense: " << player.GetDefence() << std::endl;
                CutLine();
                break;
            case 5:
                ViewStatus(player);
                break;
            default:
                StartLine();
                std::cout << "Invalid choice. No stats were upgraded." << std::endl;
                CutLine();
                break;
        }
    }
    return isGameStart;
}

bool IsOutRange(int value, int min, int max)
{
    return value < min || value > max;
}