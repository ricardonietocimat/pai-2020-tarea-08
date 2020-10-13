#include "./heap.c"
#include "./median.c"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int test_insert_element(void);
int test_remove_max    (void);
int test_median        (void);
int test_remove_max_by_min(void);

int main(int num_args, char ** args){
  int all_tests_ok = 1;
  all_tests_ok &= test_insert_element();
  all_tests_ok &= test_remove_max();
  all_tests_ok &= test_remove_max_by_min();
   all_tests_ok &= test_median();
  assert(all_tests_ok);
  return 0;
}

int test_insert_element(void){
  printf("*- Test Insert Element -*\n");
  // Create heap
  int capacity = 10;
  THeap *th; th = THeap_new(capacity);

  // add 0
  printf("***** Insert 0 *****\n"); insert(th, 0, by_max);
  if(getMax(th) != 0){puts("ERROR"); return 0;}
  showHead(th);
  // add 1
  printf("***** Insert 1 *****\n"); insert(th, 1, by_max);
  if(getMax(th) != 1){puts("ERROR"); return 0;}
  showHead(th);
  // add 5
  printf("***** Insert 5 *****\n"); insert(th, 5, by_max);
  if(getMax(th) != 5){puts("ERROR"); return 0;}
  showHead(th);
  // add 3
  printf("***** Insert 3 *****\n"); insert(th, 3, by_max);
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
  for (int i = 0; i<10; i++){
    insert(th,i, by_max);
  }
  showHead(th);

  removeMax(th, by_max);
  if(getMax(th) != 8){puts("ERROR"); return 0;}
  showHead(th);

  removeMax(th, by_max);
  if(getMax(th) != 7){puts("ERROR"); return 0;}
  showHead(th);

  removeMax(th, by_max);
  if(getMax(th) != 6){puts("ERROR"); return 0;}
  showHead(th);

  free_THeap(&th);

  puts("OK");
  return 1;
}

int test_remove_max_by_min(void){
  printf("*- Test Remove Min -*\n");
  // Create heap
  int capacity = 10;
  THeap *th; th = THeap_new(capacity);

  printf("Adding elements\n");
  insert(th, 6, by_min);
  insert(th, 8, by_min);
  insert(th, 4, by_min);
  printf("Antes: ");
  showHead(th);

  removeMax(th, by_min);
  printf("Despues: ");
  showHead(th);

  free_THeap(&th);

  return 1;
}

int test_median(void){
  printf("*- Test Medium Element -*\n");
  int capacity = 10;
  THeap *thmax; thmax = THeap_new(capacity);
  THeap *thmin; thmin = THeap_new(capacity);
  double median = 0;

  median = theap_median(thmin, thmax, 0);
  printf("median: %lf\n", median);
  if(median != 0){puts("ERROR"); return 0;}

  median = theap_median(thmin, thmax, 1);
  printf("median: %lf\n", median);
  if(median != 0.5){puts("ERROR"); return 0;}

  median = theap_median(thmin, thmax, 5);
  printf("median: %lf\n", median);
  if(median != 1){puts("ERROR"); return 0;}

  median = theap_median(thmin, thmax, 3);
  printf("median: %lf\n", median);
  if(median != 2){puts("ERROR"); return 0;}

  showHead(thmin);
  showHead(thmax);
  printf("median: %lf\n", median);




  puts("OK");
  return 1;
}
