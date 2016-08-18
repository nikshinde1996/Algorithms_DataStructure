
#include <bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> *adj;   // Array of list to maintain adjaceny list of conneected vertices.
    bool isCyclicUtil(int v,bool visited[], bool *rs);

public:
    Graph(int v);
    void addEdge(int u,int v);
    bool isCyclic();
};

Graph::Graph(int v){
    V = v;
    adj = new list<int>[V];    // Creates the array of the list.
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

bool Graph::isCyclicUtil(int v, bool *visited, bool *rs) {
    if(visited[v]==false){
        visited[v] = true;
        rs[v] = true;

        list<int>::iterator i;

        for(i = adj[v].begin();i!=adj[v].end();i++){
            if(!visited[*i] && isCyclicUtil(*i,visited,rs)){
                return true;
            }else if(rs[*i]){
                return true;
            }
        }
    }
    rs[v] = false;  // removes vertex from recusion stack
    return false;
}

bool Graph::isCyclic() {
    bool *visited = new bool[V];
    bool *restack = new bool[V];

    for(int i=0;i<V;i++){
        visited[i] = false;restack[i]=false;
    }

    for(int i=0;i<V;i++){
        if(isCyclicUtil(i,visited,restack))return true;
    }
    return false;
}


int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    if(g.isCyclic()){
        cout<<"Graph is cyclic !"<<endl;
    }else{
        cout<<"Graph is not-cyclic !"<<endl;
    }
    return 0;
}