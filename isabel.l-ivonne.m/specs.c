#include "./heap.h"
#include "./median.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
void test_insert()
{
  //prueba del funcionamiento de insert
  int n=7;
  int c = 100;
  int *arr = (int*)malloc(n*sizeof(int));
  //llena el arreglo con datos aletorios
  for (unsigned int i=0; i<n; i++)
    {
     arr[i] = abs(rand()%50);
     printf("%d ",arr[i]);
    }
    printf("\n");
  THeap *h = THeap_new(c);
   for(unsigned int i=0; i<n; i++)
  {
    insert(h,arr[i]);
    printf("\n El monticulo es:\n");
    for(unsigned int j=0; j<=h->n; j++)
    printf("%d ",h->data[j]);
    printf("\n");
  }
  free_THeap(&h);
}

void test_removeMAx()
{
  //prueba de la funcion removemax
  int n=4;
  int c = 100;
  int *arr = (int*)malloc(n*sizeof(int));
  //llena el arreglo con datos aletorios
  for (int i=0; i<n; i++)
    {
     arr[i] = abs(rand()%50);
     printf("%d ",arr[i]);
    }
    printf("\n");
  THeap *h = THeap_new(c);
  for(int i=0; i<n; i++)
    insert(h,arr[i]);
  for(int i=0; i<n; i++)
    printf("%d ",h->data[i]);
  printf("\n");
  for(int i=0; i<n; i++)
  {
    printf("\n maximo:%d\n",removeMax(h));
    for(int j=0; j<=h->n; j++)
      printf("%d ",h->data[j]);
    printf("\n");
  }
  free_THeap(&h);

}
void test_median()
{
//prueba de la funcion theap_median
 int n=7;
  int c = 100;
  int *arr = (int*)malloc(n*sizeof(int));
//llena el arreglo con datos aletorios
  for (int i=0; i<n; i++)
    {
     arr[i] = abs(rand()%50);
     printf("%d ",arr[i]);
    }
    printf("\n");
  THeap *hmin = THeap_new(c);
  THeap *hmax = THeap_new(c);
  for(int i=0; i<n; i++)
  {
    double k=theap_median(hmin, hmax, arr[i]);
    printf("la media es: %lf ",k);
    printf("\nhmin es:  \n");
    for(int j=0; j<=hmin->n; j++)
    {
      printf("%d ",hmin->data[j]);
    }
    printf("\n");
    printf("hmax es:  ");
    for(int j=0; j<=hmax->n; j++)
    {
      printf("%d ",hmax->data[j]);
    }
    printf("\n");
  }

  free_THeap(&hmax);
  free_THeap(&hmin);

}

int test_insert_element(void){ 
  printf("Al probar un elemento se debe mantener la propiedad del heap: "); 
  // Create heap 
  int c = 100;
  THeap *th = THeap_new(c);
  // add 0
  insert(th,0);
  if(getMax(th) != 0){puts("ERROR"); return 0;}

  // add 1
  insert(th,1);
  if(getMax(th) != 1){puts("ERROR"); return 0;}

  // add 5
  insert(th,5);
  if(getMax(th) != 5){puts("ERROR"); return 0;}

  // add 3
  insert(th,3);
  if(getMax(th) != 5){puts("ERROR"); return 0;}

  puts("OK"); 
  return 1;
} 

int test_Remove_element(void){ 
  printf("Probar que al retirar el max se debe mantener la propiedad del heap: "); 
  // Create heap 
  int c = 100;
  THeap *th = THeap_new(c);
  // add 0
  insert(th,0);
  insert(th,1);
  insert(th,5);
  insert(th,3);

  if(removeMax(th) != 5){puts("ERROR"); return 0;}

  if(removeMax(th) != 3){puts("ERROR"); return 0;}

  if(removeMax(th) != 1){puts("ERROR"); return 0;}

  if(removeMax(th) != 0){puts("ERROR"); return 0;}

  puts("OK"); 
  return 1;
}

int test_median_tarea(void){ 
  printf("Probar el regresa la mediana es: "); 
  // Create heap 
  int c = 100;
  THeap *th1 = THeap_new(c);
  THeap *th2 = THeap_new(c);
  int *arr = (int*)malloc(4*sizeof(int));
  arr[0]=1;
  arr[1]=4;
  arr[2]=6;
  arr[3]=2;


  if(theap_median(th1, th2, arr[0]) != 1){puts("ERROR"); return 0;}

  if(theap_median(th1, th2, arr[1])  != 2.5){puts("ERROR"); return 0;}

  if(theap_median(th1, th2, arr[2])  != 4){puts("ERROR"); return 0;}

  if(theap_median(th1, th2, arr[3])  != 3){puts("ERROR"); return 0;}

  puts("OK"); 
  return 1;
} 
int test_removeMax_emptyHeap(void){
	printf("Probar que al querer remover el maximo de un monticulo vacío regrese -inf: ");
	int c = 100;
	THeap *h = THeap_new(c);
	if(removeMax(h)!=INT_MIN){puts("ERROR"); return 0;}
	 
	puts("OK"); 
    return 1;
}
int test_max_capacity(void){
	printf("Probar que al querer inserter un elemento que excede la capacidad no lo incerta: ");
	
}
int main(int num_args, char ** args)
{
  test_insert();
  test_removeMAx();
  test_median();


  int all_tests_ok = 1;
  all_tests_ok &= test_insert_element();
  all_tests_ok &= test_Remove_element();
  all_tests_ok &= test_median_tarea();
  all_tests_ok &= test_removeMax_emptyHeap();
  assert(all_tests_ok); 

 

  return 0;
} 
