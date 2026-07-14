#include "SelectClass.h"

Player* SelectClass( string name, int stat[] )
{   

    int selectedClass;

    cout << "<Class Selection>" << endl;
    cout<< "1. Magician" << " 2. Warrior" << " 3. Archer" << " 4. Thief" << endl;
    cout << "Select your class: ";
    cin >> selectedClass;
    cout << "====================================================" << endl;
    cout << endl;

    switch (selectedClass)
    {
        case 1:
            cout << "*You have selected Magician!( mp+30 )" << endl;
            cout << "*Can uesd Fireball" << endl;
            cout << endl;
            return new Magician(name, stat[0], stat[1], stat[2], stat[3]);
            break;
        case 2:
            cout << "*You have selected Warrior!( defence+30 )" << endl;
            cout << "*Can uesd Slash" << endl;
            cout << endl;
            return new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
            break;
        case 3:
            cout << "*You have selected Archer!( hp+30 )" << endl;
            cout << "*Can uesd Shoot" << endl;
            cout << endl;
            return new Archer(name, stat[0], stat[1], stat[2], stat[3]);
            break;
        case 4:
            cout << "*You have selected Thief!( power+30 )" << endl;
            cout << "*Can uesd Dagger Throw" << endl;
            cout << endl;
            return new Thief(name, stat[0], stat[1], stat[2], stat[3]);
            break;
        default:
            cout << "Invalid class selection. Please try again." << endl;
            cout << "====================================================" << endl;
            cout << endl;
            return nullptr;
    }

}