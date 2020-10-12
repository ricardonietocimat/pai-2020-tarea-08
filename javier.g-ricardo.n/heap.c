#ifndef HEAP_T08
#define HEAP_T08

// Prototipos =================================================================

typedef struct _THeap{
 	unsigned int capacity;
	int n;
	int *data;
}THeap;

THeap * THeap_new(void);
void    free_THeap(THeap ** hptr);

void    insert(THeap *h, int data, char ord);
int     removeMax(THeap *h, char ord);
int     getMax(THeap *h);

void    bottomUpHeapify(int *arr, int k, char ord);


// Definiciones ===============================================================

void insert(THeap *h, int data, char ord){
	if (h->n==h->capacity-1) 
		return;
	h->data[++h->n]=data;
	bottomUpHeapify(h->data,h->n,ord);
}
int removeMax(THeap *h, char ord){
	if (h->n<1) 
		return -1;
	int tmp = h->data[1];
	h->data[1]= h->data[h->n--];
	topDownHeapify(h->data,1,h->n,ord);
	return tmp;
}
int getMax(THeap *h){ 
  if (h->n<1) 
    return -1;
  return h->data[1];
} 

void bottomUpHeapify(int *arr, int k, char ord){

	if(ord==1){
		while (k > 1 && arr[(k+1)/3]>arr[k]) {
			swap(arr ,k, (k+1)/3);
			k=(k+1)/3;
		}
	}else{
		while (k > 0 && arr[(k+1)/3]<arr[k]) {
			swap(arr ,k, (k+1)/3);
			k=(k+1)/3;
		}
	}
} 

void topDownHeapify(int * arr, int k, int n){ 
  return;
} 

#endif
