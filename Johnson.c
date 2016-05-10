#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Initialize_S_S (int n, int s, int *d, int *pi){
    int v;
    for (v=0; v<n; v++){
        d[v]=1000*n;
        pi[v]=n;
        }
    d[s] = 0;
    }

void Relax(int u, int v, int *w, int n, int *d, int *pi){
    if(d[v]> d[u]+ w[u+n*v]){
        d[v] = d[u]+ w[u+n*v];
        pi[v]=u;
        }
    }

int Bellman_ford (int *w, int s, int *d, int *pi, int n){
    int i, u, v, ris=1;
    Initialize_S_S(n,s,d,pi);
    for (i = 1; i<n; i++){
        for (u=0; u<n; u++){
            for (v=0; v<n; v++){
                Relax(u,v,w,n,d,pi);
            }
        }
    }
    for(u=0;u<n;u++){
        for(v=0;v<n;v++){
            if(d[v] > d[u]+w[u+n*v])
                ris =0;

        }
    }

    return ris;
}

void Dijkstra (int *w, int s, int *d, int *pi, int n){
    int v, k, min, u;
    int *S;
    S = calloc(n, sizeof(int));
    Initialize_S_S(n,s,d,pi);
    for (v=0; v<n; v++){
        Relax(s,v,w,n,d,pi);
        }
    S[s] =s;
    for (k=1; k<n; k++){
        u = n;
        min = 1000 * n;
        for(v=0; v<n; v++){
                if((d[v]<min) && (S[v] == 0)){
                    min = d[v];
                    u=v;
                }
            }
        S[u] = 1;
        for (v=0; v<n; v++){
                Relax(u,v,w,n,d,pi);
            }
        }
    }


int Johnson (int *D, int *Pi, int *W, int n){
    int u,v,ans;
    int *W1, *d1,*pi1, *W2, *d, *pi; //W1 ha dimensione n+1 x n+1, d1, pi1 hanno dimensione n+1; W2 = ripesatura degli archi
    W1 = calloc((n+1)*(n+1), sizeof(int));
    d1 = calloc(n+1, sizeof(int));
    pi1 = calloc(n+1, sizeof(int));
    W2 = calloc(n*n, sizeof(int));
    d = calloc(n, sizeof(int));
    pi = calloc(n, sizeof(int));

    for (u=0; u<n; u++){
        for (v=0; v<n; v++){
            W1[u+(n+1)*v] = W[u+n*v];
        }
    }
    for (v=0; v<n; v++){
        W1[v+(n+1)*n] = 1000 * n;
    }
    ans = Bellman_ford (W,n,d1,pi1,n+1);
    if(ans ==0){
        printf("Il grafo contiene cicli negativi \n");
        return ans;
        }
    else {
        for(u=0; u<n; u++){
            for(v=0;v<n;v++){
                if(W[u+n*v] != n*1000)
                    W2[u+n*v] = W[u+n*v] + d1[u] - d1[v];
                else
                    W2[u+n*v] = 1000 *n;
            }
        }
        for (u=0; u<n; u++){
            Dijkstra(W2, u, d, pi, n);
            for (v=0; v<n; v++){
                D[u+n*v] = d[v] + d1[v] - d1[u];
                Pi[u+n*v] = pi [v];
            }
        }

        return ans;
    }
}


int main(){
    return 0;
}
