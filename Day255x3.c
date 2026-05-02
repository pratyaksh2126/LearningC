#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, idx;
} Pair;

void merge(Pair* arr, int l, int m, int r, int* count) {
    int i = l, j = m + 1, k = 0, rightCount = 0;
    Pair* temp = (Pair*)malloc((r - l + 1) * sizeof(Pair));

    while (i <= m && j <= r) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= m) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        arr[i] = temp[k];

    free(temp);
}

void mergeSort(Pair* arr, int l, int r, int* count) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m, count);
    mergeSort(arr, m + 1, r, count);
    merge(arr, l, m, r, count);
}

int main() {
    int n;
    scanf("%d", &n);

    Pair* arr = malloc(n * sizeof(Pair));
    int* count = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1, count);

    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    return 0;
}