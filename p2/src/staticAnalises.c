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

int DFS(Graph * G,int * visited, int nodeID){
  listNode * node;
  Edge * e;
    if(visited[nodeID]){
      return 1;
    }else{
      visited[nodeID] = 1;
    }


    node = G->adj[nodeID]->begin;
    while (node!=NULL) {
      e =(Edge * ) node->item;
      if( e->type == COSTUMER){
        if(DFS(G,visited,e->w)){
          return 1;
        }
      }
      node=node->next;
    }
    return 0;
}
int hasCustomerCycles(Graph * G){
    int i,j;
    int visited[MAX_NODES];
    listNode * node;
    Edge * e;
    for(i=0;i<MAX_NODES;i++){
      visited[i]=0;
    }
    for(i=0;i<G->V;i++){
      if(G->adj[i]->begin != NULL){
          visited[i] = 1;
          node = G->adj[i]->begin;
          while (node!=NULL) {
            e =(Edge * ) node->item;
            if( e->type == COSTUMER){
              if(DFS(G,visited,e->w)){
                printf("coomercial connected\n");
                exit(0);
              }
            }
            node=node->next;
          }

      }
      for(j=0;j<MAX_NODES;j++){
        visited[j]=0;
      }
    }
}

int isComercialConnected(Graph * G){
    return 1;
}

int electedRoute(Graph * G, int destination){
    return 1;
}
