#include <iostream>
#include <string>
#include "Clerk.h"

Clerk::Clerk(std::string arme, std::string nom) : Hero((rand() % (60-40+1)+40), (rand() % (5-3+1)+3), 6, arme, nom){}

void Clerk::lancerPouvoir()
{
    this->vie += 5;
    std::cout << this->nom << " a regagné des PVs" << std::endl;
}

Clerk::~Clerk(){}