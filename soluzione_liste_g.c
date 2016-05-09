#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int nodo;
    struct elemento *next;
} elemento;

typedef elemento *link;

void stampa (link a)
{
    while(a->next != NULL)
    {
        printf("\n %d \n", a->nodo);
        a=a->next;
    }
}

int isolato (link A[], int n, int i)
{
    int ris;
    link a;
    if (A[i] != NULL)
        ris =0;
    else
    {
        ris =1;

        for(i=0; i<n && ris==1; i++){
                if(A[i]!= NULL){

                    a= A[i];
                    while((a->nodo!=i)&& (a->next != NULL)){
                          a = a->next;
                          }
                }
                if (a->nodo == i)
                    ris =0;
        }
    }

    printf("\n Ciao \n %d \n", ris);

}

int inserisci(link a, int i)
{

    int ris=0;
    while ((a->nodo != i)&&(a->next != NULL))
    {
        a=a->next;
    }
    if (a->nodo ==i)
        ris =1;
    else
    {
        ris=0;
        a->next=malloc(sizeof(elemento));
        a= a->next;
        a->nodo =i;
        a->next = NULL;
    }


    return ris;
}

int main()
{

    int i, n, m, j, k, r;

    link *A;
    printf("\n Da quanti nodi e' composto il grafo? \n");
    scanf("%d", &n);
    A = calloc(n, sizeof(link));

    printf("\n Di quanti elementi e' composto il grado? \n");

    scanf("%d", &m);


    for(k=0; k<m; k++)
    {
        do
        {

            printf("\n Inserisci l'arco %d \n", k);
            printf("\n Inserisci il primo nodo \n");
            scanf("%d", &i);
            printf("\n Inserisci il secondo arco \n");
            scanf("%d", &j);
            if (A[i]==NULL)
            {
                A[i]=malloc(sizeof(elemento));
                A[i]->nodo = j;
                A[i]->next = NULL;
                r=0;
            }
            else
                r=inserisci (A[i],j);
        }
        while (r);
    }

    stampa(A);
    isolato(A, 5,4);

}
