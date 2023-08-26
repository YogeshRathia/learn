#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#include <time.h>
struct node
{
  int data;
  struct node *next;
};
void insert_at_beginning(struct node **head,int d){
    struct node *new_node=NULL;
    new_node=malloc(sizeof(struct node));
    new_node->data=d;
    new_node->next=*head;
    *head=new_node;
    
}

void insert_at_end(struct node **head,int d){
    //  ------//------
    // printf("%p %p\n",head,*head);
    //------\\------
    struct node *new_node=NULL;
    new_node=malloc(sizeof(struct node));
    new_node->data=d;
    struct node*temp;
    temp=*head;
    if(*head==NULL){
        *head=new_node;
        new_node->next=NULL;
    }
    else{
         while(temp->next!=NULL){
        temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=NULL;
    }
}

void delete_at_beginning(struct node **head){
    if(*head!=NULL){
        struct node*temp;
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}

void delete_last(struct node **head){
    if(*head==NULL){
        return;
    }
    if((*head)->next==NULL){
        struct node*temp;
        temp=*head;
        *head=NULL;
        free(temp);
    }
    else{
    struct node*temp;
    struct node*temp2;
    temp=*head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=NULL;
    free(temp2);
    }
}

void delete_specific(struct node **head,int d){
    if(*head==NULL){
        printf("Not found\n");
        return;
    }
    if((*head)->next==NULL){
        if((*head)->data==d){
            struct node*temp;
            temp=*head;
            *head=NULL;
            free(temp);
            return;
        }
        else{
            printf("Not found\n");
            return;
        }
    }
    struct node*temp=*head;
    while(temp->next!=NULL && temp->next->data!=d){
        temp=temp->next;
    }
    if(temp->next->data==d){
        struct node* temp2=temp->next;
        temp->next=temp2->next;
        free(temp2);
    }
    else{
        printf("Not found\n");
    }
}

void find(struct node**head,int d){
    int count=1;
    if(*head==NULL){
        printf("Empty linked list:\n");
        return;
    }
    struct node*temp;
    temp=*head;
    while(temp!=NULL && temp->data!=d){
        temp=temp->next;
        count++;
    }
    if(temp!=NULL){
        printf("Found at position : %d \n",count);
    }
    else{
        printf("Not found\n");
    }
}


void size(struct node**head){
    if(*head==NULL){
        printf("Empty\n");
        return;
    }
    int count=0;
    struct node*temp;
    temp=*head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    printf("Size is %d\n",count);
}

void display(struct node**head){
    if(*head==NULL){
        printf("Empty\n");
        return;
    }
    struct node*temp;
    temp=*head;
    while(temp!=NULL){
        printf("%d=>",temp->data);
        temp=temp->next;
    }
}

int main(){
    
    FILE *file;
    int value,v2,v3;
    file = fopen("./input1.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1; // Exit with an error code
    }
    fscanf(file, "%d %d %d", &value,&v2,&v3);
    fclose(file);
    printf("Value read from the file: %d %d %d\n", value,v3,v2);


    int run=1;
    int d;
    int val=999;
    struct node*head=NULL;
    // printf("%p %p\n",&head,head);  &head is address of head and head alco contain address which is NULL
    while(run){
        printf("Enter Choice:");
        scanf("%d",&val);
        switch (val)
        {
        case 1:
            printf("Enter Data to insert at beginning:");
            scanf("%d",&d);
            insert_at_beginning(&head,d);

            break;
        case 2:
            printf("Enter Data to insert at Last:");
            scanf("%d",&d);
            insert_at_end(&head,d);
            break;
        case 3:
            printf("Delete at begining:\n");
            delete_at_beginning(&head);
            break;
        case 4:
            printf("Delete Last Node:\n");
            delete_last(&head);
            break;
        case 5:
            printf("Delete specific Node:\n");
            printf("Enter Data to delete:");
            scanf("%d",&d);
            delete_specific(&head,d);
            break;
        case 6:
            printf("Finde position of a node:\n");
            printf("Enter Data to find:");
            scanf("%d",&d);
            find(&head,d);
            break;
        case 7:
            printf("Size:\n");
            size(&head);
            break;
        case 8:
            printf("Display:\n");
            display(&head);
            break;
        
        case 0:
            run=0;
            break;
        default:
            printf("Wrong Input.\n");
            break;
        }
    }
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    
    return 0;
}