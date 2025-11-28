#include<stdio.h>
#include<math.h>

float f(float x, float y)
{
    return (sin(x)-y);
}

int main()
{
    double k1, k2, k3, k4, xi, y, xf, h, x;
    h=0.01; xi=0.0; xf=20.0; y=0.0;
    FILE*fp=fopen("extra.txt", "w");
    for(x=xi; x<=xf; x+=h)
    {
        k1=h*f(x,y);
        k2=h*f(x+h/2.0, y+k1/2.0);
        k3=h*f(x+h/2.0, y+k2/2.0);
        k4=h*f(x+h, y+k3);
        y+=(k1+2.0*k2+2.0*k3+2.0*k4)/(6.0);
        x+=h;
        fprintf(fp, "%lf\t %lf\n", x, y);
    }
    fclose(fp);
}