#include "MenuManager.h"
#include <iostream>
#include <string>
#include <vector>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"
#include <stdlib.h>
#include <queue>
using namespace std;
using namespace bridges;

//i believe this should get the data we need for each game
vector<Games> MenuManager::get_games_data() {
    char* mySecretUser = getenv("SECRET_HOLDING_USER_ID"); 
	char* mySecretAPI = getenv("SECRET_HOLDING_API_KEY");

	Bridges bridges(1, mySecretUser, mySecretAPI);

	DataSource ds (&bridges);
	vector<Game> game_list = ds.getGameData();
    vector<Games> games_info;
	for (const auto& g : game_list) {
		Games game(g.getTitle(), g.getPlatformType(), g.getGameGenre(), static_cast<float>(g.getRating()));
		game.set_title(g.getTitle());
		game.set_platform_type(g.getPlatformType());
		game.set_genres(g.getGameGenre());
		game.set_rating(static_cast<float>(g.getRating()));
		games_info.push_back(game);
	}
	return games_info; 
}

void MenuManager::merge(vector<Games>& games, int left, int mid, int right) {
	
}

void MenuManager::mergeSort(vector<Games>& games, int left, int right) {
	
}

vector<Games> MenuManager::get_top_N_games(int n) {
	
}

//heap
vector<Games> MenuManager::get_top_N_games_by_genre(const string& genre, int n) { 
	
}

//merge sort
vector<Games> MenuManager::get_top_N_games_by_platform(const string& platform, int n) {
	
}

void MenuManager::compare_sort_performance(int n) {

	
}