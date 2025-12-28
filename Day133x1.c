#include <stdio.h>

struct Student {
    int roll;
    char name[30];
    float marks[3];
};

float calculateAverage(float m[]) {
    return (m[0] + m[1] + m[2]) / 3;
}

int main() {
    struct Student s;
    int i;

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter marks of 3 subjects:\n");
    for (i = 0; i < 3; i++) {
        scanf("%f", &s.marks[i]);
    }

    printf("\n--- Student Details ---\n");
    printf("Roll: %d\nName: %s\nAverage Marks: %.2f\n",
           s.roll, s.name, calculateAverage(s.marks));

    return 0;
}
