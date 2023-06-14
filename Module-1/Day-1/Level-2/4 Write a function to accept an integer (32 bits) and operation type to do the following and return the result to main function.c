#include <stdio.h>

int bitOperations(int num, int oper_type, int pos) {
    switch (oper_type) {
        case 1:
            num |= (1 << (pos - 1)) | (1 << (pos - 2));  // Set 2 bits from nth bit position
            break;
        case 2:
            num &= ~((1 << (pos - 1)) | (1 << (pos - 2)) | (1 << (pos - 3)));  // Clear 3 bits from nth bit position
            break;
        case 3:
            num ^= (1 << 31);  // Toggle MSB (Most Significant Bit)
            break;
        default:
            printf("Error: Invalid operation type\n");
            break;
    }
    return num;
}

int main() {
    int num, oper_type, pos;

    printf("Enter the 32-bit integer: ");
    scanf("%d", &num);

    printf("Enter the operation type (1, 2, or 3): ");
    scanf("%d", &oper_type);

    printf("Enter the position: ");
    scanf("%d", &pos);

    int result = bitOperations(num, oper_type, pos);

    printf("Modified number: %d\n", result);

    return 0;
}
