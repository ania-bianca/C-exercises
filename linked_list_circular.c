/* Problem:
        Create a list out of an array of integers, a function that inserts a node in the front of the list with the given value
        and a function that deletes the node with the givwn value.
        
    */
#include<stdio.h>

typedef struct node{
    int info;
    struct node*next;
}node;

void create_list(node **head, int value)
{
    if(*head!=NULL)
    {
        node *curr=*head;
        node *prev=NULL;
        do{
            prev=curr;
            curr=curr->next;
        }while(curr!=*head);

        node *elem=malloc(sizeof(node));
        if(elem==NULL)
        {
            printf("malloc failed");
            return ;
        }
        elem->info=value;
        prev->next=elem;
        elem->next=curr;
    }
    else{
        node *elem=malloc(sizeof(node));
        if(elem==NULL)
        {
            printf("malloc failed");
            return ;
        }
        elem->info=value;
        *head=elem;
        elem->next=*head;
    }
}

void insert_at_front(node **head, int value)
{
    if(*head!=NULL)
    {
        node *curr=*head;
        node *prev=NULL;
        do{
            prev=curr;
            curr=curr->next;
        }while(curr!=*head);

        
        node *elem=malloc(sizeof(node));
        if(elem==NULL)
        {
            printf("malloc failed");
            return ;
        }
        elem->info=value;
        prev->next=elem;
        elem->next=curr;
        *head=elem;
        
    }
}

void delete_node(node **head, int value)
{
    if(*head !=NULL)
    {
        if((*head)->info==value)
        {
            node *tmp=*head;
            node *curr=*head;
            node *prev=NULL;
            do{
                prev=curr;
                curr=curr->next;
            }while(curr!=*head);
            
            if(prev==*head && curr->next==*head)// only one element in the list
            {
                *head=NULL;
                free(tmp);
                return;
            }

            curr=curr->next;
            prev->next=curr;
            *head=curr;
            free(tmp);
            return;
        }

        node *curr=*head;
        node *prev=NULL;
        do{
            prev=curr;
            curr=curr->next;
        }while(curr!=*head && curr->info!=value);

        if(curr==*head)
        {
            printf("This element is not in the list");
            return;
        }

        node *tmp=curr;
        curr=curr->next;
        prev->next=curr;
        free(tmp);
        return ;

    }
}

void free_list(node **head)
{
    if(*head==NULL) // if the list is empty
        return;
    node *curr=(*head)->next;
    while(curr!=head)
    {
        node *tmp=curr;
        curr=curr->next;
        free(tmp);
    }
    free(*head);
    *head=NULL;    
}

int main()
{
    int arr[6]={23,45,56,48,35,90};
    int n=6;
    node *head=NULL;
    for(int i=0; i<n; i++)
    {
        create_list(&head, arr[i]);
    }

    insert_at_front(&head,99);
    delete_node(&head, 23);

    free_list(&head);

    return 0;
},