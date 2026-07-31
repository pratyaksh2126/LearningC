#include <stdio.h>

int main()
{
    int n;

    printf("Enter size: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int largest = arr[0];
    int second = arr[0];

    for(int i=1;i<n;i++)
    {
        if(arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if(arr[i] > second && arr[i] != largest)
        {
            second = arr[i];
        }
    }

    printf("Second Largest = %d", second);

    return 0;
}