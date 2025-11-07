//
// Created by Yusra Hash on 11/2/25.
//

#include "mergeSort.h"
#include "../Games.h"
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
//from geeksforgeeks, https://www.geeksforgeeks.org/dsa/merge-sort/
void merge(vector<Games>& data, int left,
                     int mid, int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<Games> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = data[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = data[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i].get_rating() >= R[j].get_rating()) {
            data[k] = L[i];
            i++;
        }
        else {
            data[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

//does a merge sort on the vector of games
// begin is for left index and end is right index of vector
void mergeSort(vector<Games>& data, int left, int right){

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
    cout << endl;

}





