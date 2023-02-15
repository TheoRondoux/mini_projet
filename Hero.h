#ifndef INCLUDE_HERO_H
#define INCLUDE_HERO_H

#include <iostream>
#include <string>
#include "Personnage.h"

class Hero : public Personnage
{
    protected:
    bool hasUsedCapactiy = false;
    public:
    Hero(int vie, int defense, int degats, std::string arme, std::string nom);
    void Protect();
    virtual void lancerPouvoir();
    ~Hero();
};

#endif