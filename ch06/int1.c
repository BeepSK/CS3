#include<stdio.h>
#include<math.h>
#define pi 3.14159

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

int main()
{
    double a=5.0, b=10.0, tr, simps; int n=50;
    tr=trap(a, b, n);
    simps=simp(a, b, n);
    FILE*fp=fopen("int1a.txt", "w");
    fprintf(fp, "Trapezoidal rule: %lf\n", tr);
    fprintf(fp, "Simpson's rule: %lf\n", simps);
    fclose(fp);
}



