#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
// Definiciones ===============================================================
THeap* THeap_new(){
	// Asignación de memoria a la  struct THeap.
	THeap* heap = (THeap*)malloc(sizeof(THeap));
	return heap;
	
}

void free_THeap(THeap** hptr){
	free((*hptr)->data);
	free(*hptr);
}

void swap(int *arr, int i, int j){
	int tmp= arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void insert(THeap *h, int data){ 
	
  if(h->n+1 == h->capacity) return;
  h->data[++(h->n)]= data;
  bottomUpHeapify(h->data, h->n);
  return;
  
} 

int removeMax(THeap *h){ 
	if (h->n<1)
	{ 
		return -1;
	}
	int tmp = h->data[0];
	h->data[0]= h->data[h->n--];
	topDownHeapify(h->data,0,h->n);
	return tmp;
} 

int getMax(THeap *h){ 

  return h->data[0];
} 

void bottomUpHeapify(int *arr, int k){ 
  while (k > 1 && arr[(k-1)/3]<arr[k]){
	swap(arr,k,(k-1)/3);
	k=(k-1)/3;
	}
  return;
} 

void topDownHeapify(int * arr, int k, int n){ 
	while (3*k+1 <= n)
	{
		int j = 3*k+1;
		int l = 3*k+1;
		if (j < n && arr[j]<arr[ j+1]) 
			l++;
		if (j < n-1 && arr[j]<arr[ j+2]) 
			l++;

		if ( arr [k]>=arr[l])
		 break;
		swap(arr,k, l );
		k = l;
	}
  return;
} 

