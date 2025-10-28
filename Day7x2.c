#include <stdio.h>
#include <math.h>

int main() {
    double base, exp;
    printf("Enter base and exponent: ");
    scanf("%lf %lf", &base, &exp);
    printf("%.2lf raised to %.2lf is %.2lf\n", base, exp, pow(base, exp));
    return 0;
}
