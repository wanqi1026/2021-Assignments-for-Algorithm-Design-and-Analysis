#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXEDGE 10
#define MAXVEX 6

typedef struct {
	int a;
	int b;
	int weight;
} Edge ;

typedef struct {
	int numVertexes;
	int numEdges;
	int *vex;
	Edge *edges;
} MGraph;


int Find(int *parent, int f) {
	while (parent[f] != -1)
		f = parent[f];
	return f;
}

int IsCompleted(int *parent) {
	int i;
	int n = 0;
	for (i = 0; i < MAXVEX; ++i) {
		if (parent[i] != -1)
			++n;
	}
	if (n == MAXVEX - 1)
		return 1;
	else
		return 0;
}

void MiniSpanTree_Kruskal(MGraph *G) {
	int i, n, m;

	int parent[MAXVEX];

	for (i = 0; i < G->numVertexes; ++i)
		parent[i] = -1;

	for (i = 0; i < G->numEdges; ++i) {
		n = Find(parent, G->edges[i].a);
		m = Find(parent, G->edges[i].b);
		if (n != m)

		{
			parent[n] = m;
			printf("(%d,%d)  %d\n", G->edges[i].a, G->edges[i].b, G->edges[i].weight);
		}
		if (IsCompleted(parent))
			return;
	}
}

int main(void) {
	MGraph *my_g = (struct MGraph *)malloc(sizeof(MGraph));
	int i, j;
	int t = 0;
	my_g->numVertexes = 6;
	my_g->numEdges = 10;
	my_g->vex = (int *)malloc(sizeof(char) * my_g->numVertexes);
	if (!my_g->vex)
		return 0;
	for (i = 0; i < my_g->numVertexes; ++i)
		my_g->vex[i] = i;
	my_g->edges = (Edge *)malloc(sizeof(Edge) * MAXEDGE);
	if (!my_g->edges)
		return 0;
	my_g->edges[0].a = 1;
	my_g->edges[0].b = 2;
	my_g->edges[0].weight = 1;
	my_g->edges[1].a = 1;
	my_g->edges[1].b = 3;
	my_g->edges[1].weight = 2;
	my_g->edges[2].a = 2;
	my_g->edges[2].b = 3;
	my_g->edges[2].weight = 2;
	my_g->edges[3].a = 2;
	my_g->edges[3].b = 5;
	my_g->edges[3].weight = 3;
	my_g->edges[4].a = 0;
	my_g->edges[4].b = 3;
	my_g->edges[4].weight = 4;
	my_g->edges[5].a = 3;
	my_g->edges[5].b = 5;
	my_g->edges[5].weight = 4;
	my_g->edges[6].a = 4;
	my_g->edges[6].b = 5;
	my_g->edges[6].weight = 4;
	my_g->edges[7].a = 0;
	my_g->edges[7].b = 1;
	my_g->edges[7].weight = 5;
	my_g->edges[8].a = 2;
	my_g->edges[8].b = 4;
	my_g->edges[8].weight = 5;
	my_g->edges[9].a = 0;
	my_g->edges[9].b = 2;
	my_g->edges[9].weight = 6;

	MiniSpanTree_Kruskal(my_g);
}