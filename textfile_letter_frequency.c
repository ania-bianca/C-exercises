/* 
    Write a program that computes the letter frquency of a text file given as the first argument to the program. The program shall
write the result into an output text file given as the second argument. The letter frequency represents the precentage of 
appearance of each letter in a text. The letters that shall be included in the letter frequency shall be the uppercase and 
lowercase letters. All the other characters that are present in the text shall be included in the statistic all the same category
defined as other.
    The output text file shall have the following structure: each line shall contain the letter and precentage of appearance :
    <letter> - <precentage>
    
    Example:
        a - 24.73%
        b - 2.31%
    
    The precentage shall be calculated in floating point with double precision.
    It is mandatory for the program to receive the filenames as arguments.
    The dimension of the file is considered unknown. The program mustwork in any situation regardless of the file size.    */

#include<stdio.h>
#include<stdlib.h>

FILE *open_file(const char *filename, const char *mode);
void close_file(FILE *fp);

FILE *open_file(const char *filename, const char *mode)
{
    FILE *fp= fopen(filename, mode);
    if(fp==NULL)
    {
        printf("!!Opening file failed");
        exit(-1);
    }

    return fp;
}

void close_file(FILE *fp)
{
    if(fclose(fp)!=0)
    {
        printf("!!Closing file failed");
        exit(-1);
    }
}

int main(int argc, char *argv[])
{
    if(argc !=3)
    {
        printf("No sufficient arguments!!");
        return -1;
    }

    FILE *fin=open_file(argv[1], "r");
    FILE *fout=open_file(argv[2], "w");

    long long int total_others=0, total_characters=0;
    long long int freq_upper[26]={0}, freq_lower[26]={0};
    int c;

    while((c=fgetc(fin))!=EOF)
    {
        if( c>= 'a' && c<='z')
        {
            freq_lower[c-'a']++;
        }
        else if( c>= 'A' && c<='Z')
            {
                freq_upper[c-'A']++;

            }
            else total_others++;
        
        total_characters++;
    }

    if(total_characters==0)
    {
        fprintf(fout, "Empty input file !!");
        close_file(fin);
        close_file(fout);
        return -1;
    }

    int i; 
    
    for(i=0; i<26; i++)
    {
        if(freq_lower[i]!=0.0)
        {
            int c='a'+i;
            double precentage= (double)(freq_lower[i]*100) / total_characters;
            fprintf(fout, "%c - %.2f%%", c, precentage);
            fprintf(fout, " \n");
        }
    }

    for(i=0; i<26; i++)
    {
        if(freq_upper[i]!=0.0)
        {
            int c='A'+i;
            double precentage= (double)(freq_upper[i]*100) / total_characters;
            fprintf(fout, "%c - %.2f%%", c, precentage);
            fprintf(fout, " \n");
        }
    }

    double precentage= (double)(total_others*100) / total_characters;
    fprintf(fout, "others - %.2f%%", precentage);

    close_file(fin);
    close_file(fout);
    return 0;
}

