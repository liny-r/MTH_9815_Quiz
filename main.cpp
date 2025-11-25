//
// Created by Yueqi Lin on 25/11/2025.
//

#include <iostream>
#include <vector>
#include "quicksort.hpp"
#include "maxheap.hpp"

using namespace std;

int main() {

    // =======================================================
    // Quicksort Test Cases
    // =======================================================
    cout << "===== Quicksort Tests =====" << endl;

    // 1. Random sample
    vector<int> arr = {8, 3, 1, 7, 0, 10, 2};
    quicksort(arr);
    cout << "Sorted: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // 2. Already sorted
    vector<int> sortedArr = {1, 2, 3, 4, 5};
    quicksort(sortedArr);
    cout << "Sorted (already sorted): ";
    for (int x : sortedArr) cout << x << " ";
    cout << endl;

    // 3. Reverse sorted
    vector<int> reverseArr = {9, 7, 5, 3, 1};
    quicksort(reverseArr);
    cout << "Sorted (reverse sorted): ";
    for (int x : reverseArr) cout << x << " ";
    cout << endl;

    // 4. All duplicates
    vector<int> dupArr = {4, 4, 4, 4, 4};
    quicksort(dupArr);
    cout << "Sorted (duplicates): ";
    for (int x : dupArr) cout << x << " ";
    cout << endl;

    // 5. Negative numbers
    vector<int> negArr = {5, -1, 3, -20, 7, 0};
    quicksort(negArr);
    cout << "Sorted (negatives): ";
    for (int x : negArr) cout << x << " ";
    cout << endl;

    // 6. Single element
    vector<int> singleArr = {42};
    quicksort(singleArr);
    cout << "Sorted (single element): ";
    for (int x : singleArr) cout << x << " ";
    cout << endl;

    // 7. Empty array
    vector<int> emptyArr = {};
    quicksort(emptyArr);
    cout << "Sorted (empty array): <empty>" << endl;

    // 8. Mixed random
    vector<int> randomArr = {12, 99, -5, 8, 0, 34, 34, -1, 7, 100, -50};
    quicksort(randomArr);
    cout << "Sorted (mixed input): ";
    for (int x : randomArr) cout << x << " ";
    cout << endl;


    // =======================================================
    // MaxHeap Test Cases
    // =======================================================
    cout << "\n===== MaxHeap Tests =====" << endl;

    // Basic heap inserts
    MaxHeap heap;
    heap.Add(10);
    heap.Add(4);
    heap.Add(15);
    heap.Add(20);
    heap.Add(3);

    cout << "Heap after inserts: ";
    heap.Print();

    cout << "RemoveMax: " << heap.RemoveMax() << endl;

    cout << "Heap after one removal: ";
    heap.Print();


    // Mixed values
    MaxHeap h2;
    vector<int> values = {10, -1, 50, 50, 3, 7, -20, 100};
    for (int v : values) h2.Add(v);

    cout << "\nHeap (mixed values): ";
    h2.Print();

    cout << "Removing values until empty:" << endl;
    while (true) {
        try {
            cout << "RemoveMax -> " << h2.RemoveMax() << " | Heap: ";
            h2.Print();
        } catch (exception& e) {
            cout << "Heap is empty." << endl;
            break;
        }
    }

    return 0;
}


