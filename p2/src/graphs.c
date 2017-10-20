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
GraphG = (Graph) malloc(sizeof *G);
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

Graph GRAPHrandp(int V, int E) {
int i, j;
double p = 2.0 * E / (V * (V - 1));
Graph G = GRAPHinit(V);
randini();
for (i = 0; i < V; i++)
 for (j = 0; j <i; j++)
 if (randlcg(1) < p)
 GRAPHinsertE(G, EDGE(i, j));
return G;
}


