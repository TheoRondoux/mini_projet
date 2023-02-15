#include "Hero.h"

#include <iostream>
#include <string>

Hero::Hero(int vie, int defense, int degats, std::string arme, std::string nom):Personnage(vie, defense, degats, arme, nom){}

void Hero::lancerPouvoir()
{
    std::cout << "Hero Ability" << std::endl;
}

Hero::~Hero(){}