#include <stdio.h>

// Function to print the bits of a 32-bit integer
void printBits(unsigned int num) {
    int i;
    // Loop through each bit position from left to right
    for (i = 31; i >= 0; i--) {
        // Get the value of the bit at position i
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);
    
    printBits(num);
    
    return 0;
}
