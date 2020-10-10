#ifndef HEAP_T08
#define HEAP_T08

// Prototipos =================================================================

typedef struct _THeap{
  unsigned int capacity;
	unsigned int n;
	int *data;
}THeap;

THeap * THeap_new(void);
void    free_THeap(THeap ** hptr);

void    insert(THeap *h, int data);
int     removeMax(THeap *h);
int     getMax(THeap *h);

void    bottomUpHeapify(int *arr, int k);
void    topDownHeapify(int * arr, int k, int n);

// Definiciones ===============================================================

void insert(THeap *h, int data){ 
  if (h->n==h->capacity-1) 
		return;
	h->data[++h->n]=data;
	bottomUpHeapify(h->data,h->n);
  return;
} 

int removeMax(THeap *h){ 
  if (h->n<1) 
		return -1;
	int tmp = h->data[1];
	h->data[1]= h->data[h->n--];
	topDownHeapify(h->data,1,h->n);
	return tmp;
} 

int getMax(THeap *h){ 
  if (h->n<1) 
    return -1;
  return h->data[1];
} 

void bottomUpHeapify(int *arr, int k){ 
  while (k > 0 && arr[(k+1)/3]<arr[k]) {
		swap(arr ,k, (k+1)/3);
		k=(k+1)/3;
	}
  return;
} 

void topDownHeapify(int * arr, int k, int n){ 
  return;
} 

#endif
