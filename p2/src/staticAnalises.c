#include "staticAnalises.h"


Graph loadFromFile(char * filePath){

  FILE * file = fopen(filePath, "r");
  char buffer[100];
  int v1,v2,type;

  Graph G = GRAPHinit(20);

  while ( fgets(buffer,100,file) != NULL ) {
    sscanf(buffer,"%d %d %d", &v1, &v2,&type);
    switch (type) {
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      default:
        printf("Invalid File Format");
        exit(-1);
    }
  }

  fclose(file);
  return G;
}
