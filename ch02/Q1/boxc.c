#include<stdio.h>
#include<math.h>

int main()
{
    float x, y;
    FILE*fp=NULL;
    fp=fopen("boxc.txt", "w");
    for(x=1.0; x<=5.0; x+=1)
    {y=1.0; fprintf(fp, "%f\t %f\n", x, y);}
    for(y=1.0; y<=5.0; y+=1)
    {x=5.0; fprintf(fp, "%f\t %f\n", x, y);}
    for(x=5.0; x>=1.0; x-=1)
    {y=5.0; fprintf(fp, "%f\t %f\n", x, y);}
    for(y=5.0; y>=1.0; y-=1)
    {x=1.0; fprintf(fp, "%f\t %f\n", x, y);}
    fclose(fp);
}