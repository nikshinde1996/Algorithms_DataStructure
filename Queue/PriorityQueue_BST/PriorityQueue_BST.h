//
// Created by vastu5996 on 04-05-2016.
//

#ifndef ALGORITHMS_DATASTRUCTURE_PRIORITYQUEUE_BST_H
#define ALGORITHMS_DATASTRUCTURE_PRIORITYQUEUE_BST_H

#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *rightChild;
    struct node *leftChild;
    struct node *same_next;
    int priority;
} *root;

class PriorityQueue_BST {
private:
    node* create_node(int, int);
public:
    void insert_node();
    void display();
    void traverse(node*);
    void same_Priority(node*);

    PriorityQueue()
    {
        root = NULL;
    }
};

node* PriorityQueue_BST::create_node(int n, int p)
{
    struct node *temp;
    temp = new(struct node);
    temp->data = n;
    temp->rightChild = NULL;
    temp->leftChild = NULL;
    temp->priority = p;
    temp->same_next = NULL;
    return temp;
}

void PriorityQueue_BST::insert_node()
{
    int n, priority;
    cout << "Enter the number to insert: ";
    cin >> n;
    cout << "Enter the priority of the number: ";
    cin >> priority;

    struct node *t = root, *temp, *p;
    temp = create_node(n, priority);

    if(root==NULL)
    {
        root = temp;
    }
    else
    {
        int count = 0;
        while(t!=NULL)
        {
            p = t;
            if(t->priority > temp->priority)
            {
                t = t->rightChild;
            }
            else if(t->priority < temp->priority)
            {
                t = t->leftChild;
            }
            else if(t->priority==temp->priority)
            {
                while(t->same_next!=NULL)
                {
                    t = t->same_next;
                }
                t->same_next = temp;
                count = 1;
                break;
            }
        }
        if(count==0)
        {
            if(p->data > temp->data)
            {
                p->rightChild = temp;
            }
            else
            {
                p->leftChild = temp;
            }
        }
    }
}

void PriorityQueue_BST::display()
{
    int c;
    cout << "Insert the priority of element to search: " << endl;
    cin >> c;
    struct node *t = root;
    bool flag = false;

    while(t!=NULL)
    {
        if(t->priority==c)
        {
            cout << "Element: ";
            if(t->same_next!=NULL)
            {
                cout << t->data << " ";
                struct node *p = t;
                while(p->same_next!=NULL)
                {
                    cout << p->same_next->data << " ";
                    p = p->same_next;
                }
            }
            else
            {
                cout << t->data << endl;
            }
            cout << endl;
            flag = true;
            break;
        }
        else if(t->priority>c)
        {
            t = t->leftChild;
        }
        else if(t->priority<c)
        {
            t = t->rightChild;
        }
    }
    if(flag== false) cout << "Value not found" << endl;
}

void PriorityQueue_BST::traverse(struct node *t)
{
    if(t!=NULL)
    {
        traverse(t->leftChild);
        cout << t->data << "[" << t->priority <<"]  ";
        if(t->same_next!=NULL)
        {
            same_Priority(t);
        }
        else
        {
            cout <<endl;
        }
        traverse(t->rightChild);
    }
}

void PriorityQueue_BST::same_Priority(node *s)
{
    while(s->same_next!=NULL)
    {
        s = s->same_next;
        cout << s->data << "[" << s->priority <<"]  ";
    }
    cout << endl;
}


#endif //ALGORITHMS_DATASTRUCTURE_PRIORITYQUEUE_BST_H
