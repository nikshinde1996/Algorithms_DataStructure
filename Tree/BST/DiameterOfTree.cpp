/**
 *  Diameter of tree is the longest path between two leaf nodes. It may
 *  or may not have root node as its part.
 *     1) It can be through root node.
 *     2) It can be largest diameter of either right or left subtree
 */ 

int HEIGHT(TNODE* root) {
    if(root==NULL){
        return 0;
    }else{
        return MAX(HEIGHT(root->lnode),HEIGHT(root->rnode))+1;
    }
}

int DIAMETER(TNODE* root) {
    if(root==NULL){
        return 0;
    }else{
        int LSTDiameter = DIAMETER(root->lnode);
        int RSTDiameter = DIAMETER(root->rnode);
        return max(HEIGHT(root->lnode)+HEIGHT(root->rnode)+1,max(LSTDiameter,RSTDiameter));
    }
}