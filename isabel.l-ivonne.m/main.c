#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "./heap.h"
#include "./median.h"

// Función principal, recibe de STDIN un stream de datos e imprime a STDOUT
// la mediana. 
//
int main(int num_args, char ** args){ 
  int c = 20;
  THeap *thmin = THeap_new(c);
  THeap *thmax = THeap_new(c);
  int data;
  while(scanf("%d",&data)>0){
		printf("\nMediana: %f\n",theap_median(thmin,thmax,data));

	 }
  free_THeap(&thmin);
  free_THeap(&thmax);
  
  return 0;
} 
