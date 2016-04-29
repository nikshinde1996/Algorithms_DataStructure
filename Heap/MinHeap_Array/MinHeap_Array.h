//
// Created by vastu5996 on 28-04-2016.
//

#ifndef ALGORITHMS_DATASTRUCTURE_MINHEAP_ARRAY_H
#define ALGORITHMS_DATASTRUCTURE_MINHEAP_ARRAY_H

#include <iostream>
#include <c++/cstdlib>

using namespace std;

class MinHeap_Array {
    int *array;
    int size, current_heap;
public:
    MinHeap_Array(int s) {
        size = s;
        array = new int[size];
        current_heap = 0;
    }

    void min_heapify(int k) {
        int left = 2 * k + 1;
        int right = 2 * k + 2;
        int smallest = k;

        if (left < current_heap && array[left] < array[k]) smallest = left;
        if (right < current_heap && array[right] < array[k]) smallest = right;
        if (smallest != k) {
            swap((int *&) array[k], (int *&) array[smallest]);
            min_heapify(smallest);
        }
    }

    void insert_heap(int n) {
        if (current_heap == size) {
            cout << "Overflow" << endl;
            return;
        }
        current_heap++;
        array[current_heap - 1] = n;
        int i = current_heap - 1;

        while (i != 0 && array[(i - 1) / 2] > array[i]) {
            swap((int *&) array[i], (int *&) array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void delete_heap(int n) {
        if (n > current_heap) {
            cout << "Index out of bounds" << endl;
            return;
        }
        else if (current_heap == 0) {
            cout << "Underflow" << endl;
            return;
        }
        else if (current_heap == 1) {
            current_heap--;
            array[0] = INT_MAX;
            return;
        }

        array[n - 1] = array[current_heap - 1];
        current_heap--;
        min_heapify(0);
    }

    void display() {
        cout << "Current Heap: ";
        if (current_heap == 0) cout << "Empty" << endl;
        else {
            for (int i = 0; i < current_heap; i++) {
                cout << array[i] << " ";
            }
        }
    }

    int get_element() {
        if (current_heap == 0) return INT_MIN;
        return array[0];
    }
};


#endif //ALGORITHMS_DATASTRUCTURE_MINHEAP_ARRAY_H
