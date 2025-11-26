/*Solving for the first 20 terms of a geometric series
and comparing with the analytic result*/
#include<stdio.h>
#include<math.h>

int main()
{
    float x, t, s, an;
    FILE*fp=NULL;
    fp=fopen("infini1.txt", "w");
    for(x=0.01; x<=2.0; x+=0.01)
    {
        t=1.0/(x*x); 
        s=1.0; 
        for(int i=1; i<=18; i++)
        {
            {
                t*=(1.0/x);
                s+=t; 
            }
        }
        an = 1.0+(1.0/(x*(x-1.0)));
        fprintf(fp, "%f\t %f\t %f\n", x, s, an);
    }
    fclose(fp);
}