#ifndef INCLUDE_NINJA_H
#define INCLUDE_NINJA_H

#include <iostream>
#include <string>
#include "Hero.h"

class Ninja : public Hero
{
    public:
    Ninja(std::string arme, std::string nom);
    virtual void lancerPouvoir();
    ~Ninja();
};

#endif 