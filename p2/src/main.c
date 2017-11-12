#include "staticAnalises.h"
#include "list.h"
#include <stdio.h>
#include "heap.h"
#include <pthread.h>

//Global variable to be acessed in every thread
Graph  * G;

/**
 * structure to pass arguments to the thread
 * start   [int* that is the node where thread start computation]
 * end     [int* that is the node where thread end the computation]
 * results [int* with 3 positions, the first store number of cutomer routes
 *                  second peer routes and third the provider routes]
 */
typedef struct thread_args{
  int start;
  int end;
  int results[3];
}thread_args;

/**
 * [handler_destination thread function that computes the destinaton from nodes start to nodes end in the
 graph G.]
 * @param new_args [see structure]
 */
void* handler_destination(void* new_args){

  int start_aux;
  int end_aux;
  int* results_aux;
  thread_args* new_args_aux;

  //variables to store the number of routes elected
  int customer=0;
  int peer=0;
  int provider=0;

  new_args_aux = (thread_args*)new_args;
  start_aux = new_args_aux->start;
  end_aux = new_args_aux->end;
  results_aux = new_args_aux->results;

  //compute the routes
  for(int i = start_aux;i<end_aux;i++){
    dijkstra(G,i,&customer,&peer,&provider);
  }

  printf("customer: %d , peer: %d , provider: %d \n", customer,peer,provider);

  //save results
  results_aux[0] = customer;
  results_aux[1] = peer;
  results_aux[2] = provider;

  return NULL;
}

/**
 * [compute_routes_all_network function that given a network G computes the
 *  the routes from all nodes to all and returns the results, distributes the
 *  work between N threads]
 * @param N [int number of threads to divide the work]
 * @param  G [Graph* structure that represents the network]
 * @return   [int* with 3 positions in the first is the number of customer
 *            routes, second peer routes and third provider routes]
 */
int* compute_routes_all_network(int N){

  //we will divide the work between N threads
  int division_step = (G->V)/N;
  int division_remainder = (G->V)%N;//this will be present in the last thread
  pthread_t thread[N];//we will have N threads

  //to send the comands to each thread and save the results
  thread_args* new_args [N];

  for(int i = 0; i< N; i++){

    new_args[i] = (thread_args*)malloc(sizeof(thread_args));

    //in the last element we have to include the division_remainder
    if(i == N-1){
      new_args[i]->start = i*division_step;
      new_args[i]->end = (i+1)* division_step + division_remainder;
    }else{
      new_args[i]->start = i*division_step;
      new_args[i]->end = (i+1)*division_step;
    }

    /*create thread*/
		int err = pthread_create(&thread[i], NULL, handler_destination,
                              (void*)new_args[i]);
		if(err != 0){
			perror("pthread_create:");
			exit(-1);
		}


  }

  //Wait for threads completetion
  for(int i=0; i < N; i++){
    pthread_join(thread[i],NULL);
  }

  //Compute overall results
  int* results_return;
  results_return = (int*)malloc(3*sizeof(int));
  results_return[0] = 0;
  results_return[1] = 0;
  results_return[2] = 0;

  for(int i = 0; i< N; i++){
    results_return[0] = results_return[0] + new_args[i]->results[0];
    results_return[1] = results_return[1] + new_args[i]->results[1];
    results_return[2] = results_return[2] + new_args[i]->results[2];
  }

  return results_return;

}



int main(int argc, char const *argv[]) {

  char filePath[100];
  //myList * test_list;
  if(argc != 3){
    printf("Usage : main.o [filename]\n");
    exit(-1);
  }

  sprintf(filePath, "%s",argv[1]);

  G = loadFromFile(filePath);


  printf("%d\n",hasCustomerCycles(G));
  printf("%d\n",isComercialConnected(G));

  /*
  int customer=0,provider=0,peer=0;
  for(int i=1;i<67000;i++){
      if(G->adj[i]->begin != NULL)
        dijkstra(G,i,&customer,&peer,&provider);
      //printf("%d\n",i);
  }*/

  int* results;
  results = compute_routes_all_network(4);

  printf("CUSTOMER %d\n",results[0]);
  printf("PEER %d\n",results[1]);
  printf("PROVIDER %d\n",results[2]);

  return 0;
}
