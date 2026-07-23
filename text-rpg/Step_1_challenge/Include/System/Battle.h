#pragma once

#include "../Common.h"
#include "../Constants.h"

#include "../Monster/Slime.h"
#include "../Monster/Mushroom.h"
#include "../Monster/MonsterBone.h"

#include "../Player/PlayerStatus.h"

#include "../Ui/Ui.h"

void BattleAssist(Player& player, Monster& monster);

void ExtractDropItem(const Monster& monster, std::string& itemName, int& price);

template<typename Attacker, typename Defender>
int Attack(Attacker& attacker, Defender& defender)
{

    int Damage = attacker.GetPower() - defender.GetDefence();
    
    int DamageCalc = Damage <= 0 ? defender.GetHp() - 1 : defender.GetHp() - Damage;

    defender.SetHp(DamageCalc); 
    return Damage <= 0 ? 1 : Damage;

}