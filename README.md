# Engg-1340-Project
## Team Members
- Matthew Dylan Widjaya 3035667144
- Reynard Verill Buntoro 3035663461
## Game Description and Rules

### Description
We are planning to make a RPG (Role Playing Game) which will have items in the game. We propose that the game will have a story and will end once the user has defeated the final boss in the game. Apart from that, we also would like to suggest the implementation of word arts in the battles (to introduce player and enemy) to make the game more appealing for the audience. The scheme for the game is taking actions until the user is able to beat the final boss in the by choosing final in the menu. The user can encounter enemies and fight them off to gain level and coins, run some errands to get coins and gain experience to increase levels, fight the final boss to finish the game, and buy items or weapons to prepare for the next fight. 

### Features in the Game
The game would feature three types of classes for the character that are going to be used in the game; player, enemy, and boss.  Generating the types of enemies in battles and the quests given to the player will be random. The game will also feature a turn-based battle mode where the player would go against different enemies. 
Non standard c++ libraries used:
- string = to obtain inputs from the user, to store strings in various data structures in the game, and to make word_art.
- cstdlib
- ctime

### Rules
- Player will have a level to determine the stats of his/her character. Player can upgrade their level by gaining experience points which can be earned by doing various activities in the game (i.e. by fighting enemies and doing errands). Gaining level will increase the character's basic stats.
- Player will be given actions to choose(battle, final, shop, sleep, and doing errands), in which some action will increase the player's experience points and coins respectively.
- Each type of character has their own strengths and weaknesses.
- If the player dies in a battle, he/she will continue from the previous saved data.

### Battle Rules:
- Player will take turn alternately with the enemy in a 1 on 1 battle, in which the player can choose to regain mana by (some number), attack , use items (from shop), use spells (by spending mana)
### Code Requirements
- Generation of random events : The quests given to the player and the enemies that the player encounters in the game will be random, some errands also include randomness, the type of enemies the player encounter will also be random in battle. However, there will only be one word_art for standard enemies and boss.
- Data structures for storing game status : The types of classes and enemies will use the class data structure to handle characteristics and interactions of the character.
- Dynamic memory management : The game will make use of pointers and dynamic arrays, especially for the word_art.
- File I/O : There is an autosave feature, it will save the stats after every turn in the main game (i.e. amount of gold possessed, levels, and experience points). This will be saved to a “game_data.txt” file and can be loaded again to the game.
- Program codes in multiple files : There will be a battle feature in the game, we will store the functions needed for the battle feature, as well as the classes for the characters, shop items, items and spells execution, main game, errands, and items in a different file. We will use makefile to compile them together with the main program.

### Assumptions
- As a user, it is assumed that you are the protagonist in this game. You entered a village that has been ruled by the evil monster named "Sauron the Destroyer" (Lord of the Rings reference). The ultimate goal of this game is to beat Sauron and bring back peace to the village once and for all. In doing that, you are granted doing whichever action necessary that is provided in the game in order to gain enough strength to defeat Sauron. The defeat of Sauron will conclude the game to its happy ending and reflects the end of the game.

### Footnotes:
- We find it hard to include any sample input/output due to the nature of our game, which is an rpg game, and the outcome can be quite unpredictable. Therefore, we think that it would be more appropriate if the player of this game would just try it manually.
