#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// Write a program that reads a HTML command as the form "<a href="link"><ClickIndex></a> " and prints
//the URL links in alphabetical order using qsort.
int compare(const void *ps1,const void *ps2)
{
    return strcmp(ps1,ps2);
    
}
void URL_alphabetical()
{
    int i=0,n=0,click,ok=0;
    char s[101];
    char arr[10][101];
    while(fscanf(stdin,"<a href=\"%101[^\"]\"><Click%d></a> ",s,&click)==2)
    {  ok=1;
       strcpy(arr[i],s);
       i++;
    }
    n=i;
    if(ok==0)
        printf("no input\n");
    else if(n==1)
        printf("%s",arr[0]);
    else {qsort(arr,n, sizeof(arr[0]),compare);
            for(i=0;i<n;i++)
            {
                printf("s[%d]: %s\n",i,arr[i]);
            }
    }
}
int main()
{
    URL_alphabetical();
    return 0;
}