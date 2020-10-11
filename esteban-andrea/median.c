#ifndef MEDIAN_T8
#define MEDIAN_T8

// Prototipo ==================================================================

int theap_median(THeap * thmin, THeap * thmax, int data);


// Definiciones ===============================================================

double theap_median(THeap * thmin, THeap * thmax, int data){

    int min_sze = thmin->size;
    int max_sze = thmax->size;
    if(abs(min_sze-max_sze)>1){
        printf("El tamaño de los monticulos difiere por mas de uno\n");
        return -1;
    }
    double med = 0; //Valor actual del mediano
    if(max_sze>min_sze){
        med = (double)getMax(thmax);
        if(data<med){
            removeMax(thmax);
            insert(thmin, med);
            insert(thmax, data);
        }
        else{
            insert(thmin, data);
        }

        return (getMax(thmin)+getMax(thmax))/2.0;

    }
    else if(min_sze>max_sze){
        med = getMax(thmin);
        if(data>med){
            removeMax(thmin);
            insert(thmax, med);
            insert(thmin, data);
        }
        else{
            insert(thmax, data);
        }
        return (getMax(thmin)+getMax(thmax))/2.0;
    }
    else{
        med = (getMax(thmin)+getMax(thmax))/2.0;
        if(data<med){
            insert(thmax, data);
            return (double)getMax(thmax);
        }
        else{
            insert(thmin, data);
            return (double)getMax(thmin);
        }


    }


    return -1;
}


#endif
