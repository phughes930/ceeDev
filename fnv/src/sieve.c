#define _GNU_SOURCE
#include "arrfunc.h"
#include "intarr.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printsieve(struct intarr *sieve)
{
    int stop = 0;
    for (int i = 0; i < sieve->len; i++) {
        if (i % 6 == 0 && i > 0) {
            printf("%u\n", sieve->arr[i]);
        } else {
            printf("%u | ", sieve->arr[i]);
        }
    }
    printf("\n");
}

/* sieve: returns a pointer to array of prime numbers less than n*/
void sieve(struct intarr *primes, int start)
{
    uint32_t prod;
    uint32_t start_num = primes->arr[start];
    uint32_t max_mult = primes->arr[primes->len - 1] / start_num;
    if (binsearch(primes->arr, 0, primes->len, start_num) > -1) {
        for (uint32_t mult = 2; mult <= max_mult; mult++) {
            removeval(primes, start_num * mult);
        }
    }

    if (start < primes->len - 1) {
        sieve(primes, ++start);
    }
}

uint32_t bigsieve(struct intarr *possible_primes)
{
    for (int i = 0; i < possible_primes->len; i++) {
        int isprime = 1;
        uint32_t testval = possible_primes->arr[i];
        for (uint32_t div = 2; div < testval; div++) {
            if (testval % div == 0) {
                isprime = 0;
                break;
            }
        }

        if (isprime) {
            return testval;
        }
    }
    return 0;
}