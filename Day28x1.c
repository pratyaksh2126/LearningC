#include <stdio.h>
int main() {
    int arr[] = {5, 3, 8, 4, 2}, n = 5, temp;
    for(int i = 0; i < n-1; i++) {
        for(int j=0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp=arr[j]; arr[j]=arr[j+1]; arr[j+1]=temp;
            }
        }
    }
    printf("Sorted array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
