//
// Created by vastu5996 on 28-04-2016.
//

#ifndef ALGORITHMS_DATASTRUCTURE_MAXHEAP_ARRAY_H
#define ALGORITHMS_DATASTRUCTURE_MAXHEAP_ARRAY_H

#include <iostream>

using namespace std;

class MaxHeap_Array {
    int size, current_heap;
    int *array;
public:
    MaxHeap_Array(int n) {
        size = n;
        array = new int[size];
        current_heap = 0;
    }

    void max_heapify(int k) {
        int left = 2 * k + 1;
        int right = 2 * k + 2;
        int largest = k;

        if (left < current_heap && array[left] > array[(k - 1) / 2]) largest = left;
        if (right < current_heap && array[right] > array[(k - 1) / 2]) largest = right;
        if (largest != k) {
            swap((int *&) array[k], (int *&) array[(k - 1) / 2]);
            max_heapify(largest);
        }
    }

    void delete_heap(int n) {
        if (current_heap == 0) {
            cout << "Underflow" << endl;
            return;
        }
        else if (n > current_heap) {
            cout << "Index out of bounds" << endl;
        }
        else if (current_heap == 1) {
            current_heap--;
            array[0] = INT_MIN;
            return;
        }

        array[n - 1] = array[current_heap - 1];
        current_heap--;
        max_heapify(0);
    }

    void insert_heap(int n) {
        if (current_heap == size) {
            cout << "Overflow" << endl;
            return;
        }

        current_heap++;
        array[current_heap - 1] = n;
        int i = current_heap - 1;

        while (i != 0 && array[i] > array[(i - 1) / 2]) {
            swap((int *&) array[i], (int *&) array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void display() {
        cout << "Current Heap: ";
        if (current_heap == 0) cout << "Empty" << endl;
        else {
            for (int i = 0; i < current_heap; i++) cout << array[i] << " ";
        }
        cout << endl;
    }

    int get_element() {
        if (current_heap == 0) return INT_MAX;
        return array[0];
    }
};


#endif //ALGORITHMS_DATASTRUCTURE_MAXHEAP_ARRAY_H
