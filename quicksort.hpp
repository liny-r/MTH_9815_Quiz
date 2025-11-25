//
// Created by Yueqi Lin on 25/11/2025.
//


#pragma once
#include <vector>
using namespace std;

// Partition using the FIRST ELEMENT as pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];   // pivot = first element
    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && arr[left] <= pivot) {
            left++;
        }
        while (left <= right && arr[right] > pivot) {
            right--;
        }
        if (left > right) break;
        swap(arr[left], arr[right]);
    }

    swap(arr[low], arr[right]); // place pivot correctly
    return right;
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}
