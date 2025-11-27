#include <stdio.h>

float add(float a, float b) { return a + b; }
float sub(float a, float b) { return a - b; }
float mul(float a, float b) { return a * b; }
float div(float a, float b) { return (b != 0) ? a / b : 0; }

int main() {
    int choice;
    float x, y;

    do {
        printf("\n--- Calculator Menu ---\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            scanf("%f %f", &x, &y);
        }

        switch(choice) {
            case 1: printf("Result: %.2f\n", add(x, y)); break;
            case 2: printf("Result: %.2f\n", sub(x, y)); break;
            case 3: printf("Result: %.2f\n", mul(x, y)); break;
            case 4: printf("Result: %.2f\n", div(x, y)); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid Choice!\n");
        }
    } while(choice != 5);

    return 0;
}
