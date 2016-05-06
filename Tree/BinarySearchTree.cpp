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
     int flag;
     struct node{
         T data;
         node * leftnode;
         node * rightnode;
     } *root=NULL,*temp,*q;

     BinarySearchTree(){
         root = NULL;
     }
     ~BinarySearchTree(){}

    node * newNode(T val){
        node* temp = new node;
        temp->leftnode = temp->rightnode = NULL;
        temp->data = val;
        return temp;
    }

    node* Insert(node* troot,T val){
       if(troot == NULL){
           return newNode(val);
       }
       if(troot->data < val){
           troot->rightnode = Insert(troot->rightnode,val);
       }
       else if(troot->data > val){
           troot->leftnode = Insert(troot->leftnode,val);
       }
        return troot;
    }

    node* Delete(node* troot,T val){
        if(troot == NULL){
            return troot;
        }
        if(troot->data < val){
            troot->rightnode = Delete(troot->rightnode,val);
        }
        else if(troot->data > val){
            troot->leftnode = Delete(troot->leftnode,val);
        }
        else{
            if(troot->leftnode == NULL){        // Deleting nodes with single children
                node* temp = troot->rightnode;
                delete troot;
                return temp;
            }
            else if(troot->rightnode == NULL){
                node* temp = troot->leftnode;
                delete troot;
                return temp;
            }
            node* temp = inorder_successor(troot);
            troot->data = temp->data;
            troot = Delete(troot->rightnode,temp->data);
        }
        return troot;
    }

    node* inorder_successor(node* troot){
        while(troot->leftnode != NULL){
            troot = troot->leftnode;
        }
        return troot;
    }

    void Search(node* troot,T val){
        if(troot != NULL){
            if(troot->data == val){
                flag = 1;
                return;
            }
            Search(troot->leftnode,val);
            Search(troot->rightnode,val);
        }
    }

    int Height(node* troot){
        if(troot == NULL){
            return 0;
        }
        else{
            return 1 + max(Height(troot->leftnode),Height(troot->rightnode));
        }
    }

    int Diameter(node* troot){
        return 1 + Height(troot->leftnode) + Height(troot->rightnode);
    }

    void Inorder(node* troot){
        if(troot != NULL){
            Inorder(troot->leftnode);
            cout<<troot->data<<" ";
            Inorder(troot->rightnode);
        }
    }

    void Preorder(node* troot){
        if(troot != NULL){
            cout<<troot->data<<" ";
            Preorder(troot->leftnode);
            Preorder(troot->rightnode);
        }
    }

    void Postorder(node* troot){
        if(troot != NULL){
            Postorder(troot->leftnode);
            Postorder(troot->rightnode);
            cout<<troot->data<<" ";
        }
    }

};

int main(){

    BinarySearchTree<int> bst;
    BinarySearchTree<double> dbst;

    int choice;
    do{
        cout<<"1) Insert. 2) Delete. 3) Search. 4) Pre-order. 5) Post-order. 6) In-order. "<<endl;
        cout<<"7) Height. 8) Diameter. 9) kth Maximum Element. 10) Exit"<<endl;
        cout<<"Enter the choice of operation to perform :: ";cin>>choice;

        switch(choice){
            case 1:
                int val;
                cout<<"Enter the data to insert : ";cin>>val;
                bst.root = bst.Insert(bst.root,val);
                break;

            case 2:
                cout<<"Enter the data to delete : ";cin>>val;
                bst.root = bst.Delete(bst.root,val);
                break;

            case 3:
                bst.flag = 0;
                cout<"Enter the data to search : ";cin>>val;
                bst.Search(bst.root,val);
                if(bst.flag == 0){ cout<<"Data not found in BST"<<endl;}
                else{ cout<<"Data found in BST"<<endl;}
                break;

            case 4:
                bst.Preorder(bst.root);
                break;
            case 5:
                bst.Postorder(bst.root);
                break;
            case 6:
                bst.Inorder(bst.root);
                break;
            case 7:
                cout<<"Height of BST is : "<<bst.Height(bst.root)<<endl;
                break;
            case 8:
                cout<<"Diameter of BST is : "<<bst.Diameter(bst.root)<<endl;
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
