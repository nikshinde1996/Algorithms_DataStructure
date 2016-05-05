//
// Created by nikhi on 05-04-2016.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <typename T> class Doubly_Circ_LinkedList{
public:
    struct node{
        T data;
        node *next;
        node *prev;
    }*head = NULL,*tail,*temp,*q;

    Doubly_Circ_LinkedList(){}
    ~Doubly_Circ_LinkedList(){}

    node* newNode(T val){
        node* temp = new node;
        temp->data = val;
        return temp;
    }

    void Insert(){
        T val;
        cout<<"Enter the data to Insert in List : ";cin>>val;
        temp = newNode(val);

        if(head==NULL){
            head = tail = temp;
        }else{
            temp->next = head;
            head = temp;
        }
        tail->next = head;
        head->prev = tail;
    }

    void Delete(){
        // Deleting from end (tail)
        node* temp = tail;
        q = head;
        while(q->next != tail){
            q = q->next;
        }
        q->next = head;
        tail = q;
        head->prev = q;
        delete temp;
    }

    void Display(){
        node *temp = head;
        cout<<"Normal order : ";
        while(temp->next != head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<temp->data<<endl;

        cout<<"Reverse order : ";
        temp = tail;
        while(temp->prev != tail){
            cout<<temp->data<<" ";
            temp = temp->prev ;
        }
        cout<<temp->data<<endl;
    }

};

int main(){
    Doubly_Circ_LinkedList<double> cl;
    int choice;
    do{
        cout<<"1) Insert. 2) Delete.  3) Display. 4) Exit."<<endl;
        cout<<"Enter the choice for operation to perform : ";cin>>choice;

        switch(choice) {
            case 1 :
                cl.Insert();
                break;
            case 2 :
                cl.Delete();
                break;
            case 3 :
                cl.Display();
                break;
            case 4 :
                exit(0);
            default :
                cout<<"Invalid option !"<<endl;
        }
        fflush(stdin);
        getchar();
        system("cls");
    }while(choice != 4);
}




