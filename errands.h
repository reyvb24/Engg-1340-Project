#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "character.h"
#ifndef ERRANDS_H
#define ERRANDS_H
using namespace std;

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
        player1.coin += 100;
        player1.xp += 80;
    }
}

#endif
