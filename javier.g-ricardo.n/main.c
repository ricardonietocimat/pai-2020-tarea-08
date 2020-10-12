#include<stdio.h>
#include<stdlib.h>
#include "./heap.c"
#include "./median.c"

// Función principal, recibe de STDIN un stream de datos e imprime a STDOUT
// la mediana. 
//
int main(int num_args, char ** args){ 
    int num=0;
    float med=0;
    THeap * thmin=NULL,* thmax=NULL;
    FILE *arch.*arch2;
    arch = stdin;
    arch2 = stdout;
    if(arch!=NULL && arch2!=NULL){
        while( fscanf(arch,"%d ",num)>0){
            med=theap_median(thmin, thmax, num);
            fprintf(arch2,"%f \n",med);
        }
    }
  
  
    free_THeap(&thmin);
    free_THeap(&thmax)
    fclose(arch);
    fclose(arch2);
  return 0;
} 
