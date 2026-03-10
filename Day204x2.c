#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val){
    struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
    node->val=val;
    node->next=NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode *head=NULL,*tail=NULL;
    int carry=0;

    while(l1 || l2 || carry){

        int sum=carry;

        if(l1){
            sum+=l1->val;
            l1=l1->next;
        }

        if(l2){
            sum+=l2->val;
            l2=l2->next;
        }

        carry=sum/10;

        struct ListNode* newNode=createNode(sum%10);

        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    return head;
}

void printList(struct ListNode* head){
    while(head){
        printf("%d ",head->val);
        head=head->next;
    }
}

int main(){

    struct ListNode *l1=createNode(2);
    l1->next=createNode(4);
    l1->next->next=createNode(3);

    struct ListNode *l2=createNode(5);
    l2->next=createNode(6);
    l2->next->next=createNode(4);

    struct ListNode* result=addTwoNumbers(l1,l2);

    printList(result);

    return 0;
}