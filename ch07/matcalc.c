#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "makemat.c"
#include "matops.c"

int main()
{
    int i, j, m=4, n=4; 
    float **a, **b, **c, **A, **B; 
    a=matalloc(m,n);
    b=matalloc(m,n);
    c=matalloc(m,n);
    A=matalloc(m,n);
    B=matalloc(m,n);
    printf("Matrix A: \n");
    for(i=1; i<=m; i++)
    { for(j=1; j<=n; j++)
        {
            a[i][j] = (float) i/ (float) (i+j);
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matrix B: \n");
    for(i=1; i<=m; i++)
    { for(j=1; j<=n; j++)
        {
            b[i][j] = (float) j/ (float) (i+j);
            printf("%f\t", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Matrix AB: \n");
    matmul(a, b, A, m, n);
    printf("\n");
    printf("Matrix BA: \n");
    matmul(b, a, B, m, n);
    printf("\n");
    printf("Commutator of AB and BA: \n");
    matsub(A, B, c, m, n);
}