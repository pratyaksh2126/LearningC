#include <stdio.h>

int main() {
    float cm;
    printf("Enter distance in cm: ");
    scanf("%f", &cm);
    printf("%.2f cm is %.2f inches\n", cm, cm / 2.54);
    return 0;
}
