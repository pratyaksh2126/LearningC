#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

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

bool isPalindrome(struct Node* head){
    int arr[1000],i=0;

    struct Node* temp=head;

    while(temp){
        arr[i++]=temp->data;
        temp=temp->next;
    }

    for(int j=0;j<i/2;j++){
        if(arr[j]!=arr[i-j-1])
            return false;
    }

    return true;
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