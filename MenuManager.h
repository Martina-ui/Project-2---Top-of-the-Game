#include "Games.h"
#include <iostream>
#include <string>
#include <vector>
#include "data_src/Game.h"
using namespace std;
using bridges::dataset::Game;
#pragma once

class MenuManager {
    vector<Games> game_list; 
    void mergeSort(vector<Games>& data, int left, int right); 
    void merge(vector<Games>& data, int left, int mid, int right);
public:
    //merge sort functions
    vector<Games> get_games_data();
    vector<Games> get_top_N_games_mergeSort(int n);
    vector<Games> get_top_N_games_by_genre_mergeSort(const string& genre, int n); 
    vector<Games> get_top_N_games_by_platform_mergeSort(const string& platform, int n); 
    //void compare_sort_performance(int n);
};