#include "./heap.c"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test_insert_element(void){ 

  printf("Al probar un elemento se debe mantener la propiedad del heap: \n"); 

    // Creación del montículo
    THeap *th = THeap_new();

    // Insercion de 10, max 10
    insert(th, 10);
    if(getMax(th) != 10){printf("Resultado no deseado \n"); return 0;}

    // Inserción de 3, max 10
    insert(th, 3);
    if(getMax(th) != 10){printf("Resultado no deseado \n"); return 0;}

    // Inserción de 11, max 11
    insert(th, 11);
    if(getMax(th) != 11){printf("Resultado no deseado \n"); return 0;}

    // Inserción de 5, max 11
    insert(th, 5);
    if(getMax(th) != 11){printf("Resultado no deseado \n"); return 0;}


    printf("Se mantiene la propiedad del heap\n"); 
    return 1;
} 

int test_remove_elements(void){ 

    // Creación del montículo
    THeap *th = THeap_new();

    for(int i = 0; i < 20; i++){
        insert(th, i);
    }

    // Si no hay elementos, no debería proceder la función remove
    for(int i = 0; i < 22; i++){
        removeMax(th);
    }

    insert(th, 5);
    printf("Esto debe imprimir un 5 -> %d \n", getMax(th));

    if(getMax(th) != 5){
        return 0;
    }

    return 1;
} 

int test_free_heap(){

    // Creación de 3 heaps diferentes
    THeap *h1 = THeap_new();
    THeap *h2 = THeap_new();
    THeap *h3 = THeap_new();

    int pre_free[3] = {0,0,0};

    // Aumentar el tamaño de los heaps
    insert(h1, 1);
    insert(h2, 2);
    insert(h2, 4);
    insert(h3, 3);
    insert(h3, 6);
    insert(h3, 9);

    printf("Tamaño heap1: %d \n", h1->size);
    printf("Tamaño heap2: %d \n", h2->size);
    printf("Tamaño heap3: %d \n", h3->size);

    pre_free[0] = h1->size;
    pre_free[1] = h2->size;
    pre_free[2] = h3->size;

    free_THeap(&h1);
    free_THeap(&h2);
    free_THeap(&h3);

    if(pre_free[0] != h1->size){
        printf("Valor despues de la liberacion: %d \n", h1->size);
    }else{ return 0; }

    if(pre_free[1] != h2 ->size){
        printf("Valor despues de la liberacion: %d \n", h2->size);
    }else{ return 0; }

    if(pre_free[2] != h3 ->size){
        printf("Valor despues de la liberacion: %d \n", h3->size);
    }else{ return 0; }

    printf("Liberacion OK\n");
    return 1;
}

int main(char argc, char * argv[]){

  int all_tests_ok = 1;
   
    if(argc != 2){
        printf("Debes seleccionar un test (1-3) \n");
        printf("1: Test de insercion:\n");
        printf("2: Test remover elementos\n");
        printf("3: Test liberacion de memoria:\n");
        exit(1);
    }

    switch(*argv[1]){
        case '1'   :
            all_tests_ok &= test_insert_element();
            assert(all_tests_ok);
            break;
        case '2'   :
            all_tests_ok &= test_remove_elements();
            assert(all_tests_ok); 
            break;
        case '3'   :
            all_tests_ok &= test_free_heap();
            assert(all_tests_ok); 
            break;
        default:
                printf("Se debe seleccionar un test:\n");
                printf("1: Test de insercion:\n");
                printf("2: Test remover elementos\n");
                printf("3: Test liberacion de memoria:\n");
        }

    return 0;
} 
