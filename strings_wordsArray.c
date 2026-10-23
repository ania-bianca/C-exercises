#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Implement a function that receives a C-string, and a list of separator characters and returns a NULL-terminated
//array of copies to the ”words” found in the input string. We consider as ”word” a sequence of characters 
// delimited by any of the characters from the list of separators. You shall NOT use strtok!!!
char **constrArray(const char *s,const char *sep)
{
    const char *p=s;
    char lenght[strlen(s)];
    int i=0;
    int count=0;
    while(*p!='\0')
    {   
        while(!strchr(sep,*p) && *p!='\0')
            { p++; lenght[i]++;} 
        if(lenght[i]>0)
        {
             count=count+1;
             i++;
            lenght[i]=0;
        }
        while(strchr(sep,*p) && *p!='\0')
            p++;
          
    }
    if(strchr(sep,s[strlen(s)-1])!=NULL)
        count=count+1;
    if(count==0)
    {
        return NULL;// no words founded
    }
    char **arr=malloc((count+1)*sizeof(char*));
    for(i=0;i<count;i++)
    {
        arr[i]=malloc((lenght[i]+1)* sizeof(char));
    }
     i=0; 
    int j=0;
    while(*s!='\0' && i<count)
    {
        if(!strchr(sep,*s))
        {   j=0;
            while(!strchr(sep,*s) && *s!='\0' && j<lenght[i])
            {
                arr[i][j]=*s;
                s++; 
                j++;
            }
            arr[i][j]='\0';
            i++;
        }
        else{
            s++;
        }
    }
    arr[count]=NULL;
    return arr;
}
int main()
{  char s[]="ana.are 4?mere si.2!camioane", sep[]=". ?!";
    char **arr=constrArray(s,sep);
    for(int i=0;arr[i];i++)
    {
        printf("%s\n",arr[i]);
    }
    free(arr);
    return 0;
}