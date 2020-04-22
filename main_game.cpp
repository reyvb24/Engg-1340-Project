#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void print_instructions() {
    cout<<"1. type 'fight' to fight creeps in the village"<<endl;
    cout<<"2. type 'shop' to go shopping"<<endl;
    cout<<"3. type 'help' to run errands in the village"<<endl;
    cout<<"4. type 'final' fight the final boss"<<endl;
    cout<<"5. type 'quit' to quit the game\n"<<endl;
}

void count_remaining_actions(int check) {
    int points_remaining = 3 - check%3;
    cout<<"you have "<<points_remaining<<" points remaining today\n"<<"------------------------------------------"<<endl;
}

string input(string user_input) {
    cin>>user_input;
    cout<<"------------------------------------------"<<endl;
    return user_input;
}

int main() {
    string user_input;
    int check = 0;
    print_instructions();
    count_remaining_actions(check);
    user_input = input(user_input);
    while (true) {
        if (user_input=="fight") {
            check++;
            print_instructions();
            count_remaining_actions(check);
            user_input = input(user_input);
        }
        else if (user_input=="shop") {
            check++;
            print_instructions();
            count_remaining_actions(check);
            user_input = input(user_input);
        }
        else if (user_input=="help") {
            check++;
            print_instructions();
            count_remaining_actions(check);
            user_input = input(user_input);
        }
        else if (user_input=="final") {
            check++;
            print_instructions();
            count_remaining_actions(check);
            user_input = input(user_input);
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
            check = check%3;
            print_instructions();
            count_remaining_actions(check);
            user_input = input(user_input);
            cout<<endl;
        }
    }
}