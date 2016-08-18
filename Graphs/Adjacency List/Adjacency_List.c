#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct AdjListNode{    // Struct to represent an adjacency List Node
    int dest;
    struct AdjListNode *next;
};

struct AdjList{
    struct AdjListNode *head;  // Pointer to the head node of the List.
};

struct Graph{
    int v;
    struct AdjList *array;  // Creating the array of the head nodes.
};

struct AdjListNode *newAdjListNode(int dest){
    struct AdjListNode *newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode*));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
};

struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph*));
    graph->v = V;
    graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList*));
    int i = 0;
    for(i=0;i<V;i++){
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph,int src,int dest){
     struct AdjListNode *newNode = newAdjListNode(dest);
     newNode->next = graph->array[src].head;
     graph->array[src].head = newNode;

     // Edge has to be build from both src-to-dest and dest-to-src;
     newNode = newAdjListNode(src);
     newNode->next = graph->array[dest].head;
     graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph){
    int v=0;
    for(v=0;v<graph->v;v++){
        struct AdjListNode* pcrawl = graph->array[v].head;
        printf("\n Adjacency List of vertex %d\n head",v);
        while(pcrawl){
           printf("-> %d",pcrawl->dest);
           pcrawl = pcrawl->next;
        }
        printf("\n");
    }
}

int main(){
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,3);
    addEdge(graph,3,4);

    printGraph(graph);
    return 0;
}





