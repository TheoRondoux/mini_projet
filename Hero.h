#ifndef INCLUDE_HERO_H
#define INCLUDE_HERO_H

#include <iostream>
#include <string>
#include "Character.h"

class Hero : public Character
{
    protected:
    bool hasUsedCapactiy = false;
    public:
    Hero(int hp, int defence, int damage, std::string weapon, std::string name);
    void Protect();
    virtual void useAbility();
    ~Hero();
};

#endif