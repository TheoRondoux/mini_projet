#ifndef INCLUDE_MONSTER_H
#define INCLUDE_MONSTER_H

#include <iostream>
#include <string>
#include "Character.h"

class Monster : public Character
{
    private:
    std::string race;
    public:
    Monster(int hp, int defence, int damage, std::string weapon, std::string name, std::string race);
    std::string getRace();
    ~Monster();
};

#endif