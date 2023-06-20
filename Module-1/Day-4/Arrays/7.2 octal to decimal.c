#include <math.h>
#include <stdio.h>

int main()
{
	int octalnumber = 123, decimalnumber = 0;
	int i = 0;

	while (octalnumber != 0)
	{	

		decimalnumber = decimalnumber
						+ (octalnumber % 10) * pow(8, i++);
		octalnumber = octalnumber / 10;
	}

	printf("decimal number is: %d", decimalnumber);
	return 0;
}
