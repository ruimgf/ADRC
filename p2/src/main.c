#include "staticAnalises.h"
#include "list.h"
#include <stdio.h>
#include "heap.h"
#include <pthread.h>
#include "menu.h"
#include <time.h>
//Global variable to be acessed in every thread
Graph  * G;
int analise=0;
pthread_mutex_t lock;
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
  //printf("start: %d , end: %d \n",start_aux,end_aux );
  //compute the routes
  for(int i = start_aux;i<=end_aux;i++){
    dijkstra(G,i,&customer,&peer,&provider);
    pthread_mutex_lock(&lock);
    analise +=1;
    //progressBar(analise,MAX_NODES);
    pthread_mutex_unlock(&lock);
  }


  //save results
  results_aux[0] = customer;
  results_aux[1] = peer;
  results_aux[2] = provider;

  //printf("customer: %d , peer: %d , provider: %d \n", new_args_aux->results[0],new_args_aux->results[1],new_args_aux->results[2]);
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


    if(i == N-1){//in the last element we have to include the division_remainder
      new_args[i]->start = (i*division_step) + 1;
      new_args[i]->end = ((i+1)*division_step) + division_remainder;
    }else if(i == 0){//in zero the first element is the zero
      new_args[i]->start = i*division_step;
      new_args[i]->end = (i+1)*division_step;
    }else{//in other elements the formula of start is diferent
      new_args[i]->start = (i*division_step) + 1;
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
  //progressBarFull();
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
  if(argc < 2){
    printf("Usage : main.o [filename]\n");
    exit(-1);
  }

  sprintf(filePath, "%s",argv[1]);

  G = loadFromFile(filePath);

  printf("number_nodes :%d\n",G->V);



  welcomeScreen();
  int * results;
  int results2[3];
  int cmd, cmd2, node_djikstra = 0, flag, menu2 = 1;
  clock_t begin = clock();
  clock_t end = clock();
  double total_time;
  while(1) {
    menu2 = 1;
    cmd = commands();
    switch(cmd) {
      case 1:
          begin = clock();
          flag = hasCustomerCycles(G);
          end = clock();
          total_time = (double)(end - begin) / CLOCKS_PER_SEC;
          screenCustomerCycles(flag, total_time);
          getchar();
        break;
      case 2:
          begin = clock();
          flag = isComercialConnected(G);
          end = clock();
          total_time = (double)(end - begin) / CLOCKS_PER_SEC;
          screenCommerciallyConnected(flag, total_time);
          getchar();
        break;
      case 3:
        analise=0;
        while(menu2) {
          cmd2 = commandsTypeRoutes();
          switch(cmd2) {
            case 1:
                printf("\nDestination Node: ");
                scanf("%d", &node_djikstra);
                begin = clock();
                results[0] = 0;
                results[1] = 0;
                results[2] = 0;
                dijkstra(G, node_djikstra, &results2[0], &results2[1], &results2[2]);
                end = clock();
                total_time = (double)(end - begin) / CLOCKS_PER_SEC;
                screenResults(results2, node_djikstra, total_time);
                getchar();
              break;
            case 2:
                printf("\nIn progress... This may take some time...\n");
                begin = clock();
                results = compute_routes_all_network(4);
                end = clock();
                total_time = (double)(end - begin) / CLOCKS_PER_SEC;
                screenResults(results, node_djikstra, total_time);
                getchar();
              break;
            case 3:
                menu2 = 0;
              break;
          }
        }
        break;
      case 4:
          system("clear");
          exit(0);
        break;
    }
  }


  return 0;
}
