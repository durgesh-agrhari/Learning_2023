#include <stdio.h>

// Function to find the smallest and largest digits in a number
void findSmallestAndLargestDigits(int num, int* smallest, int* largest) {
    *smallest = 9; // Initialize smallest digit to highest possible value
    *largest = 0;  // Initialize largest digit to lowest possible value
    
    // Handle negative numbers as "Not Valid"
    if (num < 0) {
        *smallest = -1;
        *largest = -1;
        return;
    }
    
    // Process each digit in the number
    while (num != 0) {
        int digit = num % 10;
        
        // Update smallest and largest digits if necessary
        if (digit < *smallest) {
            *smallest = digit;
        }
        if (digit > *largest) {
            *largest = digit;
        }
        
        num /= 10;
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    int i, num, smallest, largest;
    for (i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);
        
        findSmallestAndLargestDigits(num, &smallest, &largest);
        
        if (smallest == -1 && largest == -1) {
            printf("Number %d: Not Valid\n", i);
        } else {
            printf("Number %d: Smallest digit: %d, Largest digit: %d\n", i, smallest, largest);
        }
    }
    
    return 0;
}
