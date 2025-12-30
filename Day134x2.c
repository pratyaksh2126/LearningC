#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}

int main() {
    int choice, a, b;

    do {
        printf("\n---- MENU ----");
        printf("\n1. Add");
        printf("\n2. Subtract");
        printf("\n3. Multiply");
        printf("\n4. Divide");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
        }

        switch(choice) {
            case 1: printf("Result = %d", add(a, b)); break;
            case 2: printf("Result = %d", subtract(a, b)); break;
            case 3: printf("Result = %d", multiply(a, b)); break;
            case 4: 
                if(b != 0)
                    printf("Result = %.2f", divide(a, b));
                else
                    printf("Division by zero not allowed");
                break;
            case 5: printf("Exiting program"); break;
            default: printf("Invalid choice");
        }
    } while(choice != 5);

    return 0;
}
