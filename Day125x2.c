#include <stdio.h>

void insert(int arr[], int *n) {
    int pos, val;
    printf("Enter position and value: ");
    scanf("%d %d", &pos, &val);

    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = val;
    (*n)++;
}

void delete(int arr[], int *n) {
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[50], n = 5, choice;

    printf("Enter 5 elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(arr, &n); break;
            case 2: delete(arr, &n); break;
            case 3: display(arr, n); break;
        }
    } while (choice != 4);

    return 0;
}
