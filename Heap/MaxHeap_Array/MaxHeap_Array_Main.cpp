//
// Created by vastu5996 on 28-04-2016.
//
#include <iostream>
#include "MaxHeap_Array.h"
#include <cstdlib>
#include <limits.h>

using namespace std;

int main() {
    int n;
    cout << "Size: ";
    cin >> n;

    MaxHeap_Array maxHeap_array(n);

    while (true) {
        int choice;
        cout << endl;
        cout << "MaxHeap: " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Get Element" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int temp;
                cout << "Enter the element to enter: ";
                cin >> temp;
                maxHeap_array.insert_heap(temp);
                cout << endl;
                break;
            case 2:
                int c;
                cout << "Index of element to delete" << endl;
                cin >> c;
                maxHeap_array.delete_heap(c);
                cout << endl;
                break;
            case 3:
                if (maxHeap_array.get_element() == INT_MAX) cout << "Empty Heap" << endl;
                else cout << "Top priority element: " << maxHeap_array.get_element() << endl;
                break;
            case 4:
                maxHeap_array.display();
                cout << endl;
                break;
            case 5:
                exit(0);
        }
    }
}