#include <stdio.h>

// Function to set a specific bit in an 8-bit number
unsigned char setBit(unsigned char num, int pos) {
    return num | (1 << pos);
}

// Function to clear a specific bit in an 8-bit number
unsigned char clearBit(unsigned char num, int pos) {
    return num & ~(1 << pos);
}

// Function to toggle a specific bit in an 8-bit number
unsigned char toggleBit(unsigned char num, int pos) {
    return num ^ (1 << pos);
}

int main() {
    unsigned char num = 0b10101010; // Example 8-bit number
    
    printf("Original number: 0x%02X\n", num);
    
    // Set bit at position 3
    num = setBit(num, 3);
    printf("After setting bit 3: 0x%02X\n", num);
    
    // Clear bit at position 5
    num = clearBit(num, 5);
    printf("After clearing bit 5: 0x%02X\n", num);
    
    // Toggle bit at position 2
    num = toggleBit(num, 2);
    printf("After toggling bit 2: 0x%02X\n", num);
    
    return 0;
}
