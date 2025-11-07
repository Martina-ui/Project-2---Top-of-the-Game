#pragma once
#include "../Game and Sorting/Games.h"
#include "data_src/Game.h"
#include <vector>
#include <string>
using namespace std;

//MenuManager class contains fucntions which give the output of the menu options
class MenuManager {

		vector<Games> game_list;
	public:
		vector<Games> get_games_data();
		void Mget_top_N_games(int n);
		void Mget_top_N_games_by_genre(const string& genre, int n); //heap
		void  Mget_top_N_games_by_platform(const string& platform, int n); //merge sort
        void  Mget_top_N_games_by_rank(const float& rank, int n);

	void Hget_top_N_games(int n);
	void Hget_top_N_games_by_genre(const string& genre, int n); //heap
	void Hget_top_N_games_by_platform(const string& platform, int n); //merge sort
	void Hget_top_N_games_by_rank(const float& rank, int n);
		//void compare_sort_performance(int n);
};