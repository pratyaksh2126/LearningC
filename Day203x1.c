#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* reverse(struct Node* head){
    struct Node *prev=NULL,*next=NULL;
    while(head){
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    return prev;
}

bool isPalindrome(struct Node* head){
    struct Node *slow=head,*fast=head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    slow=reverse(slow);
    struct Node* temp=head;

    while(slow){
        if(temp->data!=slow->data)
            return false;
        temp=temp->next;
        slow=slow->next;
    }
    return true;
}

struct Node* create(int n){
    struct Node *head=NULL,*temp=NULL,*newnode;
    int x;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=x;
        newnode->next=NULL;

        if(head==NULL){
            head=temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

int main(){
    int n;
    scanf("%d",&n);

    struct Node* head=create(n);

    if(isPalindrome(head))
        printf("true");
    else
        printf("false");

    return 0;
}