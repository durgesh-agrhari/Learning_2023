#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void swapStudents(struct Student* students, int index1, int index2) {
    struct Student temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
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

    // Get the indexes of the students to swap from the user
    int index1, index2;
    printf("\nEnter the indexes (0 to %d) of the students to swap: ", numStudents - 1);
    scanf("%d %d", &index1, &index2);

    // Check if the entered indexes are valid
    if (index1 >= 0 && index1 < numStudents && index2 >= 0 && index2 < numStudents) {
        // Swap the students at the given indexes
        swapStudents(students, index1, index2);

        // Display the updated array of structures
        printf("\nUpdated Array of Structures:\n");
        displayStudents(students, numStudents);
    } else {
        printf("\nInvalid indexes entered.\n");
    }

    free(students);  // Freeing the allocated memory

    return 0;
}
