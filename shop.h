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

struct health_potion potions[amount_of_health_potions] = {{ "magic elixir", 10, 15}, { "magic cure", 20, 30}, { "super magical potion", 80, 100}};

struct attack_potion attack_elixir[amount_of_health_potions] = {{ "stun attack", 5, 15, "skip your opponent's next turn"}, 
{ "poison arrow", 10, 30, "reduce your opponent's health by 5 for the next three turns"}, 
{"olympus blade", 100, 150, "the weapon dropped by the gods of greek"}};

struct hybrid_potion hybrid = { "spirit of the gods", 5, 8, 100, "gives your hero enhanced strength and heal your hero for every turns of a battle" };


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
void check_inventory(player& player1, string user_choice) {
    int space_available = 0;
    int choose_slot;
    for (int i = 0; i<5; i++) {
        cout<<(i+1)<<" = "<<player1.inventory[i]<<endl;
        if (player1.inventory[i]=="none") {
            space_available++;
        }
    }
    if (space_available>0) {
        cout<<"which slot do you want to use?"<<endl<<"answer: ";
        cin>>choose_slot;
        while (choose_slot>5 or choose_slot<1 or player1.inventory[choose_slot-1]!="none") {
            for (int i = 0; i<5; i++) {
              cout<<(i+1)<<" = "<<player1.inventory[i]<<endl;
            }
            cout<<"invalid answer, try again: ";
            cin>>choose_slot;
        }
        player1.inventory[choose_slot-1] = user_choice;
        cout<<endl;
    }
    else {
        cout<<"your inventory is full, please use them first or discard an item. \n"<<endl;
    }
}
void print_list_of_items(player player1) {
    cout<<"#type the name of the potion to buy. ";
    cout<<"here is the list of things you can buy:"<<endl;
    cout<<"health potions:"<<endl;
    print_shop_items(potions);
    cout<<endl<<"attack potions:"<<endl;
    print_attack_items(attack_elixir);
    cout<<endl<<"hybrid potions:"<<endl;
    cout<<hybrid.name<<", attack boost: "<<hybrid.attack<<", health gain: "<<hybrid.health<<", descriptions: "<<hybrid.descriptions<<endl;
    cout<<endl<<"type 'quit' to quit shopping \n\n";
    cout<<"your coin: "<<player1.coin<<endl<<endl;
}
int main() {
    string user_choice;
    player player1;
    cout<<"welcome to shop!"<<endl;
    print_list_of_items(player1);
    cout<<"which potion do you want to buy: ";
    getline(cin, user_choice);
    while (user_choice!="quit") {
        int check = 0;
        int check_enough_money = 0;
        for (int i =0; i<amount_of_health_potions;i++) {
            if (potions[i].name==user_choice) {
                if (player1.coin-potions[i].price>=0) {
                    check++;
                    check_inventory( player1 , user_choice);
                    player1.coin-=potions[i].price;
                } else {
                    check_enough_money = 1;
                    check++;
                    cout<<"you don't have enough money to buy this item. \n"<<endl;
                }
            }
        }
        for (int i = 0; i<amount_of_attack_potions;i++) {
            if (attack_elixir[i].name==user_choice) {
                if (player1.coin-attack_elixir[i].price>=0) {
                    check++;
                    check_inventory( player1, user_choice);
                    player1.coin-=attack_elixir[i].price;
                } else {
                    check_enough_money = 1;
                    check++;
                    cout<<"you don't have enough money to buy this item. \n"<<endl;
                }
            }
        }
        if (user_choice==hybrid.name) {
            if (player1.coin-hybrid.price>=0) {
                check++;
                check_inventory( player1, user_choice);
                player1.coin-=hybrid.price;
            } else {
                check_enough_money = 1;
                check++;
                cout<<"you don't have enough money to buy this item. \n"<<endl;
            }
        }
        if (check==1) {
            if (check_enough_money==0) {
                print_list_of_items(player1);
                cout<<"which other potion do you want to buy? answer: ";
                getline(cin, user_choice);
                cout<<endl;
            } else if (check_enough_money==1) {
                cout<<"please enter an appropriate response: ";
                getline(cin, user_choice);
                cout<<endl;
            }
        }
        else if (check==0) {
            cout<<"input invalid. please enter again: ";
            getline(cin, user_choice);
            cout<<endl;
        }
    }
}
#endif
