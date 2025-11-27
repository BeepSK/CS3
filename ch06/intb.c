#include<stdio.h>
#include<math.h>

float f(float x)
{
    return (log(1+x*x));
}

void hermite(int n, double x[], double w[]);

int main()
{
    double w[12], x[12], s1, s2, s=0.0;
    int i, n;
    n=10;
    hermite(n, x, w);
    for(i=1; i<=n/2; i++)
    {
        s1=x[i-1];
        s2=-x[i-1];
        s+=((f(s1)+f(s2)*w[i-1]));
        printf("%f\n", s);
    }
}