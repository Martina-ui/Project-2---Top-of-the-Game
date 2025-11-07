#include "Menu.h"
#include "Game.h"
#include "MenuManager.h"
//#include "mergeSort.h"
#include <sstream>
#include <iostream>
using namespace std;

void  Menu::run_menu() {
   int choice;
   //creating a MenuManger object
   MenuManager menuManager;
       string yn;
       cout << endl << endl;

       //welcome screen
       cout << "\e[0;36m ---------------------------------------" << endl;
       cout<< "\e[0;36m|";
       cout << "\e[1;97m           W E L C O M E               ";
    cout<< "\e[0;36m|" << endl;
    cout<< "\e[0;36m|";
       cout << "\e[0;97m                  t o                  ";
    cout<< "\e[0;36m|" << endl;
    cout<< "\e[0;36m|";
       cout << "\e[1;31m         T O P  OF  THE  GAME          ";
    cout<< "\e[0;36m|" << endl;
    cout << "\e[0;36m ---------------------------------------" << endl;
       cout << endl;
       //user gets asked to continue
       cout << "\033[32m           are you ready?" << endl;
       cout << "\033[32m          press y to continue" << endl;
    getline(cin, yn);
    istringstream inStream(yn);
    while(true){
    if(yn == "y") {
      break;
      }
     else{
        cout << "Invalid choice. Please try again." << endl;
        getline(cin, yn);
        istringstream inStream(yn);
     }
}

    while (true) {
		//main menu displays
        cout << "\e[1;36m __________________________________" << endl;
        cout << "\e[1;36m|";
        cout << "\e[0;93m\e[4m	      Main Menu            \e[0m";
        cout << "\e[1;36m|" << endl;

        cout << "\e[1;36m|";
         cout<<       "\e[0;37m      1. Show Top 10 Games        ";
          cout <<  "\e[1;36m|" << endl;
        cout << "\e[1;36m|";
           cout<<          "\e[0;37m      2. Show Top N Games         ";
          cout <<  "\e[1;36m|" << endl;
        cout << "\e[1;36m|";
          cout<<        "\e[0;37m  3. Show Top N Games by Genre    ";
            cout << "\e[1;36m|" << endl;
        cout << "\e[1;36m|";
              cout <<      "\e[0;37m  4. Show Top N Games by Platform ";
            cout << "\e[1;36m|" << endl;
        cout << "\e[1;36m|";
            cout<<        "\e[0;37m     5. Show N Games of rank R    ";
            cout << "\e[1;36m|" << endl;
        cout << "\e[1;36m|";
                    cout<< "\e[0;37m            6. Exit               ";
              cout <<"\e[0;36m|" << endl;
        cout << "\e[1;36m ---------------------------------- "<< endl;
        cout << endl;
        //user enters which option they want
        cout << "\e[0;31mEnter your choice: ";
        cout << endl;

        string user_choice;
        string user_input;
        string genre;
        string platform;
        string rank;

        getline(cin, user_choice);
        istringstream inStream(user_choice);
        //checks if user choice is valid
		while(true){
   			 if(user_choice != "1" && user_choice != "2" && user_choice != "3" && user_choice != "4" && user_choice != "5" && user_choice != "6") {
      			cout << "Invalid choice. Please try again." << endl;
        		getline(cin, user_choice);
        		istringstream inStream(user_choice);
      		}
     		else{
       			 break;
    	 }
         }
        choice =stoi(user_choice);

        //if user choses option 1 to get top 10 games
        if (choice == 1) {
            cout << "\e[1;32mTop 10 Games" << endl;
            menuManager.Mget_top_N_games(10);
        }
        //if user choses option 2 to get top N games
        else if (choice == 2){
            cout<< "\e[1;33mEnter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            int input = stoi(user_input);
            //displays top N games
            menuManager.Mget_top_N_games(input);
        }
        //if user choses option 3 to get top N games via genre
        else if (choice == 3) {
            cout<< "\e[1;33mEnter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            cout<< "\e[0;97mWould you like to see the top genres?" << endl;
            cout << "\e[0;97mpress y for yes or n for no" << endl;
            //getline(cin, yn);
            while(true){
              getline(cin, yn);
    			if(yn != "y" && yn != "n") {
      				cout << "Invalid choice. Please try again." << endl;
        			istringstream inStream(yn);
      			}
     			else{
        			break;
     			}
            }
            //displays top game genres
            if (yn == "y") {
                cout << "\e[4;33m              Genre Menu             " << endl;
                cout << "\e[0;33mAction         Shooter        Puzzle" << endl;
                cout << "Sports        Simulation        RPG " << endl;
                cout << "Music         Adventure       Racing " << endl;
                cout << "Fighting      Strategy     Platformer" << endl;
                cout << endl << endl;

            }
            cout<< "\e[0;97mEnter the desired genre: " <<endl;
            getline(cin, genre);
            int input = stoi(user_input);
            //display top N games by genre
            menuManager.Mget_top_N_games_by_genre(genre, input);
        }
        //if user choses option 4 to get top N games via platform
        else if (choice == 4) {
            cout<< "\e[0;97mEnter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            cout<< "Would you like to see the top platforms?" << endl;
            cout << "press y for yes or n for no" << endl;
            getline(cin, yn);
            //displays top game platforms
            while(true){
    			if(yn != "y" && yn != "n") {
      				cout << "Invalid choice. Please try again." << endl;
        			getline(cin, yn);
        			istringstream inStream(yn);
      			}
     			else{
        			break;
     			}
            }
            //displays top game platforms
            if (yn == "y") {
                cout << "\e[4;33m              Platform Menu              " << endl;

                cout << "\e[0;33mMacintosh, Playstation(1, 2,3,4, Vita)" << endl;
                cout <<          "Xbox(One, 360), iPhone, Nintendo(3DS), PC" << endl;
                cout << endl << endl;

            }
            cout<< "\e[0;97mEnter the desired platform: " <<endl;
            getline(cin, platform);
            int input = stoi(user_input);
            //display top N games by platform
            menuManager.Mget_top_N_games_by_platform(platform, input);
         }
        //if user choses option 5 to get top N games via ranking
        else if (choice == 5) {
            cout<< "\e[0;97mEnter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            cout<< "Enter the desired ranking: " <<endl;
            getline(cin, rank);
            int input = stoi(user_input);
            float rating =  stof(rank);
            //display top N games by ranking
            menuManager.Mget_top_N_games_by_rank(rating, input);
        }
         //if user choses option 6 to exit out of the game
        else if (choice == 6) {
            cout << "\e[1;96mThanks for playing!" << endl;
            break;
        } else {
            cout << "\e[0;37mInvalid choice. Please try again." << endl;
        }
    }
}
