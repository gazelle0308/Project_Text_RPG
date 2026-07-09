#include "Player.h"

Player::Player(string name, int hp, int mp, int power, int defence, int level)
:name(name), hp(hp), mp(mp), power(power), defence(defence), level(level)
{}

void Player::printStatus()
{

    cout << "====================================================" << endl;
    cout << "Name: " << this->name << " Job: " << this->job << " Level: " << this->level << endl;
    cout << "HP: " << this->hp << " MP: " << this->mp << " Power: " << this->power << " Defence: " << this->defence << endl;
    cout << "====================================================" << endl;

}

string Player::GetName()
{
    
    return this->name;

}

string Player::GetJob()
{
    
    return this->job;

}

int Player::GetLevel()
{
    
    return this->level;

}

int Player::GetHp()
{
    
    return this->hp;

}

int Player::GetMp()
{
    
    return this->mp;

}

int Player::GetPower()
{
    
    return this->power;

}

int Player::GetDefence()
{
    
    return this->defence;

}

void Player::SetName(string name)
{
    
    this->name = name;

}

void Player::SetJob(string job)
{
    
    this->job = job;

}

void Player::SetLevel(int level)
{
    
    this->level = level;

}

void Player::SetHp(int hp)
{
    
    this->hp = hp;

}

void Player::SetMp(int mp)
{
    
    this->mp = mp;

}

void Player::SetPower(int power)
{
    
    this->power = power;

}

void Player::SetDefence(int defence)
{
    
    this->defence = defence;

}