#include <stdint.h>
#include <stdio.h>

void swap(uint32_t *a, uint32_t *b)
{
    uint32_t temp = *a;
    *a = *b;
    *b = temp;
}

int partition(uint32_t *arr, int low, int high)
{
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }

        // find the first element less than
        // the pivot (from last)
        while (arr[j] >= p && i >= low + 1) {
            j--;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[high]);
    return j;
}

void quicksort(int *arr, int low, int high)
{
    // call partition function to find partition index
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively call quicksort for left and right
        // half based on partition index
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}