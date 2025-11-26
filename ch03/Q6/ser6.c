#include<stdio.h>
#include<math.h>

int main()
{
    float t, C=0.35503, z, s, acc=0.0001;
    int i;
    FILE*fp=NULL;
    fp=fopen("ser6.txt", "w");
    for(z=-10.0; z<=0.0; z+=0.05)
    {
        t=1.0; 
        s=t;
        i=1;
        do
        {
            t*=(z*z*z)/(3*i*(3*i-1));
            s+=t;
            i++;
        } while(fabs(t/s)>acc);
        s*=C;
        fprintf(fp, "%f\t %f\n", z, s);
    }
    fclose(fp);
}