#include<stdio.h>
#include<math.h>
#define pi 4.0*atan(1.0)

double f(double x, double A)
{
    return (1/(1-pow(sin(A/2.0), 2)*sin(x)*sin(x)));
}

double simp(double a, double b, double A, int n)
{
    if(n%2!=0)
    { printf("Enter even no. of intervals please.\n");}
    double s1=0.0;
    double s2=0.0;
    double h=(b-a)/n;
    for(int i=1; i<n; i++)
    {
        if(i%2==0)
        { s1+= f(a+i*h, A); }
        else
        { s2+= f(a+i*h, A); }
    }
    return (h/3.0 * (f(a, A)+f(b, A)+2.0*s1+4.0*s2));
}

int main()
{
    double A1, T, T1, simps;
    double a=0.0, b=(pi*0.5);
    int n=50;
    double per;
    FILE*fp=fopen("int2.txt", "w");
    for(A1=0.0; A1<=(pi); A1+=(0.01*pi))
    {
        T1=(2.0*pi)*(1+pow((A1/4.0), 2));
        simps=simp(a,b,A1, n);
        T=4*simps;
        per=fabs((2.0*(T-T1)/(T+T1))*100);
        fprintf(fp, "%lf\t %lf\t %lf\t %lf\n", A1, per, T1, T);
    }
}