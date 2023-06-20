#include<stdio.h>

void convert(int num)
{
    long long binary = 0;
    int rem, i = 1;
    
    while(num!=0)
    {
        rem = num % 2;
        num /= 2;
        binary += rem * i;
        i *= 10;
    }
    printf("%d",binary);
}
 
int main()
{
    int decimal_num = 14;
    convert(decimal_num);
    return 0;
}