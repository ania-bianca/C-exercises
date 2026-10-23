/*A company stores medical supplies in a warehouse. Each section has a temperature sensor.
Given an array of temperatures, find:
• the minimum temperature
• the maximum temperature
using Divide and Conquer.
Example
Input:
21 25 19 30 27 18 24
Output:
Minimum temperature: 18
Maximum temperature: 30 */
# include<stdio.h>

int divide_min_temp(int left, int right, int *arr_temp)
{
    if(left== right)
        return arr_temp[left];
    else{
        
        int m, a, b;
        m=(left+right)/2;
        a=divide_min_temp(left, m, arr_temp);
        b=divide_min_temp(m+1, right, arr_temp);

        if(a<b)
            return a;
        return b;

    }
}

int divide_max_temp(int left, int right, int *arr_temp)
{
    if(left== right)
        return arr_temp[left];
    else{
        
        int m, a, b;
        m=(left+right)/2;
        a=divide_max_temp(left, m, arr_temp);
        b=divide_max_temp(m+1, right, arr_temp);

        if(a>b)
            return a;
        return b;

    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr_temp[n];

    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr_temp[i]);
    }

    printf("Minimum temperature: %d\n", divide_min_temp(0, n-1, arr_temp));
    printf("Maximum temperature: %d\n", divide_max_temp(0, n-1, arr_temp));

}