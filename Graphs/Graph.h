#include <stdbool.h>

typedef struct GraphRep *Graph;

// edges are pairs of vertices (end-points)
typedef struct Edge {
   int v;
   int w;
} Edge;

Graph newGraph(int);
int   numOfVertices(Graph);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
bool  adjacent(Graph, int, int);
void  showGraph(Graph);
void  freeGraph(Graph);
