#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void swapFields(struct Person* p1, struct Person* p2) {
    struct Person temp;
    
    // Swap name fields
    strcpy(temp.name, p1->name);
    strcpy(p1->name, p2->name);
    strcpy(p2->name, temp.name);
    
    // Swap age fields
    temp.age = p1->age;
    p1->age = p2->age;
    p2->age = temp.age;
}

int main() {
    struct Person person1, person2;
    
    printf("Enter details for Person 1:\n");
    printf("Name: ");
    scanf("%s", person1.name);
    printf("Age: ");
    scanf("%d", &person1.age);
    
    printf("\nEnter details for Person 2:\n");
    printf("Name: ");
    scanf("%s", person2.name);
    printf("Age: ");
    scanf("%d", &person2.age);
    
    printf("\nBefore swapping:\n");
    printf("Person 1:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("\nPerson 2:\n");
    printf("Name: %s\n", person2.name);
    printf("Age: %d\n", person2.age);
    
    swapFields(&person1, &person2);
    
    printf("\nAfter swapping:\n");
    printf("Person 1:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("\nPerson 2:\n");
    printf("Name: %s\n", person2.name);
    printf("Age: %d\n", person2.age);
    
    return 0;
}
