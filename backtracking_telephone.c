/* Generate all 10 digit telephone numbers which start with 0721 prefix and have 3 distinct even digits. The solutions are
printed in a file called output.txt, one sol per line, with the format:
 prefix *space* other digits ',' 
 
 Ex: 0721 468193,
    0721 864179*/

#include<stdio.h>
#include<stdlib.h>

int s[10]; // array for the 10 digit solution
int even_used_digits[9]={0};

/* Functions*/

FILE *open_file(const char *filename, const char *mode);
void close_file(FILE *f);
void backtrack(int k, FILE *fout);
int is_complete( int k);
int is_valid(int k, int v);
void choose (int k, int v);
void un_choose(int k, int v);
//----------------

FILE *open_file(const char *filename, const char * mode)
{
    FILE *f=fopen(filename, mode);
    if(f==NULL)
    {
        printf("Opening file failed");
        exit(-1);
    }

    return f;
}

void close_file(FILE *f)
{
    if(fclose(f)!=0)
    {
        printf("Closing file failed");
        exit(-1);
    }
}

int is_complete(int k)
{
    if(k>10)    
        return 1;
    return 0;
}

int is_valid(int k, int v)
{
    if(k==1 && v!=0) return 0;
    if(k==2 && v!=7) return 0;
    if(k==3 && v!=2) return 0;
    if(k==4 && v!=1)  return 0;

    if( k>4 && v%2==0)
        if(even_used_digits[v]!=0)
            return 0;

    
    return 1;
}

void choose(int k, int v)
{
    if( k>4 && v%2==0)
        even_used_digits[v]++;
    s[k]=v;
    
}

void un_choose(int k, int v)
{
    if(k>4 && v%2==0)
        even_used_digits[v]--;
}

void backtrack(int k, FILE *fout)
{
    if(is_complete(k))
    {   
        
        int i;
        int even_digits=0;
        for(i=5; i<=10; i++)
        {
            if(s[i]%2==0)
                even_digits++;
        }

        if (even_digits !=3)
            return;

        for(i=1; i<=10; i++)
        {
            if(i==5)
            {
                fprintf(fout, " ");
            }
            fprintf(fout, "%d", s[i]);
        }
        fprintf(fout, ",\n");

        return;
    }

    for(int v=0; v<=9; v++)
    {
        if(is_valid(k,v))
        {
            choose(k,v);
            backtrack(k+1, fout);
            un_choose(k,v);
        }
    }
}




int main()
{
    FILE *fout=open_file("output.txt", "w");

    backtrack(1, fout);

    close_file(fout);
    return 0;
}