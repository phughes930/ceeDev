#define _GNU_SOURCE
#include <stdio.h>

int main()
{
    int x = sizeof(long double);
    printf("%d\n", x);
    return 0;
}