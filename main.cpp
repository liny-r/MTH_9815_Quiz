#include <iostream>
#include <vector>
#include "quicksort.hpp"
#include "maxheap.hpp"

using namespace std;

int main() {
    // ----------------------------
    // Test Quicksort
    // ----------------------------
    vector<int> arr = {8, 3, 1, 7, 0, 10, 2};

    quicksort(arr);   // now only takes the array!

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;


    // ----------------------------
    // Test Max Heap Add()
    // ----------------------------

    MaxHeap heap;

    heap.Add(10);
    heap.Add(4);
    heap.Add(15);
    heap.Add(20);
    heap.Add(3);

    cout << "Max-Heap after inserts: ";
    heap.Print();

    // ----------------------------
    // Test Max Heap Remove()
    // ----------------------------
    cout << "Removing max element: " << heap.RemoveMax() << endl;

    cout << "Heap after removal: ";
    heap.Print();


    return 0;
}

