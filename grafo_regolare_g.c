#include <stdio.h>
#include <stdlib.h>

int regolare (int A[], int n)
{
    int i,j,reg=1,grado,grado1;
    i=0;
    grado=0;
    for(j=0; j<n; j++)
    {
        grado+=A[i+n*j];
    }
    grado1 = 0;
    for(i=1; reg ==1&& i<n; i++)
    {
        grado1 = 0;
        for(j=1; j<n; j++)
        {
            grado1 += A[i+n*1];
        }
        if(grado1 != grado)
            reg = 0;
    }
    return reg;
}

int main()
{
    return 0;
}
