#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encode the string
char* encode(const char* str) {
    int length = strlen(str);
    char* encoded = (char*)malloc((length + 1) * sizeof(char));
    
    for (int i = 0; i < length; i++) {
        // Perform character substitution (you can modify this logic as needed)
        encoded[i] = str[i] + 1;
    }
    
    encoded[length] = '\0'; // Add null terminator
    
    return encoded;
}

// Function to decode the string
char* decode(const char* encoded) {
    int length = strlen(encoded);
    char* decoded = (char*)malloc((length + 1) * sizeof(char));
    
    for (int i = 0; i < length; i++) {
        // Perform character reverse substitution (you can modify this logic as needed)
        decoded[i] = encoded[i] - 1;
    }
    
    decoded[length] = '\0'; // Add null terminator
    
    return decoded;
}

int main() {
    char str[100];
    printf("Enter a string to encode: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character
    
    char* encoded = encode(str);
    printf("Encoded string: %s\n", encoded);
    
    char* decoded = decode(encoded);
    printf("Decoded string: %s\n", decoded);
    
    free(encoded);
    free(decoded);
    
    return 0;
}
