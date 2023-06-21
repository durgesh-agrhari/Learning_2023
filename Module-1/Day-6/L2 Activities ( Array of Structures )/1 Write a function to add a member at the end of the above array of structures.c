#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

struct Student* addStudent(struct Student* students, int* numStudents) {
    (*numStudents)++;  // Increment the total number of students

    struct Student* newStudents = (struct Student*)realloc(students, (*numStudents) * sizeof(struct Student));
    if (newStudents == NULL) {
        printf("Memory allocation failed. Unable to add student.\n");
        return students;
    }

    printf("\nEnter the student details (rollno name marks) separated by spaces:\n");
    struct Student* newStudent = &newStudents[(*numStudents) - 1];
    scanf("%d %s %f", &(newStudent->rollno), newStudent->name, &(newStudent->marks));
    getchar();  // Clearing the newline character from the input buffer

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

    // Add a member at the end of the array of structures
    students = addStudent(students, &numStudents);

    // Display the updated array of structures
    displayStudents(students, numStudents);

    free(students);  // Freeing the allocated memory

    return 0;
}
