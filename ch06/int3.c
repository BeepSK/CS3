#include<math.h>
#include<stdio.h>
#define pi 3.14159

double intg(double r)
{
    V=(-1.0*k)/r;
    return 1/((r*r)*sqrt((2.0*(-0.25))-(2.0*V)-(1/(r*r))));
}

double gauss(double r0, double rm)
{
    double c, d, x[20], w[20], z1, z2, s, in;
    c=(rm+r0)/2.0; d=(rm-r0)/2.0;
    int n=6;
    s=0.0;
    #include <gauss.c>
    for(int i=1; i<n/2-1; i++)
    {
        z1=c+d*x[i];
        z2=c-d*x[i];
        s+=w[i]*(f(z1)+f(z2));
    }
    s*=d;
    in=s;
    return in;
}

int main()
{

}