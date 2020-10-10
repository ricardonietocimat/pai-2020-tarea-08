#ifndef HEAP_T08
#define HEAP_T08
// Prototipos =================================================================
typedef struct _THeap{
	unsigned int capacity;
	unsigned int n;
	int* data;
}THeap;

THeap * THeap_new(int c);
void    free_THeap(THeap ** hptr);

void    insert(THeap *h, int data);
int     removeMax(THeap *h);
int     getMax(THeap *h);

void    bottomUpHeapify(int *arr, int k);
void    topDownHeapify(int * arr, int k, int n);

void swap(int *arr, int i, int j);
#endif
