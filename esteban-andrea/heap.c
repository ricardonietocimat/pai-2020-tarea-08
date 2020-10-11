#ifndef HEAP_T08
#define HEAP_T08

// Prototipos =================================================================

typedef struct _THeap{
    int capacity; //capacidad máxima del arreglo
    int size; //numero actual de datos
    int* data; //arreglo
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
    THeap* h_ptr = (arrInfo*)malloc(sizeof(THeap));
    if(h_ptr== NULL){
        printf("No se concedio memoria para el monticulo\n");
        return NULL;
    }
    h_ptr->capacity = capacity;
    h_ptr->size = 0;
    h_ptr->data = (int*) calloc(capacity, sizeof(int));
    return h_ptr;
}

void free_THeap(THeap ** h_ptr){
    free(((*h_ptr)->data));
    free(*h_ptr);
    *h_ptr = NULL;
}

void insert(THeap *h, int data){
    if(h->size==h->capacity-1){
        printf("El monticulo esta lleno\n");
        return;
    }
    //A�ade el nuevo elemento al final
    h->data[(h->size)+1] = data;
    h->size++;
    //Monticuliza el arreglo
    bottomUpHeapify(h->data, h->size);
    return;
}

int removeMax(THeap *h){
  return -1;
}

int getMax(THeap *h){
    if(h->size>0){
        return h->data[1];
    }
  return -1;
}

void swap_andi(int*arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;

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

void bottomUpHeapify(int *arr, int k){
    while(k>1 && arr[(k+1)/3]<arr[k]){
        swap_andi(arr, k, k+1)/3);
        k = (k+1)/3;
    }
    return;
}



#endif
