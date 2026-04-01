#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* createList(int n){
    struct node *head=NULL,*temp=NULL,*newnode;
    int x;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            temp=head;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    return head;
}

struct node* merge(struct node* l1, struct node* l2){
    struct node dummy;
    struct node* tail=&dummy;
    dummy.next=NULL;

    while(l1 && l2){
        if(l1->data <= l2->data){
            tail->next=l1;
            l1=l1->next;
        }else{
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }

    if(l1) tail->next=l1;
    else tail->next=l2;

    return dummy.next;
}

void printList(struct node* head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
}

int main(){
    int n,m;
    scanf("%d",&n);
    struct node* l1=createList(n);

    scanf("%d",&m);
    struct node* l2=createList(m);

    struct node* merged=merge(l1,l2);
    printList(merged);

    return 0;
}