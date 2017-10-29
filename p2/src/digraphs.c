#include "digraphs.h"

Edge EDGE(int v, int w, int type) {
  Edge *eptr = (Edge *) malloc(sizeof(Edge)) ;
  eptr -> v = v;
  eptr -> w = w;
  eptr -> type = type;
  return *eptr;
}


link NEW(int v, link next, int type) {
  link x = (link) malloc(sizeof(*x));
  x -> v = v;
  x -> next = next;
  x -> type = type;
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

/*Insert a edge in a digraph from v -> w*/
void DIGRAPHinsertE(Graph G, Edge e) {
  int v = e.v;
  int w = e.w;
  int type = e.type;
  G -> adj[v] = NEW(w, G -> adj[v],type);
  G -> E++;
}
