#ifndef INCLUDE_MONSTER_H
#define INCLUDE_MONSTER_H

#include <iostream>
#include <string>
#include "Personnage.h"

class Monster : public Personnage
{
    private:
    std::string race;
    public:
    Monster(int vie, int defense, int degats, std::string arme, std::string nom, std::string race);
    std::string getRace();
    ~Monster();
};

#endif