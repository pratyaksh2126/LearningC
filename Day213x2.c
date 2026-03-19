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

void heapifyUp(Node* heap, int i) {
    while (i > 0 && heap[(i - 1)/2].freq > heap[i].freq) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void heapifyDown(Node* heap, int size, int i) {
    int smallest = i;
    int l = 2*i+1, r = 2*i+2;

    if (l < size && heap[l].freq < heap[smallest].freq) smallest = l;
    if (r < size && heap[r].freq < heap[smallest].freq) smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int freq[RANGE] = {0};

    for (int i = 0; i < numsSize; i++)
        freq[nums[i] + OFFSET]++;

    Node* heap = (Node*)malloc(k * sizeof(Node));
    int size = 0;

    for (int i = 0; i < RANGE; i++) {
        if (freq[i] > 0) {
            Node node = {i - OFFSET, freq[i]};

            if (size < k) {
                heap[size] = node;
                heapifyUp(heap, size++);
            } else if (node.freq > heap[0].freq) {
                heap[0] = node;
                heapifyDown(heap, size, 0);
            }
        }
    }

    int* res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
        res[i] = heap[i].val;

    *returnSize = k;
    return res;
}