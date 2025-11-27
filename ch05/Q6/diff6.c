#include<stdio.h>
#include<math.h>

int main()
{
    double a, x;
    int i;
    FILE*fp=fopen("diff6.txt", "w");
    for(a=0.0; a<=4.0; a+=0.05)
    {
        x=0.5;
        i=0;
        for(i=0; i<1000; i++)
        {
            x=a*x*(1-x);
        }
        for(i=0; i<100; i++)
        {
            x=a*x*(1-x);
            fprintf(fp, "%lf\t %lf\n", a, x);
        }
    }
    fclose(fp);
}