#include <iostream>
#include <string>
#ifndef POTIONS_H
#define POTIONS_H

using namespace std;

const int amount_of_health_potions = 3;
const int amount_of_attack_potions = 3;

struct health_potion {//struct for health potion items
    string name;
    int health;
    int price;
};

struct attack_potion {//struct for attack potion items
    string name;
    int attack;
    int price;
    string descriptions;
};

struct hybrid_potion {//struct for hybrid potion (only 1 item)
    string name;
    int attack;
    int health;
    int price;
    string descriptions;
};
//assign values to the structs above
struct health_potion potions[amount_of_health_potions] = {{ "magic elixir", 10, 15}, { "magic cure", 20, 30}, { "super magical potion", 80, 100}};

struct attack_potion attack_elixir[amount_of_health_potions] = {{ "stun attack", 50, 15, "skip your opponent's next turn"}, 
{ "poison arrow", 180, 30, "reduce your opponent's health by 50 for the enemy's next three turns"}, 
{"olympus blade", 350, 150, "the weapon dropped by the gods of greek"}};

struct hybrid_potion hybrid = { "spirit of the gods", 100, 50, 100, "increases your attack by 100 and health by 50 for the rest of the battle" };
#endif
