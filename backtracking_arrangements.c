/* Determine an arrangement of N integers, so when placed in a circle, the sum of the all multiplication of integers on consecutive
positions is maximum. The value N is readfrom a text file called input.txt and the solutions are printed in another text file
called output.txt, one solutions on each line, integers separated by "-".

Ex: N=6 and nr={1,2,3,4,5,6} solution = 1-2-4-6-5-3 for which the sum is 
    1*2+ 2*4+ 4*6+ 6*5 + 5*3 + 3*1= 82*/

#include<stdio.h>
#include<stdlib.h>

int N;
int s[100];        // s[k] = the number placed at position k
int used[100];      // used[v] = 1 if number v is already placed somewhere
int best_sum = -1;   // best sum found so far (start impossibly low)
int best_s[100];     // the arrangement that achieved best_sum

/*Functions*/
FILE *open_file(const char *filename, const char * mode);
void close_file(FILE *f);

FILE *open_file(const char *filename, const char * mode)
{
    FILE *f=fopen(filename, mode);
    if(f==NULL)
    {
        printf("Opening file failed!!");
        exit (-1);
    }

    return f;
}

void close_file(FILE *f)
{
    if(fclose(f)!=0)
    {
        printf("Closing file failed!!");
        exit(-1);
    }
}

int is_complete(int k)
{
    if(k >N)
        return 1;
    return 0;
}

int is_valid(int k, int v)
{
    if(used[v]==0)
        return 1;
    return 0;
}

void choose(int k, int v)
{
    s[k]=v;
    used[v]=1;
}

void un_choose(int v)
{
    used[v]=0;
}

int compute_sum() {
    int sum = 0;
    int i;
    for (i = 1; i < N; i++) {
        sum += s[i] * s[i+1];
    }
    sum += s[N] * s[1];   // the wrap-around pair closing the circle
    return sum;
}

void backtrack(int k) 
{
    if (is_complete(k)) {
        int sum=compute_sum();
        if(sum >best_sum)
        {
            best_sum=sum;
            for(int i=1; i<=N; i++)
                best_s[i]=s[i];
        }
        return;
    }
    for (int v=1; v<=N; v++) {
        if (is_valid(k, v)) {
            choose(k, v);        // place v at position k
            backtrack(k + 1);    // go solve the rest
            un_choose(v) ;     // remove v, so the loop can try the next v
        }
    }
}



int main()
{
    FILE *fin=open_file("input.txt", "r");
    FILE *fout=open_file("output.txt", "w");

    if (fscanf(fin, "%d", &N)!=1)
    {
        printf("Wrong input into the file!!");
        close_file(fin);
        close_file(fout);
        return -1;
    }

    backtrack(1);

    // writing the solution into the output file
    for(int i=1; i<=N; i++)
    {
        if(i!=N)
            fprintf(fout, "%d - ", best_s[i] );
        else
        {
            fprintf(fout, "%d", best_s[i]);
        }
    }
    
    close_file(fin);
    close_file(fout);
    return 0;
}
