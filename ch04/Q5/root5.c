#include<stdio.h>
#include<math.h>

float cheby(float x, int n)
{
    float u0, u1, u2;
    if(n==0)
    { return 1; }
    if(n==1)
    {return 2*x; }
    u0=1.0; u1=2*x;
    for(int i=1; i<n; i+=1)
    {
        u2=(2*x)*u1 - u0;
        u0=u1; u1=u2;
    }
    return u2;
}

int main()
{
    float x, x1, x2, x3, f1, f2, z, acc=0.000001;
    int n=4, i=0;
    FILE*fp=NULL;
    fp=fopen("root5.txt", "w");
    FILE*fp1=NULL;
    fp1=fopen("root5a.txt", "w");
    for(x=-1.0; x<=1.0; x+=0.01)
    { fprintf(fp1, "%f\t %f\n", x, cheby(x, n)); }
    for(x=-1.0; x<=1.0; x+=0.01)
    {
        x1=x; x2=x+0.01;
        if(cheby(x1, n)*cheby(x2, n)<0.0)
        {
            do
            {
                f1=cheby(x1, n);
                f2=cheby(x2, n);
                x3=(x1*f2-x2*f1)/(f2-f1);
                x1=x2; x2=x3;
                z=fabs(f2);
            } while(z>acc);
            i++;
            fprintf(fp, "Root=%d = %f\n", i, x2);
        }
    }
    fclose(fp);
    fclose(fp1);
}