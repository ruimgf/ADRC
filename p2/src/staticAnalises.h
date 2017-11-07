#ifndef	STATIC_ANALISES
#define	STATIC_ANALISES

#include "digraphs.h"

#define PROVIDER 1
#define PEER 2
#define CUSTOMER 3
#define NOT_VISITED 0
#define VISITING 1
#define VISITED 2
#define MAX_NODES 200000
#define BEGIN 5
#define CUSTOMER_ROUTE 4
#define PEER_ROUTE 3
#define PROVIDER_ROUTE 2
#define NO_ROUTE 1


Graph  * loadFromFile(char * filePath);
int hasCustomerCycles(Graph * G);
int isComercialConnected(Graph * G);
void dijkstra(Graph *  G, int destination);
#endif
