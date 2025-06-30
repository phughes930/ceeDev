#define _GNU_SOURCE
#include "abuf.h"
#include "buff.h"
#include "readcsv.h"
#include <stdio.h>

#define MAXCOLS 1000

/* csv: print headers, num_cols, num_rows from a file */
int main(int argc, char **argv) {
    if (argc < 1 || argc > 2) {
        printf("Error: improper usage\nProper usage: csv <path>");
        return -1;
    }

    char *path = argv[1];
    FILE *csv = fopen(path, "r");

    struct abuf *headerArr[MAXCOLS];
    int numCols = getCsvRow(csv, headerArr);

    return 0;
}
