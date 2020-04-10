# Engg-1340-Project
## Team Members
- Matthew Dylan Widjaya
- Reynard Verill Buntoro
## Game Description and Rules
Type of Text-Based Game

### Description
We are planning to make a RPG (Role Playing Game) which will have a few characters, weapons, and items in the game. We propose that the game will have a story and will end once the user has defeated the final boss in the game. Apart from that, we also would like to suggest the implementation of word arts in the battles and shops to make the game more appealing for the audience. The scheme for the game is taking a few actions per day where the user can encounter enemies and fight them off to gain level, run some errands to get coins and gain experience to increase levels, sleep to regain hp and mana, and buy items or weapons to prepare for the next fight. 

### Features in the Game
The game would feature three types of classes for the character that the player can choose; warrior, mage, and assassin. Additionally, a few items would be added to enhance the characters’ “skills”. Both of these features would use the class and struct data type to incorporate the attributes and interactions each character and item has. Generating the types of enemies in battles and the quests given to the player will be random with different seeds every time. There will be a “sleep” feature where the player can restore their stats and save the game. This will require a file I/O to a save.txt file where it will record the progress, experience and gold owned by the player. The game will also feature a turn-based battle mode where the player would go against different enemies. 

We are planning to make a RPG (Role Playing Game) which will rely more on struct and class data as the base of our game in classifying the types of characters, weapons, and items in the game. We propose that the game will have a story and will end once the user has defeated the final boss in the game. Apart from that, we also would like to suggest the implementation of word arts in the battles and shops to make the game more appealing for the audience (only for certain parts of the game). As for the classification of characters, we intend to separate them into some fields which comprise of warrior, mage, assassin, and healer. The scheme for the game is taking a few actions per day where the user can encounter enemies and fight them off to gain level and earn coins, run some errands to get coins and gain level, sleep to save the game, and buy items or weapons to prepare for the next fight. We would also try to make the difficulty of the enemies adjusted to the level of the player.

### Rules
```
- Player will have a level to determine the stats of his/her character. Player can upgrade their level by gaining experience points which can be earned by doing various activities in the game. Gaining level will increase the character's basic stats.
- Player will be given 3 action points each day (fight, shop, sleep, and doing errands), in which each action will increase the player's experience points respectively, except for sleep, which is used to save the game.
- Each type of character has their own strengths and weaknesses.
- If the player die in a battle, he/she will restart from the previous saved data.
```

### Battle Rules:
- Player will take turn alternately with the enemy in a 1 on 1 battle, in which the player can choose to defend and regain mana by (some number), choose three types of attack (which will consume different number of mana), take potions (from shop), or flee from the battle in consequence of losing your character's items.

### Features that we plan to implement

- Generation of random game sets or events
- File input/output (e.g., for loading/saving game status)
- Program codes in multiple files
- Proper indentation and naming styles
- In-code documentation




