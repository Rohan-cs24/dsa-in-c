#include <stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *createNode(int data){
    struct node *temp=malloc(sizeof(struct  node ));
    temp->data=data;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}
struct node *addBeg(struct node *head,int data){
    struct node *new=createNode(data);
    new->prev=head->prev;
    new->next=head;
    head->prev=new;
    new->prev->next=new;
    head=new;
    return head;
}
struct node *addEnd(struct node *head,int data){
    struct node *new=createNode(data),*tail;
    tail=head->prev;
    new->next=head;
    head->prev=new;
    tail->next=new;
    new->prev=tail;
    return head;
}
struct node *delLast(struct node *head){
    struct node *tail;
    tail=head->prev;
    tail->prev->next=head;
    head->prev=tail->prev;
    free(tail);
    return head;
}
struct node *delFirst(struct node *head){
    struct node *tail;
    tail=head->prev;
    head->next->prev=tail;
    tail->next=head->next;
    free(head);
    head=tail->next;
    return head;
}
void print(struct node *head){
    struct node *ptr=head;
    do{
       printf("%d<->",ptr->data);
       ptr=ptr->next;
    } while (ptr!=head);
}
int main(){
    struct node *head=createNode(24);
    head=addBeg(head,95);
    head=addEnd(head,100);
    head=addEnd(head,1000);
    head=delLast(head);
    head=delFirst(head);
    print(head);
}