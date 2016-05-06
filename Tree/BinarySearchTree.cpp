//
// Created by nikhil on 02-04-2016.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <class T> class BinarySearchTree{
     public:

     struct node{
         T data;
         node * leftnode;
         node * rightnode;
     } *root=NULL,*temp,*q;

     BinarySearchTree(){}
     ~BinarySearchTree(){}

    node * newNode(T val){}
    void Insert(T val){}
    void Delete(T val){}
    void Search(T val){}
    void Height(){}
    void Diameter(){}
    void Inorder(){}
    void Preorder(){}
    void Postorder(){}

};

int main(){


    int choice;
    do{
        cout<<"1) Insert. 2) Delete. 3) Search. 4) Pre-order. 5) Post-order. 6) In-order. "<<endl;
        cout<<"7) Height. 8) Diameter. 9) kth Maximum Element. 10) Exit"<<endl;
        cout<<"Enter the choice of operation to perform :: ";cin>>choice;

        switch(choice){
            case 1:
                break;

            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:
                exit(0);
                break;
            default:
                cout<<"Invalid option!"<<endl;
        }
        fflush(stdin);
        getchar();
        system("cls");

    }while(choice != 10);
    return 0;
}
