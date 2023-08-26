#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node* next;
};

void insert(struct node**head,struct node**tail,int d){
    if(*head==NULL){
        struct node*new_node;
        new_node=malloc(sizeof(struct node));
        new_node->data=d;
        new_node->next=NULL;
        *head=new_node;
        *tail=new_node;
    }
    else{
        struct node*new_node;
        new_node=malloc(sizeof(struct node));
        new_node->data=d;
        new_node->next=NULL;
        (*tail)->next=new_node;
        *tail=new_node;
    }

}
void val(struct node**head,struct node**tail,int n){
    int v1=1;
    while(n){
        v1=n%10;
        insert(head,tail,v1);
        n=n/10;
    }
}
int main(){
    int n;

    struct node* ans_h=NULL;
    struct node* ans_t=NULL;

    printf("Enter the value of N : ");
    scanf("%d",&n);
    while(n>1){
        for(int i=0;i<n;i++){
            struct node* array_value1_h=NULL;
            struct node* array_value1_t=NULL;

            struct node* array_value2_h=NULL;
            struct node* array_value2_t=NULL;

            val(&array_value1_h,&array_value1_t,n);
            val(&array_value2_h,&array_value2_t,1);

            

        }
        n--;
    }

    return 0;

}