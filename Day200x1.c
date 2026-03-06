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

struct Node* detectCycle(struct Node* head){
    struct Node *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            struct Node* temp = head;
            while(temp != slow){
                temp = temp->next;
                slow = slow->next;
            }
            return temp;
        }
    }
    return NULL;
}

int main(){
    int n,pos,val;
    scanf("%d",&n);

    struct Node *head=NULL,*temp=NULL,*nodes[n];

    for(int i=0;i<n;i++){
        scanf("%d",&val);
        nodes[i]=createNode(val);

        if(head==NULL){
            head=nodes[i];
            temp=head;
        }
        else{
            temp->next=nodes[i];
            temp=nodes[i];
        }
    }

    scanf("%d",&pos);

    if(pos!=-1)
        temp->next=nodes[pos];

    struct Node* res=detectCycle(head);

    if(res==NULL)
        printf("no cycle");
    else{
        for(int i=0;i<n;i++){
            if(nodes[i]==res){
                printf("tail connects to node index %d",i);
                break;
            }
        }
    }

    return 0;
}