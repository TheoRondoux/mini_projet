#ifndef INCLUDE_CLERK_H
#define INCLUDE_CLERK_H

#include <iostream>
#include <string>
#include "Hero.h"

class Clerk : public Hero
{
    public:
    Clerk(std::string weapon, std::string name);
    virtual void useAbility();
    ~Clerk();
};

#endif