//Calculated roots (only real)
#include<stdio.h>
#include<math.h>

int main()
{
    double a, b, c, D, r1, r2;
    printf("Values of a, b, c: (Leave a gap but not a comma.) \n");
    scanf("%lf %lf %lf", &a, &b, &c);
    D = ((b*b)-(4*a*c));
    if(D>=0)
    {
        printf("The roots are real.\n");
        r1 = (-b+pow(D, 0.5))/(2*a);
        r2 = (-b-pow(D, 0.5))/(2*a);
        printf("The roots are %.2lf and %.2lf.\n", r1, r2);
    }
    else {printf("The roots are not real.\n");}
}
