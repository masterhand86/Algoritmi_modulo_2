#include <stdio.h>
#include <stdlib.h>
/* Fastest_All_Pairs_Shortest_Path (int *W)
n <- rows [w]
D(W) <- W
m <- 1
while m-1 < m
    do D(2m) <- Extends_Shortest_Path (D(m), D(m) )
    m<- 2m
return D(m)
*/
void Extends_Shortest_Path (int *D, int *W, int n){
    int *D1;
    int i,j,k;
    D1 = calloc (n*n, sizeof(int));
    for (i=0; i<n; i++){
        for(j=0; j<n;j++){
            D1[i+n*j] = 1000*n;
            for(k=0; k<n;k++){
                if (W[k+n*j]!= 1000*n){
                    if((D[i+k*n]+W[k+n*j]) < D1[i+n*j]){
                        D1[i+n*j] = D[i+k*n]+W[k+n*j];
                    }
                }
            }
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            D[i+n*j]= D1 [i+n*k];
        }
    }
}

void Fastest_All_Pairs_Shortest_Path(int *D, int *W, int n){
    int i,j,m;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            D[i+n*j]=W[i+n*j];
        }
    }
    m=1;
    while (n-1 > m){
        Extends_Shortest_Path(D,D,n);
        m=2*m;
    }
}

int main(){
    return 0;
}
