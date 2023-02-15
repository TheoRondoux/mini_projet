#ifndef INCLUDE_CLERK_H
#define INCLUDE_CLERK_H

#include <iostream>
#include <string>
#include "Hero.h"

class Clerk : public Hero
{
    public:
    Clerk(std::string arme, std::string nom);
    virtual void lancerPouvoir();
    ~Clerk();
};

#endif