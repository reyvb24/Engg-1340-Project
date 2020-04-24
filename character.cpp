#include <iostream>
#include <string>
using namespace std;

class enemy {
    public:
        void setName (string name) {
            this -> name = name;
        }
        void setHealth(int health) {
            this -> health = health;
        }
        void setWordArt(string wordart[]) {
            this -> wordart[25] = wordart[25];
        }
        void setDamage(int damage) {
            this -> damage =  damage;
        }
        void setXp(int xp) {
            this -> xp = xp;
        }
        string getName() {
            return name;
        }
        int getXp() {
            return xp;
        }
        int getHealth() {
            return health;
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

    private:
        string name;
        string wordart[25];
        int xp;
        int damage;
        double health;
};