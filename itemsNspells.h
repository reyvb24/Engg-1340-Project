#include <iostream>
#include <string>
#include <cstdlib>
#ifndef ITEMSNSPELLS_H
#define ITEMSNSPELLS_H
using namespace std;

void healthPotion(int heal, int & playerHealth){
    playerHealth += heal;
    cout << "You used a heal potion! Restored " <<  heal << " health" << endl;
}

void stunAttack(int & counter) {
    counter += 1;
    cout << "You used the stun potion! Enemy skips the next turn!" << endl;
}

void poisonArrow(int counter, int & enemyHealth) {
    int turns = 3;
    // not finished
}

// more spells and item effects to be added
#endif