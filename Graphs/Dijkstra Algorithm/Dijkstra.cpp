#include<bits/stdc++.h>
#define V 5

/**
 *  This algorithm was used find the shortest path from the source to all the nodes in the graph
 *  maintain the sptset matrix of bools that denotes if we have found the shortest path
 *  to that node from the soruce.
 */ 

using namespace std;


void displayMatrix(int dist[],int V,int src) {
    for(int i=0;i<V;i++) {
    	cout<<src<<" --> "<<dist[i]<<endl;
    }
}

void minDistance(int dist,bool spt[]) {
     int min = INT_MAX,min_index;

     for(int v=0;v<V;v++) {
     	if(!sptset[v] && dist[v] <= min) {
           min = dist[v];
           min_index = v;
     	}
     }
     return min_index;
}

void Dijkstra(int graph[V][V],int src) {
    int dist[V];
    bool sptset[V];

    for(int i=0;i<V;i++) {
    	dist[i] = INT_MAX;  // intially set the distance as maximum
    	sptset[i] = false;
    }

    dist[src] = 0;   // dist from itself is set to 0

    for(int count=0;count<V-1;count++) {
    	int u = minDistance(dist,sptset);
    	sptset[u] = true;

    	for(int v=0;v<V;v++) {
    		if(!sptset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v] < dist[v]){
    			dist[v] = dist[u] + graph[u][v] ;
    		}
    	}
    }

    displayMatrix(dist,V,src);
}

int main() {
   int graph[V][V] = {  {1 , 4 , 0 , 2 , 4}
                       ,{0 , 0 , 3 , 0 , 0}
                       ,{0 , 0 , 0 , 1 , 2}
                       ,{0 , 4 , 0 , 0 , 4}
                       ,{0 , 0 , 3 , 2 , 8} };

   
}