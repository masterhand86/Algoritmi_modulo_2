#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
    int key;
    struct edge *next;
} edge;

typedef struct graph
{

    int nv;
    edge **adj;
} graph;

void g_print(graph *G)
{
    int i, ne=0;
    edge *e;
    if (!is_empty(G))
    {
        printf("\n Il grafo ha %d vertici\n", G->nv);
        for (i=0; i<G->nv; i++)
        {
            printf("nodi adiacenti al nodo %d -> ", i);
            e=G->adj[i];
            while (e!=NULL)
            {
                printf("%d ", e->key);
                ne=ne+1;
                e=e->next;
            }
            printf("\n");
        }
        printf("\n Il grafo ha %d archi \n", ne);
    }

}

graph *g_empty(int n)
    {
        graph *G;
        int i;
        G = (graph*)malloc(sizeof(graph));
        if (G==NULL) printf("ERRORE: impossibile allocare memoria per il grafo\n");
        else
        {
            G->adj = (edge**)malloc(n*sizeof(edge*));
            if ((G->adj==NULL) && (n>0))
            {
                printf("ERRORE: impossibile allocare memoria per la lista del grafo\n");
                free(G);
                G=NULL;
            }
            else
            {
                G->nv = n;
                for (i=0; i<n; i++)
                    G->adj[i]=NULL;
            }
        }
        return(G);
    }

int main()
{


return 0;
}
