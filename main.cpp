#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "Knight.h"
#include "Clerk.h"
#include "Ninja.h"
#include "Monster.h"

using namespace std;

/*------------------------------------------------------------------------------------------------------*/

//Permet de générer aléatoirement un monstre
Monster generateMonster(int& orcCounter, int& goblinCounter) 
{   
    string races[] = {"Orc", "Goblin"};                         //Liste des différentes races
    string armes[] = {"Hache", "Gourdin"};                      //Liste des armes possibles pour les monstres
    int degats[] = {8, 5};                                      //Degats possibles en fonction des armes
    int index = rand() % (sizeof(races)/sizeof(races[0]));      //Permet de choisir aléatoirement un index pour choisir la race, l'arme et les dégats
    int tmpDefense;
    string name;
    if (races[index] == "Orc"){                                 //Si c'est un orc,
        tmpDefense = rand() % (6-4+1)+4;                        //On génère aléatoirement un chiffre de défense entre 4 et 6
        name = races[index] + " " + to_string(orcCounter);      //Son nom est composé de sa race et d'un chiffre qui reprend le nombre total d'orcs créés    
        orcCounter ++;                                          //Incrémentation du compteur d'orc créés
    }
    else if (races[index] == "Goblin"){                         //Sinon, si c'est un Goblin, on effectue les memes actions que pour les orcs, mais avec des valeurs
        tmpDefense = rand() % (4-2+1)+2;                        //différentes
        name = races[index] + " " + to_string(goblinCounter);
        goblinCounter ++;
    }
    return Monster(rand() % (20-10+1)+10, tmpDefense, degats[index], armes[index], name, races[index]);
}

//Permet de créer un héros
Hero* createHero(int index)
{
    char classSelector = 'A';                           //Caractère qui permettra de choisir la classe
    string name = "";
    cout << "\nPersonnage n°"+to_string(index+1)+":" << endl;
    while (classSelector != 'K' && classSelector != 'C' && classSelector != 'N')                //Tant que le caractère de classe ne correspond pas à l'une des 3 options
    {
        cout << "Choisissez une classe parmi :\n   [K]night\n   [C]lerk\n   [N]inja\n-> ";      
        cin >> classSelector;                           //Demande à l'utilisateur d'entrer un caractère
    }
    cin.ignore();
    
    while (name == "")                      //Tant que le nom du héros ne contient pas de caractère
    {
        cout << "\nChoisissez un nom pour votre personnage:\n-> ";
        getline(cin, name);                 //Demande à l'utilisateur d'entrer un nom
    }

    int weaponSelector = rand() % 2;        //Génération d'un nombre aléatoire pour sélectionner une arme (si le héros peut choisir une arme)
    switch (classSelector)                  //En fonction de la classe choisie, génère le bon type de héros
    {
        case 'K':
            return new Knight((weaponSelector == 0 ? "Hallebarde" : "Epee longue"), name);
        case 'C':
            return new Clerk((weaponSelector == 0 ? "Masse" : "Hache"), name);
        case 'N':
            return new Ninja("Sai", name);
    }

    return new Knight("", "");  
}

//Permet au héros de faire une action
void heroAction(Hero *hero, int lapCounter, vector<Monster> &monsters)
{
    char action = 'Z';
    while (action != 'A' && action != 'D' && action != 'P')     //Tant que l'action n'est pas dans les options possibles
    {
        if (lapCounter % 3 == 0){     //Si le numéro du tour est divisible par 3, on propose à l'utilisateur d'utiliser son pouvoir
            cout << "Choissisez une action à réaliser pour " << hero->getName() << ":\n  [A]ttaquer\n  Se [D]efendre\n  Utiliser [P]ouvoir et Attaquer\n-> ";
        }
        else{
            cout << "Choissisez une action à réaliser pour " << hero->getName() << ":\n  [A]ttaquer\n  Se [D]efendre\n-> ";
        }
        cin >> action;      //On demande à l'utilisateur de saisir un caractère
    }
    cout << "" << endl;
    switch(action)          //En fonction de l'action choisie
    {
        case 'A':
            hero->Attack(&monsters[(rand() % monsters.size())]);        //On attaque un monstre aléatoire dans la liste
            break;
        case 'D':
            hero->increaseDefense();                                    //Ou on défend
            break;
        case 'P':
            if (lapCounter % 3 == 0){                                   //Ou Si le numéro du tour est divisible par 3
                hero->lancerPouvoir();                                  //On utilise le pouvoir
            }
            else{
                cout << "Le pouvoir ne peut être lancé que tous les 3 tours, un attaque simple est lancée à la place..." << endl;
            }
            hero->Attack(&monsters[(rand() % monsters.size())]);        //Et on attaque
            break;
    }
    cout << "" << endl;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    //Création des héros et de la liste où ils sont contenus
    vector<Hero*> heros;
    for (int i = 0; i < 4; i++)
    {
        heros.push_back(createHero(i));
    }
    
    //Création des monstres et de la liste où ils sont contenus
    vector<Monster> monsters;
    int orcCounter = 1;
    int goblinCounter = 1;
    for (int i = 0; i < 10; i++){
        Monster monster = generateMonster(orcCounter, goblinCounter);
        monsters.push_back(monster);
    }

    //Début de la partie
    int lapCounter = 0;
    bool endGame = false;
    char enter;
    cout << "\nAppuyez sur Entrée pour commerncer la partie" << endl;
    while(!endGame)
    {
        cin.ignore();
        lapCounter++;
        vector<int> monstersToErase;
        vector<int> herosToErase;
        cout << "\n\n--- Tour " << lapCounter << " ---\n" << endl;

        //Pour tous les héros, on leur fait éxécuter une action
        for (Hero* hero : heros)
        {
            heroAction(hero, lapCounter, monsters);
        }
        //Chaque monstre va attaquer un héros au hasard
        for (Monster monster : monsters)
        {
            if (monster.getVie() > 0)
            {
                monster.Attack(heros[(rand() % heros.size())]);
            }
        }

        cout << "\n" << "--- Résumé du tour ---\n" << endl;
        for (int i = 0; i < heros.size(); i++)  //Affichage des infotmations des héros (soit ses PVs, soit s'il est vaincu)
        {
            if (heros[i]->getVie() > 0)
            {
                heros[i]->infos();
            }
            else
            {
                cout << heros[i]->getName() << " a été vaincu !" << endl;
                herosToErase.push_back(i);                                      //Si le héros est mort, on ajoute son index dans une liste
            }
        }
        cout << "" << endl;
        for (int i = 0; i < monsters.size(); i++)   //Affichage des informations des monstres (comme les héros)
        {
            if (monsters[i].getVie() > 0)
            {
                monsters[i].infos();
            }
            else
            {
                cout << monsters[i].getName() << " a été vaincu !" << endl;
                monstersToErase.push_back(i);                                   //Si le monstre est mort, on ajoute son index dans une liste
            }
        }

        //Suppression des monstres vaincus
        for (int index : monstersToErase)
        {
            monsters.erase(monsters.begin()+index);
        }
        //Suppression des héros vaincus
        for (int index : herosToErase)
        {
            heros.erase(heros.begin()+index);
        }

        //Réinitialisation de la défense de tous les héros
        for (Hero* hero : heros)
        {
            hero->resetValues();
        }

        //On regarde si l'une des listes est vide. Si oui, on termine la partie.
        if(monsters.size() == 0 || heros.size() == 0)
        {
            endGame = true;
        }

        cout << "\nAppuyez sur Entrée pour continuer" << endl;
        cin.ignore();
    }
    cin.ignore();
    
    if(monsters.size() == 0)
    {
        cout << "Les héros remportent la victoire !" << endl;
    }
    else
    {
        cout << "Les monstres remportent la victoire..." << endl;
    }
}