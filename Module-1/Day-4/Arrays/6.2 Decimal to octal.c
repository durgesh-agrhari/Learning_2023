#include<stdio.h>

void convert(int num)
{
    int octal = 0;
    int rem, i = 1;
    
    while(num!=0)
    {
        rem = num % 8;
        num /= 8;
        octal += rem * i;
        i *= 10;
    }
    printf("%d",octal);
}
 
int main()
{
    int decimal_num = 221;
    convert(decimal_num);
    return 0;
}