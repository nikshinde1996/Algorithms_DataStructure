/*
 * Width is the number of Nodes in particular level.
 * Width of Tree is the max number oof nodes in any level
 * 
 * The logic of level order traversal can be inculcated.
 */


int WIDTH_OF_TREE(TNODE* root) {
    int maxWidth = INT_MIN;
    for(int level=1;level<=HEIGHT(root);level++) {
        maxWidth = max(maxWidth,GET_LEVEL_WIDTH(root),level));
    }
    return maxWidth;
}

int GET_LEVEL_WIDTH(TNODE* root, int level) {
    if(!root) {
        return 0;
    }else if(level == 1) {
        return 1;
    }else {
        return GET_LEVEL_WIDTH(root->lnode)+GET_LEVEL_WIDTH(root->rnode);
    }
}