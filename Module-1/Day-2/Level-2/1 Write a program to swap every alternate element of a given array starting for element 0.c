#include <stdio.h>

void swap_alternate_elements(int arr[], int length) {
    for (int i = 0; i < length - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

int main() {
    int array1[] = {10, 20, 30, 40, 50};
    int length1 = sizeof(array1) / sizeof(array1[0]);
    
    swap_alternate_elements(array1, length1);
    
    printf("Modified Array 1: ");
    for (int i = 0; i < length1; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");
    
    int array2[] = {10, 20, 30, 40, 50, 60};
    int length2 = sizeof(array2) / sizeof(array2[0]);
    
    swap_alternate_elements(array2, length2);
    
    printf("Modified Array 2: ");
    for (int i = 0; i < length2; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");
    
    return 0;
}
