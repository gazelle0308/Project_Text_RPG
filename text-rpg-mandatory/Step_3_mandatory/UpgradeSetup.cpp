#include "UpgradeSetup.h"

bool UpgradeSetup(int InsertStat[])
{
    int choice;
    int HpUpPotion = 5;
    int MpUpPotion = 5;
    bool isGameStart = false;

    cout << "You have " << HpUpPotion << " HP Up potions left" << endl;
    cout << "You have " << MpUpPotion << " MP Up potions left" << endl;
    
    while (!isGameStart)
    {

        cout << "<You have a chance to upgrade your stats!>" << endl;
        cout << "====================================================" << endl;
        cout << "1.Use HP Up 20" << " 2.Use MP Up 20" << " 3.Attack x 2" << endl;
        cout << "4.Defense x 2" << " 5.Show Stats" << " 0.Start Game" << endl;
        cout << "====================================================" << endl;
        cout << "Please choose an option (0-5): ";
        cin >> choice;

        switch(choice)
        {

            case 0:
                isGameStart = true;
                cout << "Starting the game..." << endl;
                break;
            case 1:
                if (HpUpPotion > 0)
                {
                    InsertStat[0] += 20;
                    HpUpPotion--;
                    cout << "HP +20! Current HP: " << InsertStat[0] << endl;
                    cout << "You have " << HpUpPotion << " HP Up potions left." << endl;
                    break;
                }
                else
                {
                    cout << "You don't have any HP Up potions left!" << endl;
                    break;
                }
                break;
            case 2:
                if (MpUpPotion > 0)
                {
                    InsertStat[1] += 20;
                    MpUpPotion--;
                    cout << "MP +20! Current MP: " << InsertStat[1] << endl;
                    cout << "You have " << MpUpPotion << " MP Up potions left." << endl;
                    break;
                }
                else
                {
                    cout << "You don't have any MP Up potions left!" << endl;
                    break;
                }
                break;
            case 3:
                InsertStat[2] *= 2;
                break;
            case 4:
                InsertStat[3] *= 2;
                break;
            case 5:
                PrintStatus("Your character", InsertStat);
                break;
            default:
                cout << "Invalid choice. No stats were upgraded." << endl;
                break;
        }
    }
    return isGameStart;
}