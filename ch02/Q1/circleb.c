//Making a circle given that we know the radius and the centre coordinates
#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main()
{
    float x, y, a=5.0, b=5.0, r=3.0, t;
    FILE*fp=NULL;
    fp=fopen("circleb.txt", "w");
    for(t=0.0; t<=(2*pi); t+=(pi/100.0))
    {
        x=a+r*cos(t);
        y=b+r*sin(t);
        fprintf(fp, "%f\t %f\n", x, y);
    }
    fclose(fp);
}