//
// Created by vastu5996 on 28-04-2016.
//
#include <iostream>
#include "MinHeap_Array.h"

using namespace std;

int main() {
    int n;
    cout << "Size: ";
    cin >> n;

    MinHeap_Array minHeap_array(n);

    while (true) {
        int choice;
        cout << endl;
        cout << "MinHeap: " << endl;
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
                minHeap_array.insert_heap(temp);
                cout << endl;
                break;
            case 2:
                int c;
                cout << "Index of element to delete" << endl;
                cin >> c;
                minHeap_array.delete_heap(c);
                cout << endl;
                break;
            case 3:
                if (minHeap_array.get_element() == INT_MIN) cout << "Empty Heap" << endl;
                else cout << "Top priority element: " << minHeap_array.get_element() << endl;
                break;
            case 4:
                minHeap_array.display();
                cout << endl;
                break;
            case 5:
                exit(0);
        }
    }
}
