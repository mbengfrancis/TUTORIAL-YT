#include <bits/stdc++.h>
using namespace std;
//We will define the number of vertices in the graph
#define Vtx 4
// We will Define Infinite as a significant enough
 //value.
#define INF 99999
// A function declaration to print the solution matrix
void print_sol(int distance[][Vtx]);
// A function to Solve the all-pairs shortest path problem
void floydWarshall(int graph[][Vtx])
{
    /*The output matrix will be a 2D array distance[][], 
which will have the shortest distance 
between every pair of vertices. */
    int distance[Vtx][Vtx], i, j, k;
    /* Initialize the solution matrix same
    as input graph matrix. Or we can say
    the initial values of shortest distances
    are based on shortest paths considering
    no intermediate vertex. */
    for (i = 0; i < Vtx; i++)
        for (j = 0; j < Vtx; j++)
            distance[i][j] = graph[i][j];
    /* All vertices are added to the 
        set of intermediate vertices one by one.
    --> We know shortest distances between 
all pairs of vertices before we start an iteration, 
and the shortest distances only consider 
the vertices in set 0 through k-1 as intermediate vertices.
    --> After each iteration, vertex no. k is 
added to the set of intermediate vertices, 
resulting in a set of 0 to k.*/
    for (k = 0; k < Vtx; k++) {
        // We will one by one pick all vertices as source
        for (i = 0; i < Vtx; i++) {
            //We will Pick all the vertices as destination 
 //for the above picked source
          for (j = 0; j < Vtx; j++) {
            //If k is located on the shortest path from I to j, 
//then we update distance[i][j].
           if (distance[i][j] > (distance[i][k] + distance[k][j])
                    && (distance[k][j] != INF
                        && distance[i][k] != INF))
                distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }
    //We will now Print the shortest distance matrix
    print_sol(distance);
}
/* A function to print the solution */
void print_sol(int distance[][Vtx])
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
for (int i = 0; i < Vtx; i++) {
        for (int j = 0; j < Vtx; j++) {
            if (distance[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << distance[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    /* Let us create the following weighted graph
       10
(0)------->(3)
  |             /|\
5|               |
  |               |1
 \|/              |
(1)------->(2)
        3           
*/
    int graph[Vtx][Vtx] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
    // Print the solution
    floydWarshall(graph);
    return 0;
}

