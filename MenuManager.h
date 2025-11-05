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
    vector<Games> heap;

    //merge sort operations
    void mergeSort(vector<Games>& data, int left, int right); 
    void merge(vector<Games>& data, int left, int mid, int right);

    //heap sort variables and operations
    int leftChild(int i) const  { return 2 * i + 1; }
    int rightChild(int i) const { return 2 * i + 2; }
    int parent(int i) const     { return (i - 1) / 2; }
    void heapifyUp(int index);
    void heapifyDown(int index);
public:
    //merge sort functions
    vector<Games> get_games_data();
    void get_top_N_games_mergeSort(int n);
    void get_top_N_games_by_genre_mergeSort(const string& genre, int n); 
    void get_top_N_games_by_platform_mergeSort(const string& platform, int n); 
    void  get_top_N_games_by_rank_mergeSort(const float& rank, int n);
    
    //heap sort functions
    void HeapSort(const vector<Games> &items);
    void insert(const Games &g);
    bool empty() const;
    int size() const;
    Games extractMax();
    void printHeapTopNOnDataset(const vector<Games>& gamesdata, int N);
    vector<Games> getTopN_Heap(const vector<Games>& allGames, int N);
    //void printGame(const Games& g);
};