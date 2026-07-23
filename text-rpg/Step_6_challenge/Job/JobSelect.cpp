#include "../include/Job/JobSelect.h"

#include "../include/Ui/Ui.h"

Player* JobSelect(std::string name, int status[])
{   

    int UserSelected;

    StartLine();
    std::cout << "<Job Selection>" << std::endl;
    std::cout<< "1. Magician" << " 2. Warrior" << " 3. Archer" << " 4. Thief" << std::endl;
    std::cout << "Select your Job: ";
    std::cin >> UserSelected;
    CutLine();

    switch (UserSelected)
    {
        case 1:
            StartLine();
            std::cout << "*You have selected Magician!( mp+30 )" << std::endl;
            std::cout << "*Can uesd Fireball" << std::endl;
            CutLine();
            return new Magician(name, status[0], status[1], status[2], status[3]);
            break;
        case 2:
            StartLine();
            std::cout << "*You have selected Warrior!( defence+30 )" << std::endl;
            std::cout << "*Can uesd Slash" << std::endl;
            CutLine();
            return new Warrior(name, status[0], status[1], status[2], status[3]);
            break;
        case 3:
            StartLine();
            std::cout << "*You have selected Archer!( hp+30 )" << std::endl;
            std::cout << "*Can uesd Shoot" << std::endl;
            CutLine();
            return new Archer(name, status[0], status[1], status[2], status[3]);
            break;
        case 4:
            StartLine();
            std::cout << "*You have selected Thief!( power+30 )" << std::endl;
            std::cout << "*Can uesd Dagger Throw" << std::endl;
            CutLine();
            return new Thief(name, status[0], status[1], status[2], status[3]);
            break;
        default:
            StartLine();
            std::cout << "Invalid job selection. Please try again." << std::endl;
            CutLine();
            return nullptr;
    }
}