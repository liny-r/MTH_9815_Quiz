//
// Created by Yueqi Lin on 25/11/2025.
//


#pragma once
#include <vector>
using namespace std;

// ---- Helper: partition using FIRST element as pivot ----
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && arr[left] <= pivot) left++;
        while (left <= right && arr[right] > pivot) right--;

        if (left > right) break;
        swap(arr[left], arr[right]);
    }

    swap(arr[low], arr[right]);
    return right;
}

// ---- Internal recursive helper (not exposed to user) ----
void quicksortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksortHelper(arr, low, pivotIndex - 1);
        quicksortHelper(arr, pivotIndex + 1, high);
    }
}

// ---- PUBLIC FUNCTION: only takes array ----
void quicksort(vector<int>& arr) {
    if (arr.empty()) return;
    quicksortHelper(arr, 0, arr.size() - 1);
}
