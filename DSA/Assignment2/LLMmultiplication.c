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

void solve(struct node*val1,struct node*val2,struct node**ansh,struct node**anst){
    int m1=val1->data;
    int m2,mul,reminder=0,pro;
    while(val2!=NULL){
        m2=val2->data;
        mul=m1*m2 + reminder;
        pro=mul%10;
        insert(ansh,anst,pro);
        reminder=mul/10;
        val2=val2->next;
    }
    if(reminder){
        insert(ansh,anst,reminder);
    }
}
// void solve2(int val,struct node*val2,struct node**ansh,struct node**anst){
//     int m1=val1->data;
//     int m2,mul,reminder=0,pro;
//     while(val2!=NULL){
//         m2=val2->data;
//         mul=m1*m2 + reminder;
//         pro=mul%10;
//         insert(ansh,anst,pro);
//         reminder=mul/10;
//         val2=val2->next;
//     }
//     if(reminder){
//         insert(ansh,anst,reminder);
//     }
// }

int main(){
    int n;
    int m;
    n=1234;
    m=789;

    struct node* val1_h=NULL;
    struct node* val1_t=NULL;
    val(&val1_h,&val1_t,n);
    struct node* val2_h=NULL;
    struct node* val2_t=NULL;

    val(&val2_h,&val2_t,m);
    struct node*temp1=val1_h;
    struct node*temp2=val2_h;
    while(temp1!=NULL){
        printf("%d->",temp1->data);
        temp1=temp1->next;
    }
    printf("\n");
    while(temp2!=NULL){
        printf("%d->",temp2->data);
        temp2=temp2->next;
    }
    temp1=val1_h;
    temp2=val2_h;

    struct node* ans_h=NULL;
    struct node* ans_t=NULL;
    
    struct node* ans1_h=NULL;
    struct node* ans1_t=NULL;
    struct node* ans2_h=NULL;
    struct node* ans2_t=NULL;

    solve(val1_h,val2_h,&ans_h,&ans_t);
    while(temp1!=NULL){
        int val=temp1->data;
        // solve2

    }

    printf("\n");
    struct node*tempa=ans_h;
    while(tempa!=NULL){
        printf("%d->",tempa->data);
        tempa=tempa->next;
    }

    
    return 0;

}