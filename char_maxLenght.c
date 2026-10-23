#include<stdio.h>
#include<ctype.h>

//Write a program that reads characters one by one using getchar() until EOF and determines:
//the length of the longest word in the input
//A word is a sequence of alphabetic characters (AZ, a–z)
//Any non-alphabetic character ends a word
//Words may be separated by spaces, punctuation, or digits
void reading()
{   int c;
    int lenght=0, maxlenght=0;
    while((c=getchar())!=EOF && c!='\n')
    {
        if(isalpha(c))
        {
            lenght=lenght+1;

        }
        else {
            if(lenght>maxlenght)
                maxlenght=lenght;
            lenght=0;
        }

    }
     if(lenght>maxlenght)
         maxlenght=lenght;
    printf("your maxlenght: %d", maxlenght);
    
}

int main()
{
    reading();
    return 0;
}