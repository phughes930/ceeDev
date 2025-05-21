#ifndef QSORT_H
#define QSORT_H
#include <stdint.h>

/* quicksort: sort items in arr starting from index low to index high */
void quicksort(uint32_t *arr, int low, int high);

#endif