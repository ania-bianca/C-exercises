#include<stdio.h>
#include<stdlib.h>
//reads n and n numbers from a file, and then in another file, prints only the even nr
int main (int argc,  char* argv[])
{
   if(argc<3)
   {
       printf("no sufficient arguments");
       return -1;
   }
   FILE* fp1, *fp2;
    fp1=fopen(argv[1],"r");
    if(fp1==NULL)
    {
        printf("file not found");
        return -1;
    }
    fp2=fopen(argv[2],"w");
    if(fp1==NULL)
    {
        printf("file not found");
        return -1;
    }
    int n;
    if(fscanf(fp1,"%d",&n)!=1)
    {
        printf("reading error");
        return -1;
    }
    int* v=(int*) malloc(n* sizeof(int));
    if(v==NULL)
    {
        printf("memory alloc failed");
        return -1;
    }
    int i;
    for(i=0;i<n;i++)
    {
       if(fscanf(fp1,"%d",&v[i])!=1)
        {
             printf("reading error");
             return -1;
        }
        if(v[i]%2==0)
            fprintf(fp2,"%d\n",v[i]);
    }    
    free(v);
    fclose(fp1);
    fclose(fp2);

    return 0;
}