/*Problems for undertanding simple linked lists:
  Tasks:
    1. Write the structure to create a list from a given array and write functions to build and print it into a text file
        eg: input:  array {10,11,13,14}
            output : 10 -> 11 -> 13 -> 14 -> NULL
    2. Insert into the front of the list and at the begining, nodes with a  value given in the command line. The first argument
    is the value for the new begining node and the second argument should be the the new end node. Write functions for each insertion
    3. Write a function that counts how many even nodes are in the list and returns the value. The returned value should be printed
    into a text file.
    4. Write a function that deletes the even nodes from a list. Print the new list in the text file as in exercise 1.
     */

#include<stdio.h>
#include<stdlib.h>

/*Structure:*/
    typedef struct node{
        int value;
        struct node *next;
    }node;

/* Functions:*/
    FILE *open_file(const char *filename, const char *mode);
    void close_file(FILE *f);
    void build_list(int *arr, int n, node **head);
    void print_list(FILE *f, node *head);
    void insert_begining(node **head, int value);
    void insert_end(node *head, int value);
    int even_nodes(node *head);
    void free_list(node *head);


FILE *open_file(const char *filename, const char *mode)
{
    FILE *f=fopen(filename, mode);
    if(f==NULL)
    {
        printf("!!Opening file failed");
        exit(-1);
    }
    return f;
}

void close_file(FILE *f)
{
    if(fclose(f)!=0)
    {
        printf("!!Closing file failed");
        exit(-1);
    }
}

void build_list(int *arr, int n, node **head)
{
    for(int i=0; i<n; i++)
    { 
        // create the node that needs to be inserted
        node *elem=malloc(sizeof(node));
            if(elem==NULL)
            {
                printf("Memory allocation failed");
                exit(-1);
            }
            elem->value=arr[i];

        if(*head==NULL) // if the list is empty, the element is the head
        {
            elem->next=NULL;
            *head=elem;
        }else // if the list is not empty, the element is inserted at the end of the list
        {
            node *curr=*head;
            node *prev=NULL;
            while(curr!=NULL)
            {
                prev=curr;
                curr=curr->next;
            }
            elem->next=NULL;
            prev->next=elem;
            
        }
    }

}

void print_list(FILE *f, node *head)
{
    for(;head!=NULL; head=head->next)
    {
        fprintf(f, "%d -> ", head->value);
    }
    fprintf(f, "NULL");
}

void insert_begining(node **head, int value)
{
    // create node that needs to be inserted
    node *elem=malloc(sizeof(node));
    if(elem==NULL)
        {
            printf("Memory allocation failed");
            exit(-1);
        }
    elem->value=value;

    // put it in the begining of list
    elem->next=*head;
    *head=elem;
}

void insert_end(node *head, int value)
{  
    // create node that needs to be inserted
    node *elem=malloc(sizeof(node));
    if(elem==NULL)
        {
            printf("Memory allocation failed");
            exit(-1);
        }
    elem->value=value;

    // loop to the last node (prev)
    node *prev=NULL;
    node *curr=head;
    while(curr!=NULL)
    {
        prev=curr;
        curr=curr->next;
    }

    //put the node at the ending of list (after previous)
    elem->next=NULL;
    prev->next=elem;
}

int even_nodes(node *head)
{
    int total_even_nodes=0;
    while(head!=NULL)
    {
        if((head->value)%2==0)
        {
            total_even_nodes++;
        }
        head=head->next;
    }

    return total_even_nodes;
}

void delete_even_nodes(node **head)
{
    node *prev=NULL;
    node *curr=*head;
    while(curr!=NULL)
    {
        if((curr->value)%2==0)
        {
            if(prev==NULL)
            {
                node *tmp=curr;
                curr=curr->next;
                *head=curr;
                free(tmp);
            }
            else
            {
                node *tmp=curr;
                curr=curr->next;
                prev->next=curr;
                free(tmp);
            }
        }
        else{
            prev=curr;
            curr=curr->next;
        }
        
    }
}

void free_list(node *head)
{
    while (head != NULL) {
        node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(int argc, char *argv[])
{
    FILE *fout=fopen("fout.txt", "w");
    int arr[10]={1,2,3,4,5,6,7,8,9}, n=9;
    node *head=NULL;

    // task 1:
    build_list(arr, n, &head);
    print_list(fout, head);

    //task 2:
    if(argc!=3)
    {
        printf("No sufficient arguments!");
        return -1;
    }

    int value_begining_node=atoi(argv[1]);
    int value_end_node=atoi(argv[2]);

    insert_begining(&head, value_begining_node);
    insert_end(head, value_end_node);
    fprintf(fout," \n");
    print_list(fout, head);

    // task 3:
    int n_evenNodes=even_nodes(head);
    fprintf(fout," \n");
    fprintf(fout, "Total even nodes: %d", n_evenNodes);

    //task 4:
    delete_even_nodes(&head);
    fprintf(fout," \n");
    print_list(fout, head);

    close_file(fout);
    free_list(head);
    return 0;
}





    
    