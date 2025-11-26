#include<stdio.h>
#include<math.h>

int fact(int x)
{
    if(x<0)
    {return -1;}
    int result = 1;
    do
    {
        result*=x;
        x--;
    } while(x>0);
    return result;
}

int main()
{
    float x, t, s, acc=0.0001;
    int n, i;
    FILE*fp=NULL;
    fp=fopen("ser3.txt", "w");
    for(x=0.0; x<=10.0; x+=0.01)
    {
        fprintf(fp, "%f\t", x);
        for(n=0; n<=2; n++)
        {
            t=pow((x/2.0), n)/tgamma(n+1);
            s=t;
            i=1;
            do
            {
                t*=-((x*x)/4.0)/(i*(n+i));
                s+=t;
                i++;
            } while(fabs(t/s)>acc);
            fprintf(fp, "%f\t", s);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}