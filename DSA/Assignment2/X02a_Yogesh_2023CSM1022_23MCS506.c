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
//  5
void delete_specific(struct node **head,int d){
    if(*head==NULL){
        return;
    }
    if((*head)->next==NULL){
        if((*head)->data==d){
            struct node*temp;
            temp=*head;
            *head=NULL;
            free(temp);
        }
        else{
            printf("N ");
        }
        return;    
    }
    struct node*temp=*head;
    while(temp->next){
        if(temp->next->data==d){
            struct node*temp1=temp->next;
            temp->next=temp1->next;
            temp1->next=NULL;
            free(temp1);
            return;
        }
        temp=temp->next;
    }
    printf("N ");

        
}
//  6
void find(struct node**head,int d){
    if(*head==NULL){
        return;
    }
    struct node*temp=*head;
    int count=1;
    while(temp!=NULL){
        if(temp->data==d){
            int val=*head-temp;
            if(val==0){
                printf("%d (%d) ",count,val);
            }
            else{
                printf("%d (-%d) ",count,val);
            }
        return;
        }
        temp=temp->next;
        count++;
    }
    printf("N ");
}


void size(struct node**head){
    if(*head==NULL){
        return;
    }
    int count=0;
    struct node*temp;
    temp=*head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    printf("%d ",count);
}

void display(struct node**head){
    if(*head==NULL){
        return;
    }
    struct node*temp;
    temp=*head;
    printf("[");
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
        if(temp!=NULL)
        {
            printf("-");
        }
    }
    printf("] ");
}

int main(){
    
    FILE *file;
    int test_case;
    file = fopen("./input1.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    fscanf(file, "%d", &test_case);
    // for(int i=0;i<test_case;i++){
    for(int i=0;i<5;i++){
        int input_size;
        fscanf(file, "%d", &input_size);
        int run=1;
        struct node*head=NULL;
        for(int j=0;j<input_size && run;j++)
        {
            int input_case;
            int input_data;
                fscanf(file, "%d", &input_case);
                // printf("\nInput size: %d || Input case : %d j is :%d\n",input_size,input_case,j);
                switch (input_case)
                {
                case 1:
                    fscanf(file, "%d", &input_data);
                    insert_at_beginning(&head,input_data);
                    break;
                case 2:
                    fscanf(file, "%d", &input_data);
                    insert_at_end(&head,input_data);
                    break;
                case 3:
                    delete_at_beginning(&head);
                    break;
                case 4:
                    delete_last(&head);
                    break;
                case 5:
                    fscanf(file, "%d", &input_data);
                    delete_specific(&head,input_data);
                    break;
                case 6:
                    fscanf(file, "%d", &input_data);
                    find(&head,input_data);
                    break;
                case 7:
                    size(&head);
                    break;
                case 8:
                    display(&head);
                    break;

                case 0:
                    run=0;
                    break;
                default:
                    printf("W ");
                    break;
                }            
        }
        printf("\n");

    }
    fclose(file);
    return 0;
}