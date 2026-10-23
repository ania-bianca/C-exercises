/* Consider a binary file that is composed out of an unknown/unlimited number of unsigned 4 byte integers. 
    Write a C program that reads such a file and stores all the number it reads into a sorted simple linked list. The list shall be
    build directly sorted and not sorted at the end afterwards. If a number is found more than once in a file, then it will not be
    added to the list again but an occurence counter will be updated for that number.

    Design the correct and optimal data structure that contains the unsigned integer and the number of occurrences. The input file
    shall be given as the first argument. The second argument shall contain the path to a text output file which shall contain the 
    precentage distribution of numbers that were read from the file. The file shall contain a row for each unique number with the 
    following information and the following format:

        <number> : <number_of_occurrences> : precentage of occurences
        Example:
        124 : 23 : 9.28%
        14567 : 2 : 0.17%

    The efficiency of your program shall be greatly considered when grading.
    The dimension of the input file shall be considered unknown. The program must work in any situation regardless of the file size.

    Error handling is mandatory. Your program must be as error proof as possible.(error checking sugestions: argument correctness,
    memory allocation, file operations- open, read, write- correctness... etc).

    The test files to be used shall be:
        https://staff.cs.upt.ro/-valy/pt/file3a.bin
        https://staff.cs.upt.ro/-valy/pt/file2.bin

    The files can be downloadd using wget command (download using a standard browser is not recommended).
*/

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/*Structures:*/
typedef struct node{

    unsigned int number;
    long long int number_of_occurences;
    struct node *next;
}node;


/* Functions:*/
FILE *open_file(const char *filepath, const char *mode);
void close_file(FILE *f);
void free_list(node *head);
void insert_and_update(node **head, unsigned int number_bin);




FILE *open_file(const char *filepath, const char *mode)
{
    FILE *f=fopen(filepath, mode);
    if(f==NULL)
    {
        printf("Error!! Opening file failed !!");
        exit(-1);
    }
    return f;
}

void close_file(FILE *f)
{
    if(fclose(f)!=0)
    {
        printf("Error!! Closing file failed !!");
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

void insert_and_update(node **head, unsigned int number_bin)
{
    node *prev=NULL;
    node* current=*head;


    // if the given number is greater than the current pointer, move forward
    while(current!=NULL && current->number < number_bin)
    {
        prev=current;
        current=current->next;
    }

    // case where the number is equal to current
    if(current!=NULL && current->number== number_bin)
    {
        current->number_of_occurences++;
        return;
    }
    
    // create a new node
    node *new=malloc(sizeof(node));
    if(new==NULL)// check if allocation succeed
    {
        printf("Memory allocation failed");
        exit(-1);
    }
    new->number=number_bin;
    new->number_of_occurences=1;
    new->next=current;

    if(prev==NULL)
    {
        *head=new;
    }else
    {
        prev->next=new;
    }
}


int main(int argc, char *argv[])
{
    // verify if there are enough arguments
    if(argc !=3)
    {
        printf("Not enough arguments in the command line. Try again!!");
        exit(-1);
    }

    // opening both input/ output files
    FILE *fin=open_file(argv[1],"rb"); 
    FILE *fout=open_file(argv[2],"w");

    unsigned int number_bin; // unsigned nr declared on 4 bytes=4*8=32 bits- numbers read from the binary file
    node *head=NULL; // initialise list- empty list
    long long int total=0;

    while( fread(&number_bin, sizeof(unsigned int), 1, fin)==1 ) // loop that reads and stores each number from the binary file
    {
        insert_and_update(&head, number_bin);
        total++;
    }

    // writing into the text file
    for(node *current=head ;current!=NULL; current=current->next)
    {
        double distribution=((double)(current->number_of_occurences)*100)/total;
        fprintf(fout, "%u : %lld : %.2f%%\n", current->number, current->number_of_occurences, distribution);
    }

    free_list(head);
    close_file(fin);
    close_file(fout);


    return 0;
}

