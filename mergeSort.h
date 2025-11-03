#include<vector>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"
#include "Games.h"
#include<iostream>
using namespace std;
using namespace bridges;

//idk
void merge(vector<Games>& data, int left, int mid, int right);
void mergeSort(vector<Games>& data, int left, int right);
void topNgames(int n);
void topNgenre(const string& genre, int n);
void topNplatform(const string& platform, int n);
//idkkk