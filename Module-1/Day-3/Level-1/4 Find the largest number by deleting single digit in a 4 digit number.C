#include <stdio.h>

// Function to find the largest number by deleting a single digit
int findLargestNumber(int num) {
    int largest = 0;
    
    // Convert the number to a string for easier manipulation
    char numStr[5];
    snprintf(numStr, sizeof(numStr), "%d", num);
    
    // Iterate through each position and remove the digit
    for (int i = 0; i < 4; i++) {
        // Create a temporary string to store the modified number
        char tempStr[4];
        int tempIndex = 0;
        
        // Construct the modified number by excluding the digit at position i
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                tempStr[tempIndex] = numStr[j];
                tempIndex++;
            }
        }
        
        tempStr[tempIndex] = '\0'; // Add null terminator
        
        // Convert the modified string back to an integer
        int tempNum = atoi(tempStr);
        
        // Compare and update the largest number if necessary
        if (tempNum > largest) {
            largest = tempNum;
        }
    }
    
    return largest;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    
    int largestNum = findLargestNumber(num);
    printf("Largest number after deleting a single digit: %d\n", largestNum);
    
    return 0;
}
