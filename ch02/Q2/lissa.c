//Plotting lissajous figures 
#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main()
{
    float x, y0, y1, y2, y3, del, theta;
    int A;
    float n0=1, n1=2, n2=2.5, n3=3;
    FILE*fp=NULL;
    fp=fopen("lissa.txt", "w");
    del=(pi*0.25); A=1;
    fprintf(fp, " x\t\ty for n=1\t\ty for n=2\t\ty for n=2.5\t\ty for n=3\n");
    for(theta=0.0; theta<=(4.0*pi); theta+=0.1)
    {
        x=sin(theta);
        y0=A*sin((n0*theta)+del);
        y1=A*sin((n1*theta)+del);
        y2=A*sin((n2*theta)+del);
        y3=A*sin((n3*theta)+del);
        fprintf(fp, "%f\t %f\t %f\t %f\t %f\n", x, y0, y1, y2, y3);
    }
    fclose(fp);
}