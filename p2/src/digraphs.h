#ifndef	GRAPH
#define	GRAPH

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct {
  int v;
  int w;
  int type;
}Edge;

/* Adjacency list representation of a graph */
typedef struct {
  int V;
  int E;
  myList ** adj;
}Graph;

Edge * newEdge(int v, int w, int type);

Graph * digraphInit(int);

void digraphInsertE(Graph*, Edge*);

void printGraph(Graph * G);

/*void GRAPHshow(Graph);
void GRAPHplot(Graph, char *);
int randV(Graph);
Graph GRAPHrandE(int, int);
Graph GRAPHrandp(int, int);
*/


#endif
