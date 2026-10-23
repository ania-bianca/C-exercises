#include<stdio.h>
#include<stdint.h>
//   Write a function that constructs a 64-bit unsigned result using alternating bit blocks
//The nibbles of pattern are processed from MS to LS. Each nibble is a block-lenght:
// values 0-7 have exact lenght and values 8-15 have lenght-8. Seed (starting bit) is 1.
// Bit value changes afer every non 0 block and construction stops wgen 64 bits are filled
//or digits are exhausted.
uint64_t weave_bits(uint64_t pattern,uint8_t seed)
{   uint64_t result=0;
    unsigned lenght_result=0;
    while(pattern!=0 && lenght_result<64)
    {
        int lenght;
        uint8_t firstnibble;
        firstnibble=(pattern>>(sizeof(pattern)*8-4))&0xF;
        lenght=(int)firstnibble;
         if(lenght<=15 && lenght>=8)
            lenght=lenght-8;
        if( lenght!=0)
        {
            while(lenght!=0 && lenght_result<64)
            {
                result=result|((uint64_t)(seed&0x1)<<(63-lenght_result));
                lenght--;
                lenght_result++;
            }
            seed=seed^0x1;
        }
       pattern=pattern<<4;
    }
    return result;

}
int main()
{
    printf("this is ur result:%lx ",weave_bits(0xA203,0x1));
    return 0;
}