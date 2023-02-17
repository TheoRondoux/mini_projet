#include <iostream>
#include <string>
#include "Monster.h"

Monster::Monster(int hp, int defence, int damage, std::string weapon, std::string name, std::string race):Character(hp, defence, damage, weapon, name)
{
    this->race = race;
}

std::string Monster::getRace()
{
    return this->race;
}

Monster::~Monster(){}