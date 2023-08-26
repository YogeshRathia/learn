#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
void insert_f(struct node**head){
    struct node*new_node;
    new_node=malloc(sizeof(struct node));
    new_node->data=0;
    new_node->next=*head;
    *head=new_node;
}
void insert(struct node **head, int n)
{
    if (*head == NULL)
    {
        struct node *new_node;
        new_node = malloc(sizeof(struct node));
        new_node->data = n;
        new_node->next = NULL;
        *head = new_node;
    }
    else
    {
        struct node *new_node;
        new_node = malloc(sizeof(struct node));
        new_node->data = n;
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }
}
void val(struct node **head, int n)
{
    int v1 = 1;
    while (n)
    {
        v1 = n % 10;
        insert(head, v1);
        n = n / 10;
    }
}
void solve(struct node *head, struct node **ans, int d)
{
    int m2, mul, reminder = 0, pro;
    while (head != NULL)
    {
        m2 = head->data;
        mul = d * m2 + reminder;
        pro = mul % 10;
        insert(ans, pro);
        reminder = mul / 10;
        head = head->next;
    }
    if (reminder)
    {
        insert(ans, reminder);
    }
}
void add(struct node**ans,struct node*d1,struct node*d2){
    int carry=0;
    int sum=0;
    int ins=0;
    while(d1!=NULL && d2!=NULL){
        sum=d1->data+d2->data+carry;
        ins=sum%10;
        insert(ans,ins);
        carry=sum/10;
    d1=d1->next;
    d2=d2->next;
    }
    while(d1!=NULL){
        sum=d1->data+carry;
        ins=sum%10;
        insert(ans,ins);
        carry=sum/10;
        d1=d1->next;
    }
    while(d2!=NULL){
        sum=d2->data+carry;
        ins=sum%10;
        insert(ans,ins);
        carry=sum/10;
        d2=d2->next;
    }
    if(carry){
        insert(ans,carry);
        carry=0;
    }
}
int main()
{
    int n = 70;
    int m = 5;
    struct node *a1 = NULL;
    struct node *a2 = NULL;
    val(&a1, n);
    val(&a2, m);
    struct node*temp=NULL;

    struct node *a3 = NULL;
    struct node *t1 = a2;

    solve(a1, &a3, t1->data);
    if (t1->next != NULL)
    {
        t1 = t1->next;
        int counter = 1;
        while (t1 != NULL)
        {
            struct node *a4 = NULL;
            solve(a1, &a4, t1->data);
            for (int i = 0; i < counter; i++)
            {
                insert_f(&a4);
            }
            struct node*a5=NULL;
            add(&a5,a4,a3);
            a3=a5;
            struct node* temp=a3;
            printf("\naddition : ");
            while(temp!=NULL){
                printf("%d->",temp->data);
                temp=temp->next;
            }
            counter++;
            t1=t1->next;
        }
    }
    temp=a3;
    printf("\nFinal output\n");
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    // printf("\n Multiple is");
    // struct node *t1 = a3;
    // while (t1 != NULL)
    // {
    //     printf("%d->", t1->data);
    //     t1 = t1->next;
    // }
    // // struct node* t2=val2;
    return 0;
}