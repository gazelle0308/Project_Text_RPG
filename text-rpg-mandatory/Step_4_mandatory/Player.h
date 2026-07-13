#pragma once

#include <iostream>
#include <string>

using namespace std;

class Player
{

public:

//virtual
    virtual void attack( Monster* monster ) = 0;
    virtual ~Player() {};

//Function
    void printStatus();

//Getter
    string GetName();
    string GetJob();

    int GetLevel();
    int GetHp();
    int GetMp();
    int GetPower();
    int GetDefence();

//Setter
    void SetName(string name);
    void SetJob(string job);
    
    void SetLevel(int level);
    void SetHp(int hp);
    void SetMp(int mp);
    void SetPower(int power);
    void SetDefence(int defence);

protected:  

    Player(string name, int level = 1, int hp = 50, int mp = 50, int power = 50, int defence = 50);

    string name;
    string job;

    int level;
    int hp;
    int mp;
    int power;
    int defence;

};
