#include<stdio.h>
#include<stdlib.h>
#include "./heap.h"
//test insert
void test1()
{
  int n=7;
  int c = 100;
  int *arr = (int*)malloc(n*sizeof(int));
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
  free_THeap(&h);
}

//Test get removemax
void test2()
{
	int n=7;
  int c = 100;
  int *arr = (int*)malloc(n*sizeof(int));
  for (unsigned int i=0; i<n; i++)
    {
	   arr[i] = abs(rand()%50);
	   printf("%d ",arr[i]);
    }
    printf("\n");
  THeap *h = THeap_new(c);
  for(unsigned int i=0; i<n; i++)
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
  }
  free_THeap(&h);
}

int main(int num_args, char ** args)
{ 
  
	test2();
	
  return 0;
 }  
