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

Monster generateMonster(int& orcCounter, int& goblinCounter) 
{   
    string races[] = {"Orc", "Goblin"};
    string armes[] = {"Hache", "Gourdin"};
    int degats[] = {8, 5};
    int index = rand() % (sizeof(races)/sizeof(races[0]));
    int tmpDefense;
    string name;
    if (races[index] == "Orc"){
        tmpDefense = rand() % (6-4+1)+4;
        name = races[index] + " " + to_string(orcCounter);
        orcCounter ++;
    }
    else if (races[index] == "Goblin"){
        tmpDefense = rand() % (4-2+1)+2;
        name = races[index] + " " + to_string(goblinCounter);
        goblinCounter ++;
    }
    return Monster(rand() % (20-10+1)+10, tmpDefense, degats[index], armes[index], name, races[index]);
}

Hero* createHero(int index)
{
    char classSelector = 'A';
    string name = "";
    cout << "\nPersonnage n°"+to_string(index+1)+":" << endl;
    while (classSelector != 'K' && classSelector != 'C' && classSelector != 'N')
    {
        cout << "Choisissez une classe parmi :\n   [K]night\n   [C]lerk\n   [N]inja\n-> ";
        cin >> classSelector;
    }
    cin.ignore();
    
    while (name == "")
    {
        cout << "\nChoisissez un nom pour votre personnage:\n-> ";
        getline(cin, name);
    }

    int weaponSelector = rand() % 2;
    switch (classSelector)
    {
        case 'K':
            return new Knight((classSelector == 0 ? "Hallebarde" : "Epee longue"), name);
        case 'C':
            return new Clerk((classSelector == 0 ? "Masse" : "Hache"), name);
        case 'N':
            return new Ninja("Sai", name);
    }

    return new Knight("", "");  
}

void heroAction(Hero *hero, int lapCounter, vector<Monster> &monsters)
{
    char action = 'Z';
    while (action != 'A' && action != 'D' && action != 'P')
    {
        if (lapCounter % 3 == 0){   
            cout << "Choissisez une action à réaliser pour " << hero->getName() << ":\n  [A]ttaquer\n  Se [D]efendre\n  Utiliser [P]ouvoir et Attaquer\n-> ";
        }
        else{
            cout << "Choissisez une action à réaliser pour " << hero->getName() << ":\n  [A]ttaquer\n  Se [D]efendre\n-> ";
        }
        cin >> action;
    }

    switch(action)
    {
        case 'A':
            hero->Attack(&monsters[(rand() % monsters.size())]);
            break;
        case 'D':
            hero->increaseDefense();
            break;
        case 'P':
            hero->lancerPouvoir();
            hero->Attack(&monsters[(rand() % monsters.size())]);
            break;
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    //Création des héros
    vector<Hero*> heros;
    for (int i = 0; i < 4; i++)
    {
        heros.push_back(createHero(i));
        
    }
    cin.ignore();

    //Création des monstres
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
    cin.ignore();
    while(!endGame)
    {
        cin.ignore();
        lapCounter++;
        vector<int> monstersToErase;
        vector<int> herosToErase;
        cout << "\n\n--- Tour " << lapCounter << " ---\n" << endl;

        for (Hero* hero : heros)
        {
            heroAction(hero, lapCounter, monsters);
        }

        for (Monster monster : monsters)
        {
            if (monster.getVie() > 0)
            {
                monster.Attack(heros[(rand() % heros.size())]);
            }
        }

        cout << "\n" << "--- Résumé du tour ---\n" << endl;
        for (int i = 0; i < heros.size(); i++)
        {
            if (heros[i]->getVie() > 0)
            {
                heros[i]->infos();
            }
            else
            {
                cout << heros[i]->getName() << " a été vaincu !" << endl;
                herosToErase.push_back(i);
            }
        }
        cout << "" << endl;
        for (int i = 0; i < monsters.size(); i++)
        {
            if (monsters[i].getVie() > 0)
            {
                monsters[i].infos();
            }
            else
            {
                cout << monsters[i].getName() << " a été vaincu !" << endl;
                monstersToErase.push_back(i);
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

        //On regarde si la partie est terminée ou non
        if(monsters.size() == 0 || heros.size() == 0)
        {
            endGame = true;
        }

        cout << "\nAppuyez sur Entrée pour continuer" << endl;
        cin.ignore();
    }
}