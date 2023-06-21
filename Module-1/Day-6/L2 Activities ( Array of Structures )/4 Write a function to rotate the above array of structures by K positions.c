#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void rotateStudents(struct Student* students, int numStudents, int k) {
    // Check if the rotation is required and the number of positions is valid
    if (k > 0 && k <= numStudents) {
        // Create a temporary array to store the rotated students
        struct Student* tempStudents = (struct Student*)malloc(numStudents * sizeof(struct Student));
        
        // Copy the students to the temporary array in the rotated order
        for (int i = 0; i < numStudents; i++) {
            int rotatedIndex = (i + k) % numStudents;
            tempStudents[rotatedIndex] = students[i];
        }
        
        // Copy the rotated students back to the original array
        memcpy(students, tempStudents, numStudents * sizeof(struct Student));
        
        // Free the temporary array
        free(tempStudents);
    }
}

void displayStudents(const struct Student* students, int numStudents) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();  // Clearing the newline character from the input buffer

    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    printf("Enter the student details (rollno name marks) separated by spaces:\n");

    for (int i = 0; i < numStudents; i++) {
        scanf("%d %s %f", &students[i].rollno, students[i].name, &students[i].marks);
        getchar();  // Clearing the newline character from the input buffer
    }

    // Display the original array of structures
    printf("Original Array of Structures:\n");
    displayStudents(students, numStudents);

    // Get the number of positions to rotate from the user
    int k;
    printf("\nEnter the number of positions to rotate: ");
    scanf("%d", &k);

    // Rotate the array of structures
    rotateStudents(students, numStudents, k);

    // Display the updated array of structures
    printf("\nUpdated Array of Structures:\n");
    displayStudents(students, numStudents);

    free(students);  // Freeing the allocated memory

    return 0;
}
