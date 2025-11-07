#include<vector>
#include "Bridges.h"
#include "DataSource.h"
#include "data_src/Game.h"
#include "../Games.h"
#include<iostream>
using namespace std;
using namespace bridges;



//class for heap sort functions
class MaxHeap {
private:
    vector<Games> heap;

    int leftChild(int i) const;
    int rightChild(int i) const;
    int parent(int i) const;
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    static bool isBetter(const Games &a, const Games &b);
    MaxHeap();
    MaxHeap(const vector<Games> &items);
    void insert(const Games &g);
    bool empty() const;
    int size() const;
    void heapify(vector<Games>& games, int n, int i);
    void heapSort(vector<Games>& games);
    Games extractMax();

};