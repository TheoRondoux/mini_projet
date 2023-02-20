#include "Knight.h"

#include <iostream>
#include <string>

Knight::Knight(std::string weapon, std::string name) : Hero((rand() % (70-50+1)+50), (rand() % (6-4+1)+4), 8, weapon, name){}

//Lorsqu'un chevalier utilise son pouvoir, il gagne 5 points de dégats
void Knight::useAbility()
{
    this->damage +=5;
    std::cout << this->name << " gagne 5 points de dégats pour ce tour." << std::endl; 
}

Knight::~Knight(){}