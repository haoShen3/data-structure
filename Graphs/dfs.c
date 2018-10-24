#include <stdio.h>
#include 'Graph.h'
#include <stdlib.h>
#define MAXNODES 1000

//time complexity is O(V**2). while V is the number of vertexes.

//array to store visiting order
int visited[MAXNODES]; 


bool dfsPathCheck(Graph g, int v, int dest){
	if (v == dest){
		return true;
	}
	int i;
	for (i = 0; i < numOfVertices(g); ++i){
		if (adajent(g, v, i) && (visited[i] == -1)){
			visited[i] = v;
			if dfsPathCheck(g, i, dest){
				return true;
			}
		}
	}
	return false;
}

bool findPathDFS(Graph g, int src, int dest){
	int v;
	int i;
	//the default previous node is -1
	for (i = 0; i < MAXNODES; i++){
		visited[i] = -1;
	}
	visited[src] = src;
	if dfsPathCheck(Graph g, int src, int dest){
		v = dest;
		while (v != src){
			//print the path in dest...src order
			printf("%d-", visited[v]);
			v = visited[v];
		}
		printf("%d", visited[src]);
	}
}






