#include <stdio.h>
#include <stdlib.h>

struct heap
{
    int dim;
    int A[100];
};

typedef struct heap *heapy;

int inseriscicompito(heapy h,int v, int k)
{

    int pos,aux,b1,b2;
    if(h->dim<k)
        return 0;
    else
    {
        h->A[k]=v;
        pos=v;
        while((pos!=1)&&(h->A[pos]>h->A[pos/2]))
        {
            aux=h->A[pos];
            h->A[pos/2]=aux;
            pos=pos/2;
        }
        if(pos==k)
        {
            b1=0;
            if(pos*2<=h->dim)
                if(h->A[pos*2]>h->A[pos])
                    b1=1;
            b2=0;
            if(pos*2+1 <= h->dim)
                if(h->A[pos*2+1]>h->A[pos])
                    b2=1;
            while(b1||b2)
            {
                if(b2==0)
                {
                    aux=h->A[pos*2];
                    h->A[pos*2]=h->A[pos];
                    h->A[pos]=aux;
                    pos*=2;
                }
                else
                {
                    if((h->A[pos*2])>(h->A[pos*2+1])||(pos*2==h->dim))
                    {
                        aux=h->A[pos*2];
                        h->A[pos*2]=h->A[pos];
                        h->A[pos]=aux;
                        pos*=2;
                    }
                    else
                    {
                        aux=h->A[pos*2+1];
                        h->A[pos*2+1]=h->A[pos];
                        h->A[pos]=aux;
                        pos=pos*2+1;

                    }

                }
            }
            return 1;

        }
    }

}

int main(){

return 0;}
