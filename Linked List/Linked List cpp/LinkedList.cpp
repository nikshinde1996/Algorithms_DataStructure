//
// Created by nikhi on ०४-०५-२०१६.
//
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

using namespace std;

template <class T> class LinkedList{

   public:
    struct node{
        T data;
        node* next;
    } *head=NULL,*tail,*q,*t,*temp;

    LinkedList(){}
    ~LinkedList(){}

    node* newNode(T val){
        node *t = new node;
        t->data = val;
        return t;
    }

    void Insert(){
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

    void Delete(){
        if(head == NULL){
            cout<<"LinkedList allready empty !"<<endl;
            return;
        }else{
            temp = head;
            head = head->next;
            delete(temp);
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

    void Reverse(){
       t = tail;
       while(t != head){
           q = head;
           while(q->next != t){
                q = q->next;
           }
           t->next = q;
           t = q;
       }
       t = tail;
       tail = head;
       head = t;
    }

};


// Use generalised int main with all functions and class objects  for running this code
int main(){

    return 0;
}