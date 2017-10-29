#include "staticAnalises.h"
#include "digraphs.h"

Graph * loadFromFile(char * filePath){

  FILE * file = fopen(filePath, "r");
  char buffer[100];
  int v,w,type;

  Graph * G = digraphInit(MAX_NODES);
  Edge * edge;
  while ( fgets(buffer,100,file) != NULL ) {
    if(sscanf(buffer,"%d %d %d", &v, &w,&type)!=3){
      printf("file error\n");
      return G;
    };
    switch (type) {
      case PROVIDER:
          edge = newEdge(w,v,PROVIDER);
          digraphInsertE(G, edge);
          break;
      case PEER:
          edge = newEdge(w,v,PEER);
          digraphInsertE(G, edge);
        break;
      case COSTUMER:
          edge = newEdge(w,v,COSTUMER);
          digraphInsertE(G, edge);
        break;
      default:
        printf("Invalid File Format");
        exit(-1);
    }
  }

  fclose(file);
  return G;
}
