#include <iostream>
#include <string>
#include "Ninja.h"

Ninja::Ninja(std::string weapon, std::string name) : Hero((rand() % (40-30+1)+30), (rand() % (3-1+1)+1), 5, weapon, name){}

//Lorsqu'un ninja utilise son pouvoir, il peut attaquer deux fois
void Ninja::useAbility()
{   
    this->numberOfAttacks = 2;
    std::cout << this->name << " va attaquer deux fois !" << std::endl;
}

Ninja::~Ninja(){}