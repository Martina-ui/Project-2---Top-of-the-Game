#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"


using namespace bridges;


// ...existing code...
int main(int argc, char **argv) {

    // Read credentials from environment
    const char* asn_env = getenv("BRIDGES_ASSIGNMENT");
    const char* user_env = getenv("BRIDGES_USER");
    const char* key_env  = getenv("BRIDGES_KEY");

    if (!asn_env || !user_env || !key_env) {
        cerr << "ERROR: set BRIDGES_ASSIGNMENT, BRIDGES_USER and BRIDGES_KEY environment variables.\n";
        return 1;
    }

    int assignment_num = 0;
    try {
        assignment_num = stoi(string(asn_env));
    } catch (...) {
        cerr << "ERROR: BRIDGES_ASSIGNMENT must be an integer.\n";
        return 1;
    }

    // create Bridges object
    Bridges bridges (assignment_num, string(user_env), string(key_env));

    // set title
    bridges.setTitle("How to access the IGN Game Data");

    // read the IGN game data
    DataSource ds (&bridges);
    vector<Game> game_list = ds.getGameData();

    if (game_list.empty()) {
        cerr << "No game data retrieved.\n";
        return 1;
    }

    // Print a single record of the data for illustration
    cout << "Game 0:" << endl;
    cout << "\tTitle: " << game_list[0].getTitle() << endl
        << "\tPlatform Type: " << game_list[0].getPlatformType() << endl
        << "\tRating: " << game_list[0].getRating() << endl <<
        "\tGenres: ";
    for (auto& s : game_list[0].getGameGenre())
        cout << s << ", ";
    cout << endl;

    return 0;
}