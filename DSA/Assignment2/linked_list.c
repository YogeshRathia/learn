#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
int main(){


    printf("Enter data:");
    int val;
    scanf("%d",&val);
    
    struct node*head;
    struct node *one=NULL;
    struct node *two=NULL;
    struct node *three=NULL;

    one=malloc(sizeof(struct node));
    two=malloc(sizeof(struct node));
    three=malloc(sizeof(struct node));
    one->data=11;
    one->next=two;
    two->data=22;
    two->next=three;
    three->data=33;
    three->next=NULL;
    head=one;
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    return 0;


}