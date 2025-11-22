#include<stdio.h>
#include<math.h>
#define pi 4.0*atan(1.0)

double orbital(double theta, int m)
{
    if(m==0)
        return ((3.0*sqrt(14.0))/4.0)*cos(theta)*(((5.0/3.0)*cos(theta)*cos(theta))-1.0);
    else if(m==1)
        return (sqrt(42.0)/8.0)*sin(theta)*((5.0*cos(theta)*cos(theta))-1.0);
    else if(m==2)
        return (sqrt(105.0)/4.0)*pow(sin(theta), 2)*pow(cos(theta), 2);
    else if(m==3)
        return (sqrt(70.0)/8.0)*pow(sin(theta), 3);
}

int main()
{
    double O;
    double theta, x, y;
    FILE *fp0;
    fp0 = fopen("orbital.txt", "w");
    fprintf(fp0, "x0 \t\t y0 \t\t x1 \t\t y1 \t\t x2 \t\t y2 \t\t x3 \t\t y3\n");
    for(theta = 0.0; theta <= 2*pi; theta += 0.01*pi)
    {
        for(int m=0; m<=3; m++)
        {
            O = orbital(theta, m);
            x = O*O*cos(theta);
            y = O*O*sin(theta);
            fprintf(fp0, "%lf\t%lf\t", x, y);
        }
        fprintf(fp0, "\n");
    }
    fclose(fp0);
}
