#include <stdio.h>
#include <string.h>

void bubbleSort(char *arr[], int size) {
    int i, j;
    char *temp;
    int swapped;

    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no swapping occurred in the inner loop, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    char *names[] = {
        "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
    };
    int size = sizeof(names) / sizeof(names[0]);

    bubbleSort(names, size);

    printf("Sorted names:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
