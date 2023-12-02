         #include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<limits.h>
struct Edges
{
    // This structure is equal to an edge. Edge contains two endpoints. These edges are directed edges so they
//contain source and destination and some weight. These 3 are elements in this structure
    int src, dest, wt;
};
// a structure to represent a graph
struct Graph
{
    int Vertex, Edge;
//Vertex is the number of vertices, and Edge is the number of edges
    struct Edges* edge;
// This structure contains another structure that we have already created.
};
struct Graph* designGraph(int Vertex, int Edge)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
//Allocating space to structure graph
    graph->Vertex = Vertex; //assigning values to structure elements that taken form user.
    graph->Edge = Edge;
    graph->edge = (struct Edges*) malloc( graph->Edge * sizeof( struct Edges ) );
//Creating "Edge" type structures inside "Graph" structure, the number of edge type structures are equal to number of edges 
    return graph;
}
void Solution(int dist[], int n)
{
// This function prints the last solution
    printf("\nVertex\tDistance from Source Vertex\n");
    int i;
    for (i = 0; i < n; ++i){
printf("%d \t\t %d\n", i, dist[i]);
}
}
void BellmanFordalgorithm(struct Graph* graph, int src)
{
    int Vertex = graph->Vertex;
    int Edge = graph->Edge;
    int Distance[Vertex];
    int i,j;
    // This is the initial step that we know, and we initialize all distances to infinity except the source vertex.
// We assign source distance as 0
    for (i = 0; i < Vertex; i++)
        Distance[i] = INT_MAX;
    Distance[src] = 0;
    //The shortest path of graph that contain Vertex vertices, never contain "Veretx-1" edges. So we do here "Vertex-1" relaxations
    for (i = 1; i <= Vertex-1; i++)
    {
        for (j = 0; j < Edge; j++)
        {
            int u = graph->edge[j].src; 
            int v = graph->edge[j].dest;
            int wt = graph->edge[j].wt;
            if (Distance[u] + wt < Distance[v])
                Distance[v] = Distance[u] + wt;
        }
    }
    //, up to now, the shortest path found. But BellmanFordalgorithm checks for negative edge cycles. In this step, we check for that
    // shortest path if the graph doesn't contain any negative weight cycle in the graph.
    // If we get a shorter path, then there is a negative edge cycle.
    for (i = 0; i < Edge; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int wt = graph->edge[i].wt;
        if (Distance[u] + wt < Distance[v])
            printf("This graph contains negative edge cycle\n");
    } 
    Solution(Distance, Vertex);
    return;
}
int main()
{
    int V,E,S; //V = no.of Vertices, E = no.of Edges, S is source vertex
printf("Enter number of vertices\n");
    scanf("%d",&V);
printf("Enter number of edges\n");
    scanf("%d",&E);
printf("Enter the source vertex number\n");
scanf("%d",&S);
    struct Graph* graph = designGraph(V, E); //calling the function to allocate space to these many vertices and edges
    int i;
    for(i=0;i<E;i++){
        printf("\nEnter edge %d properties Source, destination, weight respectively\n",i+1);
        scanf("%d",&graph->edge[i].src);
        scanf("%d",&graph->edge[i].dest);
        scanf("%d",&graph->edge[i].wt);
    }
    BellmanFordalgorithm(graph, S);
//passing created graph and source vertex to BellmanFord Algorithm function
    return 0;
}

