#include <stdio.h>

void swap(void *ptr1, void *ptr2, size_t size) {
    char *temp = (char *)malloc(size);
    
    // Copy contents of ptr1 to temp
    memcpy(temp, ptr1, size);
    
    // Copy contents of ptr2 to ptr1
    memcpy(ptr1, ptr2, size);
    
    // Copy contents of temp to ptr2
    memcpy(ptr2, temp, size);
    
    free(temp);
}

int main() {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("After swap: a = %d, b = %d\n", a, b);
    
    double x = 1.23, y = 4.56;
    printf("Before swap: x = %lf, y = %lf\n", x, y);
    swap(&x, &y, sizeof(double));
    printf("After swap: x = %lf, y = %lf\n", x, y);
    
    return 0;
}