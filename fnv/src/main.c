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

int main()
{
    struct intarr *primeposs = initintarr();
    for (uint32_t s = 5; s < 11; s++) {
        for (uint32_t b = 1; b < 256; b++) {
            if (validateB(b)) {
                uint32_t p1 = (uint32_t)(pow(256, (5 + pow(2, s)) / 12));
                uint32_t p2 = (uint32_t)(pow(2, b) + 32);
                uint32_t num = p1 + p2;
                appendint(primeposs, num);
            } else {
                continue;
            }
        }
    }
    quicksort(primeposs->arr, 0, primeposs->len);
    uint32_t max = primeposs->arr[primeposs->len - 1];
    struct intarr *primes = sieve(max);

    uint32_t lowestprime;
    for (int i = 0; i < primeposs->len; i++) {
        int index = binsearch(primes->arr, 0, primes->len, primeposs->arr[i]);
        if (index > -1) {
            lowestprime = primeposs->arr[i];
            break;
        }
    }

    printf("fnv_prime = %d\n", lowestprime);

    return 0;
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