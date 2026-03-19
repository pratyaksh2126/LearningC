#include <stdlib.h>

#define OFFSET 10000
#define RANGE 20001

struct Node {
    int val;
    struct Node* next;
};

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int *freq = (int*)calloc(RANGE, sizeof(int));

    for (int i = 0; i < numsSize; i++)
        freq[nums[i] + OFFSET]++;

    struct Node** bucket = (struct Node**)calloc(numsSize + 1, sizeof(struct Node*));

    for (int i = 0; i < RANGE; i++) {
        if (freq[i] > 0) {
            int f = freq[i];
            struct Node* node = (struct Node*)malloc(sizeof(struct Node));
            node->val = i - OFFSET;
            node->next = bucket[f];
            bucket[f] = node;
        }
    }

    int *res = (int*)malloc(k * sizeof(int));
    int count = 0;

    for (int i = numsSize; i >= 0 && count < k; i--) {
        struct Node* cur = bucket[i];
        while (cur && count < k) {
            res[count++] = cur->val;
            cur = cur->next;
        }
    }

    *returnSize = k;
    return res;
}