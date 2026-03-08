#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void removeLoop(struct Node* head){
    struct Node *ptr1 = head, *ptr2;

    while(ptr1 != NULL){
        ptr2 = ptr1;

        while(ptr2->next != NULL && ptr2->next != ptr1)
            ptr2 = ptr2->next;

        if(ptr2->next == ptr1){
            ptr2->next = NULL;
            return;
        }

        ptr1 = ptr1->next;
    }
}

int main(){
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    head->next->next->next->next = head;

    removeLoop(head);

    printf("Loop removed");
    return 0;
}