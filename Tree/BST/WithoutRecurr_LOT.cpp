/**
 *  Level order traversing without recursion
 *  This can be implemented using Queue data structure
 *  Insert root in queue.
 *  Now rule is to extract the node from queue and enque both child nodes of that node in queue.  
 */


 void LEVEL_ORDER_WITHOUTREC(TNODE* root){
     queue<TNODE*> q;
     q.push(root);

     while(!q.empty()){
        TNODE* temp = q.front();
        if(temp->lnode){
            q.push(temp->lnode);
        }
        if(temp->rnode){
            q.push(temp->rnode);
        }
     }
 }