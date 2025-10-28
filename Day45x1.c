#include <stdio.h>
struct Student {
    int id;
    char name[50];
    float marks;
};
int main() {
    struct Student s1;
    printf("Enter student id, name, and marks: ");
    scanf("%d %s %f", &s1.id, s1.name, &s1.marks);
    printf("Student info: %d %s %.2f\n", s1.id, s1.name, s1.marks);
    return 0;
}
