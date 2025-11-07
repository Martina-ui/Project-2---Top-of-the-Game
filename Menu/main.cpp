#include <iostream>
#include <string>
#include <vector>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"
#include "../Game and Sorting/Games.h"
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
	char* mySecretUser = getenv("SECRET_HOLDING_USER_ID"); 
	char* mySecretAPI = getenv("SECRET_HOLDING_API_KEY");
    //runs game program
	Menu menu;
        menu.run_menu();

	return 0;
}