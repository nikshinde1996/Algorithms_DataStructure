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
public:
    list<int> *adj;
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v,int w){
        adj[v].push_back(w);
    }

    void BFS(int v){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)visited[i] = false;
        list<int> queue;

        visited[v] = true;
        queue.push_back(v);

        list<int>::iterator i;

        while(!queue.empty()){
           int s = queue.front();
           cout<<s<<" ";
           queue.pop_front();

           for(i=adj[s].begin();i!=adj[s].end();i++){
               if(!visited[*i]){
                   visited[*i] = true;
                   queue.push_back(*i);
               }
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

    g.BFS(2);
    return 0;
}

