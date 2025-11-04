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

//from geeksforgeeks, why
// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void MenuManager::merge(vector<Games>& data, int left, int mid, int right) {
	int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<Games> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = data[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = data[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i].get_rating() >= R[j].get_rating()) {
            data[k] = L[i];
            i++;
        }
        else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

void MenuManager::mergeSort(vector<Games>& data, int left, int right) {
	if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
    cout << endl;
}

void MenuManager::get_top_N_games_mergeSort(int n) {
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

void MenuManager::get_top_N_games_by_genre_mergeSort(const string& genre, int n) { 
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

void MenuManager::get_top_N_games_by_platform_mergeSort(const string& platform, int n) {
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

// void MenuManager::compare_sort_performance(int n) {

	
// }