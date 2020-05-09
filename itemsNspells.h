#include <iostream>
#include <string>
#include <cstdlib>
#ifndef ITEMSNSPELLS_H
#define ITEMSNSPELLS_H
using namespace std;

void healthPotion(int heal, int & playerHealth){//function to use heal potion
    playerHealth += heal;
    cout << "You used a heal potion! Restored " <<  heal << " health" << endl;
}

void stunAttack(int & counter, int & enemyHealth, int damage) {//function to use stun attack
    enemyHealth-=damage;
    counter += 1;
    cout << "You used the stun potion! Enemy skips the next turn!" << endl;
    cout << "Enemy received " << damage << " damage while stunned!" << endl;
}

void poisonArrow(int & poisonCounter) {//function to use poison arrow
    poisonCounter = 3;
    cout<< "You used the poison arrow! Enemy's health decreases by 50 for the enemy's next 3 turns!"<<endl;
}

void poison_damage(int & enemyHealth) {//function for poison damage
    enemyHealth -= 10;
    cout << "The poison starts to kick in. Enemy lose 50 health" << endl;
}

void olympusBlade(int & enemyhealth, int damage) {
    enemyhealth-=damage;
    cout<<"You used the olympus blade! Enemy suffers 350 hp damage!"<<endl;
}

void spiritOfTheGods(int heal, int & playerHealth, int damage, int & playerAttack) {
    playerHealth+=heal;
    playerAttack+=damage;
    cout<<"The spirit of the Gods has been summoned upon you! Your health will increase by 50 and your attack damage will increase by 100 for the rest of the battle!"<<endl;
}
void heavyBlow (int & cooldown, int & mana) {
    cooldown = 5;
    mana -= 40;
    cout << "You used heavy blow! Deals 2.5X critical for next attack" << endl;
}

void bloodlust (int & cooldown, int & mana) {
    cooldown = 5;
    mana -= 35;
    cout << "You used bloodlust! Next attack has 25 percent lifesteal" << endl;
}

void fireBlast (int & enemyHealth, int & cooldown, int & mana) {
    enemyHealth -= 75;
    cooldown = 3;
    mana -= 24;
    cout << "You used fire blast! Enemy suffers 75 damage" << endl;
}

void thunderWrath (int & cooldown, int & mana, int & thunderCounter) {
    thunderCounter = 4;
    cooldown = 7;
    mana -= 70;
    cout << "The nimbus cloud has arrived! Enemy is electrocuted for 4 turns" << endl;
}

void essenceBeam (int & enemyHealth, int & turn, int & cooldown, int & mana) {
    enemyHealth -= 300;
    turn += 1;
    mana -= 100;
    cooldown = 9;
    cout << "The air vibrates, a beam stunned and damaged the enemy!" << endl;
}

void electrocuted(int & enemyhealth) {
    enemyhealth -= 40;
    cout << "Bzzz! Lighting strikes the enemy!" << endl;
}
// more spells and item effects to be added
#endif