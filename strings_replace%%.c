#include<stdio.h>
#include<string.h>

// Write a function that replaces all "%%" substrings in a given string with the values of the elements of a 
// double array multiplied by 100 with exact 1 decimal. DO NOT USE AN AUXILIAR BUFFER. YOU SHOULD MODIFY
//THE GIVEN STRING
char * replace (char *s, double *val, unsigned capacity, unsigned nr_elem)
{
    char *p=&s[0];
    double *v=&val[0];
    while(*p!='\0')
    {
        if(*(p+1)!='\0' && *p=='%' && *(p+1)=='%' && (v-val)<(nr_elem))
        {
            char temp[10];
            *v=*v*100;
            sprintf(temp,"%.1f",*v);
            int shift=strlen(temp)-2;
            if(strlen(s)+ shift < capacity -1)
            {
                int i;
                int start=strlen(s), stop=(p-s)+2; // you stop at the character right after "%%"
                for(i=start;i>=stop;i--)
                    s[i+shift]=s[i];
                char *ptemp=&temp[0];
                while(*ptemp!='\0')
                {   if((p-s)< capacity-1)
                    {*p=*ptemp;
                    ptemp++; p++;}
                }
                
            }v++; p=p+strlen(temp);
        }
        else p++;
    }
    return s;
}
int main()
{   char s[100]="CPU=%% idle, MEM=%% used, %%";
    double val[]={0.237, 0.815};
    printf("%s\n", replace(s,val,100,2));
    return 0;
}