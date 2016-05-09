#include <stdio.h>
#include <stdlib.h>

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

int main(){
    return 0;

}
