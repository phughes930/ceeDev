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
        // if (find == 3) {
        //     printf("low %d | mid %d | high %d\n", low, mid, high);
        //     printf("arr[low] %d | arr[mid] %d | arr[high] %d\n", arr[low], arr[mid], arr[high]);
        // }
        if (arr[mid] == find) {
            // if (find == 3)
            //     printf("found num = 3\n");
            return mid;
        } else if (arr[mid] < find) {
            // if (find == 3)
            //     printf("searching high end for num = 3\n");
            return binsearch(arr, mid + 1, high, find);
        } else if (arr[mid] > find) {
            // if (find == 3)
            //     printf("searching low end for num = 3\n");
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
        array->arr[index] = -1;
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

void removeval(struct intarr *array, int remval)
{
    int rem;
    if ((rem = binsearch(array->arr, 0, array->len - 1, remval)) < 0) {
        return;
    }
    removeindex(array, rem);
}