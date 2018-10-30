#include "Graph.c"

bool hasEulerPath(Graph g, int src, int dest){
	if (src != dest){
		if (degree(g, src) % 2 == 0 || degree(g, dest) % 2 == 0){
			return false;
		}
	}else if (degree(g, src) != 0){
		return false;
	}
	int i;
	for (i = 0; i < numOfVertices(g); ++i){
		if (i != src && i != dest && degree(g, i) % 2 != 0){
			return false;
		}
	}
	return true;
}
