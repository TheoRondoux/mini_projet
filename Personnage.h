#ifndef INCLUCE_PERSONNAGE_H
#define INCLUCE_PERSONNAGE_H

#include <iostream>
#include <string>

class Personnage
{
    protected:
    int vie;
    int defense;
    int degats;
    std::string arme;
    std::string nom;
    bool hasUsedCapactiy = false;
    bool hasDefend = false;

    public:
    Personnage(int vie, int defense, int degats, std::string arme, std::string nom);
    void Attack(Personnage *p);
    int getVie();
    void setVie(int newVie);
    int getDefense();
    void setDefense(int newDefense);
    int getDegats();
    void setDegats(int newDegats);
    std::string getName();
    std::string getArme();
    void infos();
    ~Personnage();
};

#endif