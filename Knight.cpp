#include "Knight.h"

#include <iostream>
#include <string>

Knight::Knight(std::string weapon, std::string name) : Hero((rand() % (70-50+1)+50), (rand() % (6-4+1)+4), 8, weapon, name){}

void Knight::useAbility()
{
    this->damage +=5;
    std::cout << this->name << " gagne 5 points de dégats pour ce tour." << std::endl; 
}

Knight::~Knight(){}