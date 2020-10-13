#include<stdio.h>
#include<stdlib.h>
#include "./heap.c"
#include "./median.c"

// Función principal, recibe de STDIN un stream de datos e imprime a STDOUT
// la mediana. 
//
int main(int num_args, char ** args){ 
    int num=0, cap=30;
    double med=0;
    THeap * thmin=NULL, *thmax=NULL;
    
    thmax=THeap_new(cap);
	thmin=THeap_new(cap);
    
    while(scanf("%d",&num)>0){
		med=theap_median(thmin, thmax, num);
           
        printf("%0.3lf\n",med);
    }
  
    free_THeap(&thmin);
    free_THeap(&thmax);
  return 0;
} 
