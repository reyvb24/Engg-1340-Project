#include <iostream>
#include "character.h"
#ifndef BATTLE_H
#define BATTLE_H 
using namespace std;

void battle(enemy & test, player & me){
    int counter = 0;
    bool fleeing = false;
    cout << "You have encountered a " << test.name << "!" << endl;
    test.printCharacter();
    cout << "Health: " << test.health << endl;

    while((test.health != 0) || (fleeing == false)) {
        if(counter % 2 == 0) {  // player's move
            int input;
            cout << "Your turn, choose any of the following actions!" << endl;
            cout << "1. Attack" << endl;
            cout << "2. Use item" << endl;
            cout << "3. Use spells" << endl;
            cout << "4. Flee" << endl;
            cin >> input;
            while ((input < 1) || (input > 4)) {
                cout << "Invalid input! Please try again" << endl;
                cin >> input;
            }
            switch (input) {
                case 1:
                    test.decreaseHealth(me.damage);
                    cout << "You dealt " << me.damage << " damage to " << test.name << "!" << endl;
                    break;
                case 2:

                    break;
                case 3:
                    
                    break;
                case 4:
                    fleeing = true;
                    break;
            }
            counter += 1;
        }
        else if (counter % 2 == 1) { // enemy's move
            test.attack();
            counter += 1;
        }
    }
    if(fleeing == false) {

    }
}
#endif
