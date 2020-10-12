#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "./heap.h"
#include "median.h"

// Definiciones ===============================================================
float getMedian(THeap * thmin, THeap * thmax){
	if((thmax->n)==-1&&(thmin->n)==-1)
		return sqrt(-1);
	if((thmax->n)>(thmin->n)){
			return getMax(thmax);
		 }
	 if((thmax->n)<(thmin->n)){
		   return -getMax(thmin);
		 }
	 if(thmax->n==thmin->n){
		 return (getMax(thmax)+(-getMax(thmin)))/2.0;
	  }
} 

float theap_median(THeap * thmin, THeap * thmax, int data){
	 int n = thmax->n;
	 int m = thmin->n;
	 float median=getMedian(thmin,thmax);
	 if(n==m){
		 if(median!= median)
			insert(thmax,data);
		 else{
			 if(data<=median)
				insert(thmax,data);
			 if (data>median){
				 insert(thmin,-data);
				 }
			}
		   
	  }
	 if(n>m){
				if(data<median){
					int max = removeMax(thmax);
					insert(thmin, -max);
					insert(thmax,data);
			 
				}  
				if(data>=median)
					insert(thmin,-data);
				  
			}
			
	 if(n<m){
			if(data>median){
			  int min = -removeMax(thmin);
			  insert(thmax,min);
			  insert(thmin,-data);
			 }
			if(data<=median)
				insert(thmax,data);
						 
			}
				
		
	return getMedian(thmin,thmax);
} 

