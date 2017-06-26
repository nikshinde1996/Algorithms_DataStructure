/**
 *  This program returns the mirror form of the Given Binary Tree
 *
 */

TNODE* MIRROR(TNODE* root) {
    if(root){
        MIRROR(root->lnode);
        MIRROR(root->rnode);
        TNODE* temp = root->lnode;
        root->lnode = root->rnode;
        root->rnode = temp;
    }
} 