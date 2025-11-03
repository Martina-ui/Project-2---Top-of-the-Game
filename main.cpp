#include <iostream>
#include <string>
#include <vector>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"
#include "Games.h" 
#include "Menu.h"
#include <stdlib.h>
#include <queue>
using namespace std;
using namespace bridges;

//to run main in the terminal use these commands:
//chmod +x run.sh
//export SECRET_HOLDING_USER_ID=martinadelger //-> only needed when you first run the program
//export SECRET_HOLDING_API_KEY=1283988499612 //-> only needed when you first run the program
//run.sh


int main(int argc, char **argv) {
    //test to see if the code reads the data
	//cout << "Bridges Test: is this printed\n";

	//got these from the prog quiz 4 FAQs
	char* mySecretUser = getenv("SECRET_HOLDING_USER_ID"); 
	char* mySecretAPI = getenv("SECRET_HOLDING_API_KEY");
/*
	//cout << "User ID: " << mySecretUser << endl;
	//cout << "API Key: " << mySecretAPI << endl;

	Bridges bridges(1, mySecretUser, mySecretAPI);

	//set title
	bridges.setTitle("How to access the IGN Game Data");

	//read the IGN game data
	DataSource ds (&bridges);
	vector<Game> game_list = ds.getGameData();

*/
	Menu menu;
        menu.run_menu();

	return 0;
}