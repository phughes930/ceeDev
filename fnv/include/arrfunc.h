#ifndef ARRFUNC_H
#define ARRFUNC_H
#include <stdint.h>

struct intarr *initintarr();
void appendint(struct intarr *array, uint32_t newval);
int binsearch(uint32_t *arr, int low, int high, uint32_t find);
void removeindex(struct intarr *array, int index);
void removeval(struct intarr *array, uint32_t remval);
int linsearch(uint32_t *arr, int len, uint32_t find);

#endif