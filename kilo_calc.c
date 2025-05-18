#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

int getUnit(char *s);

int main()
{
    int len, unit;

    size_t ptrSize = 1;
    while (ptrSize > 0) {
        char *ptr = NULL;
        getline(&ptr, &ptrSize, stdin);

        unit = getUnit(ptr);
    }

    return 0;
}

int getUnit(char *s)
{

    if (strcmp(s, "kgs")) {
        return 1;
    } else if (strcmp(s, "lbs")) {
        return 0;
    } else {
        return -1;
    }
}
