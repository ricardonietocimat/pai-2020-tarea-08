#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include "heap.h"

int main(int num_args, char ** args){ 
  
  srand(time(NULL));
  int n =15;
  int c = 100;
  printf("%d",INT_MIN);
  int *arr = (int*)malloc(n*sizeof(int));
  /*for (unsigned int i=0; i<n; i++)
   {
	   arr[i] = rand()%50-25;
	   printf("%d ",arr[i]);
	   
    }*/
    arr[0] = -10;
    arr[1] = 15;
    arr[2]=-7;
    arr[3] = -20;
    arr[4] = 18;
    arr[5]=-23;
    arr[6] =0;
    arr[7] =10;
    arr[8] =12;
    arr[9]=-14;
    arr[10]=14;
    arr[11] =13;
    arr[12]=-25;
    arr[13]=-9;
    arr[14]=18;
   /* arr[0] = 33;
    arr[1] = 36;
    arr[2]=27;
    arr[3] = 15;
    arr[4] = 43;
    arr[5]=35;
    arr[6] =36;*/
    printf("\n");
  THeap *h = THeap_new(c);
  for(unsigned int i=0; i<n; i++)
		insert(h,arr[i]);
  for(unsigned int i=0; i<n; i++)
	printf("%d ",h->data[i]);
  printf("\n");
  while(h->n>=0){
	printf("\n maximo:%d\n",removeMax(h));
	for(int j=0; j<=h->n; j++)
	  printf("%d ",h->data[j]);
    printf("\n");
   }
   printf("\n maximo:%d\n",removeMax(h));
  free_THeap(&h);
  return 0;
} 
