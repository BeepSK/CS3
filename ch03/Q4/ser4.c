#include<stdio.h>
#include<math.h>
#define pi 4.0*atan(1.0)

int main()
{
    float t, s, z, acc=0.0001;
    int n;
    FILE*fp=NULL;
    fp=fopen("ser4.txt", "w");
    for(z=0.0; z<=1.0; z+=0.05)
    {
        t=s=z*cos((pi*z*z)/2.0);
        n=0;
        do
        {
            t*=-(pi*pi*z*z*z*z)*((4*n-3)/(4*n+1));
            s+=t;
            n++;
        } while(fabs(t/s)>acc);
        fprintf(fp, "%f\t %f\n", z, s);
    }
    fclose(fp);
}