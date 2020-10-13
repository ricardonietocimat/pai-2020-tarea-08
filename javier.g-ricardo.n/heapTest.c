/* Functions to test heap implementation
 * created by: Abdiel Beltran at 11 / 10 /20 */
#include <stdio.h>
#include <stdlib.h>
#include "TernaryHeap.h"	//First bug, I changed the name of heap.h to TernaryHeap.h

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
void simpleTest(){
	THeap *Test;
	Test = createTHeap(5);	//Heap with root and 3 sons and left will have 1 son
	printf("Hello world with TernaryHeap.h\n printing empty heap\n");
	printHeap(Test);
	for(int i=1; i<7; i++){
		printf("Add %d to heap, actual heap:\t",i);
		insert(Test,i);
		printHeap(Test);
	}
	printf("Removing max of heap: %d \n Inserting negative value: -5\n",removeMax(Test));
	insert(Test,-5);
	printf("\n Actual heap: ");
	printHeap(Test);
	for(int i=1; i<7; i++){
		printf("Max of heap: %d, heap after removeMax\t",getMax(Test));
		removeMax(Test);
		printHeap(Test);
	}
}
void testRM2(){
	THeap *Test;
	Test = createTHeap(5);	//Heap with root and 3 sons and left will have 1 son
	printf("Hello world with TernaryHeap.h\n printing empty heap\n");
	printHeap(Test);
	for(int i=1; i<7; i++){
		printf("Add %d to heap, actual heap:\t",i);
		insert(Test,i);
		printHeap(Test);
	}
	printf("Removing max of heap: %d \n Inserting negative value: -5\n",removeMax2(Test));
	insert(Test,-5);
	printf("\n Actual heap: ");
	printHeap(Test);
	for(int i=1; i<7; i++){
		printf("Max of heap: %d, heap after removeMax\t",getMax(Test));
		removeMax2(Test);
		printHeap(Test);
	}
}
int main(){
	simpleTest();
	printf("Checking removeMax2\n");
	testRM2();
	return 0;
}
