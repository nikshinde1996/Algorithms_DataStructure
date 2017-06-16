#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int search_flag = 0; 

struct TNODE{
    int data;
    TNODE *lnode;
    TNODE *rnode;
}*root=NULL,*temp,*q;

TNODE* newNode(int data){
    TNODE* tempNode = new TNODE;
    tempNode->data = data;
    tempNode->lnode = tempNode->rnode = NULL;
    return tempNode;
}

/*Recursive Insert node*/
TNODE* INSERT_REC(TNODE* troot,int data){
    if(troot==NULL){
        return newNode(data);
    }else{
        if(troot->data > data){
            troot->lnode = INSERT_REC(troot->lnode,data);
        }else{
            troot->rnode = INSERT_REC(troot->rnode,data);
        }
    }
    return troot;
}

/*Recursive Delete Node*/
TNODE* DELETE_REC(TNODE* troot,int data){
    if(troot==NULL){
        return NULL;
    }
    if(troot->data > data){
        troot = DELETE_REC(troot->lnode,data);
    }else if(troot->data < data){
        troot = DELETE_REC(troot->rnode,data);
    }else{
        if(troot->lnode==NULL){   // delete node with single child
            TNODE *temp = troot->rnode;
            delete troot;
            return temp;
        }else if(troot->rnode==NULL){
            TNODE *temp = troot->lnode;
            delete troot;
            return temp;
        }
        TNODE* temp = INORDER_SUCCESSOR(troot);
        troot->data = temp->data;
        troot = Delete(troot->rnode,temp->data);
    }
    return troot;
}

TNODE* INORDER_SUCCESSOR(TNODE *troot){
    while(troot->lnode != NULL){
        troot = troot->lnode;
    }
    return troot;
}

/*Recursive Search of data in tree*/
void SEARCH_REC(TNODE* troot,int data){
    if(troot!=NULL){
        if(troot->data == data){
            search_flag = 1;
            return;
        }
        SEARCH_REC(troot->lnode,data);
        SEARCH_REC(troot->rnode,data);
    }
}

/*Recursive inorder traversal*/
void INORDER_REC(TNODE* troot,int data){
    if(troot!=NULL){
        INORDER_REC(troot->lnode,data);
        cout<<troot->data<<" ";
        INORDER_REC(troot->rnode,data);
    }
}

/*Recursive preorder traversal*/
void PREODER_REC(TNODE* troot,int data){
    if(troot!=NULL){
        cout<<troot->data<<" ";
        PREODER_REC(troot->lnode,data);
        PREODER_REC(troot->rnode,data);
    }   
}

/*Recursive postorder traversal*/
void POSTORDER_REC(TNODE* troot,int data){
    if(troot!=NULL){
        POSTORDER_REC(troot->lnode,data);
        POSTORDER_REC(troot->rnode,data);
        cout<<troot->data<<" ";
    }
}

/*Recursive Height calculation of Node*/
int HEIGHT_REC(TNODE* troot){
    if(troot==NULL){
        return 0;
    }
    else{
        return max(HEIGHT_REC(troot->lnode),HEIGHT_REC(troot->rnode))+1;
    }
}


/*Recursive Level order traversal*/
void LEVELORDER_REC(TNODE* troot){
    for(int level=1;level<=HEIGHT_REC(troot);level++){
        PRINT_GIVEN_LEVEL(troot,level);
    }
}

void PRINT_GIVEN_LEVEL(TNODE* troot,int level){
    if(troot == NULL){
        return;
    }else if(level==1){
        cout<<troot->data;
    }else{
        PRINT_GIVEN_LEVEL(troot->lnode,level-1);
        PRINT_GIVEN_LEVEL(troot->rnode,level-1);
    }
}

int main(){
    int choice;
    do{
       cout<<"1. Insert"<<endl;
       cout<<"2. Search"<<endl;
       cout<<"3. Delete"<<endl;
       cout<<"4. Level order traversal"<<endl;
       cout<<"5. Pre-order traversal"<<endl;
       cout<<"6. In-order traversal"<<endl;
       cout<<"7. Post-order traversal"<<endl;
       cout<<"7. Height of Tree"<<endl;
       cout<<"7. Diameter of Tree"<<endl;
       cout<<"7. Post-order traversal"<<endl;
       cout<<"8. EXIT"<<endl<<endl;
       cout<<"Enter choice : ";
       cin>>choice;

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
                exit(0);
                break;
           default:
                break;       
       }
       fflush(stdin);
       getchar();
       system("clear");
    }while(choice != 8);
}