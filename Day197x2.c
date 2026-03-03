#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverse(struct Node* head) {
    if(head == NULL || head->next == NULL)
        return head;

    struct Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main() {
    int n, i, value;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    head = reverse(head);

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}