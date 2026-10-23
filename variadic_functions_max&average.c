#include<stdio.h>
#include<stdarg.h>
/*1. Write a variadic function "double maxN(int n, ...)" which takes as
 input an int n followed by n double elements. The function returns the
 second largest value among all elements. Write another function that is 
 declared similarly, but calculates the average of the elements.*/

 // Functions:
 double maxN(int n, ...);
 double averageN(int n, ...);

 /*------------------------------- IMPLEMENTATION -----------------------------------------------------------*/
 double maxN(int n, ...)
 { 
    va_list args;
    va_start(args, n);

    double largest_val=va_arg(args, double);
    double second_largest_val=va_arg(args, double);

    if (second_largest_val > largest_val) // swap the 2 elements st largest_val > second_largest_val
    {
        double tmp = largest_val;
        largest_val = second_largest_val;
        second_largest_val = tmp;
    }

    for(int i=2; i<n ;i++)
    {
        double x=va_arg(args, double);
        if(x>largest_val && x>second_largest_val)
        {
            second_largest_val=largest_val;
            largest_val=x;
        }
       else if(x<largest_val && x>second_largest_val)
            {
                second_largest_val=x;
             }
    }

    va_end(args);
    return second_largest_val;

 }

 double averageN(int n, ...)
 {
    va_list args;
    va_start(args, n);

    double sum=0;
    double count=(double)n;

    for(int i=0; i<n; i++)
    {
        double x=va_arg(args, double);
        sum= sum+ x;
    }

    double average=sum/count;
    va_end(args);
    
    return average;
 }
 /*---------------------------------------------------------------------------------------------------------*/
 int main()
 {
    printf("Second largest number: %lf\n", maxN(5, 11.0, 2.0, 56.0, 99.0, 14.0));
    printf("Average: %lf\n", averageN(5, 11.0, 2.0, 56.0, 99.0, 14.0));
    return 0;
 }
