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
//export SECRET_HOLDING_USER_ID=martinadelger -> only needed when you first run the program
//export SECRET_HOLDING_API_KEY=1283988499612 -> only needed when you first run the program
//./run.sh

int main(int argc, char **argv) {
    //test to see if the code reads the data
	cout << "Bridges Test: is this printed\n";

	//got these from the prog quiz 4 FAQs
	char* mySecretUser = getenv("SECRET_HOLDING_USER_ID"); 
	char* mySecretAPI = getenv("SECRET_HOLDING_API_KEY");

	cout << "User ID: " << mySecretUser << endl;
	cout << "API Key: " << mySecretAPI << endl;

	Bridges bridges(1, mySecretUser, mySecretAPI);

	//set title
	bridges.setTitle("How to access the IGN Game Data");

	//read the IGN game data
	DataSource ds (&bridges);
	vector<Game> game_list = ds.getGameData();

	//Print a single record of the data for illustration
	cout << "Game 0:" << endl;
	cout << "\tTitle: " << game_list[0].getTitle() << endl
		<< "\tPlatform Type: " << game_list[0].getPlatformType() << endl
		<< "\tRating: " << game_list[0].getRating() << endl <<
		"\tGenres: ";

	for (auto& s : game_list[0].getGameGenre()) {
		if (s == game_list[0].getGameGenre().back()) {
			cout << s << endl;
			break;
		}
		cout << s << "," << endl;
	}

	//once we are done we'll delete the code above and implement the menu system below
	//but for now we can keep it to test if the data is working and also you guys can 
	//can see what it looks like to get the data from bridges

	//Menu menu; //uncomment once menu manager is done to test
	//menu.run_menu();
	return 0;
}