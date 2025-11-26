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

float j(float x)
{
    float t, s, acc=0.0001;
    int n=0, i;
    t=pow((x/2.0), n)/tgamma(n+1);
    s=t;
    i=1;
    do
    {
        t*=-((x*x)/4.0)/(i*(n+i));
        s+=t;
        i++;
    } while(fabs(t/s)>acc);
    return s;
}

int main()
{
    float x, x1, x2, f1, f2, x3, acc=0.00001, z;
    int nn, ii;
    FILE*fp=NULL;
    fp=fopen("root2.txt", "w");
    for(x=0.0; x<=10.0; x+=0.01)
    {
        printf("%f\t %f\n", x, j(x));
    }
    printf("What is n? \n");
    scanf("%d", &nn);
    fprintf(fp, "There are %d roots.\n", nn);
    for(ii=1; ii<=nn; ii++)
    {
        printf("What's x1 and x2? \n");
        scanf("%f %f", &x1, &x2);
        do
        {
            f1=j(x1);
            f2=j(x2);
            x3=(x1*f2-x2*f1)/(f2-f1);
            x1=x2; 
            x2=x3;
            z=fabs(f2);
        } while(z>acc);
        fprintf(fp, "For n=%d, Root=%f j0(x)=%f\n", nn, x2, f2);
    }
}
