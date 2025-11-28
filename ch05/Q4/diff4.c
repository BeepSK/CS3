#include<stdio.h>
#include<math.h>
#define f(x, y, z) ((z))
#define g(x, y, z) (f1((x))-(y)-4*(x)*(y))

float f1(float x)
{
    float s=1.0, t=1.0;
    int i;
    do
    {
        t*=(-x*x)/((2.0*i+3.0)*(2.0*i+2.0));
        s+=t;
        i++;
    } while (i<=100);
    return s;
}

int main()
{
    double x=0.0, xf=1.0, y=0.0, z=1.0;
    double k1, k2, k3, k4, m1, m2, m3, m4;
    double h=0.01; 
    FILE*fp=NULL;
    fp=fopen("diff4.txt", "w");
    do
        {
            fprintf(fp, "%lf\t %lf\n", x, y);
            k1=h*f(x, y, z);
            m1=h*g(x, y, z);
            k2=h*f(x+h/2.0, y+k1/2.0, z+m1/2.0);
            m2=h*g(x+h/2.0, y+k1/2.0, z+m1/2.0);
            k3=h*f(x+h/2.0, y+k2/2.0, z+m2/2.00);
            m3=h*g(x+h/2.0, y+k2/2.0, z+m2/2.0);
            k4=h*f(x+h, y+k3, z+m3);
            m4=h*g(x+h, y+k3, z+m3);
            x+=(k1+2*k2+2*k3+k4)/6.0;
            y+=(m1+2*m2+2*m3+m4)/6.0;
            x+=h;
        } while(x<=xf+1e-9);
    fclose(fp);
}