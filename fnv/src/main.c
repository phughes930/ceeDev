#define _GNU_SOURCE
#include "arrfunc.h"
#include "intarr.h"
#include "qsort.h"
#include "sieve.h"
#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int validateB(uint32_t b);
int countsetbits(uint32_t b);
uint32_t doubletounsignedint(double num);
uint32_t unsignedpow(uint32_t x, uint32_t y);
int comp(const void *a, const void *b);

int main()
{
    struct intarr *bvals = initintarr();
    for (uint32_t b = 1; b < 256; b++) {
        if (validateB(b)) {
            appendint(bvals, b);
        }
    }

    struct intarr *primeposs = initintarr();
    for (uint32_t s = 5; s < 11; s++) {
        for (int i = 0; i < bvals->len; i++) {
            uint32_t b = bvals->arr[i];

            uint32_t exp1 = (5 + unsignedpow(2, s)) / 12;
            uint32_t p1 = unsignedpow(256, exp1);

            uint32_t p2 = unsignedpow(2, b) + 32;

            uint32_t num = p1 + p2;
            if (num > 0 && linsearch(primeposs->arr, primeposs->len, num) == -1) {
                appendint(primeposs, num);
            }
        }
    }
    quicksort(primeposs->arr, 0, primeposs->len - 1);

    uint32_t lowestprime;
    for (int i = 0; i < primeposs->len; i++) {
        struct intarr *primes = sieve(primeposs->arr[i] + 1);

        int index = binsearch(primes->arr, 0, primes->len, primeposs->arr[i]);
        if (index > -1) {
            lowestprime = primeposs->arr[i];
            free(primes);
            break;
        }
        free(primes->arr);
        primes->arr = NULL;
    }

    // printf("fnv_prime = %u\n", lowestprime);

    return 0;
}

int comp(const void *a, const void *b)
{
    return (a - b);
}

uint32_t unsignedpow(uint32_t x, uint32_t y)
{
    uint32_t result = x;

    for (; y > 1; y--) {
        result *= x;
    }
    return result;
}

uint32_t doubletounsignedint(double num)
{
    if (num >= 0 && num <= UINT32_MAX) {
        return (uint32_t)num;
    }
}

int validateB(uint32_t b)
{
    int bitcount = countsetbits(b);
    if (bitcount == 4 || bitcount == 5) {
        return 1;
    } else {
        return 0;
    }
}

int countsetbits(uint32_t b)
{
    int count = 0;
    while (b != 0) {
        count += b & 1;
        b >>= 1;
    }
    return count;
}