#include "staticAnalises.h"
#include "digraphs.h"

#define NOT_VISITED 0
#define VISITING 1
#define VISITED 2

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

int DFS(Graph * G,int * visited, int nodeId){
    listNode * aux;
    Edge * e;
    if(visited[nodeId] == VISITED){
      return 0;
    }else{
      if(visited[nodeId] == VISITING){
        return 1;
      }
    }
    visited[nodeId] = VISITING;
    aux = G->adj[nodeId]->begin;
    while(aux!=NULL){
        e = (Edge *)aux->item;
        if(e->type == COSTUMER){
          if(DFS(G,visited,e->w)==1){
            return 1;
          }
        }

        aux = aux->next;
    }
    visited[nodeId] = VISITED;
    return 0;
}
int hasCustomerCycles(Graph * G){
    int visited[MAX_NODES];

    for(int i=0; i<MAX_NODES;i++){
      visited[i] = NOT_VISITED;
    }
    for(int i=0;i<MAX_NODES;i++){
      if(visited[i] == NOT_VISITED){
        if(DFS(G,visited,i)==1){
          return 1;
        }
      }
    }
    return 0;
}


int isComercialConnected(Graph * G){
    return 1;
}

int electedRoute(Graph * G, int destination){
    return 1;
}
