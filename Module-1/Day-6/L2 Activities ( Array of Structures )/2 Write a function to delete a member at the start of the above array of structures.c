#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

struct Student* deleteStudent(struct Student* students, int* numStudents) {
    if (*numStudents == 0) {
        printf("No students to delete.\n");
        return students;
    }

    (*numStudents)--;  // Decrement the total number of students

    struct Student* newStudents = (struct Student*)malloc((*numStudents) * sizeof(struct Student));
    if (newStudents == NULL) {
        printf("Memory allocation failed. Unable to delete student.\n");
        return students;
    }

    // Copy the remaining students to the new array
    for (int i = 0; i < *numStudents; i++) {
        newStudents[i] = students[i + 1];
    }

    free(students);  // Free memory of original array

    return newStudents;
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

    // Delete a member at the start of the array of structures
    students = deleteStudent(students, &numStudents);

    // Display the updated array of structures
    displayStudents(students, numStudents);

    free(students);  // Freeing the allocated memory

    return 0;
}
