#include <stdio.h>

int main() {
    float temp;
    char unit;

    printf("Enter temperature with unit (e.g., 100 C or 212 F): ");
    scanf("%f %c", &temp, &unit);

    if (unit == 'C' || unit == 'c')
        printf("%.2f C = %.2f F\n", temp, (temp * 9 / 5) + 32);
    else if (unit == 'F' || unit == 'f')
        printf("%.2f F = %.2f C\n", temp, (temp - 32) * 5 / 9);
    else
        printf("Invalid unit\n");

    return 0;
}
