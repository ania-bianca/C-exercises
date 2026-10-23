#include<stdio.h>
#include<stdlib.h>
typedef struct{
   unsigned x, y;
}Point2D;

typedef struct{
    float radius;
    Point2D center;
}circle;
typedef struct{
    Point2D point1, point2, point3;
    
}triangle;
typedef struct{
    Point2D point1, point2, point3, point4;
}rectangle;


typedef enum{CIRCLE, TRIANGLE ,RECTANGLE}TypeObj;

typedef struct{
    TypeObj type;
    union{
        circle C;
        triangle T;
        rectangle R;
    }u;
}Shapes;

void add_circle(int i, Shapes *list_shapes)
{
    printf("Type the lenght of radius (float point value):");
    scanf("%f",&list_shapes[i].u.C.radius);
    printf("Type the x coordinate of center:");
    scanf("%d",&list_shapes[i].u.C.center.x);
    printf("Type the y coordinate of center:");
    scanf("%d",&list_shapes[i].u.C.center.y);
}
void add_triangle(int i, Shapes *list_shapes)
{   
    printf("Type the x an y coord of point1 (format: 2 unsigned separated by a comma):");
    scanf("%d,%d",&list_shapes[i].u.T.point1.x, &list_shapes[i].u.T.point1.y);
    printf("Type the x an y coord of point2 (format: 2 unsigned separated by a comma):");
    scanf("%d,%d",&list_shapes[i].u.T.point2.x, &list_shapes[i].u.T.point2.y);
    printf("Type the x an y coord of point3 (format: 2 unsigned separated by a comma):");
    scanf("%d,%d",&list_shapes[i].u.T.point3.x, &list_shapes[i].u.T.point3.y);
    
}
void add_rectangle(int i, Shapes *list_shapes)
{   
    printf("Type the x an y coord of point1 (format: 2 unsigned separated by a comma):");
    scanf("%d,%d",&list_shapes[i].u.R.point1.x, &list_shapes[i].u.R.point1.y);
    printf("Type the x an y coord of point2 (format: 2 unsigned separated by a comma):");
    scanf("%d,%d",&list_shapes[i].u.R.point2.x, &list_shapes[i].u.R.point2.y);
    printf("Type the x an y coord of point3 (format: 2 unsigned separated by a comma):");
    scanf("%d,%d",&list_shapes[i].u.R.point3.x, &list_shapes[i].u.R.point3.y);
    printf("Type the x an y coord of point4 (format: 2 unsigned separated by a comma):");
    scanf("%d,%d",&list_shapes[i].u.R.point4.x, &list_shapes[i].u.R.point4.y);
}
 void print_list_of_shapes(int n, Shapes *list_shapes)
 {  
    for(int i=0;i<n;i++)
    {   printf("Object %d: ",i);
        if(list_shapes[i].type==CIRCLE)
        {
            printf("Circle--> radius:%f, (%d,%d)\n",list_shapes[i].u.C.radius,list_shapes[i].u.C.center.x,list_shapes[i].u.C.center.y);
        }
        else if(list_shapes[i].type==TRIANGLE)
        {
            printf("Triangle--> (%d,%d), (%d,%d), (%d,%d)\n",list_shapes[i].u.T.point1.x,list_shapes[i].u.T.point1.y,list_shapes[i].u.T.point2.x,list_shapes[i].u.T.point2.y,list_shapes[i].u.T.point3.x,list_shapes[i].u.T.point3.y);
        }
        else if(list_shapes[i].type==RECTANGLE)
        {
            printf("Rectangle--> (%d,%u), (%d,%d), (%d,%d), (%d,%d)\n",list_shapes[i].u.R.point1.x,list_shapes[i].u.R.point1.y,list_shapes[i].u.R.point2.x,list_shapes[i].u.R.point2.y,list_shapes[i].u.R.point3.x,list_shapes[i].u.R.point3.y,list_shapes[i].u.R.point4.x,list_shapes[i].u.R.point4.y);
        }
    }
 }


int main()
{   int n=4;
    Shapes *list_shapes=malloc(n*sizeof(Shapes));
    if(list_shapes==NULL)
    {
        printf("!!MEMORY ALLOCATION FAILED!!\n");
        return -1;
    }
    int i=0, to_do=-1;
    while(to_do!=0)
    {
         printf("What do u want to do?\n Press(0-Exit, 1-Add element, 2-Print list):");
         scanf("%d",&to_do);
         if(to_do==1)
         {  if(i==n)
            {   n=n*2;
                Shapes *temp=realloc(list_shapes,n*sizeof(Shapes));
                if(temp==NULL)
                {
                    printf("!!MEMORY ALLOCATION FOR TEMP FAILED!!\n");
                    free(list_shapes);
                    return -1;
                }
                list_shapes=temp;
            }
            printf("What shape do u want to add?\n Press(0-Circle, 1-Triangle, 2-Rectangle):");
            scanf("%d",(int *)&list_shapes[i].type);
            if(list_shapes[i].type==CIRCLE)
            {
                add_circle(i,list_shapes);
                printf("Shape successfully added!\n");
                i++;
            }
            else if(list_shapes[i].type==TRIANGLE)
            {
                add_triangle(i,list_shapes);
                printf("Shape successfully added!\n");
                i++;
            }
            else if(list_shapes[i].type==RECTANGLE)
            {
                add_rectangle(i,list_shapes);
                printf("Shape successfully added!\n");
                i++;
            }

         }
        else if(to_do==2)
         {
            printf("This is your list of shapes:\n");
            printf("-----------------------------------------------------------\n");
            print_list_of_shapes(i,list_shapes);
            printf("-----------------------------------------------------------\n");
         }
    }
    free(list_shapes);

    return 0;
}