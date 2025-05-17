#ifndef READCSV_H
#define READCSV_H

int parseRow(struct abuf **destArr, struct abuf *headerData, char delim);
int getValues(struct abuf *headerData, struct abuf *colptr, int start, char delim);

#endif