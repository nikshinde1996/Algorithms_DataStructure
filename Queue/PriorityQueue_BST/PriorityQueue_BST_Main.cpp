//
// Created by vastu5996 on 28-04-2016.
//
#include <iostream>
#include "PriorityQueue_BST.h"

using namespace std;


int main() {
    int choice;
    PriorityQueue_BST pq;
    struct node *t = root;
    while (true) {
        cout << "Priority Queue: " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                pq.insert_node();
                cout << endl;
                break;
            case 2:
                pq.delete_node();
                cout << endl;
                break;
            case 3:
                pq.display();
                cout << endl;
                break;
            case 4:
                cout << "Current Queue : Data[Priority]" << endl;
                pq.traverse(root);
                cout << endl;
                break;
            case 5:
                exit(0);
            default:
                cout << "Enter a valid choice" << endl;
                cout << endl;
        }
    }
}