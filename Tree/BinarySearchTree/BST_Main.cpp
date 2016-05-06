//
// Created by vastu5996 on 05-05-2016.
//
#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;

int main()
{
    int choice;
    BST bst;
    struct node *t = root;

    while(true)
    {
        cout << "Binary Search Tree: " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "4. Preorder Traversal" << endl;
        cout << "5. Postorder Traversal" << endl;
        cout << "6. Height" << endl;
        cout << "7. Diameter" << endl;
        cout << "8. Search" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                bst.insert_BST();
                cout << endl;
                break;
            case 2:
                int n;
                cout << "Enter the value to delete: ";
                cin >> n;
                bst.delete_BST(root,n);
                cout << endl;
                break;
            case 3:
                bst.in_order(root);
                cout << endl;
                break;
            case 4:
                bst.pre_order(root);
                cout << endl;
                break;
            case 5:
                bst.post_order(root);
                cout << endl;
                break;
            case 6:
                cout << "Height:  " << bst.get_height(root) << endl;
                cout << endl;
                break;
            case 7:
                cout << "Diameter: " << bst.get_diameter(root) << endl;
                cout << endl;
                break;
            case 8:
                bst.search_BST();
                cout << endl;
                break;
            case 9:
                exit(0);
            default:
                cout << "Enter a valid choice" << endl;

        }
    }

}