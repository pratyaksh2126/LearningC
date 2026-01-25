// Q1. Find sum of all array elements using recursion \\ 

#include <stdio.h>
int sum(int arr[], int n)
{
   if (n == 0)
     return 0;
   else
    return arr[n - 1] + sum(arr, n - 1);
}
int main()
{
    int arr[5];
    int i;
    printf("Enter 5 numbers:\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Sum = %d", sum(arr, 5));
    return 0;
}   