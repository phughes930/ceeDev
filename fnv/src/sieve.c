#define _GNU_SOURCE
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct intarr {
    int *arr;
    int len;
};

struct intarr *initintarr()
{
    struct intarr *new = malloc(sizeof(struct intarr));
    new->arr = NULL;
    new->len = 0;

    return new;
}

void appendint(struct intarr *array, int new)
{
    int *array2 = realloc(array->arr, array->len + 1);
    if (array2 == NULL) {
        return;
    }
    array2[array->len] = new;
    array->arr = array2;
    array->len += 1;
}

int binsearch(int *arr, int low, int high, int find)
{
    if (low < high) {
        int mid = low + (high + low) / 2;

        if (arr[mid] == find) {
            return mid;
        } else if (arr[mid] > find) {
            return binsearch(arr, mid + 1, high, find);
        } else if (arr[mid] < find) {
            return binsearch(arr, low, mid - 1, find);
        }
    } else {
        return -1;
    }
}

void removeindex(struct intarr *array, int index)
{
    if (index < array->len) {
        int *newarr[array->len - 1];
        for (int i = 0; i < array->len; i++) {
            if (i == index)
                continue;

            newarr[i] = array->arr[i];
        }
        free(array->arr);
        array->arr = newarr;
        array->len -= 1;
    }
}

void removeval(struct intarr *array, int remval)
{
    int rem;
    if ((rem = binsearch(array->arr, 0, array->len - 1, remval)) < 0) {
        return;
    }
    removeindex(array, rem);
}

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