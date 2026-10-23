#include<stdio.h>
#include<string.h>
// Write a function that receives a string (array of chars), an array of floats and it's nr of elements, and 
//another array of strings(result) with it's capacity. Replace all the "%f" substrings with the elements of 
// the float array.
char * replace(char *s,char *result, float *t, int capacity, int nr_elem)
{
    
   char *p=&s[0], *r=&result[0]; // p- pointer to char of s  ,  r- pointer to char of result
   float *ft=&t[0]; // ft- pointer to elem in float
   while(*p!='\0')
   {   
      if(*(p+1)!='\0' && *p=='%' && *(p+1)=='f' && (ft-t)<nr_elem)
      {
            char temp[10];
            sprintf(temp, "%.2f", *ft);
            char *pt=temp; // pt- pointer to temp
            while(*pt!='\0' && (r-result<capacity-1))
            {
                *r=*pt; 
                r++; pt++;
            }
            ft++;
            p=p+2;
      }else{
        *r=*p;
        r++; p++;
      }
   }
   *r='\0';
    return result;
}
int main()
{
    char s[]="ana are %f mere si %f pere %f";
    float t[]={12.5,34.0};
    int capacity=100;
    char result[capacity]; result[0]='\0';
    printf("%s\n",replace(s,result,t, capacity, 2));
    return 0;
}