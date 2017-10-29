#include "digraphs.h"

Edge * newEdge(int v, int w, int type) {
  Edge *eptr = (Edge *) malloc(sizeof(Edge)) ;
  eptr -> v = v;
  eptr -> w = w;
  eptr -> type = type;
  return eptr;
}


Graph  * digraphInit(int V) {
  int v;

  Graph * G = (Graph*) malloc(sizeof(Graph));
  G -> V = V;
  G -> E = 0;
  G -> adj = (myList **) malloc(V * sizeof(myList*));
  for (v = 0; v < V; v++)
    G -> adj[v] = createmyList();
  return G;
}

/*Insert a edge in a digraph from v -> w*/
void digraphInsertE(Graph* G, Edge * e) {
    int v = e->v;
    insertmyListEnd(G->adj[v], (void *) e);
    G->E ++ ;
}

void printEdge(void * e){
    Edge edge = *(Edge*)e;
    printf("w : %d type: %d ||",edge.w,edge.type);
}
void printGraph(Graph * G){
    int i;
    for(i=0;i<G->V;i++){
      if(G->adj[i]->begin != NULL){
          printf("V %d \n",i);
          printmyList(G->adj[i],&printEdge);
          printf("\n ----------\n");
      }

    }
}
