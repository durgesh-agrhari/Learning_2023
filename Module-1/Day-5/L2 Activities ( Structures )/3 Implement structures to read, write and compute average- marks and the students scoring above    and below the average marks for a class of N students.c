#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    float marks;
};

void readStudentData(struct Student* students, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        
        printf("Name: ");
        scanf("%s", students[i].name);
        
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
}

void writeStudentData(struct Student* students, int n) {
    printf("\nStudent details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

float calculateAverageMarks(struct Student* students, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].marks;
    }
    return sum / n;
}

void printStudentsAboveAverage(struct Student* students, int n, float averageMarks) {
    printf("\nStudents scoring above average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks > averageMarks) {
            printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
        }
    }
}

void printStudentsBelowAverage(struct Student* students, int n, float averageMarks) {
    printf("\nStudents scoring below average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks < averageMarks) {
            printf("Name: %s, Marks: %.2f\n", students[i].name, students[i].marks);
        }
    }
}

int main() {
    int n;
    struct Student* students;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    students = (struct Student*)malloc(n * sizeof(struct Student));
    
    if (students == NULL) {
        printf("Memory allocation failed. Exiting...");
        return 1;
    }
    
    readStudentData(students, n);
    
    writeStudentData(students, n);
    
    float averageMarks = calculateAverageMarks(students, n);
    printf("\nAverage Marks: %.2f\n", averageMarks);
    
    printStudentsAboveAverage(students, n, averageMarks);
    
    printStudentsBelowAverage(students, n, averageMarks);
    
    free(students);
    
    return 0;
}
