/*Some integers have a property that they are divisible by the sum of their digits. Thus, 84 is one 
such number since it is divisible by 8 + 4 = 12. Let us call them Harshad numbers. Write a
program to nd all the Harshad numbers between 50 and 70 both inclusive. */
#include<stdio.h>
#include<math.h>

int harshad(int num)
{
    int ones, tens, sum, div;
    ones = num%10;
    tens = num/10;
    sum = ones+tens;
    div = num%sum;
    if(div==0)
    {return 1;}
    else {return 0;}
}

int main()
{
    int n;
    printf("Gimme the number: \n"); //For checking any number of our choice
    scanf("%d", &n);
    if(harshad(n))
    {printf("%d is a Harshad number.\n", n);}
    for(n=50; n<=71; n+=1) //For a specific range
    {
        if(harshad(n))
        {printf("In the range between 50 and 70, %d is a Harshad number.\n", n);}
    }
}
