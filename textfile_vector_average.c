#include<stdio.h>
#include<stdlib.h>
//Write a program that prints on screen the average of a vector that was allocated dynamic and read from file.txt
int main( int argc, char* argv[])//argc e nr de argumente, iar argv[] e ca un vector in care sunt argumentele "./out file.txt"
{
    if(argc<2)
    {
        printf("nu sunt destule argumente");
        return -1;
    }
    FILE * fp;
    fp=fopen(argv[1],"r");
    if(fp== NULL) //adica nu gaseste fisier - cand nu il gaseste returneaza NULL
    {   printf("nu exista fisier");
        return -1;
    }
    int n;
    fscanf(fp,"%d",&n);
    int* v=(int*) malloc(n*sizeof(int));
    int i,sum=0;
    printf("n = %d\n", n);
    for(i=0;i<n;i++)
        fscanf(fp,"%d",&v[i]);
    for(i=0;i<n;i++)
        sum=sum+v[i];
    double average;
    average=(double) sum/n;
    printf("%f",average);
    fclose(fp);
    return 0;

}