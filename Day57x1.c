#include <stdio.h>

int isLeapYear(int year) {
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int main() {
    int start, end;
    printf("Enter start and end year: ");
    scanf("%d %d", &start, &end);
    printf("Leap years between %d and %d:\n", start, end);
    for (int y = start; y <= end; y++) {
        if (isLeapYear(y))
            printf("%d ", y);
    }
    printf("\n");
    return 0;
}
