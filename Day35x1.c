#include <stdio.h>
int linearSearch(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key) return i;
    }
    return -1;
}
int main() {
    int arr[] = {5, 10, 15, 20, 25}, n=5;
    int key;
    printf("Enter key for linear search: ");
    scanf("%d", &key);
    int index = linearSearch(arr, n, key);
    if(index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");
    return 0;
}
