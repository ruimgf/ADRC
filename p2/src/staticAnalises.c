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
          edge = newEdge(v,w,CUSTOMER);
          digraphInsertE(G, edge);
          break;
      case PEER:
          edge = newEdge(v,w,PEER);
          digraphInsertE(G, edge);
        break;
      case CUSTOMER:
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
        if(e->type == CUSTOMER){
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
    if(lastHop==CUSTOMER){
      switch (nextHop) {
        case CUSTOMER:
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
        case CUSTOMER:
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
        case CUSTOMER:
          return 1;
        case PEER:
          return 0;
        case PROVIDER:
          return 0;
        default:
          break;
      }
    }
    return 0;
}

int dfs(Graph * G,int * visited,int nodeId, myList* tier_1_nodes){
    visited[nodeId] = VISITED;
    listNode * aux;
    Edge * e;
    aux = G->adj[nodeId]->begin;
    printf("visiting: %d \n",nodeId );
    int tier_1 = 1;/*variable to check if that node is a tier 1 node*/
    while(aux!=NULL){
        e = (Edge *)aux->item;
        if(e->type == CUSTOMER){
          tier_1 = 0;
        }
        if(visited[e->w]==NOT_VISITED){
          dfs(G,visited,e->w,tier_1_nodes);
        }
        aux = aux->next;
    }
    /*if the node is a tier 1 we insert it on the list*/
    if(tier_1){
      int* tier1_nodeid = (int*) malloc(sizeof(int));
      *tier1_nodeid = nodeId;
      insertmyListEnd(tier_1_nodes, tier1_nodeid);
    }

    return 0;
}
/*function that check if the graph is commercially connected
it receives only a argument, that is the graph*/
int isComercialConnected(Graph * G){
    int visited[MAX_NODES];
    /*mark every node that has no neighbors, we assume that are not isolated
     nodes*/
    int init_dfs = 0;
    for(int i=0; i<MAX_NODES;i++){
      if(G->adj[i]->begin==NULL){
        visited[i] = VISITED;
      }else{
        init_dfs=i;
        visited[i] = NOT_VISITED;
      }
    }
    /*list to save tier_1 nodes*/
    myList* tier_1_nodes = createmyList();

    /*make a dfs to ensure that we have a connected graph and discover tier1 nodes*/
    dfs(G,visited,init_dfs,tier_1_nodes);
    for(int i=0;i<MAX_NODES;i++){
      if(visited[i] != VISITED){
        printf("Node %d cannot see node \n",i);
        return 0;
      }
    }

    /*check if the tier_1 nodes have a peer connection from one to the others*/
    listNode* aux = tier_1_nodes->begin;
    if(aux != NULL){
      /*check if there are only 1 tier1, if it is only one return 1*/
      aux = aux->next;//make aux point to the next element
      if(aux == NULL){
        return 1;
      }

      /*check if the tier_1 nodes are connected*/
      while(aux != NULL){/*for every tier_1 node*/
          int found = 0;

          listNode * aux_graph;
          Edge * e;
          aux_graph = G->adj[*(int*)(tier_1_nodes->begin->item)]->begin;
          while(aux_graph!=NULL){
              e = (Edge *)aux_graph->item;
              if(e->type == PEER){/*if the connection is of peer*/
                if(e->w == *(int*)(aux->item)){//and is the current tier_1 node
                    found = 1;
                }
              }
              aux_graph = aux_graph->next;
          }

          if(found == 0){/*if we dont find the current tier1 connection*/
            return 0;
          }
          aux = aux->next;
      }
    }else{
      printf("No tier1 nodes, something is wrong! \n");
      return 0;
    }

    return 1;

}

int electedRoute(Graph * G, int destination){
    return 1;
}
