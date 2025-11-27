#include<stdio.h>
#include<math.h>
#define pi 3.14159

void gauss(int n, double x[], double w[]);

double f(double x)
{
    return ((atan(x))/(x*x));
}

double trap(double a, double b, int n)
{
    double s=0.0;
    double h=(b-a)/n;
    for(int i=1; i<n; i++)
    {
        s+=f(a+i*h);
    }
    return (h/2.0 * (f(a)+f(b)+2.0*s));
}

double simp(double a, double b, int n)
{
    if(n%2!=0)
    { printf("Enter even no. of intervals please.\n");}
    double s1=0.0;
    double s2=0.0;
    double h=(b-a)/n;
    for(int i=1; i<n; i++)
    {
        if(i%2==0)
        { s1+= f(a+i*h); }
        else
        { s2+= f(a+i*h); }
    }
    return (h/3.0 * (f(a)+f(b)+2.0*s1+4.0*s2));
}

double gs(double a, double b)
{
    double c, d, x[20], w[20], z1, z2, s, intg;
    c=(b+a)/2.0; d=(b-a)/2.0;
    int n=6;
    s=0.0;
    gauss(n, x, w);   
    for(int i=0; i<n/2-1; i++)
    {
        z1=c+d*x[i];
        z2=c-d*x[i];
        s+=w[i]*(f(z1)+f(z2));
    }
    s*=d;
    intg=s;
    return intg;
}

int main()
{
    double a=5.0, b=10.0, tr, simps, gsq; int n=50;
    tr=trap(a, b, n);
    simps=simp(a, b, n);
    gsq=gs(a, b);
    FILE*fp=fopen("int1a.txt", "w");
    fprintf(fp, "Trapezoidal rule: %lf\n", tr);
    fprintf(fp, "Simpson's rule: %lf\n", simps);
    fprintf(fp, "Gauss Qaudrature: %lf\n", gsq);
    fclose(fp);
}



