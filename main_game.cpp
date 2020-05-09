#include<iostream>
#include<string>
#include<fstream>
#include <dirent.h>
#include<sys/stat.h>
#include "character.h"
#include "battle.h"
#include "shop.h"
#include "errands.h"

using namespace std;
void title() {
    cout<<":::.         .:::    .::::::::::::.   ::::::::::::.   :::::::::::.    .::::::::::::.   ::::::::::::."<<endl;
    cout<<":::::.     .:::::    ::::      ::::   ::::     ::::   ::::      :::   ::::      ::::   ::::     ::::"<<endl;
    cout<<":::   :: ::   :::    ::::      ::::   ::::    ::::    ::::      :::   ::::      ::::   ::::    ::::"<<endl;
    cout<<":::    :::    :::    ::::      ::::   ::::::::::      ::::      :::   ::::      ::::   ::::::::::"<<endl;
    cout<<":::     :     :::    ::::      ::::   ::::    :::     ::::      :::   ::::      ::::   ::::    :::"<<endl;
    cout<<":::           :::    `::::::::::::'   ::::    ::::    ::::::::::::'   `::::::::::::'   ::::    ::::"<<endl;
    cout<<endl;
    cout<<"                                            .:::::::."<<endl;
    cout<<"                                           .:::   :::."<<endl;
    cout<<"                                          ::::     :::: "<<endl;
    cout<<"                                           `:::   :::' "<<endl;
    cout<<"                                             `:::::' "<<endl<<endl;
}
void autosave(player &player1) {
    ofstream fout;
    fout.open("game_data.txt");
    fout<<player1.coin<<endl;
    fout<<player1.xp%100<<endl;
    for (int i = 0; i< 5; i++) {
        fout<<player1.inventory[i]<<endl;        
    }
    fout<<player1.level<<endl;
    fout<<player1.health<<endl;
    fout<<player1.damage<<endl;
    fout<<player1.mana<<endl;
    fout<<player1.name<<endl;
}
void startgame(player &player1) {
    title();
    string choice;
    cout<<"Hello! Welcome to the game! Please type 'new game' to start a new game or 'load game' to load previous data"<<endl<<"choice: ";
    getline(cin, choice);
    while (choice!="new game" && choice!="load game") {
        cout<<"Please enter an appropriate response!"<<endl;
        getline(cin, choice);
    }
    if (choice == "load game") {
        ifstream fin;
        fin.open("game_data.txt");
        if (fin) {
            cout<<"Load successful!"<<endl;
            fin>>player1.coin;
            fin>>player1.xp;
            for (int i = 0; i<6; i++) {
                if (i==0) {
                    string * blank = new string ("");
                    getline(fin, *blank);
                    delete blank;
                }
                else {
                    getline(fin, player1.inventory[i-1]);
                }
            }
            fin>>player1.level;
            fin>>player1.health;
            fin>>player1.damage;
            fin>>player1.mana;
            fin>>player1.name;
            cout<<"coin: "<<player1.coin<<endl;
            cout<<"xp: "<<player1.xp<<endl;
            cout<<"inventory : ";
            for (int i = 0; i<5; i++) {
                if (i==4) {
                    cout<<i+1<<"."<<player1.inventory[i]<<endl;
                } else {
                    cout<<i+1<<"."<<player1.inventory[i]<<" ";
                }
            }
            cout<<"level: "<<player1.level<<endl;
            cout<<"health: "<<player1.health<<endl;
            cout<<"damage: "<<player1.damage<<endl;
            cout<<"mana: "<<player1.mana<<endl;
            cout<<"character's name: "<<player1.name<<endl;
        } else {
            cout<<"No data found!"<<endl;
            startgame(player1);
        }
    } else if (choice == "new game") {
        ifstream fin;
        fin.open("game_data.txt");
        if (fin) {
            string yes_or_no;
            cout<<"There is an existing data found. Are you sure to continue? (Please type 'yes' or 'no')" <<endl;
            getline(cin, yes_or_no);
            cout<<endl;
            while (yes_or_no!="yes" && yes_or_no!="no") {
                cout<<"Please enter yes or no. Answer: "<<endl;
                cin>>yes_or_no;
            }
            if (yes_or_no=="no") {
                cout<<"Hello! Welcome to the game! Please type 'new game' to start a new game or 'load game' to load previous data"<<endl<<"choice: ";
                startgame(player1);
            } else if (yes_or_no=="yes") {
                cout<<"Please enter a name for your character: "<<endl;
                getline(cin, player1.name);
            }
        } else {
            cout<<"Please enter a name for your character: ";
            getline(cin, player1.name);
        }
    }
}
void print_instructions() {
    cout<<"Defeat the final boss in 'final' to complete the game!"<<endl;
    cout<<"1. type 'fight' to fight creeps in the village"<<endl;
    cout<<"2. type 'shop' to go shopping"<<endl;
    cout<<"3. type 'help' to run errands in the village"<<endl;
    cout<<"4. type 'final' fight the final boss"<<endl;
    cout<<"5. type 'quit' to quit the game\n"<<endl;
}

string input(string user_input) {
    cout<<"------------------------------------------"<<endl;
    cin>>user_input;
    cout<<"------------------------------------------"<<endl;
    return user_input;
}


int main() {
    player player1;
    startgame(player1);
    string user_input;
    print_instructions();
    bool result = false;
    user_input = input(user_input);
    while (result!=true) {
        if (user_input=="fight") {
            enemy creep;
            battle(creep, player1);
            player1.addlevel(player1);
            player1.showLevel();
            print_instructions();
            user_input = input(user_input);
        }
        else if (user_input=="shop") {
            shop(player1);
            print_instructions();
            user_input = input(user_input);
        }
        else if (user_input=="help") {
            runErrand(player1);
            player1.addlevel(player1);
            player1.showLevel();
            print_instructions();
            user_input = input(user_input);
        }
        else if (user_input=="final") {
            boss enemy;
            if (final_battle(enemy, player1)) {
                result = true;
            } else {
                print_instructions();
                user_input = input(user_input);
            }
        }
        else if (user_input=="quit") {
            string answer;
            cout<<"\nare you sure?"<<endl;
            cout<<"type 'yes' to quit and type 'no' to return to the game\n"<<endl;
            cin>>answer;
            while (answer!="yes" && answer!="no") {
                cout<<"please input a valid answer"<<endl;
                cin>>answer;
            }
            if (answer=="yes") {
                break;
            }
            else if (answer=="no") {
                print_instructions();
                user_input = input(user_input);
            }
        }
        else {
            cout<<"please input a valid command"<<endl;
            print_instructions();
            user_input = input(user_input);
            cout<<endl;
        }
        autosave(player1);
    }
}