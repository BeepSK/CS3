#include<stdio.h>
#include<math.h>
//In this program, I have made separate blocks of code.
//Take out whichever method you want to use from the comments.

float f(float x)
{
    float a=-1.5, b=10.0;
    return (exp(a*x)-b*x*x);
}

float g(float x)
{
    float a=-1.5, b=10.0;
    return (a*exp(a*x)-2*b*x);
}

/*int main() //For the Bisection method
{
    float x, x1, x2, xm, xl, xr, xinc=0.5, acc=0.0001, z;
    int n, i;
    FILE*fp=NULL;
    fp=fopen("r1bbis.txt", "w");
    for(x=-1.0; x<=1.0; x+=0.01)
    { printf("%f\t %f\n", x, f(x)); }
    printf("How many roots are there? \n");
    scanf("%d", &n);
    fprintf(fp, "There are %d roots for this equation.\n", n);
    for(i=1; i<=n; i++)
    {
        printf("What's the value of x1 and x2? \n");
        scanf("%f %f", &x1, &x2);
        for(x=x1; x<=x2; x+=xinc)
        {
            if(f(x)*f(x+xinc)<0)
            {
                x=xl; xr=x+xinc;
                do
                {
                    xm=(xl+xr)/2.0;
                    if(f(xm)*f(xl)<0)
                    {xr=xm;}
                    if(f(xm)*f(xl)>0)
                    {xl=xm;}
                    z=fabs((xl-xr)/(xl+xr));
                    printf("xm=%f f(xm)=%f\n", xm, f(xm));
                } while(z>acc);
                fprintf(fp, "\nUsing the values %f and %f, we get xm=%f f(xm)=%f.\n", x1, x2, xm, f(xm));
            }
        }
    }
    fclose(fp);
}

int main() //For the Secant method
{
    float x, x1, x2, f1, f2, x3, acc=0.0001, z;
    int n, i;
    FILE*fp=NULL;
    fp=fopen("r1bsec.txt", "w");
    for(x=-1.0; x<=1.0; x+=0.01)
    { printf("%f\t %f\n", x, f(x)); }
    printf("How many roots are there? \n");
    scanf("%d", &n);
    fprintf(fp, "There are %d roots for this equation.\n", n);
    for(i=1; i<=n; i++)
    {
        printf("What's the value of x1 and x2? \n");
        scanf("%f %f", &x1, &x2);
        do
        {
            f1=f(x1);
            f2=f(x2);
            x3=(x1*f2-x2*f1)/(f2-f1);
            x1=x2;
            x2=x3;
            z=fabs(f2);
        } while(z>acc);
        fprintf(fp, "\nUsing the values %f and %f, we get the Root=%f f(x)=%f.\n", x1, x2, x2, f2);
    }
    fclose(fp);
}

int main() //For the Newton-Raphson method
{
    float x, h, f1, f2, acc=0.0001;
    FILE*fp=NULL;
    fp=fopen("r1bnr.txt", "w");
    for(x=-1.0; x<=1.0; x+=0.01)
    { printf("%f\t %f\n", x, f(x)); }
    printf("Choose your x: \n");
    scanf("%f", &x);
    do
    {
        f1=f(x);
        f2=g(x);
        h=-f1/f2;
        x+=h;
    } while(fabs(h/x)>acc);
    fprintf(fp, "Root=%f f(x)=%f\n", x, f1);
    fclose(fp);
}*/