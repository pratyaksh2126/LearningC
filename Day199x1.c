#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int x){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}

struct Node* removeElements(struct Node* head,int val){
    struct Node *temp=head,*prev=NULL;

    while(temp!=NULL){
        if(temp->data==val){
            if(prev==NULL){
                head=temp->next;
                free(temp);
                temp=head;
            }
            else{
                prev->next=temp->next;
                free(temp);
                temp=prev->next;
            }
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}

void printList(struct Node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    int n,x,val;
    struct Node *head=NULL,*temp,*last=NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        temp=createNode(x);

        if(head==NULL){
            head=temp;
            last=temp;
        }
        else{
            last->next=temp;
            last=temp;
        }
    }

    scanf("%d",&val);

    head=removeElements(head,val);

    printList(head);

    return 0;
}