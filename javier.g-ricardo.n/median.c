/* Modified by: Abdiel Beltran, 11/10/20 */
#include <stdio.h>
#include "heap.h"
#include "median.h"


// Definiciones ===============================================================

double theap_median(THeap *thmin, THeap *thmax, int data) {
    //First consider the case: thmin and thmax have the same size
    //After adding data in thmax or thmin, the invarint |thmin.size - thmax.size|<=1 holds
    double currentMedian;
    double updatedMedian;

    if (thmin->size == thmax->size) {
        if (thmin->size == 0)
            currentMedian = 0;
        else
            currentMedian = (getMin(thmin) + getMax(thmax)) / 2.0;

        if (data < currentMedian) {
            insert(thmax, data);
            updatedMedian = getMax(thmax);
        } else {
            minHeapInsert(thmin, data);
            updatedMedian = getMin(thmin);
        }
    }        //Case: thmin have 1 more element than thmax
    else if (thmin->size > thmax->size) {
        //Case: data belongs to thmin
        currentMedian = getMin(thmin);
        if (data >= currentMedian) {
            int min = removeMin(thmin);
            insert(thmax, min);
            minHeapInsert(thmin, data);
        } else {
            insert(thmax, data);
        }
        updatedMedian = (getMin(thmin) + getMax(thmax)) / 2.0;
    }        //Case: thmax have 1 more element than thmin
    else {
        currentMedian = getMax(thmax);
        //Case: data belongs to thmax
        if (data < currentMedian) {
            int max = removeMax(thmax);
            minHeapInsert(thmin, max);
            insert(thmax, data);
        } else {
            minHeapInsert(thmin, data);
        }
        updatedMedian = (getMin(thmin) + getMax(thmax)) / 2.0;
    }
    return updatedMedian;
}
