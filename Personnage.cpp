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
    this->tempDefense = defense;
    this->tempDegats = degats;
}

void Personnage::Attack(Personnage *p)
{
    if  (this->degats > p->defense){
        std::cout << "\n" << this->nom << " retire " << this->degats - p->defense << "HP à " << p->nom << "\n" << std::endl;
        p->vie -= this->degats - p->defense;
    }
    else
    {
        std::cout << "\n" << this->nom << " attaque " << p->nom << ". " << p->nom << " évite l'attaque !" << "\n" << std::endl;
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

void Personnage::increaseDefense()
{
    this->defense*=1.75;
}

void Personnage::resetValues()
{
    this->defense = this->tempDefense;
    this->degats = this->tempDegats;
}

void Personnage::infos()
{
    std::cout << this->nom << ": " << this->vie << " HP " << std::endl;
}


Personnage::~Personnage(){}