#include "Graph.c"

"""
Euler path problem: ﬁnd a path connecting two vertices v,w in graph G.such that the path includes each edge exactly once 
Theorem:  A graph has an Euler circuit if and only if it is connected and all vertices have even degree 
Theorem.  A graph has a non-circuitous Euler path if and only if it is connected and exactly two vertices have odd degree
"""

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
