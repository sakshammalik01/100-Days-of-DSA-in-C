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

int length(struct node* head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    return count;
}

int main(){
    int n,m,d;
    scanf("%d",&n);
    struct node* h1=createList(n);

    scanf("%d",&m);
    struct node* h2=createList(m);

    int l1=length(h1);
    int l2=length(h2);

    struct node *p1=h1,*p2=h2;

    if(l1>l2){
        d=l1-l2;
        while(d--) p1=p1->next;
    }else{
        d=l2-l1;
        while(d--) p2=p2->next;
    }

    while(p1 && p2){
        if(p1->data==p2->data){
            printf("%d",p1->data);
            return 0;
        }
        p1=p1->next;
        p2=p2->next;
    }

    printf("No Intersection");

    return 0;
}