#include<stdio.h>
#include<stdlib.h>
#include "./heap.h"




int main(int num_args, char ** args)
{ 
  
  //int n =15;
	int n=7;
  int c = 100;
  int *arr = (int*)malloc(n*sizeof(int));
  /*arr[0]=9;
  arr[1]=5;
  arr[2]=2;
  arr[3]=7;
  arr[4]=1;
  arr[5]=3;
  arr[6]=3;*/
  for (unsigned int i=0; i<n; i++)
   {
	   arr[i] = abs(rand()%50);
	   printf("%d ",arr[i]);
	   
    }
    printf("\n");
  THeap *h = THeap_new(c);
   for(unsigned int i=0; i<n; i++)
  {
  	insert(h,arr[i]);
	printf("\n El monticulo es:\n");
	for(unsigned int j=0; j<=h->n; j++)
	  printf("%d ",h->data[j]);
    printf("\n");
  }
 /* for(unsigned int i=0; i<n; i++)
		insert(h,arr[i]);
  for(unsigned int i=0; i<n; i++)
	printf("%d ",h->data[i]);
  printf("\n");
  for(unsigned int i=0; i<n; i++)
  {
	printf("\n maximo:%d\n",removeMax(h));
	for(unsigned int j=0; j<=h->n; j++)
	  printf("%d ",h->data[j]);
    printf("\n");
  }*/
  free_THeap(&h);
  return 0;
 }  