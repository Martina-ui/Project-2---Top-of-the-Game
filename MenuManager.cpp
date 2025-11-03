#include "MenuManager.h"
#include <iostream>
#include <string>
#include <vector>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"
#include <stdlib.h>
#include <queue>
#include "mergeSort.h"
#include<chrono>
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


void MenuManager::get_top_N_games(int n) {
	auto start = chrono::high_resolution_clock::now();
	vector<Games> games = get_games_data();
	mergeSort(games, 0, games.size() - 1);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "Merge Sort: " << duration.count() << " microseconds" << endl;

	for (int i = 0; i < n; i++) {
		//cout << games[i].get_title() << endl;
        cout << "Game " << i+1 << endl;
	    cout << "\tTitle: " << games[i].get_title() << endl
		<< "\tPlatform Type: " << games[i].get_platform_type() << endl
		<< "\tRating: " << games[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < games[i].get_genre().size(); j++){
           cout << games[i].get_genre()[j] << " " ;
         };
         cout << endl << endl;

	}
}


void MenuManager::get_top_N_games_by_genre(const string& genre, int n) {
	vector<Games> games = get_games_data();
	vector<Games> updated_games;
	for (int i = 0; i < games.size(); i++) {
		vector<string> gen = games[i].get_genre();
		for (int j = 0; j < gen.size(); j++) {
			if (gen[j] == genre) {
				updated_games.push_back(games[i]);
			}
		}
	}
	auto start = chrono::high_resolution_clock::now();
	mergeSort(updated_games, 0, updated_games.size() - 1);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	for (int i = 0; i < n; i++) {
		//cout << games[i].get_title() << endl;
                int temp = i+1;
        cout << "Game " << temp << endl;
	    cout << "\tTitle: " << updated_games[i].get_title() << endl
		<< "\tPlatform Type: " << updated_games[i].get_platform_type() << endl
		<< "\tRating: " << updated_games[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < updated_games[i].get_genre().size(); j++){
           cout << updated_games[i].get_genre()[j] << " " ;
         };

cout << endl;
	}
	cout << "Merge Sort: " << duration.count() << " microseconds" << endl;

}

//merge sort
void MenuManager::get_top_N_games_by_platform(const string& platform, int n) {

	vector<Games> games = get_games_data();
	vector<Games> updated_games;
	for (int i = 0; i < games.size(); i++) {
		if(platform == games[i].get_platform_type()) {
			updated_games.push_back(games[i]);
		}
	}
	auto start = chrono::high_resolution_clock::now();
	mergeSort(updated_games, 0, updated_games.size() - 1);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	for (int i = 0; i < n; i++) {
		//cout << games[i].get_title() << endl;
         int temp = i+1;
        cout << "Game " << temp << endl;
	    cout << "\tTitle: " << updated_games[i].get_title() << endl
		<< "\tPlatform Type: " << updated_games[i].get_platform_type() << endl
		<< "\tRating: " << updated_games[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < updated_games[i].get_genre().size(); j++){
           cout << updated_games[i].get_genre()[j] << " " ;
         };
cout << endl;

	}
	cout << "Merge Sort: " << duration.count() << " microseconds" << endl;
}


