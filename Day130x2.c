#include <stdio.h>

// Structure definition
struct Employee {
    int id;
    char name[50];
    float basicSalary;
};

// Function to calculate total salary
float calculateSalary(struct Employee e) {
    float hra = 0.20 * e.basicSalary;
    float da  = 0.10 * e.basicSalary;
    return e.basicSalary + hra + da;
}

int main() {
    struct Employee emp;
    float totalSalary;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Name: ");
    scanf("%s", emp.name);
    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basicSalary);

    totalSalary = calculateSalary(emp);

    printf("\n--- Employee Details ---\n");
    printf("ID   : %d\n", emp.id);
    printf("Name : %s\n", emp.name);
    printf("Total Salary: %.2f\n", totalSalary);

    return 0;
}
