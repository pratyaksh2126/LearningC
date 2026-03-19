#include <stdlib.h>

#define OFFSET 10000
#define RANGE 20001

typedef struct {
    int val, freq;
} Node;

void swap(Node* a, Node* b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

int partition(Node* arr, int left, int right) {
    int pivot = arr[right].freq;
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j].freq > pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

void quickSelect(Node* arr, int left, int right, int k) {
    if (left < right) {
        int pi = partition(arr, left, right);
        if (pi == k) return;
        else if (pi < k) quickSelect(arr, pi + 1, right, k);
        else quickSelect(arr, left, pi - 1, k);
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int freq[RANGE] = {0};

    for (int i = 0; i < numsSize; i++)
        freq[nums[i] + OFFSET]++;

    Node arr[RANGE];
    int n = 0;

    for (int i = 0; i < RANGE; i++) {
        if (freq[i] > 0) {
            arr[n].val = i - OFFSET;
            arr[n].freq = freq[i];
            n++;
        }
    }

    quickSelect(arr, 0, n - 1, k);

    int* res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
        res[i] = arr[i].val;

    *returnSize = k;
    return res;
}