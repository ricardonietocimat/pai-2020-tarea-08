#ifndef MEDIAN_T8
#define MEDIAN_T8

// Prototipo ==================================================================

double theap_median(THeap * thmin, THeap * thmax, int data);
 

// Definiciones ===============================================================



double theap_median(THeap * thmin, THeap * thmax, int data){
    double mactual=0;
    if(thmax->n>thmin->n){ 
        mactual=getMax(thmax);
        if(data<mactual){
            insert(thmin,removeMax(thmax,0),1);
            insert(thmax,data,0);
        }
            else insert(thmin,data,1);
            mactual=(double)(getMax(thmax)+getMax(thmin))/2.0; 
          return mactual;
    }
    else{
        if(thmax->n<thmin->n){
                  mactual=getMax(thmin);
            if(data>mactual){
                insert(thmax,removeMax(thmin,1),0);
                insert(thmin,data,1);
            }
            else insert(thmax,data,0);
            mactual=(double)(getMax(thmax)+getMax(thmin))/2.0; 
          return mactual;

        }
        else{ 
                if(thmax->n==0){
                    insert(thmax,data,0);
                    mactual=data; 
                    return mactual;
                }
                else{
                     mactual=(double)(getMax(thmax)+getMax(thmin))/2.0;
                     if(data<mactual){
                          mactual=getMax(thmax); 
                          return mactual;
                     }
                     else{
                        insert(thmin,data,1);
                        mactual= getMax(thmin); 
                         return mactual;
                     }
                }
        }
    }

  return -1;
}
#endif 
