#ifndef INCLUDE_KNIGHT_H
#define INCLUDE_KNIGHT_H

#include <istream>
#include <string>
#include "Hero.h"

class Knight : public Hero 
{
    public:
    Knight(std::string arme, std::string nom);
    virtual void lancerPouvoir();
    ~Knight();
};

#endif