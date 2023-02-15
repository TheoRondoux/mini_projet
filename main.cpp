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

Hero createHero(int index)
{
    char classSelector = 'A';
    string name = "";
    cout << "\nPersonnage n°"+to_string(index)+":" << endl;
    while (classSelector != 'K' && classSelector != 'C' && classSelector != 'N')
    {
        cout << "Choisissez une classe parmi :\n   [K]night\n   [C]lerk\n   [N]inja\n-> ";
        cin >> classSelector;
    }
    
    while (name == "")
    {
        cout << "\nChoisissez un nom pour votre personnage:\n-> ";
        cin >> name;
    }

    int weaponSelector = rand() % 1;
    switch (classSelector)
    {
        case 'K':
            return Knight((classSelector == 0 ? "Hallebarde" : "Epee longue"), name);
        case 'C':
            return Clerk((classSelector == 0 ? "Masse" : "Hache"), name);
        case 'N':
            return Ninja("Sai", name);
    }

    return Knight("", "");  
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    //Création des héros
    vector<Hero> heros;
    for (int i = 0; i < 1; i++)
    {
        heros.push_back(createHero(i));
    }

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
    cout << "Appuyez sur Entrée pour commerncer la partie" << endl;
    cin.ignore();
    while(!endGame)
    {
        lapCounter++;
        cout << "--- Tour " << lapCounter << " ---\n" << endl;
        for (Hero hero : heros)
        {
            char action = 'Z';
            while (action != 'A' && action != 'D' && action != 'P')
            {
                if (lapCounter % 3 == 0){   
                    cout << "Choissisez une action à réaliser pour " << hero.getName() << ":\n  [A]ttaquer\n   Se [D]efendre   \n  Utiliser [P]ouvoir\n-> ";
                }
                else{
                    cout << "Choissisez une action à réaliser pour " << hero.getName() << ":\n  [A]ttaquer\n   Se [D]efendre\n-> ";
                }
                cin >> action;
            }

            switch(action)
            {
                case 'A':
                    hero.Attack(&monsters[(rand() % monsters.size())]);
                    break;
                case 'D':
                    hero.increaseDefense();
                    break;
                case 'P':
                    break;
            }
        }

        for (int i = 0; i < monsters.size(); i++)
        {
            monsters[i].infos();
            if (monsters[i].getVie() <= 0)
            {
                monsters.erase(monsters.begin()+i);
            }
        }

        for (Hero hero : heros)
        {
            hero.resetDefense();
        }
        cout << "Appuyez sur Entrée pour continuer" << endl;
        cin.ignore();
        if(monsters.size() == 0 || heros.size() == 0)
        {
            endGame = true;
        }
    }
}