#include <stdio.h>
#include <stdlib.h>
#include "TernaryHeap.h"
#include "median.h"

int main(){
	int stream[]={1,5,6,2,3,8,9,10,4,7,11,15,20,12,19,16,13,18,14,17};
	THeap *THmax, *THmin;
	double median=0;
	THmax = createTHeap(11);
	THmin = createTHeap(11);
	printf("Simple test of median implementation\n");
	for(int i=0; i<20; i++){
		printf("new data: %d\n",stream[i]);
		theap_median(THmin,THmax,stream[i],&median);
		printf("\t upper half: ");
		printHeap(THmin);
		printf("\t down half: ");
		printHeap(THmax);
		printf("****actual median: %lf ****\n",median);
	}
	return 0;
}
