/*
 *  Dequeue : Doubly ended queue.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <class T> class Dequeue{

    public:
    struct node{
        T data;
        node *next;
    }*head,*tail,*temp,*q,*t;

    Dequeue();
    ~Dequeue();

    node* newNode(T val){
        node *t = new node;
        t->data = val;
        return t;
    }

    void Enque_at_head(){
        T val;
        cout<<"Enter the element to insert : ";cin>>val;
        temp = newNode(val);
        if(head == NULL){
            head = tail = temp;
            head->next = tail;
        }else{
            temp->next = head;
            head = temp;
        }
    }

    void Enque_at_tail(){
        T val;
        cout<<"Enter the element to insert : ";cin>>val;
        temp = newNode(val);
        if(head == NULL){
            head = tail = temp;
            head->next = tail;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }

    void Deque_at_head(){
        if(head==NULL){
            cout<<"Dequeue allready empty!"<<endl;
            return;
        }else{
            node* q = head;
            head = head->next;
            delete q;
        }
    }

    void Deque_at_tail(){
        if(head==NULL){
            cout<<"Dequeue allready empty!"<<endl;
            return;
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
            cout<<"Dequeue allready empty."<<endl;
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

    void Peek_at_head(){
        cout<<"Element at head : "<<head->data;
    }

    void Peek_at_tail(){
        cout<<"Element at tail : "<<tail->data;
    }

};


int main(){
    int choice;
    do{
        cout<<" 1) Enque at head. 2) Enque at tail. 3) Deque at head. 4) Deque at tail."<<endl;
        cout<<" 5) Display. 6) Peek at head. 7) Peek at tail  8) exit "<<endl;
        cout<<"Enter the choice to perform : ";
        cin>>choice;

        // Use switch contoll to call necessary function to use this code.
    }while(choice != 8 );
    return 0;
}

