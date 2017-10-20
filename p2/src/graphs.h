typedef struct {int v; int w;} Edge;
Edge EDGE(int, int);

typedef struct node *link;
struct node {int v; link next;};
link NEW(int v, link next);


/* Adjacency list representation of a graph */
typedef struct {int V; int E; link *adj;} *Graph;

Graph GRAPHinit(int);
void GRAPHinsertE(Graph, Edge);
void GRAPHshow(Graph);
void GRAPHplot(Graph, char *);
int randV(Graph);
Graph GRAPHrandE(int, int);
Graph GRAPHrandp(int, int);



