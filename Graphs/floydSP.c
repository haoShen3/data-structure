#include "Graph.h"

#define NODES 6
#define VERY_HIGH_VALUE 99999

int dist[NODES][NODES]
int path[NODES][NODES]

void floyd(Graph g){
	int i, s, t;
	for (i = 0; i < NODES; ++i){
		for (s = 0; s < NODES; ++s){
			if (i == s){
				dist[i][s] = 0;
				path[i][s] = -1;
			}else{
				if (adjacent(g, i, s)){
					dist[i][s] = adjacent(g, i, s);
					path[i][s] = s;
				}else{
					dist[i][s] = VERY_HIGH_VALUE;
					path[i][s] = -1;
				}
			}
		}
	}
	for (i = 0; i < NODES; ++i){
		for (s = 0; s < NODES; ++s){
			for (t = 0; t < NODES; ++t){
				if (dist[s][i] + dist[i][t] < dist[s][t]){
					dist[s][t] = dist[s][i] + dist[i][t];
					path[s][t] = path[s][i];
				}
			}
		}
	}
}
