#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseInputString(const char* inputString, struct Student* students, int numStudents) {
    const char* delimiter = " ";
    char* token = strtok((char*)inputString, delimiter);

    for (int i = 0; i < numStudents; i++) {
        if (token == NULL) {
            printf("Error: Insufficient input!\n");
            return;
        }

        students[i].rollno = atoi(token);

        token = strtok(NULL, delimiter);

        if (token == NULL) {
            printf("Error: Insufficient input!\n");
            return;
        }

        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';

        token = strtok(NULL, delimiter);

        if (token == NULL) {
            printf("Error: Insufficient input!\n");
            return;
        }

        students[i].marks = atof(token);

        token = strtok(NULL, delimiter);
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
        char inputString[100];
        fgets(inputString, sizeof(inputString), stdin);
        inputString[strcspn(inputString, "\n")] = '\0';  // Removing the trailing newline character

        parseInputString(inputString, &students[i], 1);
    }

    // Print the initialized array of structures
    printf("\nStudent Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    free(students);  // Freeing the allocated memory

    return 0;
}
    