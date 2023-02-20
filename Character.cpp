#include "Character.h"
#include <iostream>
#include <string>

Character::Character(int hp, int defence, int damage, std::string weapon, std::string name)
{
    this->hp = hp;
    this->defence = defence;
    this->damage = damage;
    this->weapon = weapon;
    this->name = name;
    this->tempDefence = defence;
    this->tempDamage = damage;
    this->numberOfAttacks = 1;
}

//Le personnage attaque un autre personnage passé en paramètre
void Character::Attack(Character *p)
{
    for (int i = 0; i < this->numberOfAttacks; i++)         //Pour chaque attaque que possède le personnage
    {
        if  (this->damage > p->defence){                    //Si la cible n'a pas assez de point de défense
            std::cout << this->name << " retire " << this->damage - p->defence << "pv à " << p->name << std::endl;
            p->hp -= this->damage - p->defence;             //On lui retire des points de vie
        }
        else                                                //Sinon, la cible "évite" l'attaque
        {
            std::cout << this->name << " attaque " << p->name << ". " << p->name << " évite l'attaque !" << std::endl;
        }
    }
}

int Character::getHp()
{
    return this->hp;
}
void Character::setHp(int newHp)
{
    this->hp = newHp;
}
int Character::getDamage()
{
    return this->damage;
}
void Character::setDamage(int newDamage)
{
    this->damage = newDamage;
}
std::string Character::getName()
{
    return this->name;
}
std::string Character::getWeapon()
{
    return this->weapon;
}

void Character::increaseDefence()
{
    this->defence*=1.75;
}

void Character::resetValues()
{
    this->defence = this->tempDefence;
    this->damage = this->tempDamage;
    this->numberOfAttacks = 1;
}

void Character::displayInfo()
{
    std::cout << this->name << ": " << this->hp << " PV " << std::endl;
}

void Character::displayDescription()
{
    std::cout << "\n--- Résumé du personnage ---\n\n" << this->name << " (" << this->hp << " PV)\n   - Arme : " << this->weapon << "\n   - Dégats : " << this->damage << "\n   - Defense : " << this->defence << "\n\n----------------------------" << std::endl;
}


Character::~Character(){}