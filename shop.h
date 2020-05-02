#include<iostream>
#include<string>
#ifndef SHOP_H
#define SHOP_H
#include "character.h"

using namespace std;

const int amount_of_health_potions = 3;
const int amount_of_attack_potions = 3;

struct health_potion {
    string name;
    int health;
    int price;
};

struct attack_potion {
    string name;
    int attack;
    int price;
    string descriptions;
};

struct hybrid_potion {
    string name;
    int attack;
    int health;
    int price;
    string descriptions;
};

struct flee_potion {
    string name;
    int price;
    string description;
};

struct health_potion potions[amount_of_health_potions] = {{ "magic elixir", 10, 15}, { "magic cure", 20, 30}, { "super magical potion", 80, 100}};

struct attack_potion attack_elixir[amount_of_health_potions] = {{ "stun attack", 5, 15, "skip your opponent's next turn"}, 
{ "poison arrow", 10, 30, "reduce your opponent's health by 5 for the next three turns"}, 
{"olympus blade", 100, 150, "the weapon dropped by the gods of greek"}};

struct hybrid_potion hybrid = { "spirit of the Gods", 5, 8, 100, "gives your hero enhanced strength and heal your hero for every turns of a battle" };

struct flee_potion flee = { "flee potion", 50, "allow the player to flee from a battle"};

void print_shop_items (health_potion potions[]) {
    for (int i = 0; i<amount_of_health_potions; i++) {
        cout<<i+1<<". "<<potions[i].name<<" , health gain = "<<potions[i].health<<", price = "<<potions[i].price<<endl;
    }
}

void print_attack_items (attack_potion attack_elixir[]) {
    for (int i = 0; i<amount_of_attack_potions; i++) {
        cout<<i+1<<". "<<attack_elixir[i].name<<" , attack boost = "<<attack_elixir[i].attack<<", price = "<<attack_elixir[i].price<<", description = "<<attack_elixir[i].descriptions<<endl;
    }
}
void check_inventory(player& player, string user_choice) {
    int space_available = 0;
    int choose_slot;
    for (int i = 0; i<5; i++) {
        cout<<(i+1)<<" = "<<player.inventory[i]<<endl;
        if (player.inventory[i]=="none") {
            space_available++;
        }
    }
    if (space_available>0) {
        cout<<"which slot do you want to use?"<<endl<<"answer: ";
        cin>>choose_slot;
        while (choose_slot>5 or choose_slot<1 or player.inventory[choose_slot-1]!="none") {
            for (int i = 0; i<5; i++) {
              cout<<(i+1)<<" = "<<player.inventory[i]<<endl;
            }
            cout<<"invalid answer, try again: ";
            cin>>choose_slot;
        }
        player.inventory[choose_slot-1] = user_choice;
    }
    else {
        cout<<"your inventory is full, please use them first or discard an item."<<endl;
    }
}
int main() {
    string user_choice;
    cout<<"welcome to shop!"<<endl;
    cout<<"#type the name of the potion to buy";
    cout<<"here is the list of things you can buy:"<<endl;
    cout<<"health potions:"<<endl;
    print_shop_items(potions);
    cout<<endl<<"attack potions:"<<endl;
    print_attack_items(attack_elixir);
    cout<<"hybrid potions:"<<endl;
    cout<<endl<<hybrid.name<<", attack boost: "<<hybrid.attack<<", health gain: "<<hybrid.health<<", descriptions: "<<hybrid.descriptions<<endl;
    cout<<endl<<flee.name<<", price: "<<flee.price<<", description: "<<flee.description<<endl;
    cout<<"type 'quit' to quit go quit shopping \n\n";
    player player;
    cout<<player.coin<<endl;
    cout<<"which potion do you want to buy: ";
    getline(cin, user_choice);
    while (user_choice!="quit") {
        int check = 0;
        for (int i =0; i<amount_of_health_potions;i++) {
            if (potions[i].name==user_choice) {
                check++;
                check_inventory( player , user_choice);
            }
        }
        for (int i = 0; i<amount_of_attack_potions;i++) {
            if (attack_elixir[i].name==user_choice) {
                check++;
                check_inventory( player, user_choice);
            }
        }
        if (user_choice==hybrid.name) {
            check++;
            check_inventory( player, user_choice);
        }
        if (check>0) {
            cout<<"do you want to buy another item? answer: ";
            getline(cin, user_choice);
            cout<<endl;
        }
        else if (check==0) {
            cout<<"potion name invalid. please enter again: ";
            getline(cin, user_choice);
            cout<<endl;
        }
    }
}
#endif
