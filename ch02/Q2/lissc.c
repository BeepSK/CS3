//Plotting lissajous figures 
#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main()
{
    float x, y1, y2, y3, theta;
    int n=2, A=1;
    float del1=(0.25*pi), del2=(0.5*pi), del3=(pi);
    FILE*fp=NULL;
    fp=fopen("lissc.txt", "w");
    fprintf(fp, " x\t\ty for del=45\t\ty for del=90\t\ty for del=180\t\t");
    for(theta=0.0; theta<=(4.0*pi); theta+=0.1)
    {
        x=sin(theta);
        y1=A*sin((n*theta)+del1);
        y2=A*sin((n*theta)+del2);
        y3=A*sin((n*theta)+del3);
        fprintf(fp, "%f\t %f\t %f\t %f\n", x, y1, y2, y3);
    }
    fclose(fp);
}