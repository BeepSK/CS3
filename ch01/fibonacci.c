#include<stdio.h>
#include<math.h>

int fibo(int n)
{
    int n1 = 1, n2 = 1, next;
    do
        {
            printf("%d, ", n2);
            next= n1+n2;
            n1 = n2;
            n2 = next;
        } while(n2<n);
}

int main()
{
    int limit, a=1, b=1, c;
    printf("What's the limit?\n");
    scanf("%d", &limit);
    printf("The fibonacci sequence upto %d is as follows: \n", limit);
    fibo(limit);
    printf("\n\n");
}