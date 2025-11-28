#include<stdio.h>
#include<math.h>
#define pi 4.0*atan(1.0)

double intg(double x, double t)
{
    return (cos(pow(x, 1.5)*cos(t))*pow(sin(t), 3));
}

double simp(double a, double b, int n, double t)
{
    double s1=0.0, s2=0.0;
    double h=(b-a)/n;
    for(int i=1; i<n; i++)
    {
        if(i%2==0)
        { s1+=intg(a+i*h, t); }
        else
        { s2+=intg(a+i*h, t); }
    }
    return (h/3.0)*(intg(a, t)+intg(b, t)+2.0*s1+4.0*s2);
}

int main()
{
    double t1, t2, f1, f2, f3, t3, z, acc=0.000001, a=0.0, b=pi;
    int n=1000;
    FILE*fp=fopen("introot1.txt", "w");
    for(double t=0.0; t<=5.0; t+=0.01)
    {
        t1=t; t2=t+0.01;
        f1=simp(a, b, n, t1);
        f2=simp(a, b, n, t2);
        if(f1*f2<0.0)
        {
            do
            {
                t3 = (t1*f2 - t2*f1)/(f2 - f1);
                f3 = simp(a, b, n, t3);

                if(f1 * f3 < 0) {
                t2 = t3;
                f2 = f3;
                } else {
                t1 = t3;
                f1 = f3;
    }
            } while(fabs(f3)>acc);
            fprintf(fp, "Root using this method=%lf\n", t2);
        }
    }
}