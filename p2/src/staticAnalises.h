#ifndef	STATIC_ANALISES
#define	STATIC_ANALISES

#include "digraphs.h"

#define PROVIDER 1
#define PEER 2
#define COSTUMER 3
#define MAX_NODES 200000

Graph  * loadFromFile(char * filePath);
int hasCustomerCycles(Graph * G);

#endif
