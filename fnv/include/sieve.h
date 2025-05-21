#ifndef SIEVE_H
#define SIEVE_H
#include <stdint.h>

void sieve(struct intarr *primes, int start);
uint32_t bigsieve(struct intarr *primes);
void printsieve(struct intarr *sieve);

#endif