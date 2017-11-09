#ifndef	STATIC_ANALISES
#define	STATIC_ANALISES

#include "digraphs.h"

#define PROVIDER 3
#define PEER 2
#define CUSTOMER 1
#define NO_ROUTE 4

#define NOT_VISITED 0
#define VISITING 1
#define VISITED 2
#define MAX_NODES 100000
#define BEGIN 5



Graph  * loadFromFile(char * filePath);
int hasCustomerCycles(Graph * G);
int isComercialConnected(Graph * G);
void dijkstra(Graph *  G, int destination);
#endif
