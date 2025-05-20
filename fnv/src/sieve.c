#define _GNU_SOURCE
#include "arrfunc.h"
#include "intarr.h"
#include <stdint.h>
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

void printsieve(struct intarr *sieve)
{
    int stop = 0;
    for (int i = 0; i < sieve->len; i++) {
        if (i % 6 == 0 && i > 0) {
            printf("%d\n", sieve->arr[i]);
        } else {
            printf("%d | ", sieve->arr[i]);
        }
    }
    printf("\n");
}

/* sieve: returns a pointer to array of prime numbers less than n*/
struct intarr *sieve(uint32_t n)
{
    struct intarr *primes = initintarr();
    struct intarr *consec = initintarr();
    for (uint32_t i = 2; i < n; i++) {
        appendint(consec, i);
        appendint(primes, i);
    }
    // printf("PRIMES: \n");
    // printsieve(primes);
    // printf("CONSEC: \n");
    // printsieve(consec);

    int prod;
    int index = 0;
    for (int i = 0; i < consec->len; i++) {
        uint32_t num = consec->arr[i];
        // printf("using num %d\n", num);
        uint32_t prod;
        if (binsearch(primes->arr, 0, primes->len, num) > -1) {
            for (uint32_t j = 2; (prod = num * j) < n; j++) {
                // printf("\tremoving %d\n", prod);
                removeval(primes, prod);
            }
        } else {
            continue;
        }
        /* test debugger */
        // printf("PRINTING PRIMES ITERATION\n");
        // printsieve(primes);
        // if (num >= 3) {
        //     break;
        // }
        /* end test debugger */
    }

    return primes;
}
