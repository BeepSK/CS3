//Plotting lissajous figures 
#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main()
{
    float x, y1, y2, y3, del, theta;
    int n=2;
    float A1= 0.5, A2=1.0, A3=2.0;
    FILE*fp=NULL;
    fp=fopen("lissb.txt", "w");
    del=(pi*0.25);
    fprintf(fp, " x\t\ty for A=0.5\t\ty for A=1\t\ty for A=2\t\t");
    for(theta=0.0; theta<=(4.0*pi); theta+=0.1)
    {
        x=sin(theta);
        y1=A1*sin((n*theta)+del);
        y2=A2*sin((n*theta)+del);
        y3=A3*sin((n*theta)+del);
        fprintf(fp, "%f\t %f\t %f\t %f\n", x, y1, y2, y3);
    }
    fclose(fp);
}