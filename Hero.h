#ifndef INCLUDE_HERO_H
#define INCLUDE_HERO_H

#include <iostream>
#include <string>
#include "Personnage.h"

class Hero : public Personnage
{

    public:
    Hero(int vie, int defense, int degats, std::string arme, std::string nom);
    virtual void lancerPouvoir();
    ~Hero();
};

#endif