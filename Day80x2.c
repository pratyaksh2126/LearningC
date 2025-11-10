#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    int limit = (int)sqrt((double)x);
    for (int i = 3; i <= limit; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    printf("Enter N (print primes <= N): ");
    if (scanf("%d", &N) != 1 || N < 2) {
        printf("No primes in this range.\n");
        return 1;
    }

    printf("Primes up to %d:\n", N);
    for (int i = 2; i <= N; ++i) {
        if (is_prime(i)) printf("%d ", i);
    }
    printf("\n");
    return 0;
}
