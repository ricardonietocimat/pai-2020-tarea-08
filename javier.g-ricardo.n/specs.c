#include "./heap.c"
#include "./median.c"
#include <assert.h>

void test_insert_element(void){ 
  puts("Al probar un elemento se debe mantener la propiedad del heap"); 
  // Create heap 
  // add 0
  // assert(getMax(th) == 0); 
  
  // add 1
  // assert(getMax(th) == 1);

  // add 5
  // assert(getMax(th) == 5);
  
  // add 3
  // assert(getMax(th) == 5);

  assert(0); 
} 


int main(int num_args, char ** args){
  test_add_new_element();
} 
