#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

void display(struct Student s)
{
    printf("\nRoll No: %d", s.roll);
    printf("\nName: %s", s.name);
    printf("\nMarks: %.2f", s.marks);
}

int main()
{
    struct Student s;

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    printf("\n--- Student Details ---");
    display(s);

    if (s.marks >= 40)
        printf("\nStatus: PASS");
    else
        printf("\nStatus: FAIL");

    return 0;
}
