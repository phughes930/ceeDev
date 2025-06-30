#ifndef READCSV_H
#define READCSV_H

#include <stdio.h>

int parseRow(struct abuf **destArr, struct abuf *headerData, char delim);
int getValues(struct abuf *headerData, struct abuf *colptr, int start, char delim);
int getCsvRow(FILE *csv, struct abuf **headerArr);

#endif