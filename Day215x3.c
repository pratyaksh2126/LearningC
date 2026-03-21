#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int extractMax(int arr[], int *n) {
    if (*n <= 0) return 0;
    int root = arr[0];
    arr[0] = arr[--(*n)];
    heapify(arr, *n, 0);
    return root;
}

void insert(int arr[], int *n, int val) {
    arr[(*n)++] = val;
    int i = *n - 1;
    while (i && arr[(i-1)/2] < arr[i]) {
        swap(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};
    for (int i = 0; i < size; i++)
        freq[tasks[i] - 'A']++;

    int heap[26], hsize = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            heap[hsize++] = freq[i];

    buildHeap(heap, hsize);

    int time = 0;

    while (hsize > 0) {
        int temp[26], tsize = 0;
        int cycle = n + 1;

        while (cycle-- && hsize > 0) {
            int val = extractMax(heap, &hsize);
            if (val - 1 > 0)
                temp[tsize++] = val - 1;
            time++;
        }

        for (int i = 0; i < tsize; i++)
            insert(heap, &hsize, temp[i]);

        if (hsize == 0) break;

        time += cycle + 1;
    }

    return time;
}

int main() {
    int n, cooldown;
    scanf("%d", &n);

    char tasks[n];
    for (int i = 0; i < n; i++)
        scanf(" %c", &tasks[i]);

    scanf("%d", &cooldown);

    printf("%d\n", leastInterval(tasks, n, cooldown));
    return 0;
}