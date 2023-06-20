#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {

	char hexdecnumber[17] = "2D";
	long long decimalnumber, place;
	int i = 0, val, len;

	decimalnumber = 0;
	place = 1;

	len = strlen(hexdecnumber);
	len--;

	for (i = 0; hexdecnumber[i] != '\0'; i++) {

		if (hexdecnumber[i] >= '0'
			&& hexdecnumber[i] <= '9') {
			val = hexdecnumber[i] - 48;
		}
		else if (hexdecnumber[i] >= 'a'
				&& hexdecnumber[i] <= 'f') {
			val = hexdecnumber[i] - 97 + 10;
		}
		else if (hexdecnumber[i] >= 'A'
				&& hexdecnumber[i] <= 'F') {
			val = hexdecnumber[i] - 65 + 10;
		}

		decimalnumber += val * pow(16, len);
		len--;
	}

	printf("Hexadecimal number = %s\n", hexdecnumber);
	printf("Decimal number = %lld", decimalnumber);
	return 0;
}
