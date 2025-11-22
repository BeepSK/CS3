//Making a triangle
#include<stdio.h>
#include<math.h>

int main()
{
    float x, y;
    FILE*fp=NULL;
    fp=fopen("tria.txt", "w");
    for(x=0.0; x<=4.0; x+=1)
    {y=0.0; fprintf(fp, "%f\t %f\n", x, y);}
    for(y=0.0; y<=3.0; y+=1)
    {x=4.0; fprintf(fp, "%f\t %f\n", x, y);}
    for(x=0.0; x<=4.0; x+=1)
    {y=(3.0/4.0)*x; fprintf(fp, "%f\t %f\n", x, y);}
    fclose(fp);
}