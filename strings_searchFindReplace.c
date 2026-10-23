#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Implement a C function that will find, search and replace text strings. Receives three strings 
// (s1, s2 and s3) and replaces all the occurrences of string s2 into the first string (s1), with the third 
// string (s3), returning the new string. The replacement phrase can be shorter or longer than the searched 
// for phrase. Show the updated initial line of text on the display.

char *searchFind_replace(char *s1, char *s2, char *s3)
{
   char *p=s1;
   int k=0;
   while(*p!='\0')
   {  char *found=strstr(p,s2);
      if(p==found)
      {
        k++;
        p=p+strlen(s2);
      }
      else
        p++;
   }
   if(k==0)
   {
        return NULL;
   }
   k=strlen(s1)-k*strlen(s2)+k*strlen(s3);
   char *arr=malloc((k+1)*sizeof(char));
   if(arr==NULL)
   {
     return NULL;
   }
   char *dest=arr;
   p=s1;
   while(*p!='\0')
   {  char *found=strstr(p,s2);
      if(p==found)
      {
        char *ps3=s3;
        while(*ps3!='\0')
        {
            *dest=*ps3;
            dest++; ps3++;
        }
        p=p+strlen(s2);
      }
      else
       {  *dest=*p ; dest++; p++; } 
   }
   *dest='\0';
   return arr;

}
int main()
{   char s1[]="ana are 700 de mere si 2 pere", s2[]="ana", s3[]="tata";
    char *result=searchFind_replace(s1,s2,s3);
    if()
    printf("%s",result);
    free(result);
    
}