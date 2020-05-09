#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#ifndef CHARACTER_H
#define CHARACTER_H
using namespace std;

class player {
    public:
        // attributes of player
        string name;
        string wordart[25];
        string type;
        int xp = 0;
        int level = 0;
        int damage = 100;
        int health = 1000;
        int mana = 100;
        int coin = 10;
        string inventory[5] = {"none", "none", "none", "none", "none"};
        // functions of player
        int attack(string name) {   // normal attack 
            cout << "You dealt " << damage << " damage to " << name << "!" << endl;
            return damage;
        }
        void printCharacter() { // printing character wordart
            for(int i = 0; i < 25; ++i) {
                cout << wordart[0][i] << endl;
            }
        }
        void showItems( player &player1) {
            cout << "Choose a potion!" << endl;
            for(int i = 0; i < 5; ++i) {    // alphabetically sorting potion inventory
                for(int j = 0; j < 5-i-1; ++j) {
                    if(inventory[j][0] > player1.inventory[j+1][0]) {
                        string temp = player1.inventory[j];
                        player1.inventory[j] = player1.inventory[j+1];
                        player1.inventory[j+1] = temp;
                    }
                }
            }
            for (int i = 0; i<5; i++) {
                if (i!=4) {
                    cout<<i+1<<". "<<player1.inventory[i]<<endl;
                }
                else {
                    cout<<i+1<<". "<<player1.inventory[i]<<endl<<endl;
                }
            }
        }
        void addXPandCoin (int xpgain, int addcoin, player &player1) {
            player1.xp= player1.xp + xpgain;
            player1.coin= player1.coin + addcoin;
        }
        void addlevel (player &player1) {
            if (player1.xp>100 && player1.level<=10) {
                player1.level++;
                player1.health+= 60;
                player1.damage+= 8;
                player1.mana+= 20;
                player1.xp = player1.xp%100;
                cout<<"\n----------------------------------\nCongratulations! you have reached the next level!"<<endl;
                cout<<"Health gain = 20, health = "<<player1.health<<endl;
                cout<<"Damage gain = 8, damage = "<<player1.damage<<endl;
                cout<<"Mana gain = 20, mana = "<<player1.mana<<endl<<"----------------------------------\n\n";
            }
        }
        void showLevel() {  // showing level progress
            cout << "----------------------------------\nLevel: " << level << endl;
            if(level == 10) {
                cout << "Max level reached!" << endl;
            }
            else {
                cout << "Progress: " << xp % 100 << "/100 to level " << level+1 << endl << "----------------------------------\n\n";
            }
        }
        void showSpells() { // show avaliable spells according to class 
            cout<<"\n----------------------------------"<<endl;
            cout<<"Here is the list of spells you can use: "<<endl;
            cout<<"1. heavy blow"<<endl;
            cout<<"2. bloodlust"<<endl;
            cout<<"3. fire blast"<<endl;
            cout<<"4. thunder wrath"<<endl;
            cout<<"5. essence beam\n----------------------------------\n"<<endl;
        }
        void healthManaDamageBar(int currentHealth, int currentMana, int currentDamage) {
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
            cout<<"Damage: ";
            cout<<currentDamage<<endl;
        }
};

class enemy {
    public:
        // attributes of enemy
        string names [5] = {"Ogre", "Orc", "Creep", "Monster", "Ghouls"};
        string name = names[rand() % 5];
        int xp;
        int coin;
        int damage;
        int health;
        // functions of enemy
        void setAttribute(int Xp, int Coin, int Damage, int Health) {
            *&xp = Xp;
            *&coin = Coin;
            *&damage = Damage;
            *&health = Health;
        }
        void enemyAttributes() {
            if(name == "ogre"){
                setAttribute(80, 100, 50, 1000);
            }
            else if(name == "Orc"){
                setAttribute(90, 130, 30, 1500);
            }
            else if(name == "Creep"){
                setAttribute(70, 90, 40, 900);
            }
            else if(name == "Monster"){
                setAttribute(100, 120, 70, 1300);
            }
            else if(name == "Ghouls"){
                setAttribute(75, 110, 90, 1100);
            }
        }
        // functions of enemy
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
            return damage;
        }
        void healthDamageBar(int current, int damage) {
            int bar = current / (health / 10);
            cout << "\nEnemy HP = ";
            for(int i = 0; i < 10; ++i) {
                if(i < bar){
                    cout << "*";
                }
                else{
                    cout << "-";
                }
            }
            cout << " (" << current << "/" << health << ")" << endl;
            cout<<" Enemy Damage = "<<damage<<endl;
        }
};

class boss {
    public:
        // attributes of enemy
        string name = "Sauron the Destroyer";
        int xp;
        int coin;
        int damage = 180;
        int health = 2200;
        // functions of enemy
        void setAttribute(string Name, int Coin, int Damage, int Health, string Wordart[]) {
            name = Name;
            coin = Coin;
            damage = Damage;
            health = Health;

        }
        void introduction() {
            cout<<"What are you doing here, little weakling? Do you want to die?"<<endl;
            cout<<"I am going to tear you apart like the previous challengers that have come before!"<<endl;
            cout<<"MWAHAHAHAHA"<<endl;
        }
        void halfHp (boss &final, int &boss_attack) {
                cout<<final.name<<": \"I have not unleashed my full power upon you! Be prepared for your worst nightmare!!!\""<<endl;
                cout<<final.name<<": \"AAAAAAAAAAAAAAAAA!!!\""<<endl;
                boss_attack+=40;
                final.crit_damage = 2;
                cout<<"WARNING! WARNING! WARNING!\nOpponent's attack increases by 100, critical damage is now two times attack damage!\n\n";
        }
        double crit_damage = 1.8;
        int attack(int crit_damage) {
            srand(time(NULL));
            if(rand() % 5 == 1){    // critical damage
                cout << "Oof! " <<name << " dealt " << damage * crit_damage << " critical damage to you!" << endl;
                return damage * 1.8;
            } 
            else if(rand() % 5 != 1) {  // normal damage
                cout << name << " dealt " << damage << " damage to you!" << endl;
                return damage;
            } 
            return damage;
        }
        void healthDamageBar(int current, int damage) {
            int bar = current / (health / 10);
            cout << "\nEnemy HP = ";
            for(int i = 0; i < 10; ++i) {
                if(i < bar){
                    cout << "*";
                }
                else{
                    cout << "-";
                }
            }
            cout << " (" << current << "/" << health << ")" << endl;
            cout<<"Enemy Damage = "<<damage<<endl;
        }
};

#endif