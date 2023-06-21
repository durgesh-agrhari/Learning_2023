#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    float distance;
    distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return distance;
}

int main() {
    struct Point point1, point2;
    
    printf("Enter the coordinates for Point 1:\n");
    printf("x: ");
    scanf("%f", &point1.x);
    printf("y: ");
    scanf("%f", &point1.y);
    
    printf("\nEnter the coordinates for Point 2:\n");
    printf("x: ");
    scanf("%f", &point2.x);
    printf("y: ");
    scanf("%f", &point2.y);
    
    float distance = calculateDistance(point1, point2);
    
    printf("\nDistance between Point 1 and Point 2: %.2f\n", distance);
    
    return 0;
}
