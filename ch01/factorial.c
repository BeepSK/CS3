//Make a routine or a subroutine for calculating factorials
#include<stdio.h>
#include<math.h>

int factorial(int x)
{
    if(x<0)
    {return -1;}
    int result = 1;
    do
    {
        result*=x;
        x--;
    } while(x>0);
    return result;
}

int main()
{
    int a;
    printf("What's the number? \n");
    scanf("%d", &a);
    printf("The factorial of a is %d.\n", factorial(a));
}
