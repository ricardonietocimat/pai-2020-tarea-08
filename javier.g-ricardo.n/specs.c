#include "./heap.c"
#include "./median.c"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//Prueba de positivos
int test_insert_element(void){ 
  printf("Al probar un elemento se debe mantener la propiedad del heap (positivos): "); 
  // Create heap 
  THeap *th=NULL;
  th=THeap_new(20);
  insert(th,0,0);
  if(getMax(th) != 0){puts("ERROR"); return 0;}
	
  insert(th,1,0);
  if(getMax(th) != 1){puts("ERROR"); return 0;}

  insert(th,5,0);
  if(getMax(th) != 5){puts("ERROR"); return 0;}

  insert(th,2,0);
  if(getMax(th) != 5){puts("ERROR"); return 0;}
  
  free_THeap(&th);
  puts("OK"); 
  return 1;
} 

//Prueba de negativos
int test_insert_element2(void){ 
  printf("Al probar un elemento se debe mantener la propiedad del heap (negativos): "); 
  // Create heap 
  THeap *th=NULL;
  th=THeap_new(20);
  insert(th,-5,0);
  if(getMax(th) != -5){puts("ERROR"); return 0;}

  insert(th,-3,0);
  if(getMax(th) != -3){puts("ERROR"); return 0;}

  insert(th,-11,0);
  if(getMax(th) != -3){puts("ERROR"); return 0;}

  insert(th,-1,0);
   if(getMax(th) != -1){puts("ERROR"); return 0;}

  free_THeap(&th);
  puts("OK"); 
  return 1;
} 

//Prueba de negativos y positivos
int test_insert_element3(void){ 
  printf("Al probar un elemento se debe mantener la propiedad del heap (ambos): "); 
  // Create heap 
  THeap *th=NULL;
  th=THeap_new(20);
  insert(th,-7,0);
  if(getMax(th) != -7){puts("ERROR"); return 0;}

  insert(th,-5,0);
  if(getMax(th) != -5){puts("ERROR"); return 0;}

  insert(th,4,0);
  if(getMax(th) != 4){puts("ERROR"); return 0;}

  insert(th,7,0);
  if(getMax(th) != 7){puts("ERROR"); return 0;}

  free_THeap(&th);
  puts("OK"); 
  return 1;
} 

//Prueba para heap minimo
int test_insert_elementmin(void){ 
  printf("Al probar un elemento se debe mantener la propiedad del heap (orden minimo): "); 
  // Create heap 
  THeap *th=NULL;
  th=THeap_new(20);
  insert(th,0,1);
  if(getMax(th) != 0){puts("ERROR"); return 0;}
	
  insert(th,1,1);
  if(getMax(th) != 0){puts("ERROR"); return 0;}

  insert(th,-3,1);
  if(getMax(th) != -3){puts("ERROR"); return 0;}

  insert(th,2,1);
  if(getMax(th) != -3){puts("ERROR"); return 0;}
  
  free_THeap(&th);
  puts("OK"); 
  return 1;
} 

//Prueba para media positivos
int test_mediaALEP(void){ 
	// Create heap 
    THeap * thmin=NULL, *thmax=NULL;
    int i=0, cap=30, arr[9]={0, 2, 4, 3, 20, 8, 12,9, 15};
	double res[9]={0, 1, 2,2.5, 3, 3.5, 4, 6, 8},med=0;
    thmax=THeap_new(cap);
	thmin=THeap_new(cap);
	
	printf("Al probar insertar un nuevo elemento se actualiza la mediana (positivos)"); 
	
	for(i=0;i<9;i++){
		med=theap_median(thmin, thmax, arr[i]);
		//printf("%f %f", med,res[i]);
		if(med!=res[i]){puts("ERROR"); return 0;}
	}
  
	free_THeap(&thmin);
    free_THeap(&thmax);
	puts("OK"); 
	return 1;
} 

//Prueba para la mediana numeros negativos
int test_mediaALEN(void){ 
	
	THeap * thmin=NULL, *thmax=NULL;
    int i=0, cap=30, arr[13]={-5, -3, 0, -3, -2, -8, -15,-7, -2,-1, -9, -6, -4};
	double res[13]={-5, -4, -3,-3, -3, -3, -3, -4, -3,-3,-3,-4,-4},med=0;
    thmax=THeap_new(cap);
	thmin=THeap_new(cap);
	
	printf("Al probar insertar un nuevo elemento se actualiza la mediana (negativos)"); 
	
	for(i=0;i<13;i++){
		med=theap_median(thmin, thmax, arr[i]);
		if(med!=res[i]){puts("ERROR"); return 0;}
	}
  
	free_THeap(&thmin);
    free_THeap(&thmax);
	puts("OK"); 
	return 1;
} 

//Prueba para la mediana numeros combinado
int test_mediaALEC(void){ 
	
	THeap * thmin=NULL, *thmax=NULL;
    int i=0, cap=30, arr[13]={-2, 0, 1, 4, -3, 8, 12,-6, 20,-1, -7, 8, 5};
	double res[13]={-2, -1, 0, 0.5, 0,0.5,1, 0.5, 1, 0.5, 0,0.5,1},med=0;
    thmax=THeap_new(cap);
	thmin=THeap_new(cap);
	
	printf("Al probar insertar un nuevo elemento se actualiza la mediana (ambos)"); 
	
	for(i=0;i<13;i++){
		med=theap_median(thmin, thmax, arr[i]);
		if(med!=res[i]){puts("ERROR"); return 0;}
	}
  
	free_THeap(&thmin);
    free_THeap(&thmax);
	puts("OK"); 
	return 1;
} 

int main(int num_args, char ** args){
  int all_tests_ok = 1;
  all_tests_ok &= test_insert_element();
  all_tests_ok &= test_insert_element2();
  all_tests_ok &= test_insert_element3();
  all_tests_ok &= test_insert_elementmin();
  all_tests_ok &= test_mediaALEP();
  all_tests_ok &= test_mediaALEN();
  all_tests_ok &= test_mediaALEC();
  assert(all_tests_ok); 
  return 0;
} 
