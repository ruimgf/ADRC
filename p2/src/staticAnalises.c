#include "staticAnalises.h"
#include "digraphs.h"
#include "heap.h"
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
      case 1:
          edge = newEdge(v,w,PROVIDER);
          digraphInsertE(G, edge);
          break;
      case 2:
          edge = newEdge(v,w,PEER);
          digraphInsertE(G, edge);
        break;
      case 3:
          edge = newEdge(v,w,CUSTOMER);
          digraphInsertE(G, edge);
        break;
      default:
        printf("Invalid File Format");
        exit(-1);
    }
  }

  //Check how many valid nodes exist and save in G->V
  int n_valid_nodes = 0;
  for(int i = 0; i < MAX_NODES; i++){
    if(G->adj[i]->begin!=NULL){
      n_valid_nodes = i;
    }
  }

  G->V = n_valid_nodes;

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

/*DFS that gets the tier1_nodes to a list*/
int dfs(Graph * G,int * visited,int nodeId, myList* tier_1_nodes){
    visited[nodeId] = VISITED;
    listNode * aux;
    Edge * e;
    aux = G->adj[nodeId]->begin;
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

    /*load tier1 nodes to a array*/
    int number_tier1 = lenmyList(tier_1_nodes);

    if(number_tier1 == 0){
      printf("Number tier_1 nodes = 0. Something Wrong\n");
      return 0;
    }

    int * tier_1 = malloc(number_tier1 * sizeof(int));
    int i = 0;
    listNode* aux = tier_1_nodes->begin;
    while(aux != NULL){
      tier_1[i] = *(int*)aux->item;
      aux = aux->next;
      i = i+1;
    }



    /*initiate the search*/
    for(int i =0; i<number_tier1; i++){
      listNode * aux_graph;
      Edge * e;
      aux_graph = G->adj[tier_1[i]]->begin;/*get adjacent list for tier1 node number i*/

      int visited[number_tier1];
      for(int j= 0; j <number_tier1;j++){
        visited[j] = NOT_VISITED;
      }

      /*run the adjacency list*/
      while(aux_graph!=NULL){
          e = (Edge *)aux_graph->item;
          if(e->type == PEER){
            //check if that connection is one of the other tier_1 nodes
            for(int z = 0;z<number_tier1;z++){
              if(e->w == tier_1[z]){
                visited[z] = VISITED;
              }
            }
          }
        aux_graph = aux_graph->next;
      }

      /*check if all tier one nodes have been visited*/
      for(int z = 0; z<number_tier1;z++){
        if(z == i){/*do not check if visited himself*/
          continue;
        }else{
          if(visited[z] == NOT_VISITED){
            return 0;
          }
        }
      }


    }

    /* if we reach this point we have a commercially connected*/
    return 1;

}



int exported_route(int previous, int next){
    int mat[5][5];

    mat[CUSTOMER][CUSTOMER] = CUSTOMER;
    mat[CUSTOMER][PEER] = NO_ROUTE;
    mat[CUSTOMER][PROVIDER] = NO_ROUTE;
    mat[CUSTOMER][NO_ROUTE] = NO_ROUTE;

    mat[PEER][CUSTOMER] = PEER;
    mat[PEER][PEER] = NO_ROUTE;
    mat[PEER][PROVIDER] = NO_ROUTE;
    mat[PEER][NO_ROUTE] = NO_ROUTE;

    mat[PROVIDER][CUSTOMER] = PROVIDER;
    mat[PROVIDER][PEER] = PROVIDER;
    mat[PROVIDER][PROVIDER] = PROVIDER;
    mat[PROVIDER][NO_ROUTE] = NO_ROUTE;

    return mat[next][previous];
}

void dijkstra(Graph *  G, int destination,int * custumer, int * peer,int * provider){
    /*if node of destination is empty return*/
    if(G->adj[destination]->begin == NULL){
      return;
    }

    int * weights = malloc(G->V  * sizeof(int));
    heap * h = createHeap(G->V);
    listNode * aux;
    Edge * e;
    int actual_node;

    for(int i=0; i<=G->V;i++){
      if(G->adj[i]->begin != NULL){
        weights[i] = PROVIDER; // talvez mudar para costumer route
        if(i==destination){
            weights[destination] =  CUSTOMER;
        }
        insertHeap(h,i, weights[i]);
      }else{
        weights[i] = NO_ROUTE;
      }
    }
    while(!isEmpty(h)){
      actual_node = removeHeap(h);
      if(weights[actual_node] == PROVIDER){
        break;
      }
      aux = G->adj[actual_node]->begin;
      while(aux != NULL){
          e = (Edge *)aux->item;
          if (weights[e->w] > exported_route(weights[actual_node],e->type)){
            weights[e->w] = exported_route(weights[actual_node],e->type);
            modifyHeap(h,e->w,weights[e->w]);
          }
          aux = aux->next;
      }
    }

    for(int i =1 ; i<MAX_NODES;i++){
      if(G->adj[i]->begin == NULL)
          continue;
      switch (weights[i]) {
        case CUSTOMER:
          //printf("%d ",i);
          //printf("%s\n", "CUSTOMER");
          *custumer += 1;
          break;
        case PEER:
          //printf("%d ",i);
          //printf("%s\n", "PEER");
          *peer += 1;
          break;
        case PROVIDER:
          //printf("%d ",i);
          //printf("%s\n", "PROVIDER");
          *provider += 1;
          break;
        case NO_ROUTE:
          printf("%d ",i);
          printf("%s\n", "NO_ROUTE");
          break;
      }
    }
    freeHeap(h);
    free(weights);

}

int electedRoute(Graph * G, int destination){
    return 1;
}
