//Plotting a periodic function
#include<stdio.h>
#include<math.h>
#define pi 3.141159

int main()
{
    double x, y;
    FILE*fp=NULL;
    fp=fopen("periodic.txt", "w");
    fprintf(fp, " x\t\t  y\n");
    for(x=(-6.0*pi); x<=(6.0*pi); x+=(0.1*pi))
    {
        int n=(int)(x/(2.0*pi));
        float x1 = x-2.0*pi*n;
        float z = fabs(x1);
        if(z>=0.0 && z<pi)
            {y=z;}
        else if(z>=pi && z<(2.0*pi))
            {y=(2*pi - z);}
        fprintf(fp, "%lf\t %lf\n", x, y);
    }
    fclose(fp);
}