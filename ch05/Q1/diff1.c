#include<stdio.h>
#include<math.h>

#define f(x,y) ((x)+(y))

int main()
{
    double xi, xf, s, h, x, y, k1, k2, k3, k4;
    int i;
    FILE*fp=NULL;
    FILE*fp1=NULL;
    FILE*fp2=NULL;
    fp=fopen("diff1a.txt", "w");
    fp1=fopen("diff1e.txt", "w");
    fp2=fopen("diff1rk.txt", "w");
    xi=0.0; xf=5.0;
    h=0.01;
    y=1.0;
    for(x=0.0; x<=xf; x+=0.1)
    {
        s=2.0*exp(x)-x-1;
        fprintf(fp, "%f\t %f\n", x, s);
    }
    x=xi;
    do
    {
        y+=h*((x)+(y));
        x+=h;
        fprintf(fp1, "%f\t %f\n", x, y);
    } while(x<=xf+1e-9);
    x=xi;
    y=1.0;
    do
    {
        k1=h*f(x,y);
        k2=h*f(x+h/2.0, y+k1/2.0);
        k3=h*f(x+h/2.0, y+k2/2.0);
        k4=h*f(x+h, y+k3);
        y+=(k1+2*k2+2*k3+k4)/(6.0);
        x+=h;
        fprintf(fp2, "%f\t %f\n", x, y);
    } while (x<=xf+1e-9);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
}
