#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
struct Node* push(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}
int main() {
    struct Node* head = NULL;
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    printf("Original Linked list: ");
    printList(head);
    head = reverse(head);
    printf("Reversed Linked list: ");
    printList(head);
    return 0;
}
