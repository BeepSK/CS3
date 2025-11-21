//A table of trigonometric values
#include<stdio.h>
#include<math.h>
#define pi 3.14159

int main()
{
    float x, a, b, c;
    FILE*fp=NULL;
    fp=fopen("trigo.txt", "w");
    printf("x\t\t sin(x)\t\t cos(x)\t\t tan(x)\n");
    fprintf(fp, "x\t\t sin(x)\t\t cos(x)\t\t tan(x)\n");
    for(x=0.0; x<=(0.25*pi); x+=(0.01*pi))
    {
        a=sin(x);
        b=cos(x);
        c=tan(x);
        printf("%f\t %f\t %f\t %f\n", x, a, b, c);     
        fprintf(fp, "%f\t %f\t %f\t %f\n", x, a, b, c);   
    }
    fclose(fp);
}
