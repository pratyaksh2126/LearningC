#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head,int x){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;

    if(head==NULL)
        return newNode;

    struct Node* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
    return head;
}

struct Node* removeElements(struct Node* head,int val){
    while(head!=NULL && head->data==val){
        struct Node* t=head;
        head=head->next;
        free(t);
    }

    struct Node* curr=head;

    while(curr!=NULL && curr->next!=NULL){
        if(curr->next->data==val){
            struct Node* t=curr->next;
            curr->next=curr->next->next;
            free(t);
        }
        else
            curr=curr->next;
    }

    return head;
}

void display(struct Node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    int n,x,val;
    struct Node* head=NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        head=insertEnd(head,x);
    }

    scanf("%d",&val);

    head=removeElements(head,val);

    display(head);

    return 0;
}