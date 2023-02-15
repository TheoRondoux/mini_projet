#include <iostream>
#include <string>
#include "Ninja.h"

Ninja::Ninja(std::string arme, std::string nom) : Hero((rand() % (49-30+1)+30), (rand() % (3-1+1)+1), 5, arme, nom){}

void Ninja::lancerPouvoir(Personnage *p)
{
    std::cout << this->nom << " attaque une deuxième fois !" << std::endl;
}

Ninja::~Ninja(){}