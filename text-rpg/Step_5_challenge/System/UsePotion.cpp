#include "../include/System/UsePotion.h"


void DefaultHpEffect(Player& player, int Effect)
{

    player.SetHp(Effect);

}

void DefaultPowerEffect(Player& player, int Effect)
{

    player.SetPower(Effect);

}

void DefaultDefenceEffect(Player& player, int Effect)
{

    player.SetDefence(Effect);

}

void OnlyPlayerMpEffect(Player& player, int Effect)
{

    player.SetMp(Effect);

}