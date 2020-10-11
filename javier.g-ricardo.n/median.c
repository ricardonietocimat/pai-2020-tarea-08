/* Modified by: Abdiel Beltran, 11/10/20 */
#include <stdio.h>
#include "TernaryHeap.h"
#include "median.h"
/* Temporaly implemntation of removeMax, there is a bug in the original
 * this could not be the final function for bottomUpHeapify */
void bottomUpHeapify2(int *arr, int k, int n){
	int j,max=k,temp;		//Assume that k is greater than his children
	while(3*k+1 <n){	//While we can go down one more level
		j = 3*k+1;		//k has at least 1 child
		if(arr[j]>arr[max]) max=j;
		if(++j<n && arr[j]>arr[max]) max=j;
		if(++j<n && arr[j]>arr[max]) max=j;
		if(max==k)	break;
		temp = arr[k];
		arr[k] = arr[max];
		arr[max] = temp;
		k = max;
	}
}

int removeMax2(THeap *h){
	int max;
	max = h->data[0];
	h->data[0] = h->data[--(h->size)];
	bottomUpHeapify2(h->data,0,h->size);
	return max;
}

/* Functions to use ternary heap with minimum value on the root*/
int getMin2(THeap *h){
  return h->data[0];}
  
void topDownMinHepify(int *arr, int k, int n){
  int j, min=k,temp; //Assume that k is min than it's children
  while(3*k+1 <n){ //While we can down one more level
    j = 3*k+1;
    if(arr[j]<arr[min]) min=j;
    if(++j<n && arr[j]<arr[min]) min=j;
    if(++j<n && arr[j]<arr[min]) min=j;
    if(min==k) break;
    temp = arr[k];
    arr[k] = arr[min];
    arr[min] = temp;
    k = min;
  }
}
int removeMin2(THeap *h){
  int min = h->data[0];
  h->data[0] = h->data[--(h->size)];
  topDownMinHepify(h->data, 0, h->size);
  return min;
}

void bottomUpMinHeapify(int *arr,int k){
  int j,temp;
  while(parent(k)>=0){
    j=parent(k);
    if(arr[k] >= arr[j]) break;
    temp = arr[j];
    arr[j] = arr[k];
    arr[k] = temp;
    k = j;
  }
}
void insertMin2(THeap *h,int data){
  if(h->size == h->capacity){
    printf("This heap is full\n");
    return;
  }
  h->data[(h->size)++]=data;
  bottomUpMinHeapify(h->data,(h->size)-1);
}
// Definiciones ===============================================================

void theap_median(THeap *thmin, THeap *thmax, int data, double *median){
//Frist consider the case: thmin and thmax have the same size
//After adding data in thmax or thmin, the invarint |thmin.size - thmax.size|<=1 holds
   if(thmin->size == thmax->size){
     if(1.0*data >= *median){   //Add equal case in one condition
       insertMin2(thmin,data);
       *median = (double)getMin2(thmin);
     }
     else{
       insert(thmax,data);
       *median = (double)getMax(thmax);
     }
   }
//Case: thmin have 1 more element than thmax
   else if(thmin->size > thmax->size){
     //Case: data belongs to thmin
     if(1.0*data >= *median){
        //Add min of thmin in thmax
        insert(thmax,removeMin2(thmin));
        insertMin2(thmin,data);
     }
     //Case: data belongs to thmax
     else
       insert(thmax,data);
  //At this point thmax.size = thmin.size
    *median = (double)(getMax(thmax)+getMin2(thmin))/2.0;
   }
//Case: thmax have 1 more element than thmin
   else{
  //Case: data belogs to thmax
     if(1.0*data < *median){
        insertMin2(thmin,removeMax2(thmax));
        insert(thmax,data);
     }
  //Case: data belongs to thmin
    else
      insertMin2(thmin,data);
  //At this point thmax.size = thmin.size
    *median = (double)(getMax(thmax)+getMin2(thmin))/2.0;
   }
} 
