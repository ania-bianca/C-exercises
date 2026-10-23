#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
// You receive via the command line: path to text file, float value. Each line of the file has the format:
//"dd.mm.yyyy NAME float_value,". NAME is a non-empty string without spaces and float_value is a real nr.
//1.FILES MAY CONTAIN ARBITRARLY NR OF LINES (U DON'T KNOW THE NR)
//2.LINES THAT ARE INVALID ARE IGNORED
//Write a program that reads the file line by line(without buffer), selects only the records where the float_value
//is strictly greater than threshold, stores records in dyn alloc structures, then sorts the selected records
//(primarly by NAME, then by date-both ascending) and prints the sorted records.
//NOTE: YOU MUST USE QSORT
typedef struct{
    int dd,mm,yyyy;
    char NAME[20];
    float float_value;
}Student_t;
int isvalid(char *line, float trsh)
{   char day[3], month[3], year[5];
    char name[20];
    float float_value;
    if(sscanf(line, "%2[0-9].%2[0-9].%4[0-9] %19s %f,",day,month, year, name, &float_value)==5)
    {
        int dd=atoi(day), mm=atoi(month), yyyy=atoi(year);
        if(mm>0 && mm<=12 && yyyy!=0 && float_value>trsh)
        {
            if(mm==2)
            {
                if(yyyy%4==0 && dd>0 && dd<=29)
                   {return 1;} 
                else if(yyyy%4!=0 && dd>0 && dd<=28)
                   { return 1;}
                 return 0;
            }else
            {   if(mm<=7)
                { if(mm%2!=0 && dd>0 && dd<=31)
                    return 1;
                 if(mm%2==0 && dd>0 && dd<=30)
                    return 1;
                return 0;
                } 
                else{
                    if(mm%2!=0 && dd>0 && dd<=30)
                        return 1;
                     if(mm%2==0 && dd>0 && dd<=31)
                         return 1;
                     return 0;
                }
                

            }
            return 0;
        }
        return 0;
    }
    return 0;
}
int cmp(const void *p1, const void *p2)
{
    const Student_t *pa=p1;
    const Student_t *pb=p2;
    if(strcmp(pa->NAME,pb->NAME)!=0)
        return strcmp(pa->NAME,pb->NAME);
    else{// if the strings are the same
       if(pa->yyyy!=pb->yyyy)
            return pa->yyyy-pb->yyyy;
       else if(pa->mm!=pb->mm)
                return pa->mm-pb->mm;
            else if(pa->dd!=pb->dd)
                    return pa->dd-pb->dd;
    }
    return 0;// if all fields are equal
}
int program(int argc, char *argv[])
{
    if(argc<3)
    {
        printf("no suff arguments\n");
        return -1;
    }
    float trsh=atof(argv[2]);
    FILE *fp=fopen(argv[1],"r");
    if(fp==NULL)
    {
        printf("no file founded\n");
        return -1;
    }
    char *line=NULL; //getline will allocate this
    size_t capacity=0;// how much memory is allocated
    ssize_t lenght; // lenght takes the value -1 at an ERROR or EOF
    int cap_dyn_alloc=4, i=0;
    Student_t *x=NULL; // inittialize the pointer with NULL to see if it is the first alloc
    while((lenght=getline(&line, &capacity, fp))!=-1)
    {
        if(isvalid(line,trsh))// function that verifies the validation of a line
        {
            if(x==NULL)
            {   x=malloc(cap_dyn_alloc* sizeof(Student_t));
                if(x==NULL)
                {
                    printf("memory alloc failed\n");
                    free(line);
                    fclose(fp);
                    return -1;
                }
                sscanf(line, "%d.%d.%d %19s %f,",&x[i].dd, &x[i].mm,&x[i].yyyy,x[i].NAME,&x[i].float_value);
                i++;
            }
            else{
               if(i==cap_dyn_alloc)
               {cap_dyn_alloc=cap_dyn_alloc*2;
                Student_t *tmp=realloc(x,cap_dyn_alloc* sizeof(Student_t));// create temp to allocate more space
                if(tmp==NULL)
                {
                    printf("memory alloc failed\n");
                    free(x);
                    free(line);
                    fclose(fp);
                    return -1;
                }
                x=tmp;
                }
                sscanf(line, "%d.%d.%d %19s %f,",&x[i].dd, &x[i].mm,&x[i].yyyy,x[i].NAME,&x[i].float_value);
                i++;
            }
    }
    }
    if(x==NULL)
    {
        printf("no valid line\n");
        free(line);
        fclose(fp);
        return -1;
    }
    else{
        int n=i;
        int size_elem=sizeof(Student_t);
        qsort(x,n,size_elem,cmp);
        for(i=0;i<n;i++)
            printf("%d.%d.%d %s %f,\n", x[i].dd, x[i].mm, x[i].yyyy,x[i].NAME,x[i].float_value);
    }
    free(x);
    free(line);
    fclose(fp);
    return 0;

}
int main(int argc, char *argv[])
{  return program(argc,argv);
}