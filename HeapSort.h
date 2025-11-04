#include "data_src/Game.h"   //Bridges Game class (from Martina)
#include "Games.h"           //local Games class
#include <vector>
#include <string>
#include <iostream>
using bridges::dataset::Game;
using namespace std;

class HeapSort {
private:
    vector<Games> heap;
    int leftChild(int i) const  { return 2 * i + 1; }
    int rightChild(int i) const { return 2 * i + 2; }
    int parent(int i) const     { return (i - 1) / 2; }
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    HeapSort() {}
    HeapSort(const vector<Games> &items);
    void insert(const Games &g);
    bool empty() const;
    int size() const;
    Games extractMax();

    //heap game functions
    // vector<Games> convertBridgesToLocal(const vector<Game>& bridgeList);
    // void runHeapTopNOnDataset(const vector<Game>& bridgeList, int N);
    // vector<Games> getTopN_Heap(const vector<Games>& allGames, int N);
    // void printGame(const Games& g);

    //using games data NOT bridges
    void printHeapTopNOnDataset(const vector<Games>& gamesdata, int N);
    vector<Games> getTopN_Heap(const vector<Games>& allGames, int N);
    void printGame(const Games& g);
};