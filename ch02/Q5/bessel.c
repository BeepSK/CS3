#include<stdio.h>
#include<math.h>

double bessel(double z, int n)
{
    int i; double j0, j1, j2;
    if(n==0)
    {return (sin(z)/z);}
    else if(n==1)
    {return ((sin(z)/(z*z))-(cos(z)/z));}
    j0 = (sin(z)/z);
    j1 = ((sin(z)/(z*z))-(cos(z)/z));
    for(i=1; i<n; i+=1)
        {
            j2 = ((2*i+1)*(j1)/z)-j0;
            j0=j1;
            j1=j2;
        }
    return j2;
}

int main()
{
    double z;
    FILE*fp=NULL;
    fp=fopen("bessel.txt", "w");
    for(z=0.0; z<=5.0; z+=0.01)
    {
        fprintf(fp, "%lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n", z, bessel(z,0),
        bessel(z,1), bessel(z,2), bessel(z,3), bessel(z,4), bessel(z,5));
    }
    fclose(fp);
}
