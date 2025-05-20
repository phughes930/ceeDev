#define _GNU_SOURCE
#include "intarr.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct intarr *initintarr()
{
    struct intarr *newarr = malloc(sizeof(struct intarr));
    newarr->arr = NULL;
    newarr->len = 0;

    return newarr;
}

void appendint(struct intarr *array, int newval)
{
    int *array2 = realloc(array->arr, sizeof(int) * (array->len + 1));
    if (array2 == NULL) {
        return;
    }
    array2[array->len] = newval;
    array->arr = array2;
    array->len += 1;
}

int binsearch(int *arr, int low, int high, int find)
{
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == find) {
            return mid;
        } else if (arr[mid] < find) {
            return binsearch(arr, mid + 1, high, find);
        } else if (arr[mid] > find) {
            return binsearch(arr, low, mid - 1, find);
        }
    } else {
        return -1;
    }
}

void removeindex(struct intarr *array, int index)
{
    if (index < array->len) {
        int *newarr = malloc(sizeof(int) * array->len - 1);
        for (int i = 0; i < array->len - 1; i++) {
            if (i == index) {
                continue;
            } else if (i < index) {
                newarr[i] = array->arr[i];
            } else if (i > index) {
                newarr[i] = array->arr[i + 1];
            }
        }
        array->arr = newarr;
        array->len -= 1;
    }
}

void removeval(struct intarr *array, int remval)
{
    int rem;
    if ((rem = binsearch(array->arr, 0, array->len - 1, remval)) < 0) {
        printf("val not found\n");
        return;
    }
    printf("val found at index %d\n", rem);
    removeindex(array, rem);
}