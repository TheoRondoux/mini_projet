#ifndef INCLUDE_CLERIC_H
#define INCLUDE_Cleric_H

#include <iostream>
#include <string>
#include "Hero.h"

class Cleric : public Hero
{
    public:
    Cleric(std::string weapon, std::string name);
    virtual void useAbility();
    ~Cleric();
};

#endif