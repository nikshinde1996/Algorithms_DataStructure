/**
 *  This is much similar to level order traversal using stack, with only 
 *  change in push nodes in stack.   
 *  1) Initialise currentNode to root and push it to stack
 *  2) While stack is not empty
 *     a) pop item from stack and assign it to currentNode.
 *     b) print(currentNode->data)
 *     c) push rightnode of popped node 
 *     d) push leftnode of popped node
 */

void PRE_ORDER_WITHOUTREC_USING_STACK(TNODE* root){
    TNODE* currentNode;
    stack<TNODE*> stack;
    stack.push(root);

    while(!stack.empty()){
        currentNode = stack.pop();
        print(currentNode->data);
        stack.push(currentNode->rnode);
        stack.push(currentNode->lnode);
    }
}