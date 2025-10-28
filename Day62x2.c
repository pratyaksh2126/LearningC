#include <stdio.h>
void rotateLeft(int arr[], int n, int d) {
    for(int i=0; i<d; i++) {
        int temp = arr[0];
        for(int j=0; j<n-1; j++) arr[j] = arr[j+1];
        arr[n-1] = temp;
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;
    rotateLeft(arr, n, d);
    printf("After rotation: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}
