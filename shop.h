#include<iostream>
#include<string>

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

int main() {
    cout<<"welcome to shop!"<<endl;
    cout<<"here is the list of things you can buy:"<<endl;
    cout<<"health potions:"<<endl;
    print_shop_items(potions);
    cout<<endl<<"attack potions:"<<endl;
    print_attack_items(attack_elixir);
    cout<<"hybrid potions:"<<endl;
    cout<<endl<<hybrid.name<<", attack boost: "<<hybrid.attack<<", health gain: "<<hybrid.health<<", descriptions: "<<hybrid.descriptions<<endl;
    cout<<endl<<flee.name<<", price: "<<flee.price<<", description: "<<flee.description<<endl;
}
