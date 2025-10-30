#include "Games.h"
#include <vector>
#include <string>

class MenuManager {
    vector<Games> game_list; 
    void mergeSort(vector<Games>& games, int left, int right); 
    void merge(vector<Games>& games, int left, int mid, int right);
public:
    vector<Games> get_games_data();
    vector<Games> get_top_N_games(int n);
    vector<Games> get_top_N_games_by_genre(const string& genre, int n); //heap
    vector<Games> get_top_N_games_by_platform(const string& platform, int n); //merge sort
    void compare_sort_performance(int n);
};