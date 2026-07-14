#include "Ui.h"

int printUi()
{

    int answer;
    
    cout << "=================================================" << endl;
    cout << "[Dungeon Escape RPG]" << endl;
    cout << "=================================================" << endl;
    cout << "1.Enter Dungeon" << endl;
    cout << "2.Check Inventory" << endl;
    cout << "3.Alchemy Workshop" << endl;
    cout << "4.Quit" << endl;
    cout << "=================================================" << endl;
    cout << "choose: ";
    cin >> answer;
    cout << "=================================================" << endl;
    cout << endl;

    return answer;

}