#include <stdio.h>
#include <math.h>
int main() {
    double principal, rate, time, amount;
    printf("Enter principal, rate (%%), and time: ");
    scanf("%lf%lf%lf", &principal, &rate, &time);
    amount = principal * pow((1 + rate / 100), time);
    printf("Compound Interest: %.2lf\n", amount - principal);
    return 0;
}
