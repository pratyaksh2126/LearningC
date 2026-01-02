#include <stdio.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    struct Employee e;
    FILE *fp;
    int n, i;

    fp = fopen("employee.txt", "w");

    if(fp == NULL) {
        printf("File error");
        return 0;
    }

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &e.id);
        printf("Name: ");
        scanf("%s", e.name);
        printf("Salary: ");
        scanf("%f", &e.salary);

        fprintf(fp, "%d %s %.2f\n", e.id, e.name, e.salary);
    }

    fclose(fp);

    printf("\nEmployee records saved successfully");

    return 0;
}
