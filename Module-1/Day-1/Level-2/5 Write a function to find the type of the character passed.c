#include <stdio.h>

int findCharacterType(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return 1;  // Uppercase letter
    } else if (ch >= 'a' && ch <= 'z') {
        return 2;  // Lowercase letter
    } else if (ch >= '0' && ch <= '9') {
        return 3;  // Digit
    } else if (ch >= 32 && ch <= 126) {
        return 4;  // Printable symbol
    } else {
        return 5;  // Non-printable symbol
    }
}

int main() {
    char character;

    printf("Enter a character: ");
    scanf(" %c", &character);

    int type = findCharacterType(character);

    switch (type) {
        case 1:
            printf("Type: Uppercase letter\n");
            break;
        case 2:
            printf("Type: Lowercase letter\n");
            break;
        case 3:
            printf("Type: Digit\n");
            break;
        case 4:
            printf("Type: Printable symbol\n");
            break;
        case 5:
            printf("Type: Non-printable symbol\n");
            break;
        default:
            printf("Type: Unknown\n");
            break;
    }

    return 0;
}
