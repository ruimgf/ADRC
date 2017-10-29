#ifndef	STATIC_ANALISES
#define	STATIC_ANALISES

#include "digraphs.h"

#define PROVIDER 1
#define PEER 2
#define COSTUMER 3
#define MAX_NODES 500000

Graph  * loadFromFile(char * filePath);

#endif
