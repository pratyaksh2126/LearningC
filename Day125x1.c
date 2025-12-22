#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void display(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nRoll: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}

void sortByMarks(struct Student s[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].marks < s[j].marks) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    struct Student s[3];

    for (int i = 0; i < 3; i++) {
        printf("\nEnter roll, name, marks: ");
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);
    }

    sortByMarks(s, 3);

    printf("\nStudents sorted by marks:");
    display(s, 3);

    return 0;
}
