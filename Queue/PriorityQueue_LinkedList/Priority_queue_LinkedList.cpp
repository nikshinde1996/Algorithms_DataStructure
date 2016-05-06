//
// Created by nikhi on 04-04-2016.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

using namespace std;

template <class T> class Priority_queue{
private:
    int max_prio = 0;
    int min_prio = 0;
public:
    struct node{
        T val;
        int priority;
        node* next;
    }*head = NULL,*tail,*temp,*q;

    Priority_queue(){}
    ~Priority_queue(){}

    node* newNode(T val,int priority){
        node* temp = new node;
        temp->data = val;
        temp->priority = priority;
        return temp;
    }

    void InsertElement(){
        T val;
        int prio;

        if(prio > max_prio){
            max_prio = prio;
        }

        if(prio < min_prio){
            min_prio = prio;
        }
        cout<<"Enter the data to Enqueue and its priority ";cin>>val>>prio;
        temp = newNode(val,prio);

        if(head==NULL){
            head = tail = temp;
            max_prio = min_prio = temp->priority;
        }else{
            if(temp->priority >= tail->priority){
                tail->next = temp;
                tail = temp;
            }
            else if(temp->priority <= head->priority){
                temp->next = head;
                head = temp;
            }
            else{
                q = head;
                while(q->next->priority <= temp->priority){
                    q = q->next;
                }
                temp->next = q->next;
                q->next = temp;
            }
        }
    }

    void getMaxPriority(){
        q = head;
        while(q->priority != max_prio){
          q = q->next ;
        }
        cout<<"The element with MaxPriority is : "<<q->val<<endl;
    }

    void removeMaxPriority(){
        q = head;
        while(q->priority != max_prio){
            q = q->next ;
        }
        cout<<"The element with MaxPriority is : "<<q->val<<endl;
    }

    void Display(){
        if(head == NULL){
            cout<<"PriorityQueue_LinkedList is allready empty."<<endl;
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
    // Use generaised main with switching controll with necessary functions and class objects to run this code
    return 0;
}
