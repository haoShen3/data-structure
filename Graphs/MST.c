#include "Graph.c"

bool visited[MAXNOES]

bool dfsCycleCheck(Graph mst, int v, int w){
	visited[v] = true;
	int i;
	for (i = 0; i < numOfVertices(mst); i++){
		if(adjacent(g, i, v) || adjacent(g, v, i)){
			if (!visited[i]){
				return dfsCycleCheck(mst, i, v);
			}else if (i != w){
				return true;
			}
		}
	}	
	return false;
}

Graph kruskal(Graph g, int sortedEdges[], int nE){
	int nV = numOfVertices(g);
	Graph mst = newGraph(nV);
	int i;
	int n = 0;
	for (i = 0; i < nE && n < nV - 1; ++i){
		Edge e = sortedEdges[i];
		insertEdge(mst, e);
		n++;
		int v;
		for(v = 0; v < nV; ++v){
			visited[v] = false;
		}
		if (dfsCycleCheck(mst, e.v, e.v)){
			n--;
			removeEdge(mst, e);
		}
	}
	return mst;
}
