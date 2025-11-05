#include "data_src/Game.h"   //Bridges Game class (from Martina)
#include "Games.h"  //local Games class
#include "HeapSort.h"   //Bridges Game class (from Martina)
#include <vector>
#include <string>
#include <iostream>
using bridges::dataset::Game;


using namespace std;


int  MaxHeap::leftChild(int i) const  { return 2 * i + 1; }
int  MaxHeap::rightChild(int i) const { return 2 * i + 2; }
int  MaxHeap::parent(int i) const     { return (i - 1) / 2; }


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


    bool MaxHeap::isBetter(const Games &a, const Games &b) {
        return a.get_rating() > b.get_rating();
    }



    MaxHeap::MaxHeap(const vector<Games> &items) {
        heap = items;
        for (int i = (int)heap.size() / 2; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    void MaxHeap::insert(const Games &g) {
        heap.push_back(g);
        heapifyUp((int)heap.size() - 1);
    }

    bool MaxHeap::empty() const {
        return heap.empty();
    }

    int MaxHeap::size() const {
        return (int)heap.size();
    }

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


