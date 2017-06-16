/**
 *  INorder Traversal can be done without recursion using stack.
 *  Using stack for this problem makes task a lot easier.
 *      1) Create empty stack.
 *      2) Initialise currentNode as root 
 *      3) push currentNode to stack and set currentNode=currentNode->lnode until currentNode is NULL.
 *      4) Now if currentNode is NULL and stack is not empty
 *           a) pop top item from stack.
 *           b) print popped item and set currentNode=currentNode->rnode
 *           c) go to 3
 *      5) We are done is currentNode is NULL and stack is empty.
 */

void IN_ORDER_WITHOUTREC_USING_STACK(TNODE* root){
    stack<TNODE*> s;
    TNODE* currentNode = root;

    while(!currentNode && s.empty()){
        if(currentNode){
            s.push(currentNode);
            currentNode = currentNode->lnode;
        }else if(!s.empty()){
            currentNode = s.pop();
            print(currentNode->data);
            currentNode = currentNode->rnode;
        }
    }
} 

/**
 * TODO : using Morris Traversal
 */

void IN_ORDER_WITHOUTREC_WITHOUT_STACK(TNODE* root){

} 

