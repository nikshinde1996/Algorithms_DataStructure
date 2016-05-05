//
// Created by nikhi on 01-03-2016.
//

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <queue>

using namespace std;

template <class T> class Queue{

    public:
    struct node{
        T data;
        node* next;
    } *head=NULL,*tail=NULL,*temp=NULL,*q=NULL;

    Queue(){}
    ~Queue(){};

    node* newNode(T val){
        node* temp = new node;
        temp->data = val;
        return temp;
    }

    void Enqueue(){
        T val;
        cout<<"Enter the data to Enqueue ";cin>>val;
        temp = newNode(val);

        if(head==NULL){
           head = tail = temp;
        }else{
           temp->next = head;
           head = temp;
        }
    }

    void Dequeue(){
         if(head == NULL){
             cout<<"Queue is allready empty !"<<endl;
         }else{
             node* q = head;
             while(q->next!= tail){
                 q = q->next;
             }
             temp = tail;
             tail = q;
             delete temp;
         }
    }

    void Display(){
        if(head == NULL){
            cout<<"Queue is allready empty."<<endl;
            return;
        }else{
            node* q = head;
            while(q!=tail){
                cout<<q->data<<" ";
                q = q->next;
            }
            cout<<q->data<<endl;
        }
    }

    void Peek(){
        if(head == NULL && head == tail){
            cout<<"Queue is allready empty."<<endl;
            return;
        }else{
            cout<<"Data at top is : "<<tail->next;
        }
    }
};

int main(){

    Queue<int> qi();
    Queue<double> *qd = new Queue<double>();

    int choice;
    do{
        cout<<"1) Enqueue. 2) Dequeue. 3) Peek. 4) Display. 5) Exit."<<endl;
        cout<<"Enter the choice for operation to perform : ";cin>>choice;

        switch(choice) {
            case 1 :
                qd->Enqueue();
                break;
            case 2 :
                qd->Dequeue();
                break;
            case 3 :
                qd->Peek();
                break;
            case 4 :
                qd->Display();
                break;
            case 5 :
                exit(0);
            default :
                cout<<"Invalid option !"<<endl;
        }
        fflush(stdin);
        getchar();
        system("cls");
    }while(choice != 5);

    return 0;
}
