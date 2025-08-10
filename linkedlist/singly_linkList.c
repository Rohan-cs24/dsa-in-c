#include <stdio.h>
#include<stdlib.h>
// declare the node
struct node{
    int data;
    struct node* link;
};
struct node* insert_beg(struct node *head,int data){
      struct node*ptr;
      ptr=malloc(sizeof(struct node));
      ptr->data=data;
      ptr->link=head;
      head=ptr;
    return head;
}
struct node* insert_end(struct node *head,int data){
      struct node *ptr,*temp;
      ptr=head;
      temp=malloc(sizeof(struct node));
      temp->data=data;
      temp->link=NULL;
      while(ptr->link!=NULL){
        ptr=ptr->link;
      }
      ptr->link=temp;
      return head;
}
struct node* after_node(struct node *head,int data,int val){
      struct node *ptr,*pre_ptr,*temp;
      temp=malloc(sizeof(struct node));
      ptr=head;
      pre_ptr=ptr;
      temp->data=data;
      while(pre_ptr->data!=val){
        pre_ptr=ptr;
        ptr=ptr->link;
      }
      pre_ptr->link=temp;
      temp->link=ptr;
      return head;
}
struct node* before_node(struct node *head,int data,int val){
      struct node *ptr,*pre_ptr,*temp;
      temp=malloc(sizeof(struct node));
      ptr=head;
      pre_ptr=ptr;
      temp->data=data;
      while(ptr->data!=val){
        pre_ptr=ptr;
        ptr=ptr->link;
      }
      pre_ptr->link=temp;
      temp->link=ptr;
      return head;
}
struct node * del_at_beg(struct node*head){
      struct node *ptr;
      ptr=head;
      head=head->link;
      free(ptr);
      ptr=NULL;
      return head;
}
struct node * del_at_end(struct node*head){
      struct node *ptr;
      ptr=head;
      while(ptr->link->link!=NULL){
        ptr=ptr->link;
      }
      free(ptr->link);
      ptr->link=NULL;
      return head;
}
struct node* del_afterNode(struct node *head,int val){
   struct node *ptr,*pre_ptr;
   ptr=head;
   pre_ptr=ptr;
   while(pre_ptr->data!=val){
    pre_ptr=ptr;
    ptr=ptr->link;
   }
   pre_ptr->link=ptr->link;
   free(ptr);
   return head;
}
struct node* del_Node(struct node *head,int val){
   struct node *ptr,*pre_ptr;
   ptr=head;
   pre_ptr=ptr;
   while(ptr->data!=val){
    pre_ptr=ptr;
    ptr=ptr->link;
   }
   pre_ptr->link=ptr->link;
   free(ptr);
   return head;
}
// singly linked list
int main(){
      struct node *head=NULL,*ptr=NULL;
      head=malloc(sizeof(struct node));
      head->data=12;
      head->link=NULL;
      struct node *current=malloc(sizeof(struct node));
      current->data=24;
      current->link=NULL;
      head->link=current;
      current=malloc(sizeof(struct node));
      current->data=36;
      current->link=NULL;
      head->link->link=current;
      ptr=head;
      head=insert_beg(head,52);
      head=insert_end(head,600);
      head=after_node(head,200,24);
      head=before_node(head,150,24);
      head=del_at_beg(head);
      head=del_at_end(head);
      head=del_afterNode(head,24);
      head=del_Node(head,24);
      ptr=head;
      // Traversing and print the data of the linked list
      while(ptr!=NULL){
        printf("%d-> ",ptr->data);
        ptr=ptr->link;
      }
    return 0;
}