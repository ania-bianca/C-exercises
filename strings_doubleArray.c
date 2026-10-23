#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
// Write a function double* copyFloats(const char *s, unsigned *n); that returns an array of doubles, con-
//sisting of all the float constants found into string s. Consider floats as being written in any acceptable 
// C format.  Set value pointed by n to the number of elements from the returned array. You shall NOT use strtok!!!
double * copyFloats(const char *s, unsigned *n)
{   
    int count=0;
    const char *p=s;
    char *next;
    while(*p!='\0')
    {  strtod(p,&next); // strtod moves the pointer next to the next char after a float
        if(p!=next)// it founded a float
        {
            count++;
            p=next; // skipps the float
        }
        else
            p++;
    }
    int m=count;
    if(count==0)
    {
       *n=0; // no floats founded
        return NULL;
    }
    double *arr=malloc(m*sizeof(double));
    if(arr==NULL)
    {
        return NULL;// allocation failed
    }
    int i=0;
    p=s;
    while(i<m)
    {
       double value=strtod(p,&next); // is taking the double value
       if(p!=next)
       {
         arr[i]= value;
         i++;
         p=next;
       }
       else 
            p++;
    }
    *n=count;
    return arr;
}
int main()
{   char s[]="ana are 17.5 mere, 5. pere.9 si 2 caise.";
    unsigned n;
    double *arr=copyFloats(s,&n);
    for(int i=0; i<n; i++)
    {
        printf("%lf ", arr[i]);
    }
    return 0;
}