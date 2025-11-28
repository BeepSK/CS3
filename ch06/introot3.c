#include<stdio.h>
#include<math.h>
#define pi 4.0*atan(1.0)

double intg(double x, double z)
{
    return (cos(z*cos(x))*pow(sin(x), 5.0));
}

double simp(double a, double b, int n, double z)
{
    double si;
    double s1=0.0, s2=0.0;
    double h=(b-a)/n;
    for(int i=1; i<n; i++)
    {
        if(i%2==0)
        { s1+=intg(a+i*h, z); }
        else
        { s2+=intg(a+i*h, z); }
    }
    si = (h/3.0)*(intg(a, z)+intg(b, z)+2.0*s1+4.0*s2);
    return ((z*z)/16.0)*si;
}

int main()
{
    double b=(pi), a=0.0;
    double z1, z2, z3, f1, f2, z, f3, err, acc=0.0001;
    int n=100;
    FILE*fp=fopen("introot3.txt", "w");
    for(z=0.0; z<=10.0; z+=0.01)
    {
        z1=z; z2=z+0.01;
        f1=simp(a, b, n, z1);
        f2=simp(a, b, n, z2);
        if(f1*f2<0.0)
        {
            do
            {
                z3 = (z1*f2 - z2*f1)/(f2 - f1);
                f3 = simp(a, b, n, z3);

                if(f1 * f3 < 0) {
                z2 = z3;
                f2 = f3;
                } else {
                z1 = z3;
                f1 = f3;
    }
            } while(fabs(f3)>acc);
            fprintf(fp, "Root=%lf\n", z2);
        }
    }
}