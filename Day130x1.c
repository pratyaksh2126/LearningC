#include <stdio.h>

// Structure definition
struct Student {
    int roll;
    char name[50];
    float marks;
};

// Function to input student details
struct Student inputStudent() {
    struct Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    return s;
}

// Function to display student details
void displayStudent(struct Student s) {
    printf("\n--- Student Details ---\n");
    printf("Roll No: %d\n", s.roll);
    printf("Name   : %s\n", s.name);
    printf("Marks : %.2f\n", s.marks);
}

int main() {
    struct Student s1;
    s1 = inputStudent();
    displayStudent(s1);
    return 0;
}
