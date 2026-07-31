#include <stdio.h>
#include <math.h>

int main()
{
    int num, original, remainder, digits = 0;
    int result = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    while(original != 0)
    {
        digits++;
        original /= 10;
    }

    original = num;

    while(original != 0)
    {
        remainder = original % 10;
        result += pow(remainder, digits);
        original /= 10;
    }

    if(result == num)
        printf("Armstrong Number");
    else
        printf("Not Armstrong Number");

    return 0;
}