#include <stdio.h>

int main()
{
    int n = 1;
    if (*(char *)&n == 1) {
        printf("System is little endian\n");
    } else {
        printf("System is big endian\n");
    }

    return 0;
}