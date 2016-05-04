//
// Created by vastu5996 on 04-05-2016.
//
#include <iostream>
#include <cstdlib>
#include "PriorityQueue_BST.h"

using namespace std;

int main()
{
    int choice;
    PriorityQueue_BST pq;
    struct node *t = root;
    while(true)
    {
        cout << "Priority Queue: " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                pq.insert_node();
                cout << endl;
                break;
            case 2:
                pq.display();
                cout << endl;
                break;
            case 3:
                cout << "Current Queue : Data[Priority]" << endl;
                pq.traverse(root);
                cout << endl;
                break;
            case 4:
                exit(0);
            default:
                cout << "Enter a valid choice" << endl;
                cout << endl;
        }
    }
}