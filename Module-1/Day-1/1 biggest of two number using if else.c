#include<stdio.h>

int main()
{
    int a,b;
    scanf("%d%d", &a,&b);
    
    if(a>b)
    {
        printf("A is greater",a);
    }
    else
    {
        printf("B is greater",b);
    }
    return 0;
}