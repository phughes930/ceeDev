#define _GNU_SOURCE
#include "../include/arrfunc.h"
#include "../include/intarr.h"
#include "../include/qsort.h"
#include "../include/sieve.h"
#include <stdint.h>

int validateB(uint32_t b);
int countsetbits(uint32_t b);
uint32_t unsignedpow(uint32_t x, uint32_t y);
struct intarr *getbvals();
struct intarr *getpossibleprimes(struct intarr *b_values);
int isvalidp(uint32_t p);

uint32_t getfnvprime() {
    struct intarr *bvals = getbvals();
    struct intarr *primeposs = getpossibleprimes(bvals);
    uint32_t lowestprime = bigsieve(primeposs);
    return lowestprime;
}

struct intarr *getpossibleprimes(struct intarr *b_values) {
    struct intarr *possibilities = initintarr();
    for (uint32_t s = 5; s < 11; s++) {
        for (int i = 0; i < b_values->len; i++) {
            uint32_t b = b_values->arr[i];

            uint32_t exp1 = (5 + unsignedpow(2, s)) / 12;
            uint32_t p1 = unsignedpow(256, exp1);
            uint32_t p2 = unsignedpow(2, 8) + b;
            uint32_t num = p1 + p2;

            int ispresent;
            if (linsearch(possibilities->arr, possibilities->len, num) == -1) {
                ispresent = 0;
            } else {
                ispresent = 1;
            }

            if (num > 0 && !ispresent && isvalidp(num)) {
                appendint(possibilities, num);
            }
        }
    }
    quicksort(possibilities->arr, 0, possibilities->len - 1);
    return possibilities;
}

int isvalidp(uint32_t p) {
    uint32_t lhs = p % (unsignedpow(2, 40) - unsignedpow(2, 24) - 1);
    uint32_t rhs = unsignedpow(2, 24) + unsignedpow(2, 8) + unsignedpow(2, 7);
    if (lhs > rhs) {
        return 1;
    } else {
        return 0;
    }
}

struct intarr *getbvals() {
    struct intarr *bvals = initintarr();
    for (uint32_t b = 1; b < 256; b++) {
        if (validateB(b)) {
            appendint(bvals, b);
        }
    }
    return bvals;
}

uint32_t unsignedpow(uint32_t x, uint32_t y) {
    uint32_t result = x;

    for (; y > 1; y--) {
        result *= x;
    }
    return result;
}

int validateB(uint32_t b) {
    int bitcount = countsetbits(b);
    if (bitcount == 4 || bitcount == 5) {
        return 1;
    } else {
        return 0;
    }
}

int countsetbits(uint32_t b) {
    int count = 0;
    while (b != 0) {
        count += b & 1;
        b >>= 1;
    }
    return count;
}