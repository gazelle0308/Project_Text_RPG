#include "CharacterSetup.h"

void SetupStatus(string& InsertName, int InsertStat[])
{

    cout << "=================================================" << endl;
    cout << "[Dungeon Escape RPG]" << endl;
    cout << "=================================================" << endl;
    cout << "Input your chracter name: ";
    getline(cin, InsertName);
    cout << "Input your character's HP and MP: ";
    cin >> InsertStat[0] >> InsertStat[1];
    cout << "Input your character's attack and defense: ";
    cin >> InsertStat[2] >> InsertStat[3];
    cout << "=================================================" << endl;
    //stat[0] = HP, stat[1] = MP, stat[2] = 공격력, stat[3] = 방어력
}
void PrintStatus(const string PrintName, const int PrintStat[])
{

    cout << "================================" << endl;
    cout << PrintName << "'s stats:" << endl;
    cout << "================================" << endl;
    cout << "HP : " << PrintStat[0] << " MP : " << PrintStat[1] << endl;
    cout << "Attack : " << PrintStat[2] << " Defense : " << PrintStat[3] << endl;
    cout << "================================" << endl;

}