#include<vector>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"
#include "../Games.h"
#include<iostream>
using namespace std;
using namespace bridges;

//merge sort functions
void merge(vector<Games>& data, int left, int mid, int right);
void mergeSort(vector<Games>& data, int left, int right);

