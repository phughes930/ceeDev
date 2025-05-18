#define _GNU_SOURCE
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 2**8 = 256 = 0100000000 --octal--> 04000
    // smallest = 01111 = 1+2+4+8 = 15 = F
    u_int32_t n = pow(256, (double)((5 + pow(2, 5)) / 12)) + pow(2, 8) + 32;
    printf("%d\n", n);
    return 0;
}