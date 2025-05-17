#define _GNU_SOURCE
#include "abuf.h"
#include "buff.h"
#include "readcsv.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCOLS 1000

/* csv: print headers, num_cols, num_rows from a file */
int main(int argc, char **argv)
{
    if (argc < 1 || argc > 2) {
        printf("Error: improper usage\nProper usage: csv <path>");
        return -1;
    }

    char *path = argv[1];
    FILE *csv = fopen(path, "r");

    struct abuf *headerArr[MAXCOLS];
    struct abuf *headers = initBuffer();

    char *temp = NULL;
    size_t headerSize = 0;
    getline(&temp, &headerSize, csv);
    appendBuffer(headers, temp, strlen(temp));
    free(temp);

    int numCols = parseRow(headerArr, headers, ',');
    printf("%d columns\n", numCols);
    printf("Column names:\n");
    for (int i = 0; i < numCols; i++) {
        printf("\t%s\n", headerArr[i]->str);
    }

    return 0;
}