#ifndef	MENU
#define MENU
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BAR_SIZE 50
void welcomeScreen();
int commands();
void runTime(time_t total_time);
void screenCustomerCycles(int flag, time_t time_spent);
void screenCommerciallyConnected(int flag, time_t time_spent);
void screenResults(int * results, int node, time_t time_spent);
int commandsTypeRoutes();
void progressBar(int curr, int max);
void progressBarFull();

#endif
