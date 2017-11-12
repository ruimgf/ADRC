#ifndef	MENU
#define MENU
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BAR_SIZE 50
void welcomeScreen();
int commands();
void screenCustomerCycles(int flag);
void screenCommerciallyConnected(int flag);
void screenResults(int * results, int node);
void progressBar(int curr, int max);
void progressBarFull();

#endif
