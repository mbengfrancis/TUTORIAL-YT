#include <stdio.h>
//structure for denoting an edge
struct Edge {
int source, destination, weight;
};
//structure for representing a weighted, connected and undirected graph
struct Graph {
int Node, E;
struct Edge* edge;
};
//memory allocation for storing graph with V vertices and E edges
struct Graph* create_Graph(int Node, int E)
{
struct Graph* gph = (struct Graph*)malloc(sizeof(struct Graph));
gph->Node = Node;
gph->E = E;
gph->edge = (struct Edge*)malloc( Node * E * sizeof( struct Edge));
return gph;
}
//Union-Find Subset
struct tree_subset {
int parent;
int rank;
};
//finding the set of selected nodes
int DisjointSet_find(struct tree_subset subsets[], int i)
{
     //find root and make root as parent of i
if (subsets[i].parent != i)
subsets[i].parent
= DisjointSet_find(subsets, subsets[i].parent);
return subsets[i].parent;
}
void DisjointSet_Union(struct tree_subset subsets[], int x, int y)
{
int xroot = DisjointSet_find(subsets, x);
int yroot = DisjointSet_find(subsets, y);
if (subsets[xroot].rank < subsets[yroot].rank)
subsets[xroot].parent = yroot;
else if (subsets[xroot].rank > subsets[yroot].rank)
subsets[yroot].parent = xroot;
else
{
subsets[yroot].parent = xroot;
subsets[xroot].rank++;
}
}
//Comparing edges with qsort() in C
int myComp(const void* a, const void* b)
{
struct Edge* a1 = (struct Edge*)a;
struct Edge* b1 = (struct Edge*)b;
return a1->weight > b1->weight;
}
//function for creating MST using Kruskal's Approach
void MST_Kruskal(struct Graph* gph)
{
int Node = gph->Node;
struct Edge
result[Node]; 
int e = 0; 
int i = 0; 
     //edge sorting
qsort(gph->edge, gph->E, sizeof(gph->edge[0]),
myComp);
     //allocating memory for v subsets
struct tree_subset* subsets
= (struct tree_subset*)malloc(Node * sizeof(struct tree_subset));
for (int v = 0; v < Node; ++v) {
subsets[v].parent = v;
subsets[v].rank = 0;
}
     //V-1 : Path traversal limit
while (e < Node - 1 && i < gph->E) {
struct Edge next_edge = gph->edge[i++];
int x = DisjointSet_find(subsets, next_edge.source);
int y = DisjointSet_find(subsets, next_edge.destination);
if (x != y) {
result[e++] = next_edge;
DisjointSet_Union(subsets, x, y);
}
}
     //prompting state of MST
printf(
"Edges created in MST are as below: \n");
int minimumCost = 0;
     //calculating minimum cost using for loop
for (i = 0; i < e; ++i)
{
printf("%d -- %d == %d\n", result[i].source,
result[i].destination, result[i].weight);
minimumCost += result[i].weight;
}
printf("The Cost for created MST is : %d",minimumCost);
return;
}
//driver function
int main()
{
int Node = 4; 
int E = 6; 
struct Graph* gph = create_Graph(Node, E);
     //graph creation
gph->edge[0].source = 0;
gph->edge[0].destination = 1;
gph->edge[0].weight = 2;
gph->edge[1].source = 0;
gph->edge[1].destination = 2;
gph->edge[1].weight = 4;
gph->edge[2].source = 0;
gph->edge[2].destination = 3;
gph->edge[2].weight = 4;
gph->edge[3].source = 1;
gph->edge[3].destination = 3;
gph->edge[3].weight = 3;
gph->edge[4].source = 2;
gph->edge[4].destination = 3;
gph->edge[4].weight = 1;
gph->edge[5].source = 1;
gph->edge[5].destination = 2;
gph->edge[5].weight = 2;
MST_Kruskal(gph);
return 0;
}

