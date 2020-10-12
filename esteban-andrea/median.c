#ifndef MEDIAN_T8
#define MEDIAN_T8
#include "./heap.c"

// Prototipo ==================================================================

double theap_median(THeap * thmin, THeap * thmax, int data);


// Definiciones ===============================================================

double theap_median(THeap * thmin, THeap * thmax, int data){
    /*Recibe dos mont�culos cuya diferencia de tama�os es a lo m�s 1.
    Regresa el valor de la mediana*/

    int min_sze = thmin->size;
    int max_sze = thmax->size;
    if(abs(min_sze-max_sze)>1){
        printf("El tama�o de los monticulos difiere por mas de uno\n");
        return -1.0;
    }
    if(min_sze==0 && max_sze==0){
        insert(thmin, data, by_min);
        return data;
    }
    double med = 0; //Valor actual de la mediana
    if(max_sze>min_sze){
        med = (double) getMax(thmax);
        if(data < med){
            removeMax(thmax, by_max);
            insert(thmin, med, by_min);
            insert(thmax, data, by_max);
        }
        else{
            insert(thmin, data, by_min);
        }

        return (getMax(thmin)+getMax(thmax))/2.0;

    }
    else if(min_sze>max_sze){
        med = getMax(thmin);
        if(data>med){
            removeMax(thmin, by_min);
            insert(thmax, med, by_max);
            insert(thmin, data, by_min);
        }
        else{
            insert(thmax, data, by_max);
        }
        return (getMax(thmin)+getMax(thmax))/2.0;
    }
    else{
        med = (getMax(thmin)+getMax(thmax))/2.0;
        if(data<med){
            insert(thmax, data, by_max);
            return (double)getMax(thmax);
        }
        else{
            insert(thmin, data, by_min);
            return (double)getMax(thmin);
        }
    }
}


#endif
