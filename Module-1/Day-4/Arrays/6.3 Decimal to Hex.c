#include<stdio.h>

void convert (int num)
{
  char hexa[100];
  int i = 0;
  while (num != 0)
    {
      int rem = 0;


      rem = num % 16;

      if (rem < 10) { hexa[i] = rem + 48; i++; } 
      else
	{
	  hexa[i] = rem + 55;
	  i++;
	}
      num = num / 16;
    }
    printf ("Hexadecimal:");
    for (int j = i- 1; j >= 0; j--)
        printf ("%c" , hexa[j]);
}

int main ()
{
  int decimal = 1457;
  convert (decimal);
  return 0;
}