#include "SetupCheck.h"

void SetupCheck(int InsertStat[])
{
    
    while(true)
    {
        
        if(InsertStat[0] < 50 || InsertStat[1] < 50)
        {

            cout << "HP and MP must be at least 50" << endl << "Please re-enter your character's stats: ";
            cin >> InsertStat[0] >> InsertStat[1];
            cout << "=================================================" << endl;
            continue;
        }
        else if(InsertStat[2] < 50 || InsertStat[3] < 50)
        {
            cout << "Attack and Defense must be at least 50" << endl << "Please re-enter your character's stats: ";
            cin >> InsertStat[2] >> InsertStat[3];
            cout << "=================================================" << endl;
            continue;
        }
        else
        {

            break;

        }

    }

}