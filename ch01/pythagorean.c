#include<stdio.h>
#include<math.h>

int main()
{
    int a, b, c;
    FILE*fp=NULL;
    fp=fopen("")
    for(a=1; a<100; a+=1)
    {for(b=a+1; b<100; b+=1)
        {for(c=a+1; c<100; c+=1)
        {
            if(a*a+b*b==c*c)
            {printf("(%d)^2 + (%d)^2 = (%d)^2\n", a, b, c);}
        }}
    }
}