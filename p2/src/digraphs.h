#ifndef	GRAPH
#define	GRAPH

#include <stdio.h>
#include <stdlib.h>




typedef struct {int v; int w; int type} Edge;

typedef struct node *link;

struct node {int v; link next; int type};
/* Adjacency list representation of a graph */
typedef struct {int V; int E; link *adj;} *Graph;




Edge EDGE(int, int, int);

link NEW(int v, link next, int type);

Graph GRAPHinit(int);

void GRAPHinsertE(Graph, Edge);

/*void GRAPHshow(Graph);
void GRAPHplot(Graph, char *);
int randV(Graph);
Graph GRAPHrandE(int, int);
Graph GRAPHrandp(int, int);
*/


#endif
