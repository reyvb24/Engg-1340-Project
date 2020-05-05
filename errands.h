#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "character.h"
#ifndef ERRANDS_H
#define ERRANDS_H
using namespace std;


void print_coin_xp (player & player1, int coin_addition, int xp_addition) {
    cout<<"coin(s) earned: "<<coin_addition<<", current coin(s): "<<player1.coin<<endl;
    cout<<"xp gained: "<<xp_addition<<", current xp: "<<player1.xp;
}
void firstErrand(player & player1) {
    srand(time(NULL));
    string options[4] = {"rock", "tree", "bush", "shack"};
    string answer = options[rand() % 4];
    string guess;
    cout << "You decided to go around the village and meet the people around" << endl;
    cout << "An old lady comes to you and asks for help" << endl;
    cout << "Old lady: \"Ohh, you must be the newcomer that everyone in the village talks about\"" << endl;
    cout << "(Type \"yes\" to continue)" << endl;
    cin >> guess;
    cout << "Old lady: \"Could you help me? I'm trying to find my cat, he keeps dissapearing lately\"" << endl;
    cout << "Hes either behind that rock over there, or maybe that tree, but the other day i found him behind that shack\"" << endl;
    cout << "(Type \"ok\" to continue)" << endl;
    cin >> guess;
    cout << "Old lady: \"Oh can you check the bush over there too? Just to be sure\"" << endl;
    cout << "(Type either \"rock\", \"bush\", \"tree\" or \"shack\" to make your guess)" << endl; 
    cin >> guess;
    while(guess != answer) {
        cout << "Old lady: \"Ohh, i don't think hes there, maybe try looking in other places?\"" << endl;
        cin >> guess;
    }
    if(guess == answer) {
        cout << "Old lady: \"Thank you, you've found him! Here is some coin for the trouble!\"" << endl;
        player1.coin += 10;
        player1.xp += 80;
        print_coin_xp(player1, 10, 80);
    }
}

void secondErrand(player & player1) {
    srand(time(NULL));
    string options[2] = {"buy", "use ladder"};
    string answer = options[rand() % 2];
    string choice;
    cout << "You decided to go around for the village for a little walk" << endl;
    cout << "A little kid comes to you and asks for help" << endl;
    cout << "Little kid: \"Hello mister, can you help me retrieve my kite? it is stucked on a very tall tree\""<<endl;
    cout<< "(Type either \"buy\" to buy him a new one, \"use ladder\" to try to use ladder, \"no\" to leave the kid"<<endl;
    if (answer == "buy") {
        string response[2] = {"There seems to be no ladder available", "The ladder you can find is not tall enough to reach the kite"};
        string comp_response = options[rand()%2];
        cin>>choice;
        while (choice!= "buy" && choice!="no") {
            cout<<comp_response<<endl<<"response: ";
            cin>>choice;
        }
        if (choice=="buy") {
            player1.coin-=4;
            cout<<"Kid: \"Thank you so much mister! Here i give you some extra coins for the trouble\""<<endl;
            player1.coin += 5;
            player1.xp += 120;
            print_coin_xp(player1, 5, 120);
        }
        else if (choice=="no") {
            cout<<"You: \"Sorry kid, i don't have enough time for you\""<<endl;
        }
    }
    else if (answer == "use ladder") {
        getline(cin, choice);
        while (choice!= "use ladder" && choice!="no") {
            cout<<"It seems that the ladder is tall enough"<<endl<<"response: ";
            cin>>choice;
        }
        if (choice=="ladder") {
            cout<<"Kid: \"Thank you so much mister! Here i give you some extra coins for the trouble\""<<endl;
            player1.coin += 5;
            player1.xp += 80;
            print_coin_xp(player1, 5, 80);
        }
        else if (choice=="no") {
            cout<<"You: \"Sorry kid, i don't have enough time for you\""<<endl;
        }       
    }

}

#endif
