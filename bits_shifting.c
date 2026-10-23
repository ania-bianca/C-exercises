#include<stdio.h>
#include<stdint.h>
#include<math.h>
//Write a function that shifts the bits of a 16-bit unsigned integer to the left by n 
// positions. Print each value in hexa and bit by bit.

void print_in_bits(uint16_t value)
{
   
     int i;
     for(i=15;i>=0;i--)
     {
        printf("%d",(value>>i)&1);
        if(i%4==0)
             printf("  ");
     }

    
}
void shift_bits(uint16_t initial, int n)
{
    uint16_t copy=initial;
    while(copy!=0)
    {
        initial=initial<<n;
       printf("this is ur value in hexa: %x\n",(uint16_t)(initial));
       printf("this is ur value in bits: ");
        print_in_bits(initial);
        printf("\n");
       
        copy=copy>>n;

       
    }
}
int main()
{
    shift_bits(0x1A2B,2);
    return 0;
}