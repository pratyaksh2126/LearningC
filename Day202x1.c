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
    struct Node *slow = head, *fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    if(fast == NULL || fast->next == NULL)
        return;

    slow = head;

    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}

int main(){
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    head->next->next->next->next = head->next;

    removeLoop(head);

    printf("Loop removed");
    return 0;
}