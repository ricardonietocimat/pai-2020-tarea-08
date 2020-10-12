#include "./heap.c"
#include "./median.c"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//Prueba de positivos
int test_insert_element(void){ 
  printf("Al probar un elemento se debe mantener la propiedad del heap: "); 
  // Create heap 
  THeap *arbl=NULL;
  arbl=THeap_new(20);
  insert(arbl,0);
  if(getMax(th) != 0){puts("ERROR"); return 0;}

  insert(arbl,1);
  if(getMax(th) != 1){puts("ERROR"); return 0;}

  insert(arbl,5);
  if(getMax(th) != 5){puts("ERROR"); return 0;}

  insert(arbl,1);
  if(getMax(th) != 5){puts("ERROR"); return 0;}

  int resultado = 1;
  if(resultado != 0){puts ("ERROR"); return 0;}
 
  free_THeap(&arbl);
  puts("OK"); 
  return 1;
} 

//Prueba de negativos
int test_insert_element2(void){ 
  printf("Al probar un elemento se debe mantener la propiedad del heap: "); 
  // Create heap 
  THeap *arbl=NULL;
  arbl=THeap_new(20);
  insert(arbl,-5);
  if(getMax(th) != -5){puts("ERROR"); return 0;}

  insert(arbl,-3);
  if(getMax(th) != -3){puts("ERROR"); return 0;}

  insert(arbl,-11);
  if(getMax(th) != -3){puts("ERROR"); return 0;}

  insert(arbl,-1);
   if(getMax(th) != -1){puts("ERROR"); return 0;}

  int resultado = 1;
  if(resultado != 0){puts ("ERROR"); return 0;}

  free_THeap(&arbl);
  puts("OK"); 
  return 1;
} 

//Prueba de negativos y positivos
int test_insert_element3(void){ 
  printf("Al probar un elemento se debe mantener la propiedad del heap: "); 
  // Create heap 
  THeap *arbl=NULL;
  arbl=THeap_new(20);
  insert(arbl,-7);
  if(getMax(th) != -7){puts("ERROR"); return 0;}

  insert(arbl,-5);
  if(getMax(th) != -5){puts("ERROR"); return 0;}

  insert(arbl,4);
  if(getMax(th) != 4){puts("ERROR"); return 0;}

  insert(arbl,7);
  if(getMax(th) != 7){puts("ERROR"); return 0;}

  int resultado = 1;
  if(resultado != 0){puts ("ERROR"); return 0;}
  
  free_THeap(&arbl);
  puts("OK"); 
  return 1;
} 

int main(int num_args, char ** args){
  int all_tests_ok = 1;
  all_tests_ok &= test_insert_element();
  all_tests_ok &= test_insert_element2();
  all_tests_ok &= test_insert_element3();
  assert(all_tests_ok); 
  return 0;
} 
