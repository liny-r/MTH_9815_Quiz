//
// Created by Yueqi Lin on 25/11/2025.
//

#pragma once
#include <vector>
#include <iostream>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Restore heap upwards
    void bubbleUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Restore heap downwards
    void bubbleDown(int index) {
        int size = heap.size();

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            // Compare with left child
            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            // Compare with right child
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }

            // If index is already largest, heap restored
            if (largest == index) break;

            swap(heap[index], heap[largest]);
            index = largest;  // continue bubbling down
        }
    }

public:
    MaxHeap() {}

    void Add(int value) {
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
    }

    // Remove and return the maximum element (root)
    int RemoveMax() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        int maxValue = heap[0];
        heap[0] = heap.back();   // Move last element to root
        heap.pop_back();         // Remove last element

        if (!heap.empty()) {
            bubbleDown(0);       // Restore heap downward
        }

        return maxValue;
    }

    // For testing
    void Print() const {
        for (int v : heap) cout << v << " ";
        cout << endl;
    }
};
