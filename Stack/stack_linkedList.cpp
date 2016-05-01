//
// Created by nikhi on ०१-०५-२०१६.
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;


template<class T> class Stack{

    public:
       struct node{
           T data;
           node *next;
       } *head=NULL,*tail=NULL,*temp=NULL,*q=NULL;

       Stack(){ head = NULL;};
       ~Stack(){};

     node* newNode(T val){
         node *t = new node;
         t->data = val;
         return t;
     }

    void Push(){
        T val;
        cout<<"Enter the element to insert : ";cin>>val;
        temp = newNode(val);
        if(head == NULL){
            head = temp;
            head->next = tail;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }

    void Pop(){
        if(head==NULL){
            cout<<"Stack allready empty!"<<endl;
            return;
        }else{
           node* q = head;
            while(q->next!= tail){
                q = q->next;
            }
            temp = tail;
            tail = q;
            cout<<"Poped data is : "<<temp->data<<endl;
            delete temp;
        }
    }

    void Top(){
        if(head == NULL && head == tail){
            cout<<"Stack allready empty."<<endl;
            return;
        }else{
            cout<<"Data at top is : "<<tail->next;
        }
    }

    void display(){
        if(head == NULL){
            cout<<"Stack allready empty."<<endl;
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

};


int main(){
    Stack<int> *s = new Stack<int>();
    Stack<double> d();

    int choice;
    do{
        cout<<"1) Push. 2) Pop. 3) Top. 4) Display. 5) Exit."<<endl;
        cout<<"Enter the choice for operation to perform : ";cin>>choice;

        switch(choice) {
            case 1 :
                s->Push();
                break;
            case 2 :
                s->Pop();
                break;
            case 3 :
                s->Top();
                break;
            case 4 :
                s->display();
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
}
