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
       string yn;
       cout << endl << endl;
       cout << "\e[1;97m           W E L C O M E             "<< endl;
       cout << "                 t o                  "<< endl;
       cout << "\e[3m         T O P  OF  THE  GAME         \e[0m"<< endl;
       cout << "ready to see the games that are on the top of there game?" << endl;
       cout << "\033[32mpress y to continue" << endl;
    getline(cin, yn);
    istringstream inStream(yn);
    if(yn == "y") {


    while (true) {

        cout << "\e[1;93m __________________________________" << endl;
        cout << "\e[1;93m|";
        cout << "\e[0;93m\e[4m	      Main Menu            \e[0m";
        cout << "\e[1;93m|" << endl;

        cout << "\e[1;93m|";
         cout<<       "\e[0;37m      1. Show Top 10 Games        ";
          cout <<  "\e[1;93m|" << endl;
        cout << "\e[1;93m|";
           cout<<          "\e[0;37m      2. Show Top N Games         ";
          cout <<  "\e[1;93m|" << endl;
        cout << "\e[1;93m|";
          cout<<        "\e[0;37m  3. Show Top N Games by Genre    ";
            cout << "\e[1;93m|" << endl;
        cout << "\e[1;93m|";
              cout <<      "\e[0;37m  4. Show Top N Games by Platform ";
            cout << "\e[1;93m|" << endl;
        cout << "\e[1;93m|";
            cout<<        "\e[0;37m     5. Show N Games of rank R    ";
            cout << "\e[1;93m|" << endl;
        cout << "\e[1;93m|";
                    cout<< "\e[0;37m            6. Exit               ";
              cout <<"\e[1;93m|" << endl;
        cout << "\e[1;93m ---------------------------------- "<< endl;
        cout << endl;
        cout << "\033[32mEnter your choice: ";

        string user_choice;
        string user_input;
        string genre;
        string platform;
        string rank;

        getline(cin, user_choice);
        istringstream inStream(user_choice);

        choice =stoi(user_choice);

        //once we finish the functions we will call them here based on user choice
        if (choice == 1) {
            cout << "\e[0;37mTop 10 Games" << endl;

            menuManager.get_top_N_games(10);
        }
        else if (choice == 2){
            cout<< "\e[0;37mEnter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            int input = stoi(user_input);
            menuManager.get_top_N_games(input);
        }
        else if (choice == 3) {
            //display top N games by genre
            cout<< "\e[0;37mEnter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            cout<< "Would you like to see the top genres?" << endl;
            cout << "press y for yes or n for no" << endl;
            getline(cin, yn);
            if (yn == "y") {
                cout << "\e[0;33mAction      Shooter      Puzzle" << endl;
                cout << "Sports     Simulation      RPG " << endl;
                cout << "Music       Adventure     Racing " << endl;
                cout << "Fighting    Strategy   Platformer" << endl;

            }
            cout<< "\e[0;37mEnter the desired genre: " <<endl;
            getline(cin, genre);
            int input = stoi(user_input);
            menuManager.get_top_N_games_by_genre(genre, input);
        }
        else if (choice == 4) {
            //display top N games by platform

            cout<< "\e[0;37mEnter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            cout<< "Would you like to see the top platforms?" << endl;
            cout << "press y for yes or n for no" << endl;
            getline(cin, yn);
            if (yn == "y") {
                cout << "Playstation(1, 2,3,4, Vita)" << endl;
                cout << "Macintosh    Nintendo (3DS)" << endl;
                cout << "Xbox (One, 360)  iPhone  PC" << endl;

            }
            cout<< "Enter the desired platform: " <<endl;
            getline(cin, platform);
            int input = stoi(user_input);
            menuManager.get_top_N_games_by_platform(platform, input);
         }
        else if (choice == 5) {
            cout<< "\e[0;37mEnter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            cout<< "Enter the desired ranking: " <<endl;
            getline(cin, rank);
            int input = stoi(user_input);
            float rating =  stof(rank);
            menuManager.get_top_N_games_by_rank(rating, input);
        }
        else if (choice == 6) {
            cout << "\e[0;37mExiting the program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}}