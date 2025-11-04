#include "Menu.h"
#include "MenuManager.h"
#include "HeapSort.h"
#include <sstream>
#include <iostream>
using namespace std;

void  Menu::run_menu() {
   int choice;
   MenuManager menuManager;
   HeapSort Maxheap;
    while (true) {
        cout << " __________________________________"<< endl;
        cout << "|           Main Menu              |" << endl;
        cout << "|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   |"<< endl;
        cout << "|           Merge Sort             |" << endl; 
        cout << "|      1. Show Top 10 Games        |" << endl; 
        cout << "|      2. Show Top N Games         |" << endl;
        cout << "|  3. Show Top N Games by Genre    |" << endl;
        cout << "|  4. Show Top N Games by Platform |" << endl;
        cout << "|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   |"<< endl;
        cout << "|           Heap Sort              |" << endl; 
        cout << "|      5. Show Top 10 Games        |" << endl; 
        cout << "|      6. Show Top N Games         |" << endl;
        cout << "|  7. Show Top N Games by Genre    |" << endl;
        cout << "|  8. Show Top N Games by Platform |" << endl;
        cout << "|            9. Exit               |" << endl;
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
            cout << "Top 10 Games (Merge Sort)" << endl;

            menuManager.get_top_N_games_mergeSort(10);
        }
        else if (choice == 2){
            cout << "Enter the number of games you'd like to show: " << endl;
            getline(cin, user_input);
            int input = stoi(user_input);
            menuManager.get_top_N_games_mergeSort(input);
        }
        else if (choice == 3) {
            //display top N games by genre
            cout << "Enter the number of games you'd like to show: " << endl;
            getline(cin, user_input);
            cout << "\nAvailable Genres:\n";
            cout << "Action, Adventure, RPG, Shooter, Fighting, Platformer," << endl;
            cout << "Puzzle, Racing, Sports, Strategy, Simulation, Survival," << endl;
            cout << "Horror, MMO, Music, Sandbox, Stealth, Indie, Visual Novel," << endl;
            cout << "Card Game, Party, Casual" << endl;
            cout << "Enter the desired genre: " << endl;
            getline(cin, genre);
            int input = stoi(user_input);
            menuManager.get_top_N_games_by_genre_mergeSort(genre, input);
        }
        else if (choice == 4) {
            //display top N games by platform
            cout << "Enter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            cout << "\nAvailable Platforms:\n";
            cout << "PC, PlayStation 5, PlayStation 4, Xbox One, Xbox Series X," << endl;
            cout << "Nintendo Switch, Nintendo Wii, Nintendo DS, PS Vita, PSP," << endl;
            cout << "Mac, Linux, Mobile, Browser, Stadia" << endl;
            cout << "Enter the desired platform: " << endl;
            getline(cin, platform);
            int input = stoi(user_input);
            menuManager.get_top_N_games_by_platform_mergeSort(platform, input);
         }
         if (choice == 5) {
            cout << "Top 10 Games (Heap Sort)" << endl;
            Maxheap.runHeapTopNOnDataset(menuManager.get_games_data(), 10);
        }
        else if (choice == 6){
            cout << "Enter the number of games you'd like to show: " << endl;
            getline(cin, user_input);
            int input = stoi(user_input);
            Maxheap.getTopN_Heap(menuManager.get_games_data(), input);
        }
        else if (choice == 7) {
            //display top N games by genre
            cout << "Enter the number of games you'd like to show: " << endl;
            getline(cin, user_input);
            cout << "\nAvailable Genres:\n";
            cout << "Action, Adventure, RPG, Shooter, Fighting, Platformer," << endl;
            cout << "Puzzle, Racing, Sports, Strategy, Simulation, Survival," << endl;
            cout << "Horror, MMO, Music, Sandbox, Stealth, Indie, Visual Novel," << endl;
            cout << "Card Game, Party, Casual" << endl;
            cout << "Enter the desired genre: " << endl;
            getline(cin, genre);
            int input = stoi(user_input);
            //insert heap function for finding by genre here
        }
        else if (choice == 8) {
            //display top N games by platform
            cout << "Enter the number of games you'd like to show: " <<endl;
            getline(cin, user_input);
            cout << "\nAvailable Platforms:\n";
            cout << "PC, PlayStation 5, PlayStation 4, Xbox One, Xbox Series X," << endl;
            cout << "Nintendo Switch, Nintendo Wii, Nintendo DS, PS Vita, PSP," << endl;
            cout << "Mac, Linux, Mobile, Browser, Stadia" << endl;
            cout << "Enter the desired platform: " << endl;
            getline(cin, platform);
            int input = stoi(user_input);
            //insert heap function for finding by platform here
         }
        else if (choice == 9) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}