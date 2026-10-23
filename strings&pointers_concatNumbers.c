#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Implement a function that receives an array of pointers to C-strings and returns a C-string obtained by concate-
//nating the strings from the array which are actually C-floating point numbers (in any C format)
int isFloat(char *s)
{
    char *next;
    strtod(s,&next);
    if(*next=='\0' && s!=next)
        return 1;
    return 0;
}
char *concatenateFloats(char **s)
{
    int n=0;
    int i=0;
    while(s[i]!=NULL)
    {
       if(isFloat(s[i]))
       {
         n=n+strlen(s[i]);
       }
       i++;
    }
    char *result=malloc(n+1);
    if(result==NULL)
    {
        return NULL;
    }
    char *copy=result;
    i=0;
    while(s[i]!=NULL)
    {
       if(isFloat(s[i]))
       { 
         int lenght=strlen(s[i]);
         int j=0;
         while(j<lenght)
         {
            *copy=s[i][j];
            j++;
            copy++;
         }
       }
       i++;
    }
    *copy='\0';
    return result;
}

int main()
{   char *s[]={"12.5","ana",".2", "are", "0.99",NULL};
    char *result=concatenateFloats(s);
    if(result)
    {
        printf("%s\n",result);
        free(result);
    }
    else
        printf("error\n");
    return 0;
}