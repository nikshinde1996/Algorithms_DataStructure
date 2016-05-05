//
// Created by nikhi on 05-04-2016.
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <list>
#include <algorithm>

using namespace std;

template <typename T> class Graph{
private:
    int V;
    list<int> *adj;
public:
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v,int w){
        adj[v].push_back(w);
    }

    void DFS(int v){
        bool *visited = new bool[V];

        for(int i=0;i<V;i++) visited[i] = false;
        dfsTraversal(v,visited);
    }

    void dfsTraversal(int v,bool visited[]){
        cout<<v<<" ";
        visited[v] = true;

        list<int>::iterator i;

        for(i = adj[v].begin();i!=adj[v].end();i++){
            if(!visited[*i]){
                visited[*i] = true;
                dfsTraversal(*i,visited);
            }
        }
    }
};

int main(){
    Graph<int> g(5);
    g.addEdge(1,2);
    g.addEdge(4,3);
    g.addEdge(4,3);
    g.addEdge(4,2);
    g.addEdge(3,1);
    g.addEdge(2,3);

    g.DFS(2);
    return 0;
}
