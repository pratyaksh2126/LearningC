#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
};

struct Node* head=NULL;
int size=0;

int get(int index){
    if(index<0 || index>=size) return -1;
    struct Node* temp=head;
    for(int i=0;i<index;i++)
        temp=temp->next;
    return temp->val;
}

void addAtHead(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->prev=NULL;
    newNode->next=head;

    if(head!=NULL)
        head->prev=newNode;

    head=newNode;
    size++;
}

void addAtTail(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->next=NULL;

    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
    }else{
        struct Node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=newNode;
        newNode->prev=temp;
    }
    size++;
}

void addAtIndex(int index,int val){
    if(index<0 || index>size) return;

    if(index==0){
        addAtHead(val);
        return;
    }

    struct Node* temp=head;
    for(int i=0;i<index-1;i++)
        temp=temp->next;

    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;

    newNode->next=temp->next;
    newNode->prev=temp;

    if(temp->next!=NULL)
        temp->next->prev=newNode;

    temp->next=newNode;

    size++;
}

void deleteAtIndex(int index){
    if(index<0 || index>=size) return;

    struct Node* temp=head;

    if(index==0){
        head=temp->next;
        if(head!=NULL)
            head->prev=NULL;
        free(temp);
    }else{
        for(int i=0;i<index;i++)
            temp=temp->next;

        if(temp->prev!=NULL)
            temp->prev->next=temp->next;

        if(temp->next!=NULL)
            temp->next->prev=temp->prev;

        free(temp);
    }
    size--;
}

int main(){

    addAtHead(1);
    addAtTail(3);
    addAtIndex(1,2);

    printf("%d\n",get(1));

    deleteAtIndex(1);

    printf("%d\n",get(1));

    return 0;
}