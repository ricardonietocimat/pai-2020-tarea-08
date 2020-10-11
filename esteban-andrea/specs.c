#include "./heap.c"
#include "./median.c"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test_insert_element(void);
int test_remove_max    (void);

int main(int num_args, char ** args){
    int all_tests_ok = 1;
    all_tests_ok &= test_insert_element();
    all_tests_ok &= test_remove_max();
    assert(all_tests_ok);
    return 0;
}

int test_insert_element(void){
  printf("*- Test Insert Element -*\n");
  // Create heap
  int capacity = 10;
  THeap *th; th = THeap_new(capacity);

  // add 0
  printf("***** Insert 0 *****\n"); insert(th, 0);
  if(getMax(th) != 0){puts("ERROR"); return 0;}
  showHead(th);
  // add 1
  printf("***** Insert 1 *****\n"); insert(th, 1);
  if(getMax(th) != 1){puts("ERROR"); return 0;}
  showHead(th);
  // add 5
  printf("***** Insert 5 *****\n"); insert(th, 5);
  if(getMax(th) != 5){puts("ERROR"); return 0;}
  showHead(th);
  // add 3
  printf("***** Insert 3 *****\n"); insert(th, 3);
  if(getMax(th) != 5){puts("ERROR"); return 0;}
  showHead(th);

  free_THeap(&th);
  puts("OK");
  return 1;
}

int test_remove_max(void){
  printf("*- Test Remove Max -*\n");
  // Create heap
  int capacity = 50;
  THeap *th; th = THeap_new(capacity);

  printf("Adding elements\n");
  for (int i = 0; i< 10; i++){
    insert(th,i);
  }
  showHead(th);

  removeMax(th);
  if(getMax(th) != 8){puts("ERROR"); return 0;}
  showHead(th);

  removeMax(th);
  if(getMax(th) != 7){puts("ERROR"); return 0;}
  showHead(th);

  removeMax(th);
  if(getMax(th) != 6){puts("ERROR"); return 0;}
  showHead(th);

  free_THeap(&th);

  puts("OK");
  return 1;
}