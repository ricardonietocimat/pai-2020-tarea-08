#include "./heap.h"
#include "median.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int getRandom(int base, int limit) {
    return base + rand() % (limit - base + 1);
}



int testMinHeap() {
    srand(time(0));
    THeap *h = createTHeap(100);
    int status = 1;
    printf("testing resize heap too\n");
    for (int i = 0; i < 200; i++) {
        int data = getRandom(0, 200);
        //printf("%d ", data);
        minHeapInsert(h, data);
    }
    //printf("\n");
    status &= verifyMinHeapProperty(h);
    //printHeap(h);

    //printf("max: %d\n", getMin(h));
    removeMin(h);

    status &= verifyMinHeapProperty(h);
    //printHeap(h);

    removeMin(h);

    status &= verifyMinHeapProperty(h);
    //printHeap(h);

    return status;
}

int testMaxHeap() {
    srand(time(0));
    THeap *h = createTHeap(100);
    int status = 1;

    printf("testing resize heap too\n");
    for (int i = 0; i < 200; i++) {
        int data = getRandom(0, 200);
        insert(h, data);
    }

    status &= verifyHeapProperty(h);

    removeMax(h);

    status &= verifyHeapProperty(h);

    removeMax(h);

    status &= verifyHeapProperty(h);

    return status;
}



int medianTest(){
    THeap *thmax = createTHeap(100);
    THeap *thmin = createTHeap(100);
    double median = 0;
    median = theap_median(thmin, thmax, 1);
    printf("%lf\n", median);
    if (median!= 1) return 0;
    median = theap_median(thmin, thmax, 4);
    printf("%lf\n", median);
    if (median!= 2.5) return 0;
    median = theap_median(thmin, thmax, 6);
    printf("%lf\n", median);
    if (median!= 4) return 0;
    median = theap_median(thmin, thmax, 2);
    printf("%lf\n", median);
    if (median!= 3) return 0;
    median = theap_median(thmin, thmax, 8); //4
    printf("%lf\n", median);
    if (median!= 4) return 0;
    median = theap_median(thmin, thmax, 15); //5
    printf("%lf\n", median);
    if (median!= 5) return 0;
    median = theap_median(thmin, thmax, 20); //6
    printf("%lf\n", median);
    if (median!= 6) return 0;
    median = theap_median(thmin, thmax, 3); //5
    printf("%lf\n", median);
    if (median!= 5) return 0;
    median = theap_median(thmin, thmax, 5); //5
    printf("%lf\n", median);
    if (median!= 5) return 0;
    
    return 1;
}

int main(int num_args, char ** args){
    printf("INIT TESTS\n");
    int all_tests_ok = 1;
    all_tests_ok &= testMinHeap();
    all_tests_ok &= testMaxHeap();
    all_tests_ok &= medianTest();
    assert(all_tests_ok);
    return 0;
}
