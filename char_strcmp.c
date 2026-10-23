#include<stdio.h>
int my_strcmp_with_pointers(char *s1, char *s2)// strings ex1
{
    int i=0;
    
    while(s1[i]!='\0'&& s2[i]!='\0')
    {
       if(s1[i]!=s2[i])
        return s1[i]-s2[i];
         i++;
    }
    if(s1[i]=='\0'&& s2[i]!='\0')
        return -1;
    if(s2[i]=='\0'&& s1[i]!='\0')
        return 1;
    return 0;
}
//io ex1

int main()
{
    char *s1="ama", *s2="anam";
    printf("%d\n",my_strcmp_with_pointers(s1,s2));
    char buffer[100];
    while(fgets(buffer,sizeof(buffer),stdin))
    return 0;
}