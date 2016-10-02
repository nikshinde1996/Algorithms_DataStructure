#include<bits/stdc++.h>
#include<algorithm>
#define V 5
#define INF 99999
/**
 *   Floyd Warshall algorithm is used to send find the shortest path between all the nodes. 
 */

using namespace std;

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    for(int i=0;i<V;i++) {
    	for(int j=0;j<V;j++) {
    		dist[i][j] = graph[i][j];
    	}
    }

    for(int i=0;i<V;i++) {
    	for(int j=0;j<V;j++) {
    		for(int k=0;k<V;k++) {
    			if(dist[i][k] + dist[k][j] < dist[i][j]) { 
    				dist[i][j] = dist[i][k] + dist[k][j];
    			}
    		}
    	}
    }

    displayMatrix(dist);
}

void displayMatrix(int dist[V][V]) {
   for(int i=0;i<V;i++) {
   	  for(int j=0;j<V;j++) {
   	  	 if(dist[i][j]==INF){cout<<setw(5)<<"INF";}
   	  	 else {cout<<setw(5)<<dist[i][j];}
   	  }
   	  cout<<endl;
   }
}

int main() {
    
    int graph[V][V] = { {1,4,INF,12,4}
                       ,{INF,0,3,INF,INF}
                       ,{INF,INF,0,1,2}
                       ,{INF,4,INF,INF,4}
                       ,{INF,INF,3,2,8} };

    floydWarshall(graph);
                       
}