#include <iostream>
#include <string>
#include "shop.h"
#ifndef CHARACTER_H
#define CHARACTER_H
using namespace std;

class player {
    public:
        string name;
        int xp;
        int level = xp/1000;
        int damage;
        int health;
        int mana;
        int coin;
        string inventory[5];
};

class enemy {
    public:
        string name;
        string wordart[25];
        int xp;
        int gold;
        int damage;
        int health;

        void setAttribute(string Name, int Xp, int Gold, int Damage, int Health) {
            name = Name;
            xp = Xp;
            gold = Gold;
            damage = Damage;
            health = Health;
        }
        int attack() {
            cout << name << " dealt " << damage << " to you!" << endl;
            return damage;
        }
        void printCharacter() {
            for(int i = 0; i < 25; ++i) {
                cout << wordart[i] << endl;
            }
        }
        void decreaseHealth(int damage) {
            health -= damage;
        }
        void healthBar() {
            int bar = health/10;
            cout << "HP = ";
            for(int i = 0; i < bar; ++i) {
                cout << "*";
            }
            cout << endl;
        }
};

#endif
