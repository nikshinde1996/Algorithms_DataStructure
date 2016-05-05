//
// Created by vastu5996 on 05-05-2016.
//

#ifndef ALGORITHMS_DATASTRUCTURE_BST_H
#define ALGORITHMS_DATASTRUCTURE_BST_H

#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *rightChild;
    struct node*leftChild;
} *root;

class BST {
private:
    node* create_node(int);
    node* get_successor(node*);
public:
    int height, diameter;
    BST()
    {
        root = NULL;
        height = 0;
        diameter = 0;
    }
    void insert_BST();
    node* delete_BST(node*,int);
    void search_BST();
    int get_height(node*);
    void in_order(node*);
    void post_order(node*);
    void pre_order(node*);
    int get_diameter(node*);
};

node* BST::create_node(int n)
{
    struct node *temp;
    temp = new(struct node);
    temp->data = n;
    temp->rightChild = NULL;
    temp->leftChild = NULL;
    return temp;
}


void BST::insert_BST()
{
    int n;
    cout << "Number to insert: ";
    cin >> n;

    struct node *temp;
    temp = create_node(n);

    if(root==NULL) root = temp;
    else
    {
        struct node *t = root, *p;
        while(t!=NULL)
        {
            p = t;
            if(temp->data > t->data) t = t->rightChild;
            else if(temp->data < t->data) t = t->leftChild;
        }

        if(temp->data > p->data) p->rightChild = temp;
        else p->leftChild = temp;
    }
}

void BST::in_order(node *s)
{
    if(s!=NULL)
    {
        in_order(s->leftChild);
        cout << s->data << " ";
        in_order(s->rightChild);
    }
}

void BST::post_order(node *s)
{
    if(s!=NULL)
    {
        post_order(s->leftChild);
        post_order(s->rightChild);
        cout << s->data << " ";
    }
}

void BST::pre_order(node *s)
{
    if(s!=NULL) {
        cout << s->data << " ";
        pre_order(s->leftChild);
        pre_order(s->rightChild);
    }
}

int BST::get_height(node *s)
{
    if(s==NULL) return 0;
    else
    {
        int left = get_height(s->leftChild);
        int right = get_height(s->rightChild);

        if(left>right) return left+1;
        else return right+1;
    }
}

int BST::get_diameter(node *s)
{
    if(s==NULL) return 0;
    else
    {
        int left_height = get_height(s->leftChild);
        int right_height = get_height(s->rightChild);

        int left_diameter = get_diameter(s->leftChild);
        int right_diameter = get_diameter(s->rightChild);

        return max(left_height + right_height + 1,max(left_diameter,right_diameter));
    }
}

void BST::search_BST()
{
    int n;
    bool flag = false;
    cout << "Enter the number to search: ";
    cin >> n;
    struct node *t = root;

    while(t!=NULL)
    {
        if(n>t->data) t = t->rightChild;
        else if(n < t->data) t = t->leftChild;
        else
        {
            flag = true;
            cout << "Element found" << endl;
            break;
        }
    }
    if(flag==false) cout << "Element not found" << endl;
}

node* BST::delete_BST(node *t,int n)
{
    if(t==NULL)
    {
        cout << "Empty Tree" << endl;
        return t;
    }
    else if(n < t->data)
    {
        t->leftChild = delete_BST(t->leftChild, n);
    }
    else if(n > t->data)
    {
       t->rightChild = delete_BST(t->rightChild, n);
    }
    else
    {
        if(t->leftChild==NULL)
        {
            struct node *temp = t->rightChild;
            free(t);
            return temp;
        }
        else if(t->rightChild==NULL)
        {
            struct node *temp = t->leftChild;
            free(t);
            return temp;
        }
        struct node* temp = get_successor(t->rightChild);
        t->data = temp->data;
        t->rightChild = delete_BST(t->rightChild, temp->data);
    }
    return t;
}

node* BST::get_successor(node* r)
{
    struct node* temp = r;
    while (temp->leftChild != NULL)
        temp = temp->leftChild;

    return temp;
}
#endif //ALGORITHMS_DATASTRUCTURE_BST_H
