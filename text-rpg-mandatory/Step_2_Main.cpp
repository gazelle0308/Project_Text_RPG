#include "Step_1_mandatory/CharacterSetup.h"
#include "Step_2_mandatory/SetupCheck.h"

int main()
{

    const int SIZE = 4;

    string name;
    int stat[SIZE] = {0};

    SetupStatus(name, stat);
    SetupCheck(stat);
    PrintStatus(name, stat);

    return 0;

}
