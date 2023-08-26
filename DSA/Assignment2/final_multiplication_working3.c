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
void compute(struct node**head,int n){
    struct node *a2 = NULL;
    val(&a2, n);
    struct node *a1 = NULL;
    a1=*head;
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
    *head=a3;
}

void rev(struct node** head){
    struct node* pre = NULL;
    struct node* current = *head;
    struct node* nxt;
    while (current != NULL) {
        nxt = current->next;
        current->next = pre;
        pre = current;
        current = nxt;
    }
    *head = pre;
}
void insert_p(struct node**head,int *data){
        // printf("\n to insert : %d %d\n",ins,data);
    int ins=*data;
    while(*data!=0){
        ins=*data%10;
        insert(head,ins);
        *data=*data/10;
    }
    rev(head);
}

void find_pattern(struct node**ll1, struct node**ll2,int *count) {
    struct node*tll1 = *ll1;
    struct node*tll2 = *ll2;
    while (tll1 != NULL && tll2 != NULL) {
        if (tll1->data != tll2->data) {
            tll2 = *ll2;  // Reset current2 to the beginning of list2
        } else {
            tll2 = tll2->next;
            if (tll2 == NULL) {
                *count=*count+1;
                tll2=*ll2;
            }
        }
        tll1 = tll1->next;
    }
}
void find_zero(struct node**head,int*n){
    struct node*temp=*head;
    while(temp!=NULL){
        if(temp->data==0){
            *n=*n+1;
        }
        else{
            *n=0;
        }
        temp=temp->next;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    struct node *ans = NULL;
    insert(&ans,1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            compute(&ans,i);
        }
    }
    rev(&ans);
    struct node*temp=ans;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    int ptrn=22;
    struct node*pattern=NULL;
    insert_p(&pattern,&ptrn);
    temp=pattern;
    printf("\n");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    // ----find patterns
    int count=0;
    find_pattern(&ans,&pattern,&count);
    printf("\n Count: %d",count);
    //---find zeros
    int zro=0;
    find_zero(&ans,&zro);
    printf("\n Zeros: %d",zro);
    return 0;
}