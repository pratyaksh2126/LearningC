#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* create(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

int hasCycle(struct Node* head){
    struct Node *slow=head,*fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        return 1;
    }

    return 0;
}

int main(){
    int n,pos,x;
    scanf("%d",&n);

    struct Node *head=NULL,*temp=NULL,*nodes[100];

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        struct Node* newNode=create(x);

        nodes[i]=newNode;

        if(head==NULL){
            head=newNode;
            temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }

    scanf("%d",&pos);

    if(pos!=-1)
    temp->next=nodes[pos];

    if(hasCycle(head))
    printf("true");
    else
    printf("false");

    return 0;
}