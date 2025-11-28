#include<stdio.h>
#include<math.h>
#define f(t, x, y) (0.25*(x)-0.01*(x)*(y))
#define g(t, x, y) (-1.0*(y)+0.01*(x)*(y))

int main()
{
    double x, y, y1, ti, k1, k2, k3, k4, m1, m2, m3, m4;
    double h=0.001; double tf=200.0;
    FILE*fp=NULL;
    for(y1=5.0; y1<=30.0; y1+=5.0)
    {
        ti=0.0; y=y1;
        x=100.0;
        char filename[50];
        sprintf(filename, "diff3b_%.0f.txt", y1); 
        fp = fopen(filename, "w");
        do
        {
            k1=h*f(ti, x, y);
            m1=h*g(ti, x, y);
            k2=h*f(ti+h/2.0, x+k1/2.0, y+m1/2.0);
            m2=h*g(ti+h/2.0, x+k1/2.0, y+m1/2.0);
            k3=h*f(ti+h/2.0, x+k2/2.0, y+m2/2.0);
            m3=h*g(ti+h/2.0, x+k2/2.0, y+m2/2.0);
            k4=h*f(ti+h, x+k3, y+m3);
            m4=h*g(ti+h, x+k3, y+m3);
            x+=(k1+2.0*k2+2.0*k3+k4)/6.0;
            y+=(m1+2.0*m2+2.0*m3+m4)/6.0;
            ti+=h;
            fprintf(fp, "%lf\t %lf\n", x, y);
        } while(ti<=tf);
    }
    fclose(fp);
}