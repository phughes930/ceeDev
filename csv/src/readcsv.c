#define _GNU_SOURCE
#include "abuf.h"
#include "buff.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getValues(struct abuf *headerData, struct abuf *colptr, int start, char delim) {
    int j = start;
    char v, vplus;
    int quoteflag = 0;
    while ((v = headerData->str[j++]) != '\n') {
        char s[1];
        s[0] = v;
        vplus = headerData->str[j];
        if (v == '"') {
            if (j - 1 == start) {
                quoteflag = 1;
                continue;
            } else if (vplus == delim) {
                quoteflag = 0;
            } else if (vplus == '"') {
                continue;
            }
        } else if (v == delim && quoteflag == 0) {
            break;
        }
        appendBuffer(colptr, s, 1);
    }
    return j;
}

int parseRow(struct abuf **destArr, struct abuf *headerData, char delim) {
    int i = 0;
    int numcols = 0;
    while (i < headerData->len) {
        char c = headerData->str[i];
        struct abuf *newHeader = initBuffer();
        i = getValues(headerData, newHeader, i, delim);
        destArr[numcols++] = newHeader;
    }

    return numcols;
}

int getCsvRow(FILE *csv, struct abuf **headerArr) {
    struct abuf *headers = initBuffer();

    char *temp = NULL;
    size_t headerSize = 0;
    getline(&temp, &headerSize, csv);
    appendBuffer(headers, temp, strlen(temp));
    free(temp);

    int numCols = parseRow(headerArr, headers, ',');
    return numCols;
}