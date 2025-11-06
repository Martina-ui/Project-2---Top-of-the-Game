
#include "MenuManager.h"
//#include "HeapSort.cpp"
#include <iostream>
#include <string>
#include <vector>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"
#include <stdlib.h>
#include <queue>
#include "mergeSort.h"
#include "HeapSort.h"
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




void MenuManager::Mget_top_N_games(int n) {
    vector<Games> games = get_games_data();
	auto start = chrono::high_resolution_clock::now();
	mergeSort(games, 0, games.size() - 1);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);


	for (int i = 0; i < n; i++) {
		//cout << games[i].get_title() << endl;
        cout << "\e[1;32mGame " << i+1 << endl;
	    cout << "\e[1;32m\tTitle: " << games[i].get_title() << endl
		<< "\tPlatform Type: " << games[i].get_platform_type() << endl
		<< "\tRating: " << games[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < games[i].get_genre().size(); j++){
           cout << games[i].get_genre()[j] << " " ;
         };
         cout << endl << endl;

	}
    cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mMerge Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
    Hget_top_N_games(n);
    cout << endl << endl << endl;
}


void MenuManager::Mget_top_N_games_by_genre(const string& genre, int n) {
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
        cout << "\e[1;32mGame " << temp << endl;
	    cout << "\e[1;32m\tTitle: " << updated_games[i].get_title() << endl
		<< "\tPlatform Type: " << updated_games[i].get_platform_type() << endl
		<< "\tRating: " << updated_games[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < updated_games[i].get_genre().size(); j++){
           cout << updated_games[i].get_genre()[j] << " " ;
         };

cout << endl;
	}
     cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mMerge Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
    Hget_top_N_games_by_genre(genre, n);

    cout << endl << endl << endl;
}

//merge sort
void MenuManager::Mget_top_N_games_by_platform(const string& platform, int n) {

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
        cout << "\e[1;32mGame " << temp << endl;
	    cout << "\e[1;32m\tTitle: " << updated_games[i].get_title() << endl
		<< "\tPlatform Type: " << updated_games[i].get_platform_type() << endl
		<< "\tRating: " << updated_games[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < updated_games[i].get_genre().size(); j++){
           cout << updated_games[i].get_genre()[j] << " " ;
         };
cout << endl;

	}
	 cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mMerge Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
    Hget_top_N_games_by_platform(platform, n);

    cout << endl << endl << endl;
}

void MenuManager::Mget_top_N_games_by_rank(const float& rank, int n){

	vector<Games> games = get_games_data();
	vector<Games> updated_games;
	for (int i = 0; i < games.size(); i++) {
		if(rank == games[i].get_rating()) {
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
        cout << "\e[1;32mGame " << temp << endl;
	    cout << "\e[0;32m\tTitle: " << updated_games[i].get_title() << endl
		<< "\tPlatform Type: " << updated_games[i].get_platform_type() << endl
		<< "\tRating: " << updated_games[i].get_rating() << endl <<
		"\tGenres: ";
         for(int j =0; j < updated_games[i].get_genre().size(); j++){
           cout << updated_games[i].get_genre()[j] << " " ;
         };
    cout << endl;

	}
    cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mMerge Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
    Hget_top_N_games_by_rank(rank, n);

    cout << endl << endl << endl;
}



  void MenuManager::Hget_top_N_games(int N){
   auto start = chrono::high_resolution_clock::now();
	vector<Games> allGames = get_games_data();
	MaxHeap heap(allGames);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    /*
    auto startBuild = std::chrono::high_resolution_clock::now();
    MaxHeap heap(allGames);
    auto endBuild = std::chrono::high_resolution_clock::now();

    auto startExtract = std::chrono::high_resolution_clock::now();
    vector<Games> result;
    result.reserve(N);

    for (int i = 0; i < N && !heap.empty(); i++) {
        Games g = heap.extractMax();
        result.push_back(g);
    }

    auto endExtract = std::chrono::high_resolution_clock::now();

    auto buildMicros = std::chrono::duration_cast<std::chrono::microseconds>(endBuild - startBuild).count();
    auto extractMicros = std::chrono::duration_cast<std::chrono::microseconds>(endExtract - startExtract).count();

    size_t numGames = allGames.size();
    size_t bytesPerGame = sizeof(Games);
    size_t totalBytes = numGames * bytesPerGame;
*/
    cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mHeap Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
         cout<< "\e[1;36m-----------------------------------------" << endl;
    cout << endl << endl << endl;
/*
    std::cout << "[Heap] Extracted top " << result.size() << " in "
              << extractMicros << " microseconds.\n";

    */
}

 void MenuManager::Hget_top_N_games_by_genre(const string& genre, int n){
   vector<Games> allGames = get_games_data();
	vector<Games> gamesOfGenre;
	for (int i = 0; i < allGames.size(); i++) {
		vector<string> genres = allGames[i].get_genre();
		for (int j = 0; j < genres.size(); j++) {
			if (genres[j] == genre) {
				gamesOfGenre.push_back(allGames[i]);
			}
		}
	}
	auto start = chrono::high_resolution_clock::now();
	MaxHeap heap(gamesOfGenre);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mHeap Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
         cout<< "\e[1;36m-----------------------------------------" << endl;
    cout << endl << endl << endl;
}
 void MenuManager::Hget_top_N_games_by_platform(const string& platform, int n){
   vector<Games> allGames = get_games_data();
	vector<Games> gamesOfPlatform;
	for (int i = 0; i < allGames.size(); i++) {
		if(platform == allGames[i].get_platform_type()) {
			gamesOfPlatform.push_back(allGames[i]);
		}
	}
	auto start = chrono::high_resolution_clock::now();
    MaxHeap heap(gamesOfPlatform);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mHeap Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
         cout<< "\e[1;36m-----------------------------------------" << endl;
    cout << endl << endl << endl;
}


void MenuManager::Hget_top_N_games_by_rank(const float& rank, int n){
	vector<Games> allGames = get_games_data();
	vector<Games> gamesOfRank;
	for (int i = 0; i < allGames.size(); i++) {
		if(rank == allGames[i].get_rating()) {
			gamesOfRank.push_back(allGames[i]);
		}
	}
	auto start = chrono::high_resolution_clock::now();
	MaxHeap heap(gamesOfRank);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout<< "\e[1;36m-----------------------------------------" << endl;
	cout << "\e[1;37mHeap Sort" << "\e[0;37m : " << duration.count() << " microseconds" << endl;
         cout<< "\e[1;36m-----------------------------------------" << endl;
    cout << endl << endl << endl;
}
