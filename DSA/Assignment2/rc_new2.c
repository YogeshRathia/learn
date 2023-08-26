#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
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
void insert1(struct node **head,struct node**tail, int n)
{
    if (*head == NULL)
    {
        struct node *new_node;
        new_node = malloc(sizeof(struct node));
        new_node->data = n;
        new_node->next = NULL;
        *head = new_node;
        *tail = new_node;
    }
    else
    {
        struct node *new_node;
        new_node = malloc(sizeof(struct node));
        new_node->data = n;
        (*tail)->next=new_node;
        new_node->next = NULL;
        *tail=(*tail)->next;
    }
}



void compute(struct node**head,int n){
    struct node*mul=NULL;
    struct node*tail=NULL;
    int rem=0;
    struct node*temp=*head;
    while(temp!=NULL){
        int in=temp->data*n + rem;
        rem=in/10;
        insert1(&mul,&tail,in%10);
        temp=temp->next;
    }
    while(rem){
        int in=rem%10;
        insert(&mul,in);
        rem=rem/10;
    }
    temp=mul;
    *head=mul;
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
void insert_p(struct node**head,char data[],int n){
        for(int i=0;i<n;i++){
            int is=data[i]-'0';
            insert(head,is);
        }
}

void find_pattern(struct node**ll1, struct node**ll2,int *count) {
    struct node*temp=*ll1;
    struct node*temp2=*ll2;

    while(temp!=NULL)
    {
        if(temp->data==temp2->data){
            struct node*tll1 = temp;
            struct node*tll2 = *ll2;
            while (tll1 != NULL && tll2 != NULL)
            {
                if(tll1->data==tll2->data){
                    tll1=tll1->next;
                    tll2=tll2->next;
                }
                else{
                    break;
                }
            }
            if(tll2==NULL){
                *count=*count+1;
            }
        }
        temp=temp->next;
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
    FILE *file;
    int test_case;
    file = fopen("./input.txt", "r");
    fscanf(file, "%d", &test_case);
    for(int i=0;i<test_case;i++)
    {
        int n;
        char ptrn[1000];
        fscanf(file, "%d",&n);
        fscanf(file, "%s",ptrn);

        struct node *ans = NULL;

        insert(&ans,1);
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                compute(&ans,i);
            }
        }
        rev(&ans);
        // ------Multiplication stored in Linked list (ans) in proper order------

        struct node*pattern=NULL;
        int p_s=strlen(ptrn);
        insert_p(&pattern,ptrn,p_s);

        // ------Pattern stored in linked list (pattern)------

        int count=0;
        find_pattern(&ans,&pattern,&count);

        //------Value of count pattern stored in count------

        int zro=0;
        find_zero(&ans,&zro);

        //------Value of count stored in zro------

        printf("%d ",zro);
        printf("%d ",count);
        struct node*temp=ans;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}