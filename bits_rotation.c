#include<stdint.h>
#include<stdio.h>
// write a function that rotates the bits of n by k positions
uint16_t rotate_bits(uint16_t n, unsigned k)
{   
    unsigned bits_of_n=sizeof(n)*8;
    k=k%bits_of_n;
    while(k!=0)
    {
        uint16_t first_bit=n&0x8000;
        n=(n<<1) | (first_bit>>15) ;
        k--;

    }
    return n;

}
int main()
{
    printf("this is the result: %x\n", rotate_bits(0x0123,11));
    return 0;
}