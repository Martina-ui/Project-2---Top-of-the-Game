#include <iostream>
#include <string>
#include <vector>
#include "Bridges.h"
#include "DataSource.h"
#include "BSTElement.h"
#include "data_src/Game.h"
#include <stdlib.h>
#include <queue>
using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	cout << "Bridges Test: I can see this is getting printed\n";

	char* mySecretUser = getenv("SECRET_HOLDING_USER_ID"); //got these from the prog 4 FAQs
	char* mySecretAPI = getenv("SECRET_HOLDING_API_KEY");

	cout << "User ID: " << mySecretUser << endl;
	cout << "API Key: " << mySecretAPI << endl;

	Bridges bridges(1, mySecretUser, mySecretAPI);

	// set title
	bridges.setTitle("How to access the IGN Game Data");

	// read the IGN game data
	DataSource ds (&bridges);
	vector<Game> game_list = ds.getGameData();

	// Print a single record of the data for illustration
	cout << "Game 0:" << endl;
	cout << "\tTitle: " << game_list[0].getTitle() << endl
		<< "\tPlatform Type: " << game_list[0].getPlatformType() << endl
		<< "\tRating: " << game_list[0].getRating() << endl <<
		"\tGenres: ";
	for (auto& s : game_list[0].getGameGenre())
		cout << s << "," << endl;

	return 0;
}