#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
_Bool state = 0;
int main(void)
{
    unsigned char b1 = 0b01101111;
    unsigned char b2 = 0b01101111;
    b1 = b1 & b2;
    float res;
    uint32_t x = 1ul<<16;
    res=x/15.0;
    state = !state;
    printf("%.3f bool %d byte %i",res,state, b1);
    return 0;
}
