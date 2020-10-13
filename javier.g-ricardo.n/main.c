#include<stdio.h>
#include<stdlib.h>
#include "./heap.h"
#include "./median.h"
#include "string.h"

// Función principal, recibe de STDIN un stream de datos e imprime a STDOUT
// la mediana. 
//
int main(int num_args, char **args){

    FILE *fp = fopen(args[1], "r");
    FILE *outFile = fopen("executionOutput.txt", "w");
    char buffer[20];

    if (fp == NULL){
        printf("could not open file\n");
        return 1;
    }

    THeap *thmax = createTHeap(100);
    THeap *thmin = createTHeap(100);
    double median = 0;
    while(fgets(buffer, 20, fp)!= NULL){
        double data = atof(buffer);
        median = theap_median(thmin, thmax, data);
        fprintf(outFile, "%.3lf\n", median);
        printf("%.3lf\n", median);
    }

    //close file
    fclose(fp);
    fclose(outFile);

    //free memory
    free(thmax);
    free(thmin);
  return 0;
} 
