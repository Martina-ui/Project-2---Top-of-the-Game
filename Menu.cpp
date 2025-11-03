#include "Menu.h"
#include "Game.h"
#include "MenuManager.h"
#include "mergeSort.h"
#include <sstream>
#include <iostream>
using namespace std;

void  Menu::run_menu() {
   int choice;
   MenuManager menuManager;
    while (true) {
        cout << " __________________________________"<< endl;
        cout << "|           Main Menu              |" << endl;
        cout << "|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   |"<< endl;
        cout << "|      1. Show Top 10 Games        |" << endl; //Unless someone WANTS to use a merge sort or heap here i say let's just use whatever
        cout << "|      2. Show Top N Games         |" << endl;
        cout << "|  3. Show Top N Games by Genre    |" << endl;
        cout << "|  4. Show Top N Games by Platform |" << endl;
        cout << "|            5. Exit               |" << endl;
        cout << " ---------------------------------- "<< endl;
        cout << endl;
        cout << "Enter your choice: ";

        string user_choice;
        string user_input;
        string genre;
        string platform;
        getline(cin, user_choice);
        istringstream inStream(user_choice);

        choice =stoi(user_choice);

        //once we finish the functions we will call them here based on user choice
        if (choice == 1) {
            cout << "Top 10 Games" << endl;

            menuManager.get_top_N_games(10);
        }
        else if (choice == 2){
            cout<< "Enter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            int input = stoi(user_input);
            menuManager.get_top_N_games(input);
        }
        else if (choice == 3) {
            //display top N games by genre
            cout<< "Enter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            cout<< "Enter the desired genre: " <<endl;
            getline(cin, genre);
            int input = stoi(user_input);
            menuManager.get_top_N_games_by_genre(genre, input);
        }
        else if (choice == 4) {
            //display top N games by platform
            cout<< "Enter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            cout<< "Enter the desired platform: " <<endl;
            getline(cin, platform);
            int input = stoi(user_input);
            menuManager.get_top_N_games_by_platform(platform, input);
         }
        else if (choice == 5) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}