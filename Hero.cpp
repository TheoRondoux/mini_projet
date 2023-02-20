#include "Hero.h"

#include <iostream>
#include <string>

Hero::Hero(int hp, int defence, int damage, std::string weapon, std::string name):Character(hp, defence, damage, weapon, name){}

//Fonction de base pour le pouvoir d'un héros
void Hero::useAbility()
{
    std::cout << "Hero Ability" << std::endl;
}

Hero::~Hero(){}