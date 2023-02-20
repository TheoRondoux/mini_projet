#include <iostream>
#include <string>
#include "Clerk.h"

Clerk::Clerk(std::string weapon, std::string name) : Hero((rand() % (60-40+1)+40), (rand() % (5-3+1)+3), 6, weapon, name){}

//Lorsque le Clerc utilise son pouvoir, il regagne 5 PV
void Clerk::useAbility()
{
    this->hp += 5;
    std::cout << this->name << " a regagné 5 PVs" << std::endl;
}

Clerk::~Clerk(){}