#include "Knight.h"

#include <iostream>
#include <string>

Knight::Knight(std::string arme, std::string nom) : Hero((rand() % (70-40+1)+40), (rand() % (6-4+1)+4), 8, arme, nom){}

void Knight::lancerPouvoir()
{
    this->degats +=5;
    std::cout << this->nom << " gagne 5 points de dégats pour le prochain tour" << std::endl; 
}

Knight::~Knight(){}