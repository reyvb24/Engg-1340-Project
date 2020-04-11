# Engg-1340-Project
## Team Members
- Matthew Dylan Widjaya 3035667144
- Reynard Verill Buntoro 3035663461
## Game Description and Rules

### Description
We are planning to make a RPG (Role Playing Game) which will have a few characters, weapons, and items in the game. We propose that the game will have a story and will end once the user has defeated the final boss in the game. Apart from that, we also would like to suggest the implementation of word arts in the battles and shops to make the game more appealing for the audience. The scheme for the game is taking a few actions per day where the user can encounter enemies and fight them off to gain level, run some errands to get coins and gain experience to increase levels, sleep to regain hp and mana, and buy items or weapons to prepare for the next fight. 

### Features in the Game
The game would feature three types of classes for the character that the player can choose; warrior, mage, and assassin. Additionally, a few items would be added to enhance the characters’ “skills”. Generating the types of enemies in battles and the quests given to the player will be random. There will be a “sleep” feature where the player can restore their stats and save the game. The game will also feature a turn-based battle mode where the player would go against different enemies. 

### Rules
- Player will have a level to determine the stats of his/her character. Player can upgrade their level by gaining experience points which can be earned by doing various activities in the game. Gaining level will increase the character's basic stats.
- Player will be given 3 action points each day (fight, shop, sleep, and doing errands), in which each action will increase the player's experience points respectively, except for sleep, which is used to save the game.
- Each type of character has their own strengths and weaknesses.
- If the player dies in a battle, he/she will restart from the previous saved data.

### Battle Rules:
- Player will take turn alternately with the enemy in a 1 on 1 battle, in which the player can choose to defend and regain mana by (some number), choose three types of attack (which will consume different number of mana), take potions (from shop), or flee from the battle in consequence of losing your character's items.

### Code Requirements
- Generation of random events : The quests given to the player and the enemies that the player encounters in the game will be random.
- Data structures for storing game status : The types of classes and enemies will use the class data structure to handle characteristics and interactions of the character.
- Dynamic memory management : The game will make use of pointers and dynamic arrays.
- File I/O : There will be a sleep feature in the game, when the player sleeps it saves all the current stats of the player (i.e. amount of gold possessed, levels, and experience points). This will be saved to a “save.txt” file and can be loaded again to the game.
- Program codes in multiple files : There will be a battle feature in the game, we will store the functions needed for the battle feature as well as the classes for the characters and items in a different file. We will use makefile to compile them together with the main program.
