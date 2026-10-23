#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
// Write a program that receives a string, an array and its capacity and copies into the array all words
//from the string. If it is a digit, the word is replaced with the coresponding English word.
void Replace_with_english_words(char *s, char *arr[],int capacity)
{
    int j=0;
    char *p=strtok(s," ");
    char *numbers_words[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    while(p!=NULL&& j<capacity)
    {   char word[100]="";
        for(int i=0;i<strlen(p);i++)
        {   char temp[10]; // temp string for converted characters
            if(isdigit(p[i]))
            { 
                int digit=p[i]-'0';
                strcpy(temp,numbers_words[digit]);
            }
            else {temp[0]=p[i];
                 temp[1]='\0';}
            strcat(word,temp); //attach temp to word
        }
        if (j<capacity){
            arr[j]=malloc(strlen(word)+1); // allocate dynamic strlen +1 because it takes the null terminator
            strcpy(arr[j],word);
            j++;
        }
        p=strtok(NULL," ");
    }
    for(int i=0;i<j;i++)
    {
        printf("%s ",arr[i]);
    }
    printf("\n");
    for(int i=0;i<j;i++)
    {
        free(arr[i]);
    }
}
int main()
{
    char s[]="I have 2 cats and 7 dogs ";
    char *arr[20]; // maxim 20 words and it has a star because it is alocated dynamically
    Replace_with_english_words(s,arr,20);
    return 0;
}