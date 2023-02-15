#include "Personnage.h"
#include <iostream>
#include <string>

Personnage::Personnage(int vie, int defense, int degats, std::string arme, std::string nom)
{
    this->vie = vie;
    this->defense = defense;
    this->degats = degats;
    this->arme = arme;
    this->nom = nom;
}

void Personnage::Attack(Personnage *p)
{
    if  (this->degats > p->defense){
        p->vie -= this->degats - p->defense;
    }
    else
    {
        std::cout << "L'ennemi a réussi à se défendre" << std::endl;
    }
}

int Personnage::getVie()
{
    return this->vie;
}
void Personnage::setVie(int newVie)
{
    this->vie = newVie;
}
int Personnage::getDefense()
{
    return this->defense;
}
void Personnage::setDefense(int newDefense)
{
    this->defense = newDefense;
}
int Personnage::getDegats()
{
    return this->degats;
}
void Personnage::setDegats(int newDegats)
{
    this->degats = newDegats;
}
std::string Personnage::getName()
{
    return this->nom;
}
std::string Personnage::getArme()
{
    return this->arme;
}

void Personnage::infos()
{
    std::cout << this->nom << ", " << this->arme << ": " << this->vie << " HP " << this->degats << " points de degats " << this->defense << " points de defense." << std::endl;
}


Personnage::~Personnage(){}