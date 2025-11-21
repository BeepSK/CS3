//Calculating permutations and combinations
#include<stdio.h>
#include<math.h>
#include "fact.c" //Using the subroutine I made earlier

int main()
{
    int per, comb, n, r;
    printf("What is n and r? (Leave a gap but not a comma.) \n");
    scanf("%d %d", &n, &r);
    per = fact(n)/fact(n-r);
    comb = fact(n)/fact(r)*fact(n-r);
    printf("The permutation is %d and the combination is %d for n = %d and r = %d.\n", per, comb, n, r);
}
