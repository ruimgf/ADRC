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
    }
    switch (type) {
      case PROVIDER:
          edge = newEdge(v,w,COSTUMER);
          digraphInsertE(G, edge);
          break;
      case PEER:
          edge = newEdge(v,w,PEER);
          digraphInsertE(G, edge);
        break;
      case COSTUMER:
          edge = newEdge(v,w,PROVIDER);
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

int visit(Graph * G,int * visited, int nodeId){
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
          if(visit(G,visited,e->w)==1){
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
        if(visit(G,visited,i)==1){
          return 1;
        }
      }
    }
    return 0;
}

int canHop(int lastHop,int nextHop){
    if(lastHop==COSTUMER){
      switch (nextHop) {
        case COSTUMER:
          return 1;
        case PEER:
          return 0;
        case PROVIDER:
          return 0;
        default:
          break;
      }
    }

    if(lastHop==PROVIDER){
      switch (nextHop) {
        case COSTUMER:
          return 1;
        case PEER:
          return 1;
        case PROVIDER:
          return 1;
        default:
          break;
      }
    }

    if(lastHop==PEER){
      switch (nextHop) {
        case COSTUMER:
          return 1;
        case PEER:
          return 0;
        case PROVIDER:
          return 0;
        default:
          break;
      }
    }
}

int dfs(Graph * G,int * visited, int lastHop,int nodeId){
    visited[nodeId] = VISITED;
    listNode * aux;
    Edge * e;
    aux = G->adj[nodeId]->begin;
    while(aux!=NULL){
        e = (Edge *)aux->item;
        if(visited[e->w]==NOT_VISITED && canHop(lastHop,e->type)){
          dfs(G,visited,e->type,e->w);
        }
        aux = aux->next;
    }
    return 0;
}

int isComercialConnected(Graph * G){
    int visited[MAX_NODES];
    for(int j=1;j<MAX_NODES;j++){
      if(G->adj[j]->begin==NULL){
        continue;
      }
      for(int i=0; i<MAX_NODES;i++){
        if(G->adj[i]->begin==NULL){
          visited[i] = VISITED;
        }else{
          visited[i] = NOT_VISITED;
        }
      }

      dfs(G,visited,PROVIDER,j);
      for(int i=0;i<MAX_NODES;i++){
        if(visited[i] != VISITED){
          printf("Node %d cannot see node %d\n",j,i);
          return 0;
        }
      }
    }
    return 1;

}

int electedRoute(Graph * G, int destination){
    return 1;
}
