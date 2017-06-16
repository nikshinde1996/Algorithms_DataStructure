/** 
 *  Print Boundary nodes of Binary Tree
 *  This question can be solved in three parts 
 *      1)  Print left nodes in top---->bottom manner.
 *      2)  Print leaf nodes of Left subtree from left---->right
 *          Print leaf nodes of right subtree from left---->right
 *      3)  Print right nodes in bottom---->top manner    
 */

// print nodes in top to bottom order
void PRINT_LEFT_NODES(TNODE* tnode){
    if(tnode!=NULL){
        if(tnode->lnode){
            print(tnode->data);
            PRINT_LEFT_NODES(tnode->lnode);
        }else if(tnode->rnode){
            print(tnode->data);
            PRINT_LEFT_NODES(tnode->rnode);
        }
    }
}

void PRINT_RIGHT_NODES(TNODE* tnode){
    if(tnode!=NULL){
        if(tnode->lnode){
            PRINT_RIGHT_NODES(tnode->lnode);
            print(tnode->data);
        }else if(tnode->rnode){
            PRINT_RIGHT_NODES(tnode->rnode);
            print(tnode->data);
        }
    }
}

void PRINT_LEAF_NODES(TNODE* tnode){
    if(tnode){
        PRINT_LEAF_NODES(tnode->lnode);
        if(!tnode->lnode && !tnode->rnode){
            print(tnode->data);
        }
        PRINT_LEAF_NODES(tnode->rnode);
    }
}

void PRINT_BOUNDARY_NODES(TNODE* root){
    if(root){
        print(root->data) // print root data
        
        PRINT_LEFT_NODES(root->lnode);

        PRINT_LEAF_NODES(root->lnode);
        PRINT_LEAF_NODES(root->rnode);
    
        PRINT_RIGHT_NODES(root->rnode);
    }
}