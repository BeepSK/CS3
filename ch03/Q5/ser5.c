#include<stdio.h>
#include<math.h>
#define pi 4.0*atan(1.0)

int main()
{
    float t, s, z, acc=0.0001;
    int i, n=2;
    FILE*fp=NULL;
    fp=fopen("ser5.txt", "w");
    for(z=0.0; z<=5.0; z+=0.01)
    {
        t=1.0/(2.0*sqrt(pi));
        s=t; i=0;
        do
        {
            t*=(4.0*z*z*(n-i-1.0)*0.5)/((i+1.0)*(i+2.0));
            s+=t;
            i+=2;
        } while(fabs(t/s)>acc);
        fprintf(fp, "%f\t %f\n", z, s);
    }
    fclose(fp);
}