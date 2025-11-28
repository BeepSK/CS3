#include<stdio.h>
#include<math.h>
#define pi 4.0*atan(1.0)
#define f(x, y, z) (z)
#define g(x, y, z) (-sin(y))

int main()
{
    double xi, xf, ya, yrk, zi, k1, k2, k3, k4, m1, m2, m3, m4;
    double h=0.01;
    double alpha[] = {0.1, 0.5, 1.0};
    char filename[20];
    for(int n=0; n<3; n++)
    {
        xi=0.0; yrk=alpha[n];
        zi=0.0; h=0.01; 
        xf=8.0*pi;
        sprintf(filename, "diff2_%d.txt", n+1);   
        FILE*fp = fopen(filename, "w");
        do
        {
            ya=alpha[n]*cos(xi);
            fprintf(fp, "%lf\t %lf\t %lf\n", xi, ya, yrk);
            k1=h*f(xi, yrk, zi);
            m1=h*g(xi, yrk, zi);
            k2=h*f(xi+h/2.0, yrk+k1/2.0, zi+m1/2.0);
            m2=h*g(xi+h/2.0, yrk+k1/2.0, zi+m1/2.0);
            k3=h*f(xi+h/2.0, yrk+k1/2.0, zi+m1/2.0);
            m3=h*g(xi+h/2.0, yrk+k1/2.0, zi+m1/2.0);
            k4=h*f(xi+h, yrk+k3, zi+m3);
            m4=h*g(xi+h, yrk+k3, zi+m3);
            yrk+=(k1+2*k2+2*k3+k4)/6.0;
            zi+=(m1+2*m2+2*m3+m4)/6.0;
            xi+=h;
        } while (xi<=xf+1e-9);
        fclose(fp);
    }
}