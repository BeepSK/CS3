#include<stdio.h>
#include<math.h>
#define pi 4.0*atan(1.0)

int main()
{
    float t, a=2.0, omega, ep=0.8, r, ctheta, f1, f2, h, x0, y0, acc=0.00001;
    FILE*fp=NULL;
    fp=fopen("root4.txt", "w");
    for(t=0.01; t<=((2.0*pi)); t+=(0.01))
    {
        omega=t;
        do
        {
            f1=omega-ep*sin(omega)-t;
            f2=1.0-ep*cos(omega);
            h= -f1/f2;
            omega+=h;
        } while(fabs(h/omega)>acc);
        r=a*(1.0-ep*cos(omega));
        ctheta=(cos(omega)-ep)/(1.0-ep*cos(omega));
        x0=r*ctheta;
        y0=r*sqrt(1.0-ctheta*ctheta);
        fprintf(fp, "%f\t %f\n", x0, y0);
        fprintf(fp, "%f\t %f\n", x0, -y0);
    }
    
}