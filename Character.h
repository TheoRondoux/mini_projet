#ifndef INCLUCE_CHARACTER_H
#define INCLUCE_CHARACTER_H

#include <iostream>
#include <string>

class Character
{
    protected:
    int hp;
    int defence;
    int damage;
    std::string weapon;
    std::string name;
    bool hasDefend = false;
    int tempDefence;
    int tempDamage;
    int numberOfAttacks;

    public:
    Character(int hp, int defence, int damage, std::string weapon, std::string name);
    void Attack(Character *p);
    int getHp();
    void setHp(int newHp);
    int getDefence();
    void setDefence(int newDefence);
    int getDamage();
    void setDamage(int newDamage);
    std::string getName();
    std::string getWeapon();
    void setHasDefend();
    bool getHasDefend();
    void resetValues();
    void increaseDefence();
    void info();
    ~Character();
};

#endif