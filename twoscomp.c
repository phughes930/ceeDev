#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i;
    for (i = len - 1; i > -1; i--) {
        unsigned char c = start[i];
        printf(" %.2x", c);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

int main()
{
    int tc = 0xf0000008;
    unsigned int unsign = (unsigned)tc;

    show_int(tc);
    printf("%d\n", tc);
    show_int(unsign);
    printf("%u\n", unsign);

    return 0;
}