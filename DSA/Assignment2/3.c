#include <stdlib.h>
#include <stdio.h>
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
void add(struct node **a1, struct node *a2, struct node *a3)
{
    int carry = 0;
    // while (a2 != NULL && a3 != NULL)
    // {
    //     printf("\n a3: %d - a2 : %d ", a3->data, a2->data);
    //     int sum = a2->data + a3->data + carry;
    //     int to_add = sum % 10;
    //     insert(a1, to_add);
    //     carry = sum / 10;
    //     a3 = a3->next;
    //     a2 = a2->next;
    // }

    printf("%d %d %d %d",a2,a3,*a2,*a3);

    // while(a2!=NULL){
    //     printf("\n a2 : %p ",a2);
    //     int sum=a2->data+carry;
    //     int to_add=sum%10;
    //     insert(a1,to_add);
    //     carry=sum/10;
    //     a2=a2->next;
    //     // break;
    // }
    // while(a3!=NULL){
    //     printf("\n a3 : %p ",a3);
    //     int sum=a3->data+carry;
    //     int to_add=sum%10;
    //     insert(a1,to_add);
    //     carry=sum/10;
    //     a3=a3->next;
    // }
    if (carry)
    {
        insert(a1, carry);
    }
}
int main()
{
    int n = 12;
    int m = 78;
    struct node *a1 = NULL;
    struct node *a2 = NULL;
    val(&a1, n);
    val(&a2, m);

    struct node *a3 = NULL;

    struct node *t2 = a2;
    solve(a1, &a3, t2->data);
    if (t2->next != NULL)
    {
        t2 = t2->next;
        int counter = 1;
        while (t2 != NULL)
        {
            struct node *a4 = NULL;
            solve(a1, &a4, t2->data);
            for (int i = 0; i < counter; i++)
            {
                insert(&a4, 0);
            }
            struct node* t1=a4;
            printf("a4 \n");
            while(t1!=NULL){
                printf("%d->",t1->data);
                t1=t1->next;
            }
            add(&a3, a3, a4);
            printf("a3 \n");
            struct node* t2=a3;
            while(t2!=NULL){
                printf("%d->",t2->data);
                t2=t2->next;
            }
            printf("a3 end \n");

            t2 = t2->next;
            counter++;
        }
    }
    printf("\n Multiple is");
    struct node *t1 = a3;
    while (t1 != NULL)
    {
        printf("%d->", t1->data);
        t1 = t1->next;
    }
    // struct node* t2=val2;
    return 0;
}