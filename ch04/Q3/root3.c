#include<stdio.h>
#include<math.h>

float f(float x, float y)
{
    return (pow(x, 3)+pow(y, 3)+x*y+1.0);
}

int main()
{
    float x0, x, y, y1, y2, f1, f2, y3, z, acc=0.0001;
    int n, i;
    FILE*fp=NULL;
    FILE*fp1=NULL;
    fp=fopen("root3.txt", "w");
    fp1=fopen("root3a.txt", "w");
    for(x=-1.5; x<=1.5; x+=0.1)
    {
        for(y=-2.0; y<=2.0; y+=0.01)
        {
            printf("%f\t %f\t %f\n", x, y, f(x,y));
            fprintf(fp1, "%f\t %f\n", y, f(x,y));
        }
    }
    for(x=-1.5; x<=1.5; x+=0.01)
    {
        for(y=-2.0; y<=2.0; y+=0.01)
        {
            if(f(x,y)*f(x,y+0.1)<0)
            {
                y1=y; y2=y+0.1;
                do
                {
                    f1=f(x, y1);
                    f2=f(x, y2);
                    y3 = (y1*f2 - y2*f1) / (f2 - f1);
                    y1=y2;
                    y2=y3;
                    z=fabs(f2);
                    fprintf(fp, "%f\t %f\n", x, y2);
                } while(z>acc);
            }
        }
    }
    fclose(fp);
    fclose(fp1);
}