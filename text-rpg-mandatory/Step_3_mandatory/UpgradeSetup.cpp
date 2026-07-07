#include "UpgradeSetup.h"

bool UpgradeSetup(int InsertStat[])
{
    int choice;
    int HpUpPotion = 5;
    int MpUpPotion = 5;
    
    while (true)
    {

        cout << "You have " << HpUpPotion << " HP Up potions left" << endl;
        cout << "You have " << MpUpPotion << " MP Up potions left" << endl;
        cout << "<You have a chance to upgrade your stats!>" << endl;
        cout << "====================================================" << endl;
        cout << "1.Use HP Up 20" << "2.Use MP Up 20" << "3.Attack x 2" << endl;
        cout << "4.Defense x 2" << "5.Show Stats" << "0.Start Game" << endl;
        cout << "Please choose an option (0-5): ";
        cout << "====================================================" << endl;
        cin >> choice;

        switch(choice)
        {

            case 0:
                return true;
            case 1:
                if (HpUpPotion > 0)
                {
                    InsertStat[0] += 20;
                    HpUpPotion--;
                }
                else
                {
                    cout << "You don't have any HP Up potions left!" << endl;
                }
                break;
            case 2:
                if (MpUpPotion > 0)
                {
                    InsertStat[1] += 20;
                    MpUpPotion--;
                }
                else
                {
                    cout << "You don't have any MP Up potions left!" << endl;
                }
                break;
            case 3:
                InsertStat[2] *= 2;
                break;
            case 4:
                InsertStat[3] *= 2;
                break;
            case 5:
                cout << "====================================================" << endl;
                cout << "Current stats:" << endl;
                cout << "HP: " << InsertStat[0] << "MP: " << InsertStat[1] << endl;
                cout << "Attack: " << InsertStat[2] << "Defense: " << InsertStat[3] << endl;
                cout << "====================================================" << endl;
                break;
            default:
                cout << "Invalid choice. No stats were upgraded." << endl;
                break;

        }
    }
}