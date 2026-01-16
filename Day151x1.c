#include <stdio.h>

int main() {
    int n, i;
    int largest, secondLargest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = secondLargest = -999999;

    for(i = 0; i < n; i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if(arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    printf("Second Largest Element = %d\n", secondLargest);

    return 0;
}
