/**
 *  This function returns true is the given Binary tree is Binary search tree.
 *  We need to use a helper function. Every node is checked if it lies in range of
 *  min and max values. 
 */


 bool isBST(TNODE* root) {
     return isBSTUtil(root,INT_MIN,INT_MAX);
 }

 bool isBSTUtil(TNODE* root, int minv, int maxv) {
     if(!root){
         return true;
     }
     if(root->data < minv || root->data > maxv){
         return false;
     }
     return isBSTUtil(root->left,minv,root->data-1) && isBSTUtil(root->right,root->data+1,maxv);
 }