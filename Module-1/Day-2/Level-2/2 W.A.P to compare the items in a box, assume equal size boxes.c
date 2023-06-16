#include <stdio.h>

int compare_boxes(int box_a[], int box_b[], int size) {
    int i, j, found;
    
    // Check if the boxes have equal lengths
    for (i = 0; i < size; i++) {
        found = 0;
        for (j = 0; j < size; j++) {
            if (box_a[i] == box_b[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int box_a[] = {200, 10, -90};
    int box_b[] = {-90, 200, 10};
    int size = sizeof(box_a) / sizeof(box_a[0]);
    
    int result = compare_boxes(box_a, box_b, size);
    printf("%d\n", result);
    
    return 0;
}