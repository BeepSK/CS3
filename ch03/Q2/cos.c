#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main()
{
    float x, t, s, acc=0.0001;
    int i;
    FILE*fp=NULL;
    fp=fopen("cos.txt", "w");
    for(x=0.0; x<=(pi); x+=0.01)
    {
        t=s=1.0;
        i=1.0;
        do
        {
            t*=-(x*x)/(2*i*(2*i-1));
            s+=t;
            i++;
        } while(fabs(t/s)>acc);
        fprintf(fp, "%f\t %f\n", x, s);
    }
    fclose(fp);
}