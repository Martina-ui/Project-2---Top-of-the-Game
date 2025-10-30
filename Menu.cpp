#include "Menu.h"
#include <iostream>
using namespace std;

void  Menu::run_menu() {
    int user_choice;
    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Show Top 10 Games" << endl; //Unless someone WANTS to use a merge sort or heap here i say let's just use whatever
        cout << "2. Show Top N Games by Genre (Heap)" << endl;
        cout << "3. Show Top N Games by Platform (Merge Sort)" << endl;
        cout << "4. Compare Heap vs. Merge Sort Performance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> user_choice;
        
        //once we finish the functions we will call them here based on user choice
        if (user_choice == 1) {
            //display top 10 games
        } else if (user_choice == 2) {
            //display top N games by genre
        } else if (user_choice == 3) {
            //display top N games by platform
        } else if (user_choice == 4) {
            //comparison logic
        } else if (user_choice == 5) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}