#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int width;
};

struct Rectangle* modifyRectangle(struct Rectangle* rect) {
    rect->length += 5;
    rect->width += 5;
    return rect;
}

int main() {
    struct Rectangle* myRect;
    myRect = (struct Rectangle*)malloc(sizeof(struct Rectangle));
    
    if (myRect == NULL) {
        printf("Memory allocation failed. Exiting...");
        return 1;
    }
    
    printf("Enter the length of the rectangle: ");
    scanf("%d", &(myRect->length));
    
    printf("Enter the width of the rectangle: ");
    scanf("%d", &(myRect->width));
    
    printf("\nBefore modification:\n");
    printf("Length: %d\n", myRect->length);
    printf("Width: %d\n", myRect->width);
    
    myRect = modifyRectangle(myRect);
    
    printf("\nAfter modification:\n");
    printf("Length: %d\n", myRect->length);
    printf("Width: %d\n", myRect->width);
    
    free(myRect);
    
    return 0;
}
