#include "data_src/Game.h"   //Bridges Game class (from Martina)
#include "HeapSort.h"
#include "../Games.h" //local Games class
//#include "HeapSort.h"   //Bridges Game class (from Martina)
#include <vector>
#include <string>
#include <iostream>
using bridges::dataset::Game;


using namespace std;


int  MaxHeap::leftChild(int i) const  { return 2 * i + 1; }
int  MaxHeap::rightChild(int i) const { return 2 * i + 2; }
int  MaxHeap::parent(int i) const     { return (i - 1) / 2; }

MaxHeap::MaxHeap(){}
//restores heap by moving element in given index up until it is in the correct place
    void MaxHeap::heapifyUp(int index) {
        int i = index;
        while (i > 0) {
            int p = parent(i);
            if (!isBetter(heap[p], heap[i])) {
                std::swap(heap[p], heap[i]);
                i = p;
            } else {
                break;
            }
        }
    }

//restores heap by moving element in given index down until it is in the correct place
    void MaxHeap::heapifyDown(int index) {
        int i = index;
        while (true) {
            int left = leftChild(i);
            int right = rightChild(i);
            int best = i;

            if (left < (int)heap.size() && isBetter(heap[left], heap[best])) {
                best = left;
            }
            if (right < (int)heap.size() && isBetter(heap[right], heap[best])) {
                best = right;
            }

            if (best == i) {
                break;
            }

            std::swap(heap[i], heap[best]);
            i = best;
        }
    }

//gives context in how to compare games
    bool MaxHeap::isBetter(const Games &a, const Games &b) {
        return a.get_rating() > b.get_rating();
    }


//builds a heap
    MaxHeap::MaxHeap(const vector<Games> &items) {
        heap = items;
        for (int i = (int)heap.size() / 2; i >= 0; --i) {
            heapifyDown(i);
        }
    }

//inserts items into heap
    void MaxHeap::insert(const Games &g) {
        heap.push_back(g);
        heapifyUp((int)heap.size() - 1);
    }

//checks if heap is empty
    bool MaxHeap::empty() const {
        return heap.empty();
    }

//returns size of heap
    int MaxHeap::size() const {
        return (int)heap.size();
    }

//gets the top element of heap
    Games MaxHeap::extractMax() {
        if (heap.empty()) {
            return Games("", "", vector<string>{}, 0.0f);
        }

        Games top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return top;
    }

//from geeks for geeks https://www.geeksforgeeks.org/dsa/heap-sort/
void MaxHeap::heapify(vector<Games>& games, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && games[l].get_rating() > games[largest].get_rating())
        largest = l;
    if (r < n && games[r].get_rating() > games[largest].get_rating())
        largest = r;
    if (largest != i) {
        swap(games[i], games[largest]);
        heapify(games, n, largest);
    }
}

// Main function to do heap sort
void MaxHeap::heapSort(vector<Games>& games){
    int n = games.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(games, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(games[0], games[i]);
        heapify(games, i, 0);
    }
}
