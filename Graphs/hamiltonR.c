#include "Graph.c"

bool visited[MAXNODES]

bool hamiltonR(Graph g, int v, int dest, int d){
	if (v == dest){
		if (d == 0){
			return true;
		}else{
			return false;
		}
	}
	visited[v] = true;
	int i;
	for (i = 0; i < numOfVertices(g); ++i){
		if (adjacent(g, v, i) && !visited[i]){
			if (hamiltonR(g, i, dest, d-1){
				return true;
			}
		}
	}
	visited[v] = false;
	return false;
}


bool hasHamiltonianPath(Graph g, int src, int dest){
	int v;
	int nV = numOfVertices(g);
	for (v = 0; v < nV; ++v){
		visited[v] = false;
	}
	return hamiltonR(g, src, dest, nV - 1);
}
