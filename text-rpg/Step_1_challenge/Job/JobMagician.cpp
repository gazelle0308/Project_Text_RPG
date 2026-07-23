#include "../include/Job/JobMagician.h"

Magician::Magician( std::string name, int hp, int mp, int power, int defence, int level, std::string skill)
:Player(name, hp, mp, power, defence, level, skill)
{ 
    
    this->job = "Magician"; 
    this->mp = mp + 30;

}