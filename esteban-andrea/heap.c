#ifndef HEAP_T08
#define HEAP_T08
#include <stdio.h>
#include <stdlib.h>

// Prototipos =================================================================

typedef struct _THeap{
    int capacity; //capacidad máxima del arreglo
    int size;     //numero actual de datos
    int* data;    //arreglo
}THeap;

THeap * THeap_new(int capacity);
void    free_THeap(THeap ** hptr);

void    insert(THeap *h, int data);
int     removeMax(THeap *h);
int     getMax(THeap *h);

void    bottomUpHeapify(int *arr, int k);
void    topDownHeapify(int * arr, int k, int n);

// Definiciones ===============================================================

 THeap * THeap_new(int capacity){
    THeap* h_ptr = (THeap*)malloc(sizeof(THeap));
    if(h_ptr == NULL){
        printf("No se concedio memoria para el monticulo\n");
        return NULL;
    }
    h_ptr->capacity = capacity;
    h_ptr->size = 0;
    h_ptr->data = (int*) calloc(capacity, sizeof(int));
    if(h_ptr->data== NULL){
        printf("No se concedio memoria para el arreglo\n");
        return NULL;
    }
    return h_ptr;
}

void free_THeap(THeap** h_ptr){
    free(((*h_ptr)->data));
    free(*h_ptr);
    *h_ptr = NULL;
}

void insert(THeap *h, int data){
    if(h->size == h->capacity){
        printf("El monticulo esta lleno\n");
        return;
    }
    //Agrega el nuevo elemento al final
    h->data[h->size] = data;
    //Monticuliza el arreglo
    bottomUpHeapify(h->data, h->size);
    h->size++;
    return;
}

int removeMax(THeap *h){
  if (h->size == 0) {
    printf("Heap vacío.");
    return -1;
  }
  int tmp = h->data[0];
  h->data[0] = h->data[h->size--];
  topDownHeapify(h->data, 0, h->size);
  return tmp;
}

int getMax(THeap *h){
    if(h->size > 0){
        return h->data[0];
    }
  return -1;
}

void swap(int*arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;

}

void bottomUpHeapify(int *arr, int k){
    while(k>0 && arr[(k-1)/3]<arr[k]){
        swap(arr, k, (k-1)/3);
        k = (k-1)/3;
    }
    return;
}

void topDownHeapify(int * arr, int k, int n){
  while (3*k < n){
    int j = 3*k+1;                            // Busco primer hijo
    if (j < n && arr[j] < arr[j+1]) {         // Si arr[j] < arr[j+1] ...
      j++;
      if (j < n && arr[j] < arr[j+1]) j++;    // Si arr[j] < arr[j+1] < arr[j+2]
    }
    else{                                     // arr[j] > arr[j+1]
      if (j+1 < n && arr[j] < arr[j+2]) j += 2;// arr[j] > arr[j+1] y arr[j] < arr[j+2]
    }
    // Si no se cumple lo anterior, hijo maximo esta en primer hijo
    if (arr[k]>= arr[j]) break;
    swap(arr, k, j);
    k = j;
  }
}

void showHead(THeap *h){
  printf("Heap : ");
  for (int i = 0; i < h->size; i++){
    printf("%i ",h->data[i]);
  }
  printf("\n");
  printf("Size : %i, capacity: %i\n", h->size, h->capacity);
  printf("\n");

}

//Por si nos dejan usar apuntadores a funciones, para el siguiente ejercicio
int by_min(int a, int b){

    if(a<=b){
        return -1;
    }
    else
        return 1;
}

int by_max(int a, int b){

    if(a>=b){
        return -1;
    }
    else
        return 1;
}

#endif
