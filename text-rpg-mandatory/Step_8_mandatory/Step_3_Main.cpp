#include "../Step_1_mandatory/CharacterSetup.h"
#include "../Step_2_mandatory/SetupCheck.h"
#include "../Step_3_mandatory/UpgradeSetup.h"

int main()
{

    const int SIZE = 4;

    string name;

    int stat[SIZE] = {0};

    bool isGameStart = false;

    SetupStatus(name, stat);
    SetupCheck(stat);
    isGameStart = UpgradeSetup(stat);
    PrintStatus(name, stat);

    return 0;

}
