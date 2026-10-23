#include<stdio.h>
#include<stdint.h>
//  Write a function that takes 2 unsigned nr and makes the result with pairs of bits
//  (ex : a0b0, a1b1...). Print the result in hex.
void construct_encoding(uint32_t a, uint32_t b)
{
    uint64_t result=0;
    int i;
    for(i=32;i>0;i--) // this is made 32 times because a and b are declared on 32 bits
    {
        uint64_t lsb_a=a&0x1, lsb_b=b&0x1;
        uint64_t pair=(lsb_a<<1) | lsb_b;
        result= (result<<2) | pair;
        a=a>>1;
        b=b>>1;
    } 
     printf("this is ur result in hexa : %lx",result);
}
int main()
{
    construct_encoding(0x123,0x111);
    return 0;
}