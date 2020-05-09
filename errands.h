#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "character.h"
#ifndef ERRANDS_H
#define ERRANDS_H
using namespace std;

// Function Purpose: to print additional xp and coins to player after completing a quest
// Takes the player class as input and the xp and coin to be added
// outputs the additional and current xp and coin of the player
void print_coin_xp (player &player1, int coin_addition, int xp_addition) {
    cout<<"coin(s) earned: "<<coin_addition<<", current coin(s): "<<player1.coin<<endl;
    cout<<"xp gained: "<<xp_addition<<", current xp: "<<player1.xp<<endl;
}

// All three function below are similar
// Function Purpose: small errands the player can do to add xp and coin
// takes the player class as argument
// returns additional coin and xp to the player
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
        player1.addXPandCoin(80, 10, player1);
        print_coin_xp(player1, 10, 80);
    }
}

void secondErrand(player & player1) {
    srand(time(NULL));
    string options[2] = {"buy", "use ladder"};
    string answer = options[rand() % 2];
    string choice;
    cout << "You decided to go around for the village for a little walk\n" << endl;
    cout << "A little kid comes to you and asks for help\n" << endl;
    cout << "Little kid: \"Hello mister, can you help me retrieve my kite? it is stucked on a very tall tree\"\n"<<endl;
    cout<< "(Type either \"buy\" to buy him a new one, \"use ladder\" to try to use ladder, \"no\" to leave the kid\n"<<endl;
    if (answer == "buy") {
        string response[2] = {"There seems to be no ladder available", "The ladder you can find is not tall enough to reach the kite"};
        string comp_response = response[rand()%2];
        cin>>choice;
        while (choice!= "buy" && choice!="no") {
            cout<<comp_response<<endl<<endl<<"response: ";
            cin>>choice;
        }
        if (choice=="buy") {
            cout<<"Kid: \"Thank you so much mister! Here, i give you some coins for the trouble\""<<endl;
            player1.addXPandCoin(120, 1, player1);
            print_coin_xp(player1, 1, 120);
        }
        else if (choice=="no") {
            cout<<"You: \"Sorry kid, i don't have enough time for you\""<<endl;
        }
    }
    else if (answer == "use ladder") {
        getline(cin, choice);
        while (choice!= "use ladder" && choice!="no") {
            cout<<"It seems that the ladder is tall enough"<<endl<<"response: ";
            getline(cin, choice);
        }
        if (choice=="use ladder") {
            cout<<"Kid: \"Thank you so much mister! Here, i give you some coins for the trouble\""<<endl;
            player1.addXPandCoin(80,5,player1);
            print_coin_xp(player1, 5, 80);
        }
        else if (choice=="no") {
            cout<<"You: \"Sorry kid, i don't have enough time for you\""<<endl;
        }       
    }

}

void thirdErrand(player & player1) {   // riddle type minigame
    int correctAnswers = 0;
    string answer1 = "coin", answer2 = "fire", guess1, guess2;
    string response;
    cout << "You walk toward the end of the village near the crossroads, at the crossroads you see a jester calling you over." << endl;
    cout << "Jester: \"Aye, you over there! You're not from around 'ere are ya? Come 'ere lets have a chat!\"" << endl;
    cout << "(Type \"walk\" to approach the man)" << endl;
    cin >> response;
    cout << "Jester: \"Greetings! I'm the village jester! Now, i know you're busy off fighting these monsters and such, but spare some time for me will ya? \"" << endl;
    cout << "Jester: \"I'll give you a couple of riddles, if you can answer 'em, I'll make you worth your while.\"" << endl;
    cout << "(Type \"ok\" to play along with the jester)" << endl;
    cin >> response;
    cout << "Jester: \"Alright, first riddle. What has a head and a tail, but no body?\"" << endl;
    cout << "Answer: ";
    cin >> guess1;
    cout << endl;
    if(guess1 == answer1) {
        correctAnswers += 1;
        cout << "Jester: \"Hmm, lucky guess. Alright, I'll give you something harder\"" << endl;
    }
    else if(guess1 != answer1) {
        cout << "Jester: \"Hahaha! Tricky one ain't it? I'll give you another chance\"" << endl;
    }
    cout << "Jester: \"Next riddle. Errhmm, what is not alive but grows, does not breath but needs air?\"" << endl;
    cout << "Answer: ";
    cin >> guess2;
    cout << endl;
    if(guess2 == answer2) {
        correctAnswers += 1;
        cout << "Jester: \"Huh, thats the right answer, pretty good\"" << endl;
    }
    else if(guess2 != answer2) {
        cout << "Jester: \"No no no, i don't think thats the right one\"" << endl;
    }
    if(correctAnswers == 0) {
        cout << "Jester: \"Har Har Har, i guess you're not that smart after all, here a little gold for the trouble, don't lose them on the way home!\"" << endl;
        player1.addXPandCoin(50, 50, player1);
        print_coin_xp(player1, 50, 50);
    }
    else if(correctAnswers == 1) {
        cout << "Jester: \"Huh, not to shabby boy. Just as i promised, some gold for your trouble.\"" << endl;
        player1.addXPandCoin(70, 70, player1);
        print_coin_xp(player1, 70, 70);
    }
    else if(correctAnswers == 2) {
        cout << "Jester: \"Wow! You're pretty clever huh? Here take some extra gold, you've earned it!\"" << endl;
        player1.addXPandCoin(90, 90, player1);
        print_coin_xp(player1, 90, 90);
    }
}

// Function purpose: to randomly select which errand to run
// Takes the player class as argument
// Runs one of the three errand functions
void runErrand (player &player1) {
    int errand = rand() %3 + 1;
    if (errand==1) {
        firstErrand(player1);
    } else if (errand==2) {
        secondErrand(player1);
    } else if (errand==3) {
        thirdErrand(player1);
    }

}

#endif
