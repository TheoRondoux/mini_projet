#include <iostream>
#include <string>
#include "Monster.h"

Monster::Monster(int vie, int defense, int degats, std::string arme, std::string nom, std::string race):Personnage(vie, defense, degats, arme, nom)
{
    this->race = race;
}

std::string Monster::getRace()
{
    return this->race;
}

Monster::~Monster(){}