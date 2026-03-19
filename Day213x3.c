#include <stdlib.h>

#define OFFSET 10000
#define RANGE 20001

typedef struct {
    int val, freq;
} Node;

int cmp(const void* a, const void* b) {
    return ((Node*)b)->freq - ((Node*)a)->freq;
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

    qsort(arr, n, sizeof(Node), cmp);

    int* res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
        res[i] = arr[i].val;

    *returnSize = k;
    return res;
}