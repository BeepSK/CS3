/* This program allocates memory for a vector, integer vector
   and an m x n matrix */

#include <stdio.h>
#include <stdlib.h>

/* Prototypes */
float *vecalloc(int n);
int   *vecint_alloc(int n);
float **matalloc(int m, int n);

/* Program for allocation of memory space for an n vector */
float *vecalloc(int n)
{
    float *x;

    x = (float *)calloc(n, sizeof(float));
    if (x == NULL)
    {
        fprintf(stderr, "Unable to allocate memory\n");
        exit(1);
    }

    return (x - 1);
}

/* Program for allocation of memory space with integer return */
int *vecint_alloc(int n)
{
    int *v;

    v = (int *)calloc(n, sizeof(int));
    if (v == NULL)
    {
        fprintf(stderr, "Could not allocate memory\n");
        exit(1);
    }

    return (v - 1);
}

/* Program for allocation of memory space for an m x n matrix */
float **matalloc(int m, int n)
{
    float **a;
    int i;

    a = (float **)calloc(m, sizeof(float *));
    if (a == NULL)
    {
        fprintf(stderr, "Could not allocate row memory\n");
        exit(1);
    }

    a = a - 1;

    for (i = 1; i <= m; i++)
    {
        a[i] = (float *)calloc(n, sizeof(float));
        if (a[i] == NULL)
        {
            fprintf(stderr, "Could not allocate column memory\n");
            exit(1);
        }

        a[i] = a[i] - 1;
    }

    return a;
}
