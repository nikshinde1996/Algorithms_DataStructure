/**
  * This code returns the least common ancestor fr the given nodes 
  *
  */

TNODE* LCA_RECURSIVE(TNODE* root, int data1, int data2){
    if(root->data > data1 && root->data > data2){
        return LCA_RECURSIVE(root->left,data1,data2);
    }
    if(root->data < data1 && root->data < data2){
        return LCA_RECURSIVE(root->right,data1,data2);
    }
    return root;
}


// TODO - Non-recursive solution for this problem.