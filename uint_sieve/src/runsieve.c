#define _GNU_SOURCE
#include "arrfunc.h"
#include "intarr.h"
#include "sieve.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: sieve <lim>\n");
        return -1;
    }

    int lim = atoi(argv[1]);

    struct intarr *primenos = sieve(lim);

    printsieve(primenos);

    return 0;
}
