#include<stdio.h>
#include<stdint.h>
// Write a function that prints the starting and stopping bit-index of a subsequence of
//alternating bits (0101..). The values will be printed withe the symbol "-" between them.

void print_index(uint64_t number)
{
    int i, ok=0, nr_printings=0;
    for(i=0;i<63;i++)
    {   uint8_t current_bit=(number>>i)& 1;
        uint8_t next_bit=(number>>(i+1))& 1;
        if(ok==0 && current_bit!=next_bit)
        {
            printf("%d-",i); ok=1; nr_printings++;
        }
        if (ok==1 && current_bit==next_bit)
        {
            printf("%d\n",i); ok=0; nr_printings++;
        }
    }
    if(nr_printings%2!=0)
        {
            int n=sizeof(number)*8;
            if(((number>>n)&1) ==(1^((number>>(n-1))&1)))
                printf("%d\n",n);
        }
    if(nr_printings==0)
        printf("no sequences founded\n");
}
int main()
{   print_index(0x505);
    return 0;
}