#include <iostream>
#include <string>
#include "character.h"
#ifndef BATTLE_H
#define BATTLE_H 
using namespace std;

void recurringEffect(int counter, enemy & creep, player & player1) {

}

void battle(enemy & creep, player & player1){
    int counter = 0;
    bool fleeing = false;
    cout << "You have encountered a " << creep.name << "!" << endl;
    creep.printCharacter();
    cout << "Health: " << creep.health << endl;
    int enemyHealth = creep.health;
    int playerHealth = player1.health;
    int playerMana = player1.mana;

    while((enemyHealth > 0) || (fleeing == false) || playerHealth > 0) {
        if(counter % 2 == 0) {  // player's move
            player1.healthManaBar(playerHealth, playerMana);
            int input;
            cout << "Your turn, choose any of the following actions!" << endl;
            cout << "1. Attack" << endl;
            cout << "2. Use item" << endl;
            cout << "3. Use spells" << endl;
            cin >> input;
            while ((input != 1) || (input != 2) || (input != 3)) {
                cout << "Invalid input! Please try again" << endl;
                cin >> input;
            }
            if(input == 1) {
                enemyHealth -= player1.attack(creep.name);
            }
            else if(input == 2) {
                player1.showItems();
                cout << "Type \"back\" to go back and choose another action" << endl;
                string itemOption;
                getline(cin, itemOption);
                if(itemOption == "back") {
                    counter -= 1;
                }
                else{
                    player1.useItems(itemOption, playerHealth, enemyHealth, counter);
                }
            }
            else if(input == 3) {
                player1.showSpells();
                cout << "Type the potion name to use them or type \"back\" to go back and choose another action!" << endl;
                string spellOption;
                getline(cin, spellOption);
                if(spellOption == "back") {
                    counter -= 1;
                }
                else{
                    player1.useSpells(spellOption);
                }
            }
            counter += 1;
        }
        else if (counter % 2 == 1) { // enemy's move
            creep.healthBar(enemyHealth);
            playerHealth -= creep.attack();
            counter += 1;
        }
    }
    if(enemyHealth <= 0) {
        cout << "Great work! You Defeated the " << creep.name << endl;
        if(player1.xp < 20 * 1000) {
            player1.xp += creep.xp;
            player1.coin += creep.coin;
            cout << "You received " << creep.xp << "XP and " << creep.coin << "gold!" << endl;
        }
        else{
            player1.coin += creep.coin;
            cout << "You received " << creep.coin << "gold!" << endl;
        }
        player1.showLevel();
    }
    else if(playerHealth <= 0) {
        cout << "You died! Rest up and try again another time!" << endl;
    }
    else if(fleeing ==  true) {
        cout << "Whew, Got out of there safely!" << endl;
    }
    
}
#endif
