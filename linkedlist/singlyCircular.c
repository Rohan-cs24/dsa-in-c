#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *createNode(int data){
    struct node *temp=malloc(sizeof(struct  node ));
    temp->data=data;
    temp->next=temp;
    return temp;
}
struct node *addBeg(struct node *tail,int data){
    struct node *new=malloc(sizeof(struct node ));
    new->data=data;
    new->next=tail->next;
    tail->next=new;
    return tail;
}
struct node *addEnd(struct node *tail,int data){
    struct node *new=malloc(sizeof(struct node )),*head;
    head=tail->next;
    new->data=data;
    tail->next=new;
    new->next=head;
    tail=new;
}
struct node *delBeg(struct node *tail){
    struct node *ptr=tail->next;
    tail->next=ptr->next;
    free(ptr);
    return tail;
}
struct node*delEnd(struct node *tail){
    struct node *ptr=tail->next;
    while(ptr->next!=tail){
        ptr=ptr->next;
    }
    ptr->next=tail->next;
    free(tail);
    tail=ptr;
}
void print(struct node *tail){
    struct node *ptr=tail->next;
    do{
       printf("%d->",ptr->data);
       ptr=ptr->next;
    } while (ptr!=tail->next);
}
int main(){
    struct node *tail;
    tail=createNode(52);
    tail=addBeg(tail,69);
    tail=addBeg(tail,79);
    tail=addEnd(tail,100);
    tail=delBeg(tail);
    tail=delEnd(tail);
    print(tail);
    return 0;
}