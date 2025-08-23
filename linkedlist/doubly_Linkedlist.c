#include <stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node * create_list(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node * add_to_begaining(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
struct node *add_to_end(struct node *head,int data){
    struct node *ptr=NULL,*temp=malloc(sizeof(struct node));
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    temp->data=data;
    temp->next=NULL;
    return head;
}
struct node *after_node(struct node *head,int data,int val){
    struct node *ptr=NULL,*after,*temp=malloc(sizeof(struct node));
    ptr=head;
    while(ptr->data!=val){
        ptr=ptr->next;
    }
    temp->data=data;
    after=ptr->next;
    temp->prev=ptr;
    ptr->next=temp;
    after->prev=temp;
    temp->next=after;
    return head;
}
struct node *before_node(struct node *head,int data,int val){
    struct node *ptr=NULL,*before,*temp=malloc(sizeof(struct node));
    ptr=head;
    while(ptr->data!=val){
        ptr=ptr->next;
    }
    temp->data=data;
    before=ptr->prev;
    before->next=temp;
    temp->prev=before;
    temp->next=ptr;
    ptr->prev=temp;
    return head;
}
struct node *delFirst(struct node *head){
    struct node *ptr=NULL;
    ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    ptr=NULL;
    return head;
}
struct node *delLast(struct node *head){
    struct node *ptr=NULL;
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
    return head;
}
struct node *del_certain_pos(struct node *head,int val){
    struct node *temp,*temp2;
    temp=head;
    while(temp->data!=val){
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    temp=NULL;
    return head;
}
int main(){
      struct node *ptr, *head=malloc(sizeof(struct node ));
      head=create_list(head,52);
      head=add_to_begaining(head,62);
      head=add_to_begaining(head,72);
      head=add_to_end(head,42);
      head=add_to_end(head,32);
      head=after_node(head,50,52);
      head=after_node(head,40,50);
      head=before_node(head,200,50);
      head=before_node(head,300,200);
      head=delFirst(head);
      head=delLast(head);
      head=del_certain_pos(head,200);
      ptr=head;
      while(ptr!=NULL){
        printf("%d ->",ptr->data);
        ptr=ptr->next;
      }
     return 0;
}