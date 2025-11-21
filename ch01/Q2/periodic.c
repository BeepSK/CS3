//Periodic function f(x,y)
#include<stdio.h>
#include<math.h>

int main()
{
    double x, y, f;
    FILE*fp=NULL;
    fp=fopen("periodic.txt", "w");
    printf(" x\t\t  y\t\t f(x,y)\n");
    fprintf(fp, " x\t\t  y\t f(x,y)\n");
    for(x=-1.0; x<=1.0; x+=0.25)
    {for(y=-1.0; y<=1.0; y+=0.25)
        {
            if(fabs(x)>fabs(y))
            {f = (x*x+y*y);}
            else if(fabs(x)==fabs(y))
            {f = (x*x*(x*x+1));}
            else if(fabs(x)<fabs(y))
            {f = (y*y*pow(x, 4));}
            printf("%lf\t %lf\t %lf\n", x, y, f);
            fprintf(fp, "%lf\t %lf\t %lf\n", x, y, f);
        }
    }
}
