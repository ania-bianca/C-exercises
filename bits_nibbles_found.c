#include<stdio.h>
#include<stdint.h>
//Implement a function which receives an uint16_t a number and another uint64 t b 
// and checks whether all the nibbles of a are to be found into b 
// (in the same order but not necessarily adjacent)
//I.e. a=0xAB12 and b=0xAD2B32DFF1C278 is a pair of such numbers;
void check(uint16_t a, uint64_t b)
{
    int nr_nibbles=sizeof(a)*2, nibbles_found=0;
    while (b!=0 && nibbles_found<nr_nibbles)
    {
    uint8_t MSnibble_a=(a>>(sizeof(a)*8-4))&0xF;
    uint8_t MSnibble_b=(b>>(sizeof(b)*8-4))&0xF;
    if(MSnibble_a==MSnibble_b)
    {
        nibbles_found=nibbles_found+1;
        a=(uint16_t)(a<<4);
    }
    b=(uint64_t)(b<<4);
   }
   if(nibbles_found==nr_nibbles)
    printf("Yes\n");
   else
    printf("No\n");
    
}
int main()
{
    check(0xAB12,0xAD2B32DFF1C278);
    return 0;
}