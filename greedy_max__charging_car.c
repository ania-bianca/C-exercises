#include<stdio.h>
#include<stdlib.h>
/*We need to charge 𝑁 cars before going on a journey. The 𝑖𝑡ℎ car has an energy capacity 𝐴𝑖 Watt-hours.

There are 𝑀 power outlets. The 𝑗𝑡ℎ outlet provides a power of 𝐵𝑗​ Watt.
If an outlet can charge at most one car and a car can be charged by at most one outlet, find the maximum total energy (in Watt-hours) stored in all cars after 𝐻 hours.
 We will plug some cars in and and then we will leave the charging station for 𝐻 hours, so there is no one to plug in a different car in an outlet in case the currently plugged car finishes charging.

Note:

A power outlet cannot charge a different car even after completely charging a car.
Energy is the product of power and time. For instance, a car can store 10 Watt-hour of energy if it is charged at a power station with 5 Watt power for 2 hours.
Input Format
The first line contains 3 space-separated integers 𝑁, 𝑀, and 𝐻, the number of cars, the number of power outlets, and the number of hours respectively.
The second line contains 𝑁 space-separated integers, the energy capacities (in Watt-hour) of the 𝑁 cars.
The third line contains 𝑀 space-separated integers, the power (in Watt) of the 𝑀 power outlets.
Output Format
Print the maximum total energy (in Watt-hours) stored in all cars after 𝐻 hours.

Examples
1 2 2
100
20 40
==> the total power is 80

2 1 2
10 20
11
==> the total power is 20

3 2 1
30 30 30
40 20
==> the total power is 50*/
int cmp( const void *a, const void *b)
{
    long long p1 = *(long long*)a;
    long long p2 = *(long long*)b;

    if (p1 < p2) return 1;
    if (p1 > p2) return -1;
    return 0;
}

int main()
{
    int N,M;
    long long H;
    
    scanf("%d %d %lld", &N, &M, &H);

    long long A[N], B[M];

    for(int i=0; i<N; i++)
        scanf("%lld", &A[i]);
    for(int j=0; j<M; j++)
        {
            scanf("%lld", &B[j]);
            B[j]=B[j]*H;
        }

    // sorts ascending both arrays
    qsort(A, N, sizeof(long long), cmp);
    qsort(B, M, sizeof(long long), cmp);

    long long maximum_power=0;

    int i=N-1;

    for(int j=M-1; j>=0 && i>=0 ;  j--)
    {
        if(A[i]>= B[j])
        {
            maximum_power= maximum_power+ B[j];
            i--;
        }  
        else
        {
            maximum_power= maximum_power+ A[i];
            i--;
        }
            
    }

    printf("==> the total power is %lld\n", maximum_power);

}
