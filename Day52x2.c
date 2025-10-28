#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == startIndex) {
            printf("Hash Table is full\n");
            return;
        }
    }
    hashTable[index] = key;
}

int search(int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return index;
        index = (index + 1) % SIZE;
        if (index == startIndex) return -1;
    }
    return -1;
}

int main() {
    for(int i = 0; i < SIZE; i++) hashTable[i] = -1;
    insert(10); insert(20); insert(30); insert(40);
    int key = 20;
    int idx = search(key);
    if(idx != -1)
        printf("Key %d found at index %d\n", key, idx);
    else
        printf("Key %d not found\n", key);
    return 0;
}
