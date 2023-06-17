#include <stdio.h>

// Macro to convert a decimal digit to BCD
#define DEC_TO_BCD(digit) (((digit) / 10) << 4 | ((digit) % 10))

// Function to convert a decimal number to BCD format
void decimalToBCD(unsigned char decimal, unsigned char *bcdHigh, unsigned char *bcdLow) {
    *bcdHigh = DEC_TO_BCD(decimal / 10);
    *bcdLow = DEC_TO_BCD(decimal % 10);
}

int main() {
    unsigned char decimal = 59; // Example decimal number
    
    unsigned char bcdHigh, bcdLow;
    decimalToBCD(decimal, &bcdHigh, &bcdLow);
    
    printf("Decimal: %d\n", decimal);
    printf("BCD High: 0x%02X\n", bcdHigh);
    printf("BCD Low: 0x%02X\n", bcdLow);
    
    return 0;
}
