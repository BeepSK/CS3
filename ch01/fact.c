#include<stdio.h>
#include<math.h>

//Subroutine I am going to use to call the factorial function
int fact(int x)
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
