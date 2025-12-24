#include <stdio.h>

struct Student {
    int roll;
    char name[30];
    float marks;
};

void input(struct Student s[], int n);
void display(struct Student s[], int n);

int main() {
    int n;
    struct Student s[50];

    printf("Enter number of students: ");
    scanf("%d", &n);

    input(s, n);
    display(s, n);

    return 0;
}

void input(struct Student s[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
}

void display(struct Student s[], int n) {
    printf("\n--- Student Records ---\n");
    for(int i = 0; i < n; i++) {
        printf("\nRoll: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}
