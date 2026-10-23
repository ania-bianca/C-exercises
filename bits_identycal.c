#include<stdio.h>
#include<stdint.h>
// Write a function that recieves 2 64-bit unsigned nr & return a 8 bit nr.If the bit
// i of the both nrs are identycal, then on pos i of the result has bit 1.

uint8_t identical_byte(uint64_t n1,uint64_t n2)
{
    uint8_t result=0;
    int i;
    for(i=0;i<8;i++)
    {
        uint8_t byte_n1=n1&0xFF, byte_n2=n2&0xFF;  //FF=1111  1111
        if(byte_n1==byte_n2)
            result=result | (1<<i);
        n1=n1>>8;
        n2=n2>>8;
    }
    return result;

}
int main()
{  
    printf("this is ur result: %x\n",identical_byte(0x1478,0x1455));
    return 0;
}