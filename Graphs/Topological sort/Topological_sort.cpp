#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

class Graph {
  
public :
   int V;
   list<int> *adj;  // Array of lists for all the nodes 

   Graph(int V) {
   	  this.V = V;
   	  adj = new list<int>[V];
   }

   void addEdge(int src,int dest) {
   	  adj[src].push_back(dest);
   }

   void topologicalSort() {
   	  bool *visited = new bool[V];
   	  for(int i=0;i<V;i++) {
   	  	 visited[i] = false;  // Initially mark all nodes as un visited
   	  }

   	  stack<int> Stack;

   	  for(int i=0;i<V;i++) {
   	  	 if(!visited[i]) {
            topologicalSortUtil(i,visited,Stack);
   	  	 }
   	  }

   	  while(!Stack.empty()) {
   	  	 cout<<Stack.top()<<" ";
   	  	 Stack.top();
   	  }
   	  
   }

   void topologicalSortUtil(int v,bool visited[],stack<int> &Stack) {
      visited[v] = true;

      list<int>::iterator i;
      for(i=adj[v].begin();i!=adj[v].end();i++) {
         if(!visited[*i]) {
           topologicalSortUtil(*i,visited,Stack);
         }
      }

      Stack.push(v);
   }

}

int main() {
    Graph grp(5);
    grp.addEdge(0,1);
    grp.addEdge(0,3);
    grp.addEdge(3,2);
    grp.addEdge(2,4);
    grp.addEdge(4,1);
    grp.addEdge(4,3);
    grp.addEdge(3,1);

    g.topologicalSort();   // Prints the toplological sorting of given order.
}