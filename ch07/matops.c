/*#include<stdio.h>
#include<stdlib.h>
#include "makemat.c"*/

void matprint(float **a, int m, int n) //For printing
{
    int i, j;
    for(i=1; i<=m; i++)
    { for(j=1; j<=n; j++)
        {
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }
}

void matadd(float **a, float **b, float **c, int m, int n)
//For adding matrices
{
    int i, j;
    for(i=1; i<=m; i++)
    { for(j=1; j<=n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
            printf("%f\t", c[i][j]);
        }
        printf("\n");
    }
}

void matsub(float **a, float **b, float **c, int m, int n)
//For subtracting matrices
{
    int i, j;
    for(i=1; i<=m; i++)
    { for(j=1; j<=n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
            printf("%f\t", c[i][j]);
        }
        printf("\n");
    }
}

void mattrnsfr(float **a, float **b, int m, int n)
//For transferring matrices
{
    int i, j;
    for(i=1; i<=m; i++)
    { for(j=1; j<=n; j++)
        {
            b[i][j] = a[i][j];
            printf("%f\t", b[i][j]);
        }
        printf("\n");
    }
}

void matmul(float **a, float **b, float **c, int m, int n)
//For multiplying matrices
{
    int i, j, k;
    for(i=1; i<=m; i++)
    { for(j=1; j<=n; j++)
        { c[i][j] = 0.0;
            for(k=1; k<=n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%f\t", c[i][j]);
        }
        printf("\n");
    }
}

void mattr(float **a, int m, int n)
//For finding the trace of the matrix
{
    int i, j;
    float tr=0.0;
    for(i=1; i<=m; i++)
    { for(j=1; j<=n; j++)
        { 
            if(i==j)
            {tr+=a[i][i];}
            else
            {tr+=0.0;}
        }
    }
    printf("%f\n", tr);
}

/* Take out of comments for testing the above
int main()
{
    int i, j, m=3, n=3; 
    float **a, **b, **c; 
    a=matalloc(m,n);
    b=matalloc(m,n);
    c=matalloc(m,n);
    for(i=1; i<=m; i++)
    { for(j=1; j<=n; j++)
        {
            a[i][j] = i;
            b[i][j] = j;
        }
    }
    mattr(b, m, n);
}*/