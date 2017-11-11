//    gcc menu.c -o pg
//    ./pg

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BAR_SIZE 50

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
  printf("Press enter to start");
  printf("\n");
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
  scanf("%d",&cmd);
  return cmd;
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

int main(int argc, char ** argv) {
  welcomeScreen();
  int cmd = commands();
  switch(cmd) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
  }
  printf("\n%d\n", cmd);
  int i = 0;
  for( i=0;i<BAR_SIZE;i++) {
    progressBar(i,123);
    sleep(1);
  }
  progressBarFull();
  //progressBarFull();
}
