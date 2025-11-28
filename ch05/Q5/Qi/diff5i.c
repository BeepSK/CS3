#include<stdio.h>
#include<math.h>
#define f(t, x, y, z, a) (10.0*((y)-(x)))
#define g(t, x, y, z, a) ((x)*((a)-(z))-(y))
#define h(t, x, y, z, a) ((x)*(y)-(8.0/3.0)*(z))

int main()
{
    double x=1.0, y=1.0, z=1.0, h=0.01, ti, tf=50.0;
    double k1, k2, k3, k4, m1, m2, m3, m4, l1, l2, l3, l4;
    FILE*fp=NULL;
    fp=fopen("diff5i.txt", "w");
    double a=5.0; 
    for(ti=0.0; ti<=tf; ti+=h)
    {
            k1=h*f(ti, x, y, z, a);
            m1=h*g(ti, x, y, z, a);
            l1=h*h(ti, x, y, z, a);
            k2=h*f(ti+h/2.0, x+k1/2.0, y+m1/2.0, z+k1/2.0, a);
            m2=h*g(ti+h/2.0, x+k1/2.0, y+m1/2.0, z+m1/2.0, a);
            l2=h*h(ti+h/2.0, x+k1/2.0, y+m1/2.0, z+l1/2.0, a);
            k3=h*f(ti+h/2.0, x+k2/2.0, y+m2/2.0, z+k2/2.0, a);
            m3=h*g(ti+h/2.0, x+k2/2.0, y+m2/2.0, z+m2/2.0, a);
            l3=h*h(ti+h/2.0, x+k1/2.0, y+m1/2.0, z+l2/2.0, a);
            k4=h*f(ti+h, x+k3, y+m3, z+k3, a);
            m4=h*g(ti+h, x+k3, y+m3, z+m3, a);
            l4=h*h(ti+h, x+k3, y+m3, z+l3, a);
            x+=(k1+2.0*k2+2.0*k3+k4)/6.0;
            y+=(m1+2.0*m2+2.0*m3+m4)/6.0;
            z+=(l1+2.0*l2+2.0*l3+l4)/6.0;
            ti+=h;
            fprintf(fp, "%lf\t %lf\t %lf\t %lf\n", ti, x, y, z);
        }
    fclose(fp);
}