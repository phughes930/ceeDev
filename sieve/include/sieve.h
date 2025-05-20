#ifndef SIEVE_H
#define SIEVE_H

struct intarr *multiples(int p, int n);
struct intarr *sieve(int n);
void printsieve(struct intarr *sieve);

#endif