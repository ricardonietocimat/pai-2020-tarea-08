#ifndef HEAP_T08
#define HEAP_T08

// Prototipos =================================================================


typedef struct _THeap{
    int capacity; //capacidad máxima del arreglo
    int size; //numero actual de datos
    int* data; //arreglo
}THeap;

THeap * THeap_new(void);
void    free_THeap(THeap ** hptr);

void    insert(THeap *h, int data);
int     removeMax(THeap *h);
int     getMax(THeap *h);

void    bottomUpHeapify(int *arr, int k);
void    topDownHeapify(int * arr, int k, int n);

// Definiciones ===============================================================
 //getMax, bottomUp, insert,  testTopDown

void insert(THeap *h, int data){
    if(h->size==h->capacity-1){
        printf("El monticulo esta lleno\n");
        return;
    }
    //Añade el nuevo elemento al final
    h->data[(h->size)+1] = data;
    h->size++;
    //Monticuliza el arreglo xD
    bottomUpHeapify(h->data, h->size);
    return;
}

int removeMax(THeap *h){
  return -1;
}

int getMax(THeap *h){
  return -1;
}

void swap_andi(int*arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;

}

void bottomUpHeapify(int *arr, int k){
    while(k>1 && arr[(k+1)/3]<arr[k]){
        swap(arr, k, k+1)/3);
        k = (k+1)/3;
    }
    return;
}

void topDownHeapify(int * arr, int k, int n){
  return;
}

#endif
