#ifndef	STATIC_ANALISES
#define	STATIC_ANALISES

#include "digraphs.h"

#define PROVIDER 1
#define PEER 2
#define COSTUMER 3
#define NOT_VISITED 0
#define VISITING 1
#define VISITED 2
#define MAX_NODES 200000

Graph  * loadFromFile(char * filePath);
int hasCustomerCycles(Graph * G);
int isComercialConnected(Graph * G);

#endif
