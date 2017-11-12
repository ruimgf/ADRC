//    gcc menu.c -o pg
//    ./pg

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"


void welcomeScreen() {
  system("clear");
  printf("╔═════════════════════════════════════════════════╗\n");
  printf("║       Static Analysis of Inter-AS Routing       ║\n");
  printf("╠════════════════╦════════════════════════════════╣\n");
  printf("║      ADRC      ║     Rui Figueiredo - 78247     ║\n");
  printf("║  1st Semester  ║   Alexandre Candeias - 78599   ║\n");
  printf("║   2017  2018   ║     Jorge Sacadura - 78537     ║\n");
  printf("╠════════════════╩════════════════════════════════╣\n");
  printf("║        IST -- Instituto Superior Técnico        ║\n");
  printf("╚═════════════════════════════════════════════════╝\n\n");
  printf("Press enter to start...\n");
  getchar();
}

int commands() {
  int cmd;
  system("clear");
  printf("╔═════════════════════════════════════════════════╗\n");
  printf("║                    COMMANDS                     ║\n");
  printf("╠═════════════════════════════════════════════════╣\n");
  printf("║ 1. Check if Network has Customer Cycles         ║\n");
  printf("║ 2. Check if Network is Commercially Connected   ║\n");
  printf("║ 3. Type of routes elected by a Destination Node ║\n");
  printf("║ 4. Exit                                         ║\n");
  printf("╚═════════════════════════════════════════════════╝\n\n");
  printf("cmd: ");
  if(scanf("%d",&cmd)==0){
    exit(0);
  }
  return cmd;
}

int commandsTypeRoutes() {
  int cmd;
  system("clear");
  printf("╔═════════════════════════════════════════════════╗\n");
  printf("║                    COMMANDS                     ║\n");
  printf("╠═════════════════════════════════════════════════╣\n");
  printf("║ 1. Destination Node                             ║\n");
  printf("║ 2. All Nodes                                    ║\n");
  printf("║ 3. Back to Menu                                 ║\n");
  printf("╚═════════════════════════════════════════════════╝\n\n");
  printf("cmd: ");
  if(scanf("%d",&cmd)==0){
    exit(0);
  }
  return cmd;
}

void runTime(double total_time) {
  if(total_time>=60){
    printf("Run Time = %d minutes.\n\n", (int)total_time/60);
  }else if(total_time<60 && total_time>1){
    printf("Run Time = %.0lf milliseconds.\n\n", total_time);
  }else{
    printf("Run Time = %.0lf microseconds.\n\n", total_time*1000);
  }
}

void screenCustomerCycles(int flag, double time_spent) {
  system("clear");
  printf("╔═════════════════════════════════════════════╗\n");
  if(flag) {
    printf("║         NETWORK HAS COSTUMER CYCLES         ║\n");

  } else {
    printf("║        NETWORK HAS NO COSTUMER CYCLES       ║\n");
  }
  printf("╚═════════════════════════════════════════════╝\n\n");
  runTime(time_spent);
  printf("Press enter to go back to command screen...\n");
  getchar();
}

void screenCommerciallyConnected(int flag, double time_spent) {
  system("clear");
  printf("╔═════════════════════════════════════════════╗\n");
  if(flag) {
    printf("║      NETWORK IS COMMERCIALLY CONNECTED      ║\n");

  } else {
    printf("║    NETWORK IS NOT COMMERCIALLY CONNECTED    ║\n");
  }
  printf("╚═════════════════════════════════════════════╝\n\n");
  runTime(time_spent);
  printf("Press enter to go back to command screen...\n");
  getchar();
}

void screenResults(int * results, int node, double time_spent) {
  system("clear");
  printf("╔════════════════════════════════════════════╗\n");
  printf("║    TYPES OF CONNECTIONS FOR NODE %-9d ║\n", node);
  printf("╠══════════════╦══════════════╦══════════════╣\n");
  printf("║ COSTUMER     ║ PEER         ║ PROVIDER     ║\n");
  printf("╠══════════════╬══════════════╬══════════════╣\n");
  printf("║ %-9d    ║ %-9d    ║ %-9d    ║\n", results[0], results[1], results[2]);
  printf("╚══════════════╩══════════════╩══════════════╝\n\n");
  runTime(time_spent);
  printf("Press enter to go back to command screen...\n");
  getchar();
}

void progressBar(int curr, int max) {
  int i;
  printf("\rProgress: ");
  for(i = 0; i < curr * BAR_SIZE / max; i++) printf("█");
  for(i = 0; i < BAR_SIZE - curr * BAR_SIZE / max; i++) printf(" ");
  printf(" %.0f%%", (int)100*((float)curr/max));
  fflush(stdout);
  return;
}

void progressBarFull(){
  int j;
  printf("\rProgress: ");
  for(j=0; j<BAR_SIZE;j++)
    printf("█");
  printf(" %d%%", 100);
  fflush(stdout);
  printf("\n");
  return;
}
