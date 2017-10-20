#include "graphs.h"

Edge EDGE(int v, int w) {
  Edge *eptr = (Edge *) malloc(sizeof(Edge)) ;
  eptr -> v = v;
  eptr -> w = w;
  return *eptr;
}


link NEW(int v, link next) {
  link x = (link) malloc(sizeof(*x));
  x -> v = v;
  x -> next = next;
  return x;
}

Graph GRAPHinit(int V) {
  int v;

  Graph G = (Graph) malloc(sizeof *G);
  G -> V = V;
  G -> E = 0;
  G -> adj = (link *) malloc(V * sizeof(link));
  for (v = 0; v < V; v++)
    G -> adj[v] = NULL;
  return G;
}

void GRAPHinsertE(Graph G, Edge e) {
  int v = e.v;
  int w = e.w;
  G -> adj[v] = NEW(w, G -> adj[v]);
  G -> adj[w] = NEW(v, G -> adj[w]);
  G -> E++;
}
