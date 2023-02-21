# Heros VS Monsters
*Made by Théo Rondoux*

## About this project
The purpose of this project was to use the knowledge I obtained during my C++ lessons at Junia ISEN.

The subject was simple: create a little game, that can be played  in the console. This game consists of a fight between a group of 4 heros and 10 monsters.

## Rules of the game
As a hero, you can choose between three different classes. Each one has its specific characteristics:

### The knight:
- A strong character, ready for battle!

- He has between 50 and 70 HP, and wields a halbert or a longsword, both dealing 8 points of damage. His sturdy armor grants him 4 to 6 points of defense.

- His special ability ? He increase his damage by 5 points.

### The cleric:
- The mystic guy!

- He has between 40 and 60 HP, he wields either an axe or a mace, both dealing 6 points of damage. He has between 3 and 5 points of defense. 

- His ability ? Healing himself of 5 points while fighting.

### The Ninja
- Sneakiest charecter ever!

- He has between 30 and 40 HP. He loves to attack with a saï, dealing 5 points of damage. He has between 1 and 3 points of defense.

- His special ability ? He can attack another time with his other saï.

After having created 4 heros, the game can begin. Every turn, you can choose multiple options:
### Attack
It's very simple, the character attacks a random monster.

### Defend
When the character is defending himself, his points of defense increases by 75%. It only applies for the current turn.

### Use special ability
Every 3 turn, the character can use his ability. It is like a "bonus" for the current turn.

### When does the game ends ?
A game is done when all the monsters or all the heros are dead.


## How to play ?
1. Clone the repository or download as zip the project.

### In Windows
2. Install [Cygwin](https://www.cygwin.com/). In the setup, install the g++ and makefile dependencies.
3. In the directory of the game, run the command `make`
4. Launch the game using `./hero_vs_monsters.exe`

### In Linux
2. Install the gpp dependency
```bash
sudo apt install g++
```
3. In the game's directory, run the command `make`
4. Launch the game using `./hero_vs_monsters`

## Contact
Théo Rondoux: [@Linkedin](https://linkedin.com/in/theo-rondoux-948ba720a/)
