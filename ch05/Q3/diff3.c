#include<stdio.h>
#include<math.h>
#define f(t, x, y) ((0.25*x)-(0.01*x*y))
#define g(t, x, y) ((-1.0*y)+(0.01*x*y))

int main()
{
    double x, y, ti, tf, k1, k2, k3, k4, m1, m2, m3, m4;
    FILE*fp=NULL;
    double h=0.01; 
    double yi [] = {5.0 , 10.0 , 15.0 , 20.0 , 25.0};
    char filename [50];
    fp=fopen("diff3.txt", "w");
    for(int n=0; n<5; n++)
    {
        ti=0.0; tf=20.0; y=yi[n];
        x=100.0; 
        sprintf(filename,"diff3_%d.txt", n+1) ;
        FILE*fp=fopen(filename, "w") ;
        do
        {
            fprintf(fp, "%lf\t %lf\n", x, y);
            k1=h*f(ti, x, y);
            m1=h*g(ti, x, y);
            k2=h*f(ti+h/2.0, x+k1/2.0, y+m1/2.0);
            m2=h*g(ti+h/2.0, x+k1/2.0, y+m1/2.0);
            k3=h*f(ti+h/2.0, x+k2/2.0, y+m2/2.0);
            m3=h*g(ti+h/2.0, x+k2/2.0, y+m2/2.0);
            k4=h*f(ti+h, x+k3, y+m3);
            m4=h*g(ti+h, x+k3, y+m3);
            x+=(k1+2*k2+2*k3+k4)/6.0;
            y+=(m1+2*m2+2*m3+m4)/6.0;
            ti+=h;
        } while(ti<=tf+1e-9);
        fclose(fp);
    }
}