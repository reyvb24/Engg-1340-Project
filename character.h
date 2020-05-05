#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "shop.h"
#include "itemsNspells.h"
#ifndef CHARACTER_H
#define CHARACTER_H
using namespace std;

class player {
    public:
        // attributes of player
        string name;
        string wordart[25];
        string type;
        int xp;
        int level = xp/100;
        int damage;
        int health;
        int mana;
        int coin;
        string inventory[5] = {"none", "none", "none", "none", "none"};
        // functions of player
        int attack(string name) {   // normal attack 
            cout << "You dealt " << damage << " damage to " << name << "!" << endl;
            return damage;
        }
        void printCharacter() { // printing character wordart
            for(int i = 0; i < 25; ++i) {
                cout << wordart[i] << endl;
            }
        }
        void showItems() {
            cout << "Choose a potion!" << endl;
            for(int i = 0; i < 5; ++i) {    // alphabetically sorting potion inventory
                for(int j = 0; j < 5-i-1; ++j) {
                    if(inventory[j][0] > inventory[j+1][0]) {
                        string temp = inventory[j];
                        inventory[j] = inventory[j+1];
                        inventory[j+1] = temp;
                    }
                }
            }
        }
        void showLevel() {  // showing level progress
            cout << "Level: " << level << endl;
            if(level == 10) {
                cout << "Max level reached!" << endl;
            }
            else {
                cout << "Progress: " << xp % 100 << "/100" << endl;
            }
        }
        void showSpells() { // show avaliable spells according to class 
            if(type == "warrior") {
                cout << " " << endl;
            }
            else if(type == "mage") {

            }
        }
        void useItems(string choice, int & playerHealth, int & enemyHealth, int counter) {
            for(int i = 0; i < amount_of_health_potions; ++i) { // health potion
                if(choice == potions[i].name) {
                    healthPotion(potions[i].health, playerHealth);
                    for(int j = 0; j < 5; ++j) {
                        if(inventory[j] == potions[i].name) {
                            inventory[j] = "none";
                        }
                    }
                }
            }
            if(choice == "stun attack") {
                stunAttack(counter);
                for(int j = 0; j < 5; ++j) {
                    if(inventory[j] == "stun attack") {
                        inventory[j] = "none";
                    }
                }
            }
            else if(choice == "poison arrow") {
                poisonArrow(counter, enemyHealth);
                for(int j = 0; j < 5; ++j) {
                    if(inventory[j] == potions[i].name) {
                        inventory[j] = "none";
                    }
                }
            }
            else if(choice == "olympus blade") {

            }
        }
        void useSpells(string choice) {

        }
        void healthManaBar(int currentHealth, int currentMana) {
            int healthbar = currentHealth / (health / 10);
            int manabar = currentMana / (mana / 10);
            cout << "HP = ";
            for(int i = 0; i < 10; ++i) {
                if(i < healthbar){
                    cout << "*";
                }
                else{
                    cout << "-";
                }
            }
            cout << " (" << currentHealth << "/" << health << ")" << endl;
            cout << "Mana: ";
            for(int i = 0; i < 10; ++i) {
                if(i < manabar){
                    cout << "@";
                }
                else{
                    cout << "-";
                }
            }
            cout << " (" << currentMana << "/" << mana << ")" << endl;
        }
};

class enemy {
    public:
        // attributes of enemy
        string name;
        string wordart[25];
        int xp;
        int coin;
        int damage;
        int health;
        // functions of enemy
        void setAttribute(string Name, int Xp, int Coin, int Damage, int Health, string Wordart[]) {
            name = Name;
            xp = Xp;
            coin = Coin;
            damage = Damage;
            health = Health;

        }
        int attack() {
            srand(time(NULL));
            if(rand() % 5 == 1){    // critical damage
                cout << "Oof! " <<name << " dealt " << damage * 1.8 << " critical damage to you!" << endl;
                return damage * 1.8;
            } 
            else if(rand() % 5 != 1) {  // normal damage
                cout << name << " dealt " << damage << " damage to you!" << endl;
                return damage;
            }
        }
        void printCharacter() {
            for(int i = 0; i < 25; ++i) {
                cout << wordart[i] << endl;
            }
        }
        void healthBar(int current) {
            int bar = current / (health / 10);
            cout << "Enemy HP = ";
            for(int i = 0; i < 10; ++i) {
                if(i < bar){
                    cout << "*";
                }
                else{
                    cout << "-";
                }
            }
            cout << " (" << current << "/" << health << ")" << endl;
        }
};

#endif
