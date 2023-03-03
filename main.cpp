#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "Knight.h"
#include "Cleric.h"
#include "Ninja.h"
#include "Monster.h"

#define NB_HEROES 4
#define NB_MONSTERS 10

using namespace std;

/*------------------------------------------------------------------------------------------------------*/

//Permet de générer aléatoirement un monstre
Monster generateMonster(int& orcCounter, int& goblinCounter) 
{   
    string races[] = {"Orc", "Goblin"};                         //Liste des différentes races
    string weapons[] = {"Hache", "Gourdin"};                    //Liste des armes possibles pour les monstres
    int damages[] = {8, 5};                                     //Degats possibles en fonction des armes
    int index = rand() % (sizeof(races)/sizeof(races[0]));      //Permet de choisir aléatoirement un index pour choisir la race, l'arme et les dégats
    int tmpDefence;
    string name;
    if (races[index] == "Orc"){                                 //Si c'est un orc,
        tmpDefence = rand() % (6-4+1)+4;                        //On génère aléatoirement un chiffre de défense entre 4 et 6
        name = races[index] + " " + to_string(orcCounter);      //Son nom est composé de sa race et d'un chiffre qui reprend le nombre total d'orcs créés    
        orcCounter ++;                                          //Incrémentation du compteur d'orc créés
    }
    else if (races[index] == "Goblin"){                         //Sinon, si c'est un Goblin, on effectue les memes actions que pour les orcs, mais avec des valeurs
        tmpDefence = rand() % (4-2+1)+2;                        //différentes
        name = races[index] + " " + to_string(goblinCounter);
        goblinCounter ++;
    }
    return Monster(rand() % (20-10+1)+10, tmpDefence, damages[index], weapons[index], name, races[index]);
}

//Permet de créer un héros
Hero* createHero(int index)
{
    char classSelector = 'A';                           //Caractère qui permettra de choisir la classe
    string name = "";
    cout << "\nPersonnage n°"+to_string(index+1)+":" << endl;
    while (classSelector != 'K' && classSelector != 'C' && classSelector != 'N')                //Tant que le caractère de classe ne correspond pas à l'une des 3 options
    {
        cout << "Choisissez une classe parmi :\n   [K]night\n   [C]leric\n   [N]inja\n-> ";      
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
            return new Knight((weaponSelector == 0 ? "Hallebarde" : "Epee longue"), name);          //Création d'un chevalier avec une arme aléatoire
        case 'C':
            return new Cleric((weaponSelector == 0 ? "Masse" : "Hache"), name);                      //Création d'un clerc avec une arme aléatoire
        case 'N':
            return new Ninja("Sai", name);                                                          //Création d'un ninja
    }

    return new Knight("", "");  //Return obligatoire pour que le programme compile
}

//Permet au héros de faire une action
void makeActionHero(Hero *hero, int lapCounter, vector<Monster> &monsters)
{
    char action = 'Z';
    while (action != 'A' && action != 'D' && action != 'P')     //Tant que l'action n'est pas dans les options possibles
    {
        if (lapCounter % 3 == 0){     //Si le numéro du tour est divisible par 3, on propose à l'utilisateur d'utiliser son pouvoir
            cout << "Choissisez une action à réaliser pour " << hero->getName() << " (" << hero->getHp() << " PV):\n  [A]ttaquer\n  Se [D]éfendre\n  Utiliser [P]ouvoir et Attaquer\n-> ";
        }
        else{
            cout << "Choissisez une action à réaliser pour " << hero->getName() << " (" << hero->getHp() << " PV):\n  [A]ttaquer\n  Se [D]éfendre\n-> ";
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
            hero->increaseDefence();                                    //Ou on défend
            break;
        case 'P':
            if (lapCounter % 3 == 0){                                   //Ou Si le numéro du tour est divisible par 3
                hero->useAbility();                                     //On utilise le pouvoir
            }
            else{
                cout << "Le pouvoir ne peut être lancé que tous les 3 tours, un attaque simple est lancée à la place..." << endl;
            }
            Monster &monsterToAttact = monsters[(rand() % monsters.size())];    //On choisit un monstre à attaquer
            hero->Attack(&monsterToAttact);                                     //Et on attaque
            break;
    }
    cout << "" << endl;
}

//Affiche une courte introduction
void displayIntroduction()
{
    //Titre
    cout << "\n/////////////////////////////////////////////\n//          Heros VS Monsters		   //\n/////////////////////////////////////////////" << endl;
    //Crédits
    cout << "Créé par: Théo Rondoux" << endl;
    //Description
    cout << "\nBienvenue dans 'Heros VS Monsters' !\n'Heros VS Monsters' est un petit jeu où " << NB_HEROES << " héros vont affronter un groupe de " << NB_MONSTERS << " monstres, au tour par tour." << endl;
    cout << "\nAide: \n   1 - Lorsque vous voyez une lettre entre crochets, vous devez entrer cette lettre pour choisir une option.\n   2 - Pour arrêter de jouer, appuyez sur CTRL+C à n'importe quel moment." << endl;
}

//Permet d'attendre que l'utilisateur appuie sur la touche "Entrée"
void waitForEnter(string message, bool useIgnore)
{
    cout << message << endl;
    if (useIgnore)
    {
        cin.ignore();
    }
}

int main(int argc, char *argv[])
{
    displayIntroduction();
    waitForEnter("\nAppuyez sur Entrée pour passer à la création des héros", true);

    srand(time(NULL));
    //Création des héros et de la liste où ils sont contenus
    vector<Hero*> heros;
    for (int i = 0; i < NB_HEROES; i++)
    {
        heros.push_back(createHero(i));
        heros[i]->displayDescription();
    }

    waitForEnter("\nAppuyez sur Entrée pour continuer", true);

    //Création des monstres et de la liste où ils sont contenus
    cout << "\nGénération des monstres, merci de patienter..." << endl;
    vector<Monster> monsters;
    int orcCounter = 1;
    int goblinCounter = 1;
    for (int i = 0; i < NB_MONSTERS; i++){
        Monster monster = generateMonster(orcCounter, goblinCounter);
        monsters.push_back(monster);
    }

    cout << "Monstres créés !" << endl;
    //Début de la partie
    int lapCounter = 0;
    bool endGame = false;
    waitForEnter("\nAppuyez sur Entrée pour commencer la partie", false);
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
            makeActionHero(hero, lapCounter, monsters);
        }
        //Chaque monstre va attaquer un héros au hasard
        for (Monster monster : monsters)
        {
            if (monster.getHp() > 0)
            {
                monster.Attack(heros[(rand() % heros.size())]);
            }
        }

        cout << "\n" << "--- Résumé du tour ---\n" << endl;
        for (int i = 0; i < heros.size(); i++)  //Affichage des infotmations des héros (soit ses PVs, soit s'il est vaincu)
        {
            if (heros[i]->getHp() > 0)
            {
                heros[i]->displayInfo();
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
            if (monsters[i].getHp() > 0)
            {
                monsters[i].displayInfo();
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

        //Réinitialisation des valeurs par défaut pour les héros
        for (Hero* hero : heros)
        {
            hero->resetValues();
        }

        //On regarde si l'une des listes est vide. Si oui, on termine la partie.
        if(monsters.size() == 0 || heros.size() == 0)
        {
            endGame = true;
        }

        if (!endGame)
        {
            waitForEnter("\nAppuyez sur Entrée pour passer au tour suivant", true);
        }
        else
        {
            waitForEnter("\nAppuyez sur Entrée pour terminer la partie", true);
        }
    }
    cin.ignore();
    
    //Affiche une phrase en fonction de l'issue de la partie
    if(monsters.size() == 0)
    {
        cout << "Les monstres ont été vaincus, les héros remportent la victoire !" << endl;
    }
    else
    {
        cout << "Les héros ont trépassé, les monstres remportent la victoire..." << endl;
    }
}