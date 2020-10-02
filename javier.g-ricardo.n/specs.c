#include "./heap.c"
#include "./median.c"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test_insert_element(void){ 
  printf("Al probar un elemento se debe mantener la propiedad del heap: "); 
  int resultado = 1;
  if(resultado != 0){puts ("ERROR"); return 0;}

  puts("OK"); 
  return 1;
} 


int main(int num_args, char ** args){
  int all_tests_ok = 1;
  all_tests_ok &= test_insert_element();
  assert(all_tests_ok); 
  return 0;
} 
