#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// read from a file input.txt a text, and print in output.txt the nr of
// digits,spaces, char
int main( int argc, char* argv[])
{   if(argc<3)
        {
            printf("more arguments");
            return -1;
        }
    FILE *fp1, *fp2;
    fp1=fopen(argv[1],"r");
    fp2=fopen(argv[2],"w");
    if(fp1==NULL)
    {
        printf("file not found");
        return -1;
    }
    if(fp2==NULL)
    {
        printf("file not found");
        return -1;
    }
    char c;
    int nrspace=0,nrchar=0,nrdigits=0;
    while(fscanf(fp1,"%c",&c)==1)
    {
        if(isdigit(c))
            nrdigits++;
        if(isalpha(c))
            nrchar++;
        if(isspace(c))
            nrspace++;
    }
    fprintf(fp2,"Total numbers:%d\n",nrdigits);
    fprintf(fp2,"Total characters:%d\n",nrchar);
    fprintf(fp2,"Total space:%d\n",nrspace);
    fclose(fp1);
    fclose(fp2);

    return 0;
}