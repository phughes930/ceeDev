#define _GNU_SOURCE
#include "../include/intarr.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct intarr *initintarr() {
    struct intarr *newarr = malloc(sizeof(struct intarr));
    newarr->arr = NULL;
    newarr->len = 0;

    return newarr;
}

void appendint(struct intarr *array, uint32_t newval) {
    uint32_t *array2 = realloc(array->arr, sizeof(uint32_t) * (array->len + 1));
    if (array2 == NULL) {
        return;
    }
    array2[array->len] = newval;
    array->arr = array2;
    array->len += 1;
}

int binsearch(uint32_t *arr, int low, int high, uint32_t find) {
    if (low <= high && arr != NULL) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == find) {
            return mid;
        } else if (arr[mid] < find) {
            return binsearch(arr, mid + 1, high, find);
        } else if (arr[mid] > find) {
            return binsearch(arr, low, mid - 1, find);
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

int linsearch(uint32_t *arr, int len, uint32_t find) {
    if (len > 0 && arr != NULL) {
        for (int i = 0; i < len; i++) {
            if (arr[i] == find) {
                return i;
            } else {
                continue;
            }
        }
    }
    return -1;
}

void removeindex(struct intarr *array, int index) {
    if (index < array->len) {
        size_t newarrsize = sizeof(uint32_t) * (array->len - 1);
        uint32_t *newarr = malloc(newarrsize);
        for (int i = 0, j = 0; i < array->len; i++, j++) {
            if (i == index) {
                i++;
            }
            newarr[j] = array->arr[i];
        }
        free(array->arr);
        array->arr = newarr;
        array->len -= 1;
    }
}

void removeval(struct intarr *array, uint32_t remval) {
    int rem;
    if ((rem = binsearch(array->arr, 0, array->len - 1, remval)) < 0) {
        return;
    }
    removeindex(array, rem);
}