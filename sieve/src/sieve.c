#define _GNU_SOURCE
#include "arrfunc.h"
#include "intarr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct intarr *multiples(int p, int n)
{
    struct intarr *array = initintarr();
    int prod;
    for (int i = p; (prod = p * i) < n; i++) {
        appendint(array, prod);
    }
    return array;
}

/* sieve: returns a pointer to array of prime numbers less than n*/
struct intarr *sieve(int n)
{
    struct intarr *primes = initintarr();
    for (int i = 2; i < n; i++) {
        appendint(primes, i);
    }

    int prod;
    int index = 0;
    while (index < primes->len) {
        for (int i = 1; (prod = primes->arr[index] * i) < n; i++) {
            removeval(primes, prod);
        }
        index++;
    }

    return primes;
}

void printsieve(struct intarr *sieve)
{
    int stop = 0;
    for (int i = 0; i < sieve->len;) {
        if (i + 6 < sieve->len)
            stop = i + 6;
        else
            stop = sieve->len;

        while (i < stop) {
            if (i < stop - 1)
                printf("%s |", sieve->arr[i]);

            if (i == stop - 1)
                printf("%s \n", sieve->arr[i]);
        }
    }
}