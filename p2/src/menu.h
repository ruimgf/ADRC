#ifndef	MENU
#define MENU
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BAR_SIZE 50
void welcomeScreen();
int commands();
void runTime(double total_time);
void screenCustomerCycles(int flag, double time_spent);
void screenCommerciallyConnected(int flag, double time_spent);
void screenResults(int * results, int node, double time_spent);
int commandsTypeRoutes();
void progressBar(int curr, int max);
void progressBarFull();

#endif
