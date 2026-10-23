/*Generate all functions f:{1,2,...,n}->{1,2,...,m}
One function is injectiveif and only if x1 and x2 are 2 random elements from the function domain with the property that
if f(x1)=f(x2), then x1=x2

The n and m values are read from a text file called intput.txt, each values are situated on a separate line*/

#include<stdio.h>
#include<stdlib.h>

int n, m;
int f[100];

/*Functions*/
FILE *open_file(const char *filename, const char * mode);
void close_file(FILE *f);
void backtrack(int k);


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

int isInjective() {
    // check: for all x1 != x2, f(x1) != f(x2)
    for (int x1 = 1; x1 <= n; x1++) {
        for (int x2 = x1 + 1; x2 <= n; x2++) {
            if (f[x1] == f[x2]) return 0;
        }
    }
    return 1;
}

int is_complete(int k)
{
    if(k>m)
        return 1;
    return 0;
}

void choose(int k, int v)
{
    f(k)=v;
}

void backtrack(int k)
{
    if(is_complete(k))
    {
        if(!is_injective())
            return;

        int i;
        for(i=1; i<=n; i++)
        {
            printf("f(%d)=%d \n", i, f(i));
        }

        printf("\n");

    }

    for(int v=1; v<=m; v++)
    {
            choose(k,v);
            backtrack(k+1);
    }
}
int main()
{
    FILE *fin=open_file("input.txt", "r");

    if (fscanf(fin, "%d", &n)!=1)
    {
        printf("Reading n failed!!");
        close_file(fin);
        return -1;
    }

    if (fscanf(fin, "%d", &m)!=1)
    {
        printf("Reading m failed!!");
        close_file(fin);
        return -1;
    }

    backtrack(1);

    return 0;

}