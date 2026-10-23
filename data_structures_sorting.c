#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[51];
    int age;
} Data;

int cmp(const void *pa, const void *pb)// comparison function
// First criteria: age
// Second criteria: name
{
    const Data *p1=pa;
    const Data *p2=pb;
    if(p1->age != p2->age)
        return p1->age - p2->age;
    else
        return strcmp(p1->name, p2->name); // if ages are equal, second tie
}

void sort_qsort(Data *arr, int size )
{   
    qsort(arr, size, sizeof(Data),cmp);
    
}

void sort_bubble_sort(Data *arr, int size )
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-1-i ; j++)
    {
         if(cmp(&arr[j], &arr[j+1])>0)
            {
                Data temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                
            }
    }
    }
        
}

void print_array(Data *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%50s, %d\n", arr[i].name, arr[i].age);
    }
    printf("\n");
}

int main()
{
    Data *arr=malloc(6 * sizeof(Data));
    strcpy(arr[0].name,"Bianca");
    arr[0].name[50]='\0';
    arr[0].age=56;
    strcpy(arr[1].name,"Lucaci");
    arr[1].name[50]='\0';
    arr[1].age=18;
   strcpy(arr[2].name,"Mihaela");
   arr[2].name[50]='\0';
    arr[2].age=19;
    strcpy(arr[3].name,"Bogdan");
    arr[3].name[50]='\0';
    arr[3].age=12;
    strcpy(arr[4].name,"Gogu");
    arr[4].name[50]='\0';
    arr[4].age=5;
    strcpy(arr[5].name,"Luca");
    arr[5].name[50]='\0';
    arr[5].age=50;

    printf("--Array before sorting:\n");
    print_array(arr,6);

    Data *copy = malloc(6 * sizeof(Data));
    memcpy(copy, arr, 6 * sizeof(Data));

    // sorting with 2 methods
    sort_qsort(arr, 6);
    sort_bubble_sort(copy, 6);

    printf("--Array after sorting:\n");
    print_array(arr,6);

    free(copy);
    free(arr);
    return 0;
}
